#include "source_read.h"
#include "synatax/synatax_ptr.h"
#include "debug.h"
#include <string>
#include <cstdio>
#include "mysql_connect.h"
#include <iostream>

using namespace source_read_mod;


synatax_ptr_f *source_select::select_mode(std::string args)
{
  debug;
  FILE *fp;
  
  synatax_ptr_text *sy_p=new synatax_ptr_text;
  fp=fopen(args.c_str(),"r");

  if(!fp)
  {
    printf("没有这个文件！");
    exit(1);
      
  }  

  std::string str[4];
  printf("输入mysql数据库地址：");std::cin>>str[0];
  printf("输入用户名：");std::cin>>str[1];
  printf("输入密码：");std::cin>>str[2];
  printf("输入数据库名：");std::cin>>str[3];

  mysql_mod::mysql_connect("127.0.0.1", "root", "qqq111", "gra_db");
  sy_p->fp=fp;


  return sy_p;

  
}
