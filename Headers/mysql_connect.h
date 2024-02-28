#ifndef __MYSQL_CONNECT_INCLUDE__
#define __MYSQL_CONNECT_INCLUDE__
#include "analysis.h"
#include <string>


namespace mysql_mod
{
  void mysql_connect(std::string host,std::string user,std::string passwd,std::string database);
  
  
}

#endif
