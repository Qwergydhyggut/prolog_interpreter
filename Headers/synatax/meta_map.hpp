#ifndef __META_MAP_INCLUDE__
#define __META_MAP_INCLUDE__
#include "token.h"
#define ST token_class::token::Stat
#define SS token_class::token
#define D() ,


namespace meta_map_mod
{
  // struct _stat_struct{static ST _;};
  
  template <ST N>
  struct stat_struct//:_stat_struct
  {
    constexpr static ST _=N;
  };

#define if_st_eq(T,T1) _if_st_eq<T,T1>::_
  template <typename T,typename T1>
  struct _if_st_eq{constexpr static bool _=false;};

  template <typename T>
  struct _if_st_eq<T, T>{constexpr static bool _=true;};
  
  struct null_tem{};
  
  template <typename T,typename T1>
  struct cons{T car_;T cdr_;};
  
  // template <typename T>
  // struct cons<stat_struct<token_class::token N>,T>{ST car;T cdr;};
  
#define car(T) typename Car_tem<T>::_
#define cdr(T) typename Cdr_tem<T>::_
  template <typename T>
  struct Car_tem{typename T::car_ _;};

  template <typename T>
  struct Cdr_tem{typename T::cdr_ _;};

  template <typename T,typename ...args>
  struct list:cons<T, list<args...>>{};

  template <typename T>
  struct list<T> : cons<T,null_tem>{};

  template <typename T>
  struct apply_T
  {
    template <template <T> class F,T N,T ...N1>
    struct apply:cons<F<N>, apply<F,N1...>>{};

    template <template <T> class F,T N>
    struct apply<F,N>:F<N>{};
  };
  
  template <ST N,ST N1,ST ...args>
  struct dnf_item:cons<stat_struct<N>,apply_T<ST>::apply<stat_struct, N1, args...>>{};

#define if_m(T,T1,T2) typename _if_m<T,T1,T2>::_
  template <bool T,typename T1,typename T2>
  struct _if_m;

  template <typename T1,typename T2>
  struct _if_m<true,T1,T2>{T1 _;};

  template <typename T1,typename T2>
  struct _if_m<false, T1, T2>{T2 _;};

#define if_or(T,T1) _if_or<T,T1>::_
  template <bool,bool>
  struct _if_or{constexpr static bool _=false;};

  template <bool N>
  struct _if_or<true, N>{constexpr static bool _=true;};

  template <bool N>
  struct _if_or<N,true>{constexpr static bool _=true;};

#define if_and(T,T1) _if_and<T,T1>::_
  template <bool,bool>
  struct _if_and{constexpr static bool _=true;};

  template <bool N>
  struct _if_and<false, N>{constexpr static bool _=false;};

  template <bool N>
  struct _if_and<N,false>{constexpr static bool _=false;};
  
#define select_dnf_item(F,T) typename _select_dnf_item<F,T>::_
  template <typename T,typename T1>
  struct _select_dnf_item
  {
    if_m(if_st_eq(null_tem, T1),null_tem,if_m(if_st_eq(car(car(T)),T1),car(cdr(T)),select_dnf_item(T, T1))) _;
  };

#define apply_L(F,T1) typename _apply_L<F,T1>::_
  template <template <typename> class F,typename T1>
  struct _apply_L
  {
    if_m(if_st_eq(T1, null_tem), null_tem, cons<typename F<T1>::_ D() apply_L(F,cdr(T1))>) _;
  };

#define del_apply_L(F,T) typename _del_apply_L<F,T>::_
  template <template <typename> class F,typename T>
  struct _del_apply_L
  {
    if_m(if_st_eq(T, null_tem),null_tem,if_m(F<car(T)>::_, cons<car(T) D() del_apply_L(F, cdr(T))>, del_apply_L(F,cdr(T)))) _;
  };

#define if_apply_L(F,T) typename _if_apply_L<F,T>::_
  template <template <typename,typename> class F,typename T>
  struct _if_apply_L
  {
    if_m(if_st_eq(T, null_tem), null_tem, typename F<car(T) D() if_apply_L(F,cdr(T))>::_) _;
  };

  struct tr_or
  {
    constexpr static bool _=true;
  };
  
  struct fa_or
  {
    constexpr static bool _=false;
  };
  
#define if_in_L(N,S) _if_in_L<N,S>::_::_
  template <typename N,typename S>
  struct _if_in_L
  {
    template<typename T,typename T1>
    struct _if_is
    {
      struct _if_eq_b{constexpr static bool _=_if_m<if_st_eq(N,T),tr_or,fa_or>::_;};
      struct _{constexpr static bool __=_if_m<if_st_eq(T1,null_tem),_if_eq_b,if_m(T1::_,tr_or,_if_eq_b)>::_;};
    };
    if_apply_L(_if_is, S) _;
  };
  
#define dns_apply_T(F,T,N) typename _dns_apply_T<F,T,N,null_tem>::_
  template <template <typename,typename> class F,typename T,typename N,typename S>
  struct _dns_apply_T
  {
    // if_m(if_in_L(N, S),null_tem,apply_L(,select_dnf_item(T, N))) _;
  };
  
  
  struct meta_map_out:list<null_tem,null_tem,null_tem,cons<token_class::token,stat_struct<token_class::token::Atom_t>>>{};

  // template <template<typename N,typename N1> class Tok,token_class::token Tok1>
  // struct cons{cons<N,N1> car=Tok;token_class::token=Tok1;};

  // template <token_class::token Tok,template<typename N,typename N1> class Tok1>
  // struct cons{token_class::token car=Tok;cons<N, N1>=Tok1;};

  // template <template<typename N,typename N1> class cons>
  // cons =

}; // namespace meta_map_mod
  
#undef ST
#endif
