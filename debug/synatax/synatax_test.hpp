#include <cstdio>
#include <gtest/gtest.h>
#include "synatax.h"
#include "debug.h"
#include <map>
#include <utility>
#include <vector>
#include "token.h"
#include "synatax/meta_map.hpp"
#include "synatax/synatax_ptr.h"


// bool operator<(const token_class::token tok,const token_class::token tok1)
// {
//   return tok.token_exp<tok1.token_exp;
  
  
// }

// struct sbmap
// {
//   int zzz;
// }    ;

// bool operator<(const sbmap sb,const sbmap sb1)
// {return true;}
TEST(meta, cons)
{
  // meta_map_mod::cons<token_class::token, token_class::token> test;
  // token_class::token lll;
  // meta_map_mod::cons<token_class::token,meta_map_mod::stat_struct<token_class::token::Atom_t>> test;
  meta_map_mod::meta_map_out test;
  // meta_map_mod::testmdzz<token_class::token>::cons<token_class::token,token_class::token>;
  
  
}
  
TEST(synatax, test)
{
  // test_syna();
  synatax_mod::synatax_read test;
  // token_class::token t1,t2;
  // t1.str="lll";
  // t2.str="zzz";
  // std::vector<token_class::token> mdzz{t1,t2};
  // t1<t2;
  // std::map<token_class::token,int> qtm;
  // qtm[t1]=0;
  // std::map<sbmap, int> mdzzmap;
  // sbmap youbing;
  // mdzzmap[youbing]=0;
  // synatax_mod::synatax_read::synatax_dnf[t1]=mdzz;
  // std::map<int,int> kkk;
  // kkk[0]=1;
  // kkk[1]=2;
  debug;
  
}

TEST(synatax, vec)
{
  std::vector<int> test;

  printf("%ld\n",test.size());
  test.push_back(1);
  printf("%ld\n",test.size());
  test.pop_back();
  printf("%ld\n",test.size());

  
}

// TEST(synatax, default_syna)
// {
//   synatax_mod::synatax_read test;
//   token_class::token a1;a1.true_type=token_class::token::Inter_t;
//   token_class::token a2;a2.true_type=token_class::token::OP_t;
//   token_class::token a3;a3.true_type=token_class::token::Inter_t;
//   token_class::token a4;a4.true_type=token_class::token::Lkh_t;
//   token_class::token a5;a5.true_type=token_class::token::Rkh_t;

//   synatax_tree_class::synatax_tree res;
//   // res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   // res=test(a3);printf("addr %d,car %d,args %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type,res.args[1]->addr);
//   // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a4);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a5);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a3);printf("addr %d,car %d,args %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type,res.args[1]->addr);
//   // res=test(a5);printf("addr %d,car %d,args %d %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[0]->addr,res.args[1]->true_type,res.args[1]->addr);

  
// }

// TEST(synatax,do_ptr)
// {
//   synatax_mod::synatax_read test(synatax_ptr_class::ret_ptr,synatax_ptr_class::do_stack_ptr);
//   token_class::token a0;a0.true_type=token_class::token::Ter_t;
//   token_class::token a1;a1.true_type=token_class::token::Atom_t;
//   token_class::token a2;a2.true_type=token_class::token::OP_t;
//   token_class::token a3;a3.true_type=token_class::token::Atom_t;
//   token_class::token a4;a4.true_type=token_class::token::OP_t;

//   a2.pri=3;
//   a4.pri=2;
//   synatax_tree_class::synatax_tree res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a2);printf("zzzzzzzzzzz,addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a3);printf("zzzzzzzzzzz,addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a4);printf("zzzzzzzzzzz,addr %d,car %d\n",res.addr,res.car->true_type);
//   // res=test(a3);printf("addr %d,car %d,args %d %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[0]->addr,res.args[1]->true_type,res.args[1]->addr);
//   res=test(a3);printf("zzzzzzzzzzz,addr %d,car %d\n",res.addr,res.car->true_type);
//   // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a0);printf("addr %d,car %d,args %d %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[0]->addr,res.args[1]->true_type,res.args[1]->addr);
//   // res=test(a0);printf("addr %d,car %d,args %d %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[0]->addr,res.args[1]->true_type,res.args[1]->addr);
//   // res=test(a0);printf("addr %d,car %d,args %d %d \n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type);
//   res=test(a0);printf("zzzzzzzzzzz,addr %d,car %d,args %d %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[0]->addr,res.args[1]->true_type,res.args[1]->addr);

  
// }

