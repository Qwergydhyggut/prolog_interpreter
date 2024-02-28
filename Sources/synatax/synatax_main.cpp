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
  // printf("lll,%d",rcs);
  // debug;
  this->stat=rcs;
  
  
}

synatax_tree_class::synatax_tree synatax_read::null_sy_tree=synatax_tree_class::synatax_tree();

synatax_read::synatax_read()
{
  // this->ret_fun=ptr;
  // this->do_stack_fun=ptr1;
  // token_class::bnf_token *mdzz=new token_class::bnf_token(token_class::bnf_token::S);
  // debug;
  // mdzz->stat;
  // debug;
  // printf("lll,%ld\n",mdzz);
  // this->bnf_stack.push_back(token_class::bnf_token(token_class::bnf_token::S));
  // printf("lll,%ld\n",this->bnf_stack.size());
  // printf("lll,%ld\n",this->bnf_stack[0].stat);
  // debug;
  // // printf("lll,%ld\n",bnf_stack[-1]);
  // debug;
  // printf("lll,%d\n",token_class::bnf_token::S);
  // this->null_sy_tree.addr=0;
  
  
}

synatax_read::synatax_read(synatax_ptr_f *spf)
{
  spf->next_bnf_list=next_bnf_list;
  // spf->do_that();
  this->spf=spf;

  
}    

// synatax_read::
// std::vector<token_class::bnf_token> synatax_read::init_ret_fun(token_class::bnf_token bt,token_class::token tok)
// {
//   // std::vector<token_class::bnf_token> mdzz;
//   // static token_class::bnf_token T(token_class::bnf_token::T);
//   // static token_class::bnf_token T1(token_class::bnf_token::T1);
//   // static token_class::bnf_token T2(token_class::bnf_token::T2);
//   // static token_class::bnf_token E(token_class::bnf_token::E);
//   // static token_class::bnf_token E1(token_class::bnf_token::E1);
//   // static token_class::bnf_token E2(token_class::bnf_token::E2);
//   // static token_class::bnf_token S(token_class::bnf_token::S);
//   // static token_class::bnf_token F(token_class::bnf_token::F);
//   // static token_class::bnf_token OP(token_class::bnf_token::OP);
//   // static token_class::bnf_token Ter(token_class::bnf_token::Ter);
//   // static token_class::bnf_token Lkh(token_class::bnf_token::Lkh);
//   // static token_class::bnf_token Rkh(token_class::bnf_token::Rkh);
//   // static token_class::bnf_token ID(token_class::bnf_token::ID);
//   // // static std::vector<token_class::bnf_token> T1={T,E};
//   // // static bnf_token_1 TT(bnf_token_1::T);
//   // // static bnf_token_1 EE(bnf_token_1::E);
//   // // static std::map<bnf_token_1, bnf_token_1> mdzz111={{TT,EE}};
//   // static std::map<token_class::bnf_token,std::map<token_class::token::Stat,std::vector<token_class::bnf_token>>> synatax_bnf=
//   //   {{S,{{token_class::token::Inter_t,{E,Ter}},
//   // 	 {token_class::token::Lkh_t,{E,Ter}}}},
//   //    {E,{{token_class::token::Inter_t,{F,E2}},
//   // 	 {token_class::token::Lkh_t,{F,E2}}}},
//   //    {F,{{token_class::token::Inter_t,{ID}},
//   // 	 {token_class::token::Lkh_t,{Lkh,E,Rkh}}}}, //Ter E2 E2 ID
//   //    {E2,{{token_class::token::Ter_t,{Ter}},        //Ter E2 E2 Rkh E2 E2 
//   // 	  // {token_class::token::OR_t,{OP,E}},       Ter E2 Rkh E2 E2 
//   // 	  {token_class::token::OP_t,{OP,E}}}},
//   //    {ID,{{token_class::token::Inter_t,{Ter,ID}}}},
//   //    {Lkh,{{token_class::token::Lkh_t,{Ter,Lkh}}}},
//   //    {Rkh,{{token_class::token::Rkh_t,{Ter,Rkh}}}},
//   //    {OP,{//{token_class::token::AND_t,{Ter,OP}},
//   // 	  {token_class::token::OP_t,{Ter,OP}}}}};
//   // debug;

//   // return synatax_bnf[bt][tok.true_type];

  
// }  

// synatax_tree_class::synatax_tree synatax_read::init_do_stack_fun(std::vector<token_class::bnf_token> &bnf_stack,std::vector<token_class::token*> &tok_stack,std::vector<token_class::token*> &op_stack)
// {
// //   static int i=1;
// //   static token_class::bnf_token ID(token_class::bnf_token::ID);
// //   synatax_tree_class::synatax_tree ret_sy;

