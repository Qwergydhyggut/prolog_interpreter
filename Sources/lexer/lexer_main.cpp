#include <cstdio>
#include "lexer.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <ostream>
#include <type_traits>

using namespace lexer_mod;
using namespace std;


lexer_read::lexer_read()
{
  printf("lll%s\n",__FILE__);
  this->last_node=this->this_node=this->first_node=new lexer_read::lexer_node;

  
}

lexer_read::~lexer_read()
{
  printf("exit\n");

  
}

lexer_read::lexer_node::lexer_node()
{
 // printf("ttt%d\n",this->next_node[2]);
 // std::cout<<this->next_node[0]<<std::endl;
 // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  for_each(this->next_node, this->next_node+100, [](auto &node){node=0;});
  this->terminal=0;
  this->count=0;
  // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  // printf("ttt%d\n",this->next_node[2]);
  
  
}    

lexer_read::lexer_node::~lexer_node()
{
  // printf("ttt\n");
  for_each(this->next_node, this->next_node+100, [](auto &node){node?delete node:[](){}();});

  
}

token_class::token *lexer_read::operator()(char c)
{
  if(!(c-' ')) return !(this->this_node-this->first_node)||this->this_node-this->first_node&&this->this_node->get_terminal()?(this->this_node=this->first_node,this->last_node->get_token()):(this->this_node=this->first_node,this->last_node->set_node());
    
  this->last_node=this->this_node=(this->this_node->get_next_node(c)?this->this_node->get_next_node(c):this->this_node->add_node(c));

  return (this->this_node->get_terminal()?this->this_node->get_token():0);
  
  
}

lexer_read::lexer_node *lexer_read::lexer_node::add_node(char c)
{
  this->next_node[c]=new lexer_read::lexer_node;
  this->count++;

  return this->next_node[c];
  
  
}

static int mdzztest;
token_class::token *lexer_read::lexer_node::set_node(){this->set_terminal(),this->token=(token_class::token*)++mdzztest;return this->token;}

lexer_read::lexer_node *lexer_read::lexer_node::get_next_node(char c)
{
  return this->next_node[c];
  
  
}

void lexer_read::lexer_node::set_terminal()
{
  this->terminal=1;
  this->token=0;

  
}

int lexer_read::lexer_node::get_terminal()
{
  return this->terminal;
  
  
}

token_class::token *lexer_read::lexer_node::get_token()
{
  return this->token;
  
  
}

// class lexer_mod::lexer_read
// {
//   public lexer_read()
//   {
//     printf("lll%s\n",__FILE__);
    
//   }
  
// };
// void test()
// {
//   printf("lll\n");
  
// }
