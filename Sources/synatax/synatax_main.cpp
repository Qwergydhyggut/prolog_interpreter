#include <functional>
#include <iostream>
#include "synatax.h"
#include "debug.h"
#include "token.h"
#include <map>
#include <sys/types.h>
#include <vector>
#include "synatax_tree.h"
#include "synatax/synatax_ptr.h"

using namespace synatax_mod;


bool token_class::bnf_token::operator<(const token_class::bnf_token &rkh) const
{
  return this->stat<rkh.stat;
}

token_class::bnf_token::bnf_token(token_class::bnf_token::Stat rcs)
{
  this->stat=rcs;
  
  
}

synatax_tree_class::synatax_tree synatax_read::null_sy_tree=synatax_tree_class::synatax_tree();

synatax_read::synatax_read()
{
  
  
}

synatax_read::synatax_read(synatax_ptr_f *spf)
{
  spf->next_bnf_list=next_bnf_list;
  this->spf=spf;

  
}    


std::vector<token_class::bnf_token> synatax_read::next_bnf_list(token_class::bnf_token bt,synatax_ptr_f *spf)
{
  std::vector<token_class::bnf_token> mdzz;
  std::vector<token_class::bnf_token> th_next;


  std::vector<token_class::bnf_token> bnf_stack;
  std::vector<token_class::token*> tok_stack;
  bnf_stack.push_back(bt);
  token_class::token *tok=spf->ret_next_token();
  tok_stack.push_back(tok);
  // debug;
  // printf("llll,%d\n",bnf_stack[bnf_stack.size()-1].stat);
  // debug;
  // for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
  // debug;
  while(true)
  {  
    // debug;
    // printf("llllmdzz,%d\n",bnf_stack[bnf_stack.size()-1].stat);
    // debug;
    th_next=spf->ret_fun(bnf_stack[bnf_stack.size()-1],tok);
    // debug;
    bnf_stack.pop_back();
    for(int i=th_next.size()-1;i>=0;i--) bnf_stack.push_back(th_next[i]);
    // debug;
    // for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
    // debug;
    if(!(bnf_stack[bnf_stack.size()-1].stat-token_class::bnf_token::Ter))
      {
	bnf_stack.pop_back();
	bnf_stack[bnf_stack.size()-1].is_ter=tok;
	return bnf_stack;//do_stack_fun(this->bnf_stack,this->tok_stack,this->op_stack);
      }
    
  }
}

void synatax_read::operator()(synatax_ptr_f *spf)
{
  std::vector<token_class::bnf_token> mdzz;
  std::vector<token_class::bnf_token> th_next;

  spf->next_bnf_list=next_bnf_list;
  spf->do_that();
  this->spf=spf;
  

  
}

void synatax_read::operator()()
{
  this->spf->do_that();

  
}

