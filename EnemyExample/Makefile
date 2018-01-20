NAME            =       lberzerker.so

CXX             =       g++

SRCS            =       Berzerker.cpp

FILES           =       $(addprefix ./src/, $(SRCS))

INCLUDES        =       -I ./inc			\
			-I ../server/inc		\
			-I ../server/inc/Common		\
			-I ../server/inc/Components	\
			-I ../server/inc/Engine		\

CPPFLAGS        =       -std=c++14 -fPIC ${INCLUDES}

LDFLAGS         =       -shared

OBJS            =       $(FILES:.cpp=.o)

$(NAME):                $(OBJS)
			$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)
			cp ${NAME} ../DLEnemies

all:                    $(NAME)

clean:
			rm -f $(OBJS)

fclean:                 clean
			rm -f $(NAME)

re:                     fclean all

.PHONY:                 all fclean re
