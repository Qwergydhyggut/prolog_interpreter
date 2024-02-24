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

TEST(synatax, default_syna)
{
  synatax_mod::synatax_read test;
  token_class::token a1;a1.true_type=token_class::token::Inter_t;
  token_class::token a2;a2.true_type=token_class::token::OP_t;
  token_class::token a3;a3.true_type=token_class::token::Inter_t;
  token_class::token a4;a4.true_type=token_class::token::Lkh_t;
  token_class::token a5;a5.true_type=token_class::token::Rkh_t;

  synatax_tree_class::synatax_tree res;
  // res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
  // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
  // res=test(a3);printf("addr %d,car %d,args %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type,res.args[1]->addr);
  // res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
  res=test(a4);printf("addr %d,car %d\n",res.addr,res.car->true_type);
  res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
  res=test(a5);printf("addr %d,car %d\n",res.addr,res.car->true_type);

  
}

// TEST(synatax,do_ptr)
// {
//   synatax_mod::synatax_read test(synatax_ptr_class::ret_ptr,synatax_ptr_class::do_stack_ptr);
//   token_class::token a1;a1.true_type=token_class::token::Inter_t;
//   token_class::token a2;a2.true_type=token_class::token::OP_t;
//   token_class::token a3;a3.true_type=token_class::token::Inter_t;

//   synatax_tree_class::synatax_tree res=test(a1);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a3);printf("addr %d,car %d,args %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type,res.args[1]->addr);
//   res=test(a2);printf("addr %d,car %d\n",res.addr,res.car->true_type);
//   res=test(a3);printf("addr %d,car %d,args %d %d %d\n",res.addr,res.car->true_type,res.args[0]->true_type,res.args[1]->true_type,res.args[1]->addr);

  
// }
