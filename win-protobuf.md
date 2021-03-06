# 在Windows下使用Protobuf的示例

Stone


## 摘要

Protobuf全称为Google ProtoBuf,它是由Google开源的项目，类似于接口定义语言(IDL),作为一种数据交换格式,适用于跨平台数据通讯时的消息编码和解码。本文演示了在Windows下如何在C++语言环境下使用Protobuf。关键步骤为：
 1. 定义数据交换格式(proto文件)
 2. 利用protoc实用工具把proto文件编译成C++头文件和库文件
 3. 利用mwc构建工具把生成的头文件和库文件编译成动态链接库
 4. 在项目工程中引用这个库进行消息编码和/或解码

在使用前，需要先构建protoc实用工具和protobuf开发库。

## 演示环境

    * Windows 7
    * Visual Studio 2015 社区版
    * ACE 6.4.4
    * mwc 4.1.25 (in ACE )
    * Active Perl 5.22.1
    * git 2.9.0 windows.1
    * sed 4.2.2 (in git)
    * CMake 3.9.1
    * Protobuf 3.4.0 (当前最新发行版)

## 预备环境
  
  * 安装Active Perl
  
    mwc依赖Perl
    
  * 安装 git 
  
    在编译库时，需要利用git环境下的sed工具，修改生成的头文件.
  * 安装 CMake 
  
    构建protoc工具及开发库时需要用到CMake工具。
  * 在Windows下正确编译ACE (x64)
  
## 从源代码中构建protoc及开发库

### 步骤
    
1. 从github上获得protobuf的源代码

    ```
    mkdir demo
    mkdir build
    cd demo
    git clone --recursive -b v3.4.0 https://github.com/google/protobuf.git
    ```
    
2. 利用CMake生成基于Visual Studio 2015的解决方案工程文件

    ```
    cd build
    cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_INSTALL_PREFIX=/usr/local  -Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_BUILD_SHARED_LIBS=ON ../demo/protobuf/cmake
    ```
    
3. 用Visual Studio打开上一步生成的protobuf.sln文件，编译生成。执行INSTALL工程，可以将编译的结果输出到/usr/local目录下




### 说明

1. 设置生成的路径为当前盘符的/usr/local，这是我的个人喜好，目的是跟linux下的路径一致，因为绝大数时候，还是工作在linux环境下的。

2. 生成动态链接库 -Dprotobuf_BUILD_SHARED_LIBS=ON 

3. 不编译测试代码 -Dprotobuf_BUILD_TESTS=OFF



## 使用protobuf的主要步骤

1. 定义数据交换格式文件 
   ```
   syntax="proto3";
   package GP.Msg;

    message Header
    {
        uint32 cmd = 1;   //消息号
        uint32 sn = 2;    //消息序号
        string token = 3; //消息令牌
    }
   ```
2. 生成动态链接库
    
    利用ACE提供的工具generate_export_file.pl生成导出文件，这个文件后面要用到。
    
    ```
     cd libDemo
     generate_export_file.pl GP_PROTOC > GP_Protoc_Export.h
    ```
    
    
    利用protoc实用工具生成c++头文件和源文件,参见libDemo/g.sh。这一步由于要使用sed，所以需要进入到git bash环境中来运行。
    
    ```
     protoc  --cpp_out=dllexport_decl=GP_PROTOC_Export:. Demo.proto
     sed -i '21 c #include "GP_Protoc_Export.h"' Demo.pb.h
    ```
    
    protoc有dllexport_decl指令用于方便生成的代码能编译成动态库，但是我还不知道用什么指令来在生成的*.pb.h中增加包含的头文件，所以只好用sed来强行修改。如果您知道有更好的办法，请告诉我。
    
    接下来利用mwc工具生成构建文件。mwc工具类似于CMake，本文件暂不多作讨论，如果有需要更详细的介绍，请给我留言。这里直接给出操作指令。
    
    ```
     rem 当前路径 libDemo
     mwc.pl -type vc14
    ```
    
    以上指令能生成 libDemo.sln文件,用Visual Studio编译可得libDemo.dll, libDemo.lib
    

3. 在自己的工程中使用动态库进行编码或解码

    ~~~
     rem 当前路径 DemoApp
     mwc.pl -type vc14
    ~~~
    
    以上指令能生成 DemoApp.sln文件,用Visual Studio编译可得DemoApp.exe,运行结果如下：
    
    ```
        C:\workspace\win-protobuf\windows-protobuf\src\lib>DemoApp.exe
        cmd: 1
        sn: 123
        token: "abcde"

        {abcde

        cmd = 1

        sn =123

        token =abcde
     ```
    
## 示例代码
  
  https://github.com/stonejiang208/windows-protobuf
  
 
