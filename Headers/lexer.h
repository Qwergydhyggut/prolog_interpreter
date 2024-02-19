// void test();
#ifndef __LEXER_INCLUDE__
#define __LEXER_INCLUDE__
#include "token.h"
#include "lexer/token_num.h"
#include <string>
#include <vector>
#include <gtest/gtest.h>


namespace lexer_mod
{
  class lexer_read
  {
    void __debug_ret_lexer();
    FRIEND_TEST(read, lexer_list);
    FRIEND_TEST(read, del_node);
    // FRIEND_TEST(read,lexer_list);
    
    
    class lexer_node
    {
      lexer_node *next_node[256];
      lexer_node *prev_node;
      int count;
      int terminal;
      token_class::token token;
      std::string str;

    public:
      lexer_node(lexer_node *ptr);
      ~lexer_node();
      lexer_node *add_node(char c);
      void del_node();
      lexer_read::lexer_node *get_node_fork();
      token_class::token set_node(int ter);
      lexer_node *get_next_node(char c);
      void set_terminal(int ter);
      int get_terminal();
      token_class::token get_token();

      
    };

  public:
    lexer_read();
    ~lexer_read();
    token_class::token operator()(char c);
    //void __debug_ret_lexer();
    void del_token(token_class::token tok);

  private:
    lexer_node *first_node;
    lexer_node *this_node;
    lexer_node *last_node;
    static token_class::token null_token;
    //int ter_save;
    std::vector<lexer_node*> lexer_list;
    token_num_sp::token_num ter_save;


  };
  
};

#endif
