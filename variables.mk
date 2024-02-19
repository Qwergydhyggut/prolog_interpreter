gcc=x86_64-pc-linux-gnu-g++
link=

a=$^ $c-o $@
b=$< $c-o $@

mb=prolog
jg=a
test=test
cs=cs
test-command=test.pr

lo=yuan.o
zj=zj

ycmode_lexer=lexer_main.cpp token_num.cpp
yc=yuan.cpp $(ycmode_lexer)
yh=lexer.h token.h debug.h lexer/token_num.h
#yrc=
#yo=

ljc=Sources Sources/lexer
ljh=Headers
#ljr=Resources
#ljo=Others

SRCS:=$(yc)
GPATH=$(ljc):$(ljr)
VPATH=$(ljo)
vpath %.cpp $(ljc)
vpath %.o $(ljc)
vpath %.h $(ljh)
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
$(jg):c=$(link)
$(mb):c=$(link)
# $(lo):c=
# $(zj).i:c=-I$(ljh) 
%.i:c=-I$(ljh) 


.SUFFIXES:
.PHONY:all $(test) test_all

define del
rm -f *.i
rm -f *.s
./$< $(test-command)
endef

define delfirst
        $(wordlist 2,$(words $1),$1)
endef
