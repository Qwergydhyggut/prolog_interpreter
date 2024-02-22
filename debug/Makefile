include ../variables.mk

test_link=$(link) -lgtest 


test_jg=test_$(jg)

test_yc=$(call delfirst,$(yc)) test_main.cpp #lexer_test.hpp synatax_test.hpp
test_yh=$(yh) lexer_test.hpp synatax_test.hpp
#yrc=
#yo=

test_ljc=$(addprefix ../,$(call delfirst,$(ljc))) lexer synatax
test_ljh=$(addprefix ../,$(ljh)) lexer synatax
#ljr=Resources
#ljo=Others

SRCS=$(test_yc)
GPATH=$(test_ljc):$(ljr)
#VPATH=$(ljo)
vpath %.hpp $(test_ljh)
vpath %.cpp $(test_ljc)
vpath %.o $(test_ljc) #../Sources/lexer
vpath %.h $(test_ljh)
#vpath %.o ../Sources/lexer
#vpath %.rc $(ljr)
#vpath %.res $(ljr)
$(test_jg):c=$(test_link)
#$(mb):c=$(link)
# $(lo):c=
# $(zj).i:c=-I$(ljh) 
%.i:c=$(addprefix -I,$(test_ljh)) 

test_all:$(test_jg)
	$(del)

$(test_jg):$(SRCS:.cpp=.o)
	$(gcc) $a

%.o:%.s
	$(gcc) -c $a

%.s:%.i
	$(gcc) -S $a

%.i:%.cpp $(test_yh)
	$(gcc) -E $b