// TEST(synatax, do_ptr_fun)
// {
//   synatax_mod::synatax_read test(synatax_ptr_class::ret_ptr,synatax_ptr_class::do_stack_ptr);
  
//   token_class::token a0;a0.true_type=token_class::token::Ter_t;
//   token_class::token a1;a1.true_type=token_class::token::Atom_t;
//   token_class::token a2;a2.true_type=token_class::token::OP_t;
//   token_class::token a3;a3.true_type=token_class::token::Atom_t;
//   token_class::token a4;a4.true_type=token_class::token::OP_t;
//   token_class::token a5;a5.true_type=token_class::token::Lkh_t;
//   token_class::token a6;a6.true_type=token_class::token::Rkh_t;
//   token_class::token a7;a7.true_type=token_class::token::D_t;

//   a2.pri=3;
//   a4.pri=2;

//   synatax_tree_class::synatax_tree res[20];

//   // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   // res=test(a5);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res[0]=test(a1);printf("addr %d,car %d\n",res[0].addr,res[0].car->true_type);
//   res[1]=test(a2);printf("addr %d,car %d\n",res[1].addr,res[1].car->true_type);
//   res[2]=test(a1);printf("addr %d,car %d\n",res[2].addr,res[2].car->true_type);
//   res[3]=test(a2);printf("addr %d,car %d\n",res[3].addr,res[3].car->true_type);
//   res[4]=test(a5);printf("addr %d,car %d\n",res[4].addr,res[4].car->true_type);
//   res[5]=test(a1);printf("addr %d,car %d\n",res[5].addr,res[5].car->true_type);
//   res[6]=test(a2);printf("addr %d,car %d\n",res[6].addr,res[6].car->true_type);
//   res[7]=test(a1);printf("addr %d,car %d\n",res[7].addr,res[7].car->true_type);
//   res[8]=test(a2);printf("addr %d,car %d\n",res[8].addr,res[8].car->true_type);
//   res[9]=test(a3);printf("addr %d,car %d\n",res[9].addr,res[9].car->true_type);
//   res[10]=test(a6);printf("addr %d,car %d\n",res[10].addr,res[10].car->true_type);
//   res[11]=test(a0);printf("addr %d,car %d\n",res[11].addr,res[11].car->true_type);

//   debug;
//   printf("addr %d,car %d\n",res[0].addr,res[0].car->true_type);
//   printf("addr %d,car %d\n",res[1].addr,res[1].car->true_type);
//   printf("addr %d,car %d\n",res[2].addr,res[2].car->true_type);
//   printf("addr %d,car %d\n",res[3].addr,res[3].car->true_type);
//   printf("addr %d,car %d\n",res[4].addr,res[4].car->true_type);
//   printf("addr %d,car %d\n",res[5].addr,res[5].car->true_type);
//   printf("addr %d,car %d\n",res[6].addr,res[6].car->true_type);
//   printf("addr %d,car %d\n",res[7].addr,res[7].car->true_type);
//   printf("addr %d,car %d\n",res[8].addr,res[8].car->true_type);
//   printf("addr %d,car %d\n",res[9].addr,res[9].car->true_type);
//   printf("addr %d,car %d\n",res[10].addr,res[10].car->true_type);
//   printf("addr %d,car %d\n",res[11].addr,res[11].car->true_type);
  
  
// }

TEST(synatax, new_test)
{
  synatax_mod::synatax_read test;

  std::vector<token_class::bnf_token> res;
  // res=test();for(int i=0;i<res.size();i++) printf("%d\t",res[i].stat);std::cout<<std::endl;

  // test.do_that1();
  test.do_that();
  
  
}

TEST(synatax, sqldo)
{
  debug;

  
}
