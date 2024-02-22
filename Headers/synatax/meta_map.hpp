#ifndef __META_MAP_INCLUDE__
#define __META_MAP_INCLUDE__
#include "token.h"


namespace meta_map_mod
{
  struct null_tem{};
  
  template <typename T,typename T1>
  struct cons{T car;T cdr;};
  
  template <typename T>
  struct car{typename T::car _;};

  template <typename T>
  struct cdr{typename T::cdr _;};

  template <typename T,typename ...args>
  struct list:cons<T, list<args...>>{};

  template <typename T>
  struct list<T> : cons<T,null_tem>{};
  // template <template<typename N,typename N1> class Tok,token_class::token Tok1>
  // struct cons{cons<N,N1> car=Tok;token_class::token=Tok1;};

  // template <token_class::token Tok,template<typename N,typename N1> class Tok1>
  // struct cons{token_class::token car=Tok;cons<N, N1>=Tok1;};

  // template <template<typename N,typename N1> class cons>
  // cons =
  
};

#endif
