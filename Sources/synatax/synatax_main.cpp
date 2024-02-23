#include <functional>
#include <iostream>
#include "synatax.h"
#include "debug.h"
#include "token.h"
#include <map>
#include <vector>
#include "synatax_tree.h"


// void test_syna()
// {
//   debug;

  
// }
using namespace synatax_mod;


//   struct bnf_token_1
//   {
//     token_class::token is_ter;
//     typedef enum {ENABLE_BNF_TOKEN} Stat;
//     Stat stat;
//     bnf_token_1(Stat rcs);
//     bool operator<(const bnf_token_1 &rkh) const;
//   };
// bool bnf_token_1::operator<(const bnf_token_1 &rkh) const
// {
//   return this->stat<rkh.stat;
// }

// bnf_token_1::bnf_token_1(bnf_token_1::Stat rcs)
// {
//   this->stat=rcs;
  
  
// }  
bool token_class::bnf_token::operator<(const token_class::bnf_token &rkh) const
{
  return this->stat<rkh.stat;
}

token_class::bnf_token::bnf_token(token_class::bnf_token::Stat rcs)
{
  this->stat=rcs;
  
  
}  

synatax_read::synatax_read(std::function<std::vector<token_class::bnf_token>(token_class::bnf_token,token_class::token)> ptr, std::function<synatax_tree_class::synatax_tree(std::vector<token_class::bnf_token>&,std::vector<token_class::token>&,std::vector<token_class::token>&)> ptr1)
{
  this->ret_fun=ptr;
  this->do_stack_fun=ptr1;
  this->bnf_stack.push_back(token_class::bnf_token(token_class::bnf_token::S));
  
  
}    

// synatax_read::
std::vector<token_class::bnf_token> synatax_read::init_ret_fun(token_class::bnf_token bt,token_class::token tok)
{
  std::vector<token_class::bnf_token> mdzz;
  static token_class::bnf_token T(token_class::bnf_token::T);
  static token_class::bnf_token E(token_class::bnf_token::E);
  static std::vector<token_class::bnf_token> T1={T,E};
  // static bnf_token_1 TT(bnf_token_1::T);
  // static bnf_token_1 EE(bnf_token_1::E);
  // static std::map<bnf_token_1, bnf_token_1> mdzz111={{TT,EE}};
  static std::map<token_class::bnf_token,std::map<token_class::token::Stat,std::vector<token_class::bnf_token>>> synatax_bnf={{T,{{token_class::token::Atom_t,T1}}}};

  return synatax_bnf[bt][tok.true_type];

  
}  

synatax_tree_class::synatax_tree synatax_read::init_do_stack_fun(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token> &tok_stack,std::vector<token_class::token> &op_stack)
{
  static int i;
  synatax_tree_class::synatax_tree ret_sy;

  ret_sy.car=op_stack[-1];
  ret_sy.args={tok_stack[-1],tok_stack[-2]};
  ret_sy.addr=i++;

  op_stack.pop_back();
  tok_stack.pop_back();
  tok_stack.pop_back();
  bnf_stack.pop_back();

  return ret_sy;
  
  
}  

synatax_tree_class::synatax_tree synatax_read::operator()(token_class::token tok)
{
  std::vector<token_class::bnf_token> th_next;

  while(true)
  {  
    this->tok_stack.push_back(tok);
    ret_fun(this->bnf_stack[-1],tok);
    for(int i=0;i<th_next.size();i++) this->bnf_stack.push_back(th_next[i]);
    if(!(this->bnf_stack[-1].stat-token_class::bnf_token::Ter))
      return do_stack_fun(this->bnf_stack,this->tok_stack,this->op_stack);
    
  } 
  
  
}  
