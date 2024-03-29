#include "debug.h"
#include <cstdio>
#include "lexer.h"
#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
//#include <type_traits>
#include <ratio>
#include <vector>
#include "token.h"

using namespace lexer_mod;
using namespace token_class;
using namespace std;


lexer_read::lexer_read(std::function<bool(char,char)> fun_ptr,std::function<void(token_class::token&)> fun_ptr1)
{
  // printf("lll%s\n",__FILE__);
  this->last_node=this->this_node=this->first_node=new lexer_read::lexer_node(0,fun_ptr1);
  this->lexer_list.push_back(this->first_node);
  this->fun_ifter=fun_ptr;
  this->fun_set_token=fun_ptr1;
  //this->ter_save=0;

  
}

lexer_read::~lexer_read()
{
  // printf("exit\n");

  
}

lexer_read::lexer_node::lexer_node(lexer_node *ptr,std::function<void(token_class::token&)> fun_ptr)
{
 // printf("ttt%d\n",this->next_node[2]);
 // std::cout<<this->next_node[0]<<std::endl;
 // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  for_each(this->next_node, this->next_node+256, [](auto &node){node=0;});
  this->terminal=0;
  this->count=0;
  this->prev_node=ptr;
  this->token=null_token;
  this->fun_set_token=fun_ptr;
  //std::cout<<null_token.str<<std::endl;
  //printf("qqqqqqqqqqqqqqqqqqqqqqqqqqqq\n");
  //this->str=new string();
  // std::for_each(this->next_node, this->next_node+100, [](auto &node){std::cout<<node<<std::endl;});
  // printf("ttt%d\n",this->next_node[2]);
  
  
}    

lexer_read::lexer_node::~lexer_node()
{
  // printf("ttt\n");
  for_each(this->next_node, this->next_node+100, [](auto &node){node?delete node:[](){}();});

  
}

token_class::token &lexer_read::operator()(char c,char c1)
{
  // if(!(c-' ')) return !(this->this_node-this->first_node)||this->this_node-this->first_node&&this->this_node->get_terminal()?(this->this_node=this->first_node,this->last_node->get_token()):(this->this_node=this->first_node,this->last_node->set_node(++this->ter_save));
  if(c-' '&&c-'\n') this->last_node=this->this_node=(this->this_node->get_next_node(c)?this->this_node->get_next_node(c):this->this_node->add_node(c));

  if(this->fun_ifter(c,c1))
    if(!(this->this_node-this->first_node)&&!this->this_node->get_next_node(c)) return null_token;
    else if(this->this_node->get_terminal()) {// debug;
      return this->this_node=this->first_node,this->fun_set_token?(this->fun_set_token(null_token),0):0,this->last_node->get_token();}
    else
    {
      int ter_save=this->ter_save();
      if(this->lexer_list.size()>ter_save) this->lexer_list[ter_save]=this_node;
      else this->lexer_list.push_back(this_node);
      this->this_node=this->first_node;
      return this->last_node->set_node(ter_save);
    }

  // debug;
    

  // debug;

  // return (this->this_node->get_terminal()?this->this_node->get_token():null_token);
  return null_token;
}

void lexer_read::__debug_ret_lexer()
{
  for(int i=0;i<this->lexer_list.size();i++)
    std::cout<<i<<'\t'<<this->lexer_list[i]->get_token().token_exp<<'\t'<<this->lexer_list[i]->get_token().str<<std::endl;
  
  //return this->lexer_list;
}

void lexer_read::del_token(token_class::token tok)
{
  lexer_read::lexer_node *node,*fork_node;

  node=this->lexer_list[tok.token_exp];
  //for(node=lexer_list[tok.token_exp];!node->count;node=node->prev_node);
  this->lexer_list[tok.token_exp]=first_node;
  this->ter_save(tok.token_exp);
  fork_node=node->get_node_fork();
  // debug;
  if(!(fork_node-node)) node->set_terminal(0);
  else fork_node->del_node();
  // debug;
  this->last_node=this->this_node=this->first_node;
  
  
  
}  

lexer_read::lexer_node *lexer_read::lexer_node::add_node(char c)
{
  this->next_node[c]=new lexer_read::lexer_node(this,this->fun_set_token);
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

void lexer_read::lexer_node::del_node()
{
  // debug;
  lexer_read::lexer_node *prev_p;
  char c;
  prev_p=this->prev_node;
  // debug;
  c=this->str[this->str.size()-1];
  prev_p->count--;
  // std::cout<<prev_p->str<<'\t'<<c<<std::endl;
  prev_p->next_node[c]=0;
  // debug;
  delete this;
  
  
}

lexer_read::lexer_node *lexer_read::lexer_node::get_node_fork()
{
  // debug;
  lexer_read::lexer_node *ptr1,*ptr;
  // std::cout<<this->str<<'\t'<<this->count<<"kkkkkkkkk"<<std::endl;
  //ptr=this;
  if(!(this->count-1)) return this;
  //printf("%ld\n",(long int)ptr->prev_node);
  // debug;
  for(ptr=this;ptr->prev_node&&!(ptr->prev_node->count-1);ptr=ptr1)
  {
    // debug;
    ptr1=ptr->prev_node;
    // this->count--;
    // std::cout<<ptr->prev_node->prev_node->count<<std::endl;
    // std::cout<<ptr->str<<'\t'<<ptr->count<<"llll"<<std::endl;
    // delete ptr;
  }
  // std::cout<<ptr->str<<std::endl;

  return ptr;
  
  
}  

static int mdzztest;
token_class::token lexer_read::null_token=token_class::token();
token_class::token &lexer_read::lexer_node::set_node(int ter){this->set_terminal(ter)/*,this->token=(token_class::token*)++mdzztest*/;if(this->fun_set_token)this->fun_set_token(this->token);// debug;
  /*printf("%ld\n",&this->token);debug*/;return this->token;}

lexer_read::lexer_node *lexer_read::lexer_node::get_next_node(char c)
{
  // debug;
  //printf("%ld\t%ld\n",this,this->next_node[c]);
  // debug;
  return this->next_node[c];
  
  
}

void lexer_read::lexer_node::set_terminal(int ter)
{
  this->terminal=ter;
  //this->token=0;
  // debug;
  // cout<<this->str;
  // debug;
  this->token.token_exp=ter;
  this->token.str=this->str;

  
}

int lexer_read::lexer_node::get_terminal()
{
  // debug;
  // printf("%d\n",this->terminal);
  // debug;
  return this->terminal;
  
  
}

token_class::token &lexer_read::lexer_node::get_token()
{
  // debug;
  //printf("%ld\n",&(this->token));
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
