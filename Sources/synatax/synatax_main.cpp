#include <functional>
#include <iostream>
#include "synatax.h"
#include "debug.h"
#include "token.h"
#include <map>
#include <sys/types.h>
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
  // printf("lll,%d",rcs);
  // debug;
  this->stat=rcs;
  
  
}

synatax_tree_class::synatax_tree synatax_read::null_sy_tree=synatax_tree_class::synatax_tree();

synatax_read::synatax_read(RET_FUN_TYPE ptr, DO_STACK_FUN ptr1)
{
  this->ret_fun=ptr;
  this->do_stack_fun=ptr1;
  // token_class::bnf_token *mdzz=new token_class::bnf_token(token_class::bnf_token::S);
  // debug;
  // mdzz->stat;
  // debug;
  // printf("lll,%ld\n",mdzz);
  this->bnf_stack.push_back(token_class::bnf_token(token_class::bnf_token::S));
  // printf("lll,%ld\n",this->bnf_stack.size());
  // printf("lll,%ld\n",this->bnf_stack[0].stat);
  // debug;
  // // printf("lll,%ld\n",bnf_stack[-1]);
  // debug;
  // printf("lll,%d\n",token_class::bnf_token::S);
  // this->null_sy_tree.addr=0;
  
  
}    

// synatax_read::
std::vector<token_class::bnf_token> synatax_read::init_ret_fun(token_class::bnf_token bt,token_class::token tok)
{
  std::vector<token_class::bnf_token> mdzz;
  static token_class::bnf_token T(token_class::bnf_token::T);
  static token_class::bnf_token T1(token_class::bnf_token::T1);
  static token_class::bnf_token T2(token_class::bnf_token::T2);
  static token_class::bnf_token E(token_class::bnf_token::E);
  static token_class::bnf_token E1(token_class::bnf_token::E1);
  static token_class::bnf_token E2(token_class::bnf_token::E2);
  static token_class::bnf_token S(token_class::bnf_token::S);
  static token_class::bnf_token F(token_class::bnf_token::F);
  static token_class::bnf_token OP(token_class::bnf_token::OP);
  static token_class::bnf_token Ter(token_class::bnf_token::Ter);
  static token_class::bnf_token Lkh(token_class::bnf_token::Lkh);
  static token_class::bnf_token Rkh(token_class::bnf_token::Rkh);
  static token_class::bnf_token ID(token_class::bnf_token::ID);
  // static std::vector<token_class::bnf_token> T1={T,E};
  // static bnf_token_1 TT(bnf_token_1::T);
  // static bnf_token_1 EE(bnf_token_1::E);
  // static std::map<bnf_token_1, bnf_token_1> mdzz111={{TT,EE}};
  static std::map<token_class::bnf_token,std::map<token_class::token::Stat,std::vector<token_class::bnf_token>>> synatax_bnf=
    {{S,{{token_class::token::Inter_t,{E,Ter}},
	 {token_class::token::Lkh_t,{E,Ter}}}},
     {E,{{token_class::token::Inter_t,{F,E2}},
	 {token_class::token::Lkh_t,{F,E2}}}},
     {F,{{token_class::token::Inter_t,{ID,E2}},
	 {token_class::token::Lkh_t,{Lkh,E,Rkh}}}}, //Ter E2 E2 ID
     {E2,{{token_class::token::Ter_t,{Ter}},        //Ter E2 E2 Rkh E2 E2 
	  // {token_class::token::OR_t,{OP,E}},       Ter E2 Rkh E2 E2 
	  {token_class::token::OP_t,{OP,E}}}},
     {ID,{{token_class::token::Inter_t,{Ter,ID}}}},
     {Lkh,{{token_class::token::Lkh_t,{Ter,Lkh}}}},
     {Rkh,{{token_class::token::Rkh_t,{Ter,Rkh}}}},
     {OP,{//{token_class::token::AND_t,{Ter,OP}},
	  {token_class::token::OP_t,{Ter,OP}}}}};
  debug;
    // {{S,{{token_class::token::Inter_t,{E,Ter}},
    // 	 {token_class::token::Lkh_t,{E,Ter}}}},
    //  {E,{{token_class::token::Inter_t,{F,E1}},
    // 	 {token_class::token::Lkh_t,{F,E1}}}},
    //  {T,{{token_class::token::Inter_t,{F,T2}},
    // 	 {token_class::token::Lkh_t,{F,T2}}}},
    //  {F,{{token_class::token::Inter_t,{ID}},
    // 	 {token_class::token::Lkh_t,{Lkh,E,Rkh}}}},
    //  {E1,{{token_class::token::AND_t,{OP,T,E2}}}},
    //  {T1,{{token_class::token::OR_t,{OP,T,T2}}}},
    //  {E2,{{token_class::token::Ter_t,{Ter}},
    // 	  {token_class::token::AND_t,{E1}}}},
    //  {T2,{{token_class::token::Ter_t,{Ter}},
    // 	  {token_class::token::OR_t,{T1}},
    // 	  {token_class::token::AND_t,{E1}}}}};
     // {Ter,{{token_class::token::Ter_t,{Ter}}}}};

  return synatax_bnf[bt][tok.true_type];

  
}  

