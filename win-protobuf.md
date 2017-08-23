# 在Windows下使用Protobuf的示例

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
    
    * 从github上获得protobuf的源代码

~~~
mkdir demo
mkdir build
cd demo
git clone --recursive -b v3.4.0 https://github.com/google/protobuf.git
~~~
    
    * 利用CMake生成基于Visual Studio 2015的
~~~
cd build
cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_INSTALL_PREFIX=/usr/local  -Dprotobuf_BUILD_TESTS=OFF -Dprotobuf_BUILD_TESTS=OFF ../demo/protobuf/cmake
~~~
    
### 说明 
    1. 

## 主要步骤

## 示例代码


