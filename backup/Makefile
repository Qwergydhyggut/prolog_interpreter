gcc=x86_64-pc-linux-gnu-g++
link=

a=$^ $c-o $@
b=$< $c-o $@ 

mb=prolog
jg=a
cs=cs
test-command=test.pr

lo=yuan.o
zj=zj

yc=yuan.cpp lexer_main.cpp
yh=lexer.h
#yrc=
#yo=

ljc=Sources Sources/lexer
ljh=Headers
#ljr=Resources
#ljo=Others

GPATH=$(ljc):$(ljr)
VPATH=$(ljo)
vpath %.cpp $(ljc)
vpath %.o $(ljc)
vpath %.h $(ljh)
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
$(jg):c=$(link)
$(mb):c=$(link)
$(lo):c=
$(zj).i:c=-I$(ljh) 

all:$(jg)
	$(del)

$(jg):$(lo)
	$(gcc) $a

$(lo):$(zj).s
	$(gcc) -c $a

$(zj).s:$(zj).i
	$(gcc) -S $a

$(zj).i:$(yc) $(yh)
	$(gcc) -E $b

$(cs):$(mb)
	del $(jg)
	$(del)


$(mb):$(lo)
	$(gcc) $a

.PHONY:all

define del
rm *.i
rm *.s
./$< $(test-command)
endef
