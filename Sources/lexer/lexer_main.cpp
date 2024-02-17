#include "debug.h"
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
  this->last_node=this->this_node=this->first_node=new lexer_read::lexer_node(0);

  
}

lexer_read::~lexer_read()
{
  printf("exit\n");

  
}

lexer_read::lexer_node::lexer_node(lexer_node *ptr)
{
 // printf("ttt%d\n",this->next_node[2]);
 // std::cout<<this->next_node[0]<<std::endl;
 // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  for_each(this->next_node, this->next_node+256, [](auto &node){node=0;});
  this->terminal=0;
  this->count=0;
  this->prev_node=ptr;
  //this->str=new string();
  // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  // printf("ttt%d\n",this->next_node[2]);
  
  
}    

lexer_read::lexer_node::~lexer_node()
{
  // printf("ttt\n");
  for_each(this->next_node, this->next_node+100, [](auto &node){node?delete node:[](){}();});

  
}

token_class::token lexer_read::operator()(char c)
{
  if(!(c-' ')) return !(this->this_node-this->first_node)||this->this_node-this->first_node&&this->this_node->get_terminal()?(this->this_node=this->first_node,this->last_node->get_token()):(this->this_node=this->first_node,this->last_node->set_node());

  // debug;
    
  this->last_node=this->this_node=(this->this_node->get_next_node(c)?this->this_node->get_next_node(c):this->this_node->add_node(c));

  // debug;

  return (this->this_node->get_terminal()?this->this_node->get_token():null_token);
  
  
}

lexer_read::lexer_node *lexer_read::lexer_node::add_node(char c)
{
  this->next_node[c]=new lexer_read::lexer_node(this);
  //this->next_node[c].prev_node=this->this_node;
  this->count++;
  // debug;
  if(this->prev_node)this->next_node[c]->str=this->str+c;
  else this->next_node[c]->str=c;
  // cout<<(int)c<<endl;
  // cout<<this->next_node[c]->str<<endl;
  // for_each(&(this->next_node[c]->next_node[0]), &(this->next_node[c]->next_node[256]), [](auto* &i){printf("%lld \t",(long int)i);});
  // for(int i=0;i<256;i++) printf("%ld\t",this->next_node[c]->next_node[i]);
  // debug;
  // printf("%ld\t%ld\n",this->next_node[c],this->next_node[c]->next_node);
  // debug;
    // int* i[100]; // 指针数组

    // // 使用 std::for_each 将所有元素指向空指针
    // std::for_each(std::begin(i), std::end(i), [](int* &ptr) { ptr = nullptr; });

    // // 输出指针数组中的值，验证是否指向空指针
    // for (int j = 0; j < 100; ++j) {
    //     std::cout << "i[" << j << "] = " << i[j] << std::endl;
    // }
  // debug;

  return this->next_node[c];
  
  
}

static int mdzztest;
token_class::token lexer_read::lexer_node::set_node(){this->set_terminal()/*,this->token=(token_class::token*)++mdzztest*/;return this->token;}

lexer_read::lexer_node *lexer_read::lexer_node::get_next_node(char c)
{
  // debug;
  //printf("%ld\t%ld\n",this,this->next_node[c]);
  // debug;
  return this->next_node[c];
  
  
}

void lexer_read::lexer_node::set_terminal()
{
  this->terminal=1;
  //this->token=0;
  // debug;
  // cout<<this->str;
  // debug;
  this->token.str=this->str;

  
}

int lexer_read::lexer_node::get_terminal()
{
  // debug;
  // printf("%d\n",this->terminal);
  // debug;
  return this->terminal;
  
  
}

token_class::token lexer_read::lexer_node::get_token()
{
  // debug;
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