// //   bnf_stack.pop_back();
// //   ret_sy=null_sy_tree;
// //   // switch(bnf_stack[bnf_stack.size()-1].stat)
// //   // {
// //   // case token_class::bnf_token::ID:
// //   //   ret_sy.addr=i;
// //   //   ret_sy.car=tok_stack[tok_stack.size()-1];
// //   //   tok_stack.pop_back();
// //   //   tok_stack.push_back(token_class::token(i++));
// //   //   bnf_stack.pop_back();
// //   //   break;
      
// //   // }

// // here:  
// //   switch(bnf_stack[bnf_stack.size()-1].stat)
// //   {
// //   case token_class::bnf_token::ID:
// //     debug;
// //     if(!op_stack.empty()&&!(op_stack[op_stack.size()-1]->true_type-token_class::token::OP_t))
// //     {
// //       ret_sy.addr=i;
// //       ret_sy.car=op_stack[op_stack.size()-1];
// //       ret_sy.args={tok_stack[tok_stack.size()-1],tok_stack[tok_stack.size()-2]};
// //       op_stack.pop_back();
// //       tok_stack.pop_back();
// //       tok_stack.pop_back();
// //       tok_stack.push_back(new token_class::token(i++));

// //       break;
	
// //     }
// //     ret_sy.addr=i;
// //     ret_sy.car=tok_stack[tok_stack.size()-1];
// //     tok_stack.pop_back();
// //     tok_stack.push_back(new token_class::token(i++));
// //     debug;
// //     printf("%d %d\n",tok_stack[tok_stack.size()-1]->true_type,tok_stack[tok_stack.size()-1]->addr);
// //     break;
// //   case token_class::bnf_token::OP:
// //     debug;
// //     op_stack.push_back(tok_stack[tok_stack.size()-1]);
// //     tok_stack.pop_back();
// //     break;
// //   case token_class::bnf_token::Rkh:
// //     debug;
// //     op_stack.pop_back();
// //     tok_stack.pop_back();
// //     bnf_stack.pop_back();
// //     bnf_stack.push_back(ID);
// //     goto here;
// //     break;
// //   case token_class::bnf_token::Lkh:
// //     op_stack.push_back(tok_stack[tok_stack.size()-1]);
// //     tok_stack.pop_back();
// //     break;

// //   default:ret_sy=null_sy_tree;debug;//bnf_stack.pop_back();
    
// //   }
// //   bnf_stack.pop_back();

// //   debug;
// //   return ret_sy;
  
  
// }  


// token_class::token *synatax_read::test_fun()
// {
  // static int i;

  // token_class::token a0;a0.true_type=token_class::token::Ter_t;
  // token_class::token a1;a1.true_type=token_class::token::Inter_t;
  // token_class::token a2;a2.true_type=token_class::token::OP_t;
  // token_class::token a3;a3.true_type=token_class::token::Atom_t;
  // token_class::token a4;a4.true_type=token_class::token::OP_t;
  // token_class::token a5;a5.true_type=token_class::token::Lkh_t;
  // token_class::token a6;a6.true_type=token_class::token::Rkh_t;
  // token_class::token a7;a7.true_type=token_class::token::D_t;
  // token_class::token a8;a8.true_type=token_class::token::OP_t;
  // token_class::token a9;a9.true_type=token_class::token::OP_t;
  // token_class::token a10;a10.true_type=token_class::token::OP_t;

  // a2.pri=1;
  // a4.pri=2;
  // a8.pri=3;
  // a9.pri=4;
  // a10.pri=5;
  // // std::vector<token_class::token> test_t={a5,a1,a4,a5,a1,a10,a1,a6,a6,a2,a1,a4,a1,a0};//a9,a1,a8,a1,a4,a1,a2,a1,a0};
  // std::vector<token_class::token> test_t={a2,a5,a1,a7,a1,a6,a0};
  // //   {token_class::token::Atom,
  // //   token_class::token::Atom};

  // return &test_t[i++];
// }

