// void test();
#ifndef __LEXER_INCLUDE__
#define __LEXER_INCLUDE__
#include "token.h"
#include "lexer/token_num.h"
#include <functional>
#include <gtest/gtest_prod.h>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>


namespace lexer_mod
{
  class lexer_read
  {
    void __debug_ret_lexer();
    FRIEND_TEST(read, lexer_list);
    FRIEND_TEST(read, del_node);
    FRIEND_TEST(read, select);
    // FRIEND_TEST(read,lexer_list);
    
    
    class lexer_node
    {
      lexer_node *next_node[256];
      lexer_node *prev_node;
      int count;
      int terminal;
      token_class::token token;
      std::string str;
      std::function<void(token_class::token&)> fun_set_token;

    public:
      lexer_node(lexer_node *ptr,std::function<void(token_class::token&)> fun_ptr);
      ~lexer_node();
      lexer_node *add_node(char c);
      void del_node();
      lexer_read::lexer_node *get_node_fork();
      token_class::token &set_node(int ter);
      lexer_node *get_next_node(char c);
      void set_terminal(int ter);
      int get_terminal();
      token_class::token &get_token();

      
    };

  public:
    static token_class::token null_token;
    lexer_read();
    lexer_read(std::function<bool(char,char)> fun_ptr,std::function<void(token_class::token&)> fun_ptr1=0);
    ~lexer_read();
    token_class::token &operator()(char c,char c1);
    //void __debug_ret_lexer();
    void del_token(token_class::token tok);

  private:
    lexer_node *first_node;
    lexer_node *this_node;
    lexer_node *last_node;
    // bool (*fun_ifter)(char,char);
    std::function<bool(char,char)> fun_ifter;
    std::function<void(token_class::token&)> fun_set_token;
    //int ter_save;
    std::vector<lexer_node*> lexer_list;
    token_num_sp::token_num ter_save;


  };
  
};

#endif
