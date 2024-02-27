#include "mysql_connect.h"
#include "analysis.h"
#include <string>
#include <mysql/mysql.h>
#include "debug.h"
#include <iostream>

using namespace mysql_mod;


void mysql_mod::mysql_connect(std::string host,std::string user,std::string passwd,std::string database)
{
  debug;
  MYSQL *conn=mysql_init(0);


  if(mysql_real_connect(conn,host.c_str(),user.c_str(),passwd.c_str(),database.c_str(),0,0,0)==0)debug;
  std::cout<<host<<std::endl;
  //if(mysql_real_connect(conn,host.c_str(),,qqq111","gra_db",0,0,0)==0)debug;
  // if(mysql_query(conn,"SELECT * FROM lll"))debug;
  if(mysql_query(conn, "SHOW TABLES"));

  MYSQL_RES *res = mysql_store_result(conn);
  // if (res == nullptr) {
  //   std::cout << "Error storing query result" << std::endl;
  // }
    
    // int num_fields = mysql_num_fields(res);
    // MYSQL_ROW row;
    
    // while ((row = mysql_fetch_row(res))) {
    //     for (int i = 0; i < num_fields; i++) {
    //         if (row[i] != nullptr) {
    //             std::cout << row[i] << std::endl;
    //         }
    //     }
    // }

    // mysql_free_result(res);
    // mysql_close(conn);
  // MYSQL_RES *res=mysql_store_result(conn);
  // if(!res)debug;
  // MYSQL_ROW row;
  // while((row=mysql_fetch_row(res))) std::cout<<row[0]<<'\t'<<row[1]<<std::endl;
    if (res == nullptr) {
        std::cout << "Error storing query result" << std::endl;
        // return 1;
    }
    
    int num_fields = mysql_num_fields(res);
    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] != nullptr) {
                std::cout << "Table Name: " << row[i] << std::endl;

                // 查询每个表的列
                std::string query = "SHOW COLUMNS FROM " + std::string(row[i]);
                if (mysql_query(conn, query.c_str())) {
                    std::cout << "Error executing column query" << std::endl;
                    // return 1;
                }

                MYSQL_RES *col_res = mysql_store_result(conn);
                if (col_res == nullptr) {
                    std::cout << "Error storing column query result" << std::endl;
                    // return 1;
                }

                int col_num_fields = mysql_num_fields(col_res);
                MYSQL_ROW col_row;
		// // int col_num_fields = mysql_num_fields(col_res);
		// MYSQL_FIELD *field;
		// while ((field = mysql_fetch_field(col_res))) {
		//   std::cout << "Column Name: " << field->name << std::endl;
		// }
                while ((col_row = mysql_fetch_row(col_res))) {
                    for (int j = 0; j < col_num_fields; j++) {
                        if (col_row[j] != nullptr) {
                            std::cout << "Column Name: " << col_row[j] << std::endl;
                        }
                    }debug;
                }

                mysql_free_result(col_res);
            }
        }
    }

    mysql_free_result(res);
    mysql_close(conn);
  debug;
  
  
}
