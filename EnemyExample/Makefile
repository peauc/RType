NAME            =       lberzerker.so

CXX             =       g++

SRCS            =       Berzerker.cpp			\
			EnemyMoveComponent.cpp		\
			EnemyAIComponent.cpp		\
			EnemyGraphicsComponent.cpp	\
			EnemyPhysicsComponent.cpp	\

FILES           =       $(addprefix ./src/, $(SRCS))

INCLUDES        =       -I ./inc			\
			-I ../server/inc		\
			-I ../server/inc/Common		\
			-I ../server/inc/Components	\
			-I ../server/inc/Engine		\
			-I ../common/inc		\


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
			rm -f ../DLEnemies/${NAME}

re:                     fclean all

.PHONY:                 all fclean re
