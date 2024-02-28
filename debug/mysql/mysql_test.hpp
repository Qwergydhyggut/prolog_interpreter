#include <gtest/gtest.h>
#include "mysql_connect.h"
#include "debug.h"
#include "synatax.h"
#include "source_read.h"


TEST(mysql, connect_test)
{
  mysql_mod::mysql_connect("127.0.0.1", "root", "qqq111", "gra_db");
  debug;

  
}

TEST(mysql, sqldo)
{
  debug;
  synatax_mod::synatax_read test;
  synatax_ptr_sql lll;
  debug;

  test(&lll);

  
}

TEST(source, test)
{
  int i;
  char strs[]="lll";
  char **mdzz;

  // mdzz=new char*;
  // mdzz[0]=strs;
  source_read_mod::source_select::select_mode("lll");
  debug;

  
}
