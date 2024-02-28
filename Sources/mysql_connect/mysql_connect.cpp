#include "mysql_connect.h"
#include "analysis.h"
#include <string>
#include <mysql/mysql.h>
#include "debug.h"
#include <iostream>
#include <vector>

using namespace mysql_mod;


void mysql_mod::mysql_connect(std::string host,std::string user,std::string passwd,std::string database)
{
  // debug;
  std::vector<std::string> vec_str;
  std::string str;
  MYSQL *conn=mysql_init(0);


  if(!mysql_real_connect(conn,host.c_str(),user.c_str(),passwd.c_str(),database.c_str(),0,0,0))//debug;
  {
    printf("连接数据库失败\n");
    exit(23);
      
  }
  // std::cout<<host<<std::endl;
  if(mysql_query(conn, "SHOW TABLES"));

  MYSQL_RES *res = mysql_store_result(conn);
  if (res == nullptr)
  {
    std::cout << "Error storing query result" << std::endl;
    exit(1);
  }   

  // printf("%d\n",res);
  // exit(0);
    
  int num_fields = mysql_num_fields(res);
  MYSQL_ROW row;
    
  while ((row = mysql_fetch_row(res)))
  {
    for (int i = 0; i < num_fields; i++)
    {
      if (row[i] != nullptr)
      {
	// std::cout << "Table Name: " << row[i] << std::endl;
	str=row[i];
	// std::cout<<row[i]<<std::endl;

	// 查询每个表的列
	std::string query = "SHOW COLUMNS FROM " + std::string(row[i]);
	if (mysql_query(conn, query.c_str()))
	
	  std::cout << "Error executing column query" << std::endl;
                    // return 1;
      

	MYSQL_RES *col_res = mysql_store_result(conn);
	if (col_res == nullptr)
	  std::cout << "Error storing column query result" << std::endl;
                    // return 1;
      

	int col_num_fields = mysql_num_fields(col_res);
	MYSQL_ROW col_row;
	vec_str.clear();
	while ((col_row = mysql_fetch_row(col_res)))
	{
	  // std::cout<<col_row[0]<<std::endl;
	  vec_str.push_back(col_row[0]);
	  // for (int j = 0; j < col_num_fields; j++) {
	  //   if (col_row[j] != nullptr) {
	  //     std::cout << "Column Name: " << col_row[j] << std::endl;
	  //   }
	  // }debug;
	}
	analysis_mod::csz_stack::sql_shuju sq_sh;
	sq_sh.table=str;
	sq_sh.list=vec_str;
	analysis_mod::csz_stack::sql.insert(std::make_pair(str,sq_sh));
	
	mysql_free_result(col_res);
      }
    }
  }
  
  mysql_free_result(res);
  mysql_close(conn);
  debug;
  
  
}