synatax_tree_class::synatax_tree synatax_read::init_do_stack_fun(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack)
{
  static int i=1;
  synatax_tree_class::synatax_tree ret_sy;

  bnf_stack.pop_back();
  ret_sy=null_sy_tree;
  // switch(bnf_stack[bnf_stack.size()-1].stat)
  // {
  // case token_class::bnf_token::ID:
  //   ret_sy.addr=i;
  //   ret_sy.car=tok_stack[tok_stack.size()-1];
  //   tok_stack.pop_back();
  //   tok_stack.push_back(token_class::token(i++));
  //   bnf_stack.pop_back();
  //   break;
      
  // }
  switch(bnf_stack[bnf_stack.size()-1].stat)
  {
  case token_class::bnf_token::ID:
    debug;
    if(!op_stack.empty()&&!(op_stack[op_stack.size()-1]->true_type-token_class::token::OP_t))
    {
      ret_sy.addr=i;
      ret_sy.car=op_stack[op_stack.size()-1];
      ret_sy.args={tok_stack[tok_stack.size()-1],tok_stack[tok_stack.size()-2]};
      op_stack.pop_back();
      tok_stack.pop_back();
      tok_stack.pop_back();
      tok_stack.push_back(new token_class::token(i++));

      break;
	
    }
    ret_sy.addr=i;
    ret_sy.car=tok_stack[tok_stack.size()-1];
    tok_stack.pop_back();
    tok_stack.push_back(new token_class::token(i++));
    debug;
    printf("%d %d\n",tok_stack[tok_stack.size()-1]->true_type,tok_stack[tok_stack.size()-1]->addr);
    break;
  case token_class::bnf_token::OP:
    debug;
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    break;
  case token_class::bnf_token::Rkh:
    debug;
    op_stack.pop_back();
    tok_stack.pop_back();
    break;
  case token_class::bnf_token::Lkh:
    op_stack.push_back(tok_stack[tok_stack.size()-1]);
    tok_stack.pop_back();
    break;

  default:ret_sy=null_sy_tree;debug;//bnf_stack.pop_back();
    
  }
  bnf_stack.pop_back();

  debug;
  return ret_sy;
  
  
}  

synatax_tree_class::synatax_tree synatax_read::operator()(token_class::token &tok)
{
  std::vector<token_class::bnf_token> th_next;

  this->tok_stack.push_back(&tok);
  debug;
  printf("llll,%d\n",this->bnf_stack[this->bnf_stack.size()-1].stat);
    debug;
  while(true)
  {  
    th_next=ret_fun(this->bnf_stack[this->bnf_stack.size()-1],tok);
    debug;
    for(int i=th_next.size()-1;i>=0;i--) printf("ooo,%d\n",th_next[i].stat);
    debug;
    this->bnf_stack.pop_back();
    for(int i=th_next.size()-1;i>=0;i--) this->bnf_stack.push_back(th_next[i]);
    for(int i=this->bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",this->bnf_stack[i].stat);
    debug;
    if(!(this->bnf_stack[this->bnf_stack.size()-1].stat-token_class::bnf_token::Ter))
      return do_stack_fun(this->bnf_stack,this->tok_stack,this->op_stack);
    
  } 
  
  
}  
