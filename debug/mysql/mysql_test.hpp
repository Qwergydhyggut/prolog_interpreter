#include <gtest/gtest.h>
#include "mysql_connect.h"
#include "debug.h"


TEST(mysql, connect_test)
{
  mysql_mod::mysql_connect("127.0.0.1", "root", "qqq111", "gra_db");
  debug;

  
}