std::vector<token_class::bnf_token> synatax_read::next_bnf_list(token_class::bnf_token bt,synatax_ptr_f *spf)
{
  std::vector<token_class::bnf_token> mdzz;
  std::vector<token_class::bnf_token> th_next;


  std::vector<token_class::bnf_token> bnf_stack;
  std::vector<token_class::token*> tok_stack;
  bnf_stack.push_back(bt);
  token_class::token *tok=spf->ret_next_token();
  tok_stack.push_back(tok);
  debug;
  printf("llll,%d\n",bnf_stack[bnf_stack.size()-1].stat);
  debug;
  for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
  debug;
  while(true)
  {  
    debug;
    printf("llllmdzz,%d\n",bnf_stack[bnf_stack.size()-1].stat);
    debug;
    th_next=spf->ret_fun(bnf_stack[bnf_stack.size()-1],tok);
    debug;
    // th_next=synatax_bnf[bnf_stack[bnf_stack.size()-1]][tok->true_type];
    // debug;
    // for(int i=th_next.size()-1;i>=0;i--) printf("ooo,%d\n",th_next[i].stat);
    // debug;
    // for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
    bnf_stack.pop_back();
    for(int i=th_next.size()-1;i>=0;i--) bnf_stack.push_back(th_next[i]);
    // debug;
    for(int i=bnf_stack.size()-1;i>=0;i--) printf("qqqq,%d\n",bnf_stack[i].stat);
    debug;
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

// std::vector<token_class::bnf_token> synatax_read::do_that(std::vector<token_class::bnf_token> bnf_st,std::vector<token_class::token*> op_st)
// {
  // token_class::bnf_token bt;
  // std::vector<token_class::bnf_token> ret;
  // static int i;

  // debug;
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  // ret=this->next_bnf_list(bnf_st[bnf_st.size()-1]);
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  // // debug;
  // bnf_st.pop_back();
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  // for(int i=0;i<ret.size();i++) bnf_st.push_back(ret[i]);
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  // // debug;
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  // //printf("iiiii,%d\n",ret[i].stat);
  // bt=bnf_st[bnf_st.size()-1];
  // bnf_st.pop_back();
  // // printf("%d\n",bt.stat);
  // for(int i=0;i<bnf_st.size();i++) printf("tttttt\t,%d\n",bnf_st[i].stat);
  // debug;
  // // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);

  // switch(bt.stat)
  // {
  // case token_class::bnf_token::ID:
  // debug;
  // if(!op_st.empty()) printf("%lld\n",op_st[0]->true_type);
  //   printf("push %d\n",++i);
  //   return do_that(bnf_st,op_st);

  // case token_class::bnf_token::OP:
  //   debug;
  //   // if(op_st.empty())
  //   // {
  //   //   for(int i=ret.size()-1;i>=0;i--) bnf_st.push_back(ret[i]);
  //   //   op_st.push_back(bt.is_ter);
  //   //   return do_that(bnf_st,op_st);
	
  //   // }

  //   while(!op_st.empty()&&op_st[op_st.size()-1]->pri<=bt.is_ter->pri)
  //   {
  //     printf("pop %d\n",i--);
  //     printf("pop %d\n",i--);
  //     printf("do %d\n",op_st[op_st.size()-1]->pri);
  //     printf("push %d\n",++i);
  //     op_st.pop_back();
      
  //   }
  //   // ret=do_that(bnf_st,op_st);

  //   // for(int i=0;i<ret.size();i++) bnf_st.push_back(ret[i]);
  //   op_st.push_back(bt.is_ter);
  //   printf("%d\n",bt.is_ter->true_type);
  //   // printf("%lld\n",op_st[0]);
  //   // printf("%lld\n",op_st[0]->true_type);
  //   debug;
  //   return do_that(bnf_st,op_st);

  // case token_class::bnf_token::Lkh:
  //   debug;
  //   for(int i=0;i<bnf_st.size();i++) printf("tttttt\t,%d\n",bnf_st[i].stat);
  //   ret=do_that(bnf_st);
  //   return do_that(ret,op_st);
    
  // case token_class::bnf_token::Rkh:
  //   debug;
  //   while(!op_st.empty())
  //   {
  //     printf("pop %d\n",i--);
  //     printf("pop %d\n",i--);
  //     debug;
  //     printf("do %lld\n",op_st[op_st.size()-1]->pri);
  //     printf("push %d\n",++i);
  //     debug;
  //     op_st.pop_back();
	
  //   }

  //   return bnf_st;
    
  // case token_class::bnf_token::Ter:
  //   debug;
  //   while(!op_st.empty())
  //   {
  //     printf("pop %d\n",i--);
  //     printf("pop %d\n",i--);
  //     debug;
  //     printf("do %lld\n",op_st[op_st.size()-1]->pri);
  //     printf("push %d\n",++i);
  //     debug;
  //     op_st.pop_back();
	
  //   }

  //   return {};

  // case token_class::bnf_token::D:
  //   return bnf_st;

      
  // }
  // debug;

  
// }
