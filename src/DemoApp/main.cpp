// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2017-03-30 09:35:01 by root> */

/* @file main.cpp
 * $Id: main.cpp 2017-03-22 11:34:24 root 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#include "ace/OS_main.h"
#include "ace/Log_Msg.h"
#include "ace/Assert.h"
#include "libDemo/Demo.pb.h"
#include <iostream>
void test_encode();
void test_decode(const char* c, size_t n);

int ACE_TMAIN(int , ACE_TCHAR*[])
{
  test_encode();

  return 0;
}


void test_decode(const char* c, size_t n)
{
  ::GP::Msg::Header h;
 bool is_ok = h.ParseFromArray(c, (int) n);
 ACE_ASSERT(is_ok);
 std::cout << "\n cmd = " << h.cmd() << "\n";
 std::cout << "\n sn =" << h.sn() << "\n";
 std::cout << "\n token =" << h.token() << "\n";
}

void test_encode()
{
  ::GP::Msg::Header h;
  h.set_cmd(1);
  h.set_sn(123);
  h.set_token("abcde");
  h.PrintDebugString();

 std::string str = h.SerializeAsString();
 std::cout << "\n" << str << "\n";
 test_decode(str.c_str(), str.length());

}