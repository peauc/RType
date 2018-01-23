BERZERKER       =       lberzerker.so
MOJOJO		=	lmojojo.so

CXX             =       g++

SRCS_BERZERKER  =       Berzerker.cpp			\
			EnemyMoveComponent.cpp		\
			EnemyAIComponent.cpp		\
			EnemyGraphicsComponent.cpp	\
			EnemyPhysicsComponent.cpp	\

SRCS_MOJOJO	=	Mojojo.cpp			\
			MojojoMove.cpp			\
			MojojoAI.cpp			\
			MojojoGraphics.cpp		\
			MojojoPhysics.cpp		\

FILES_BERZERKER =       $(addprefix ./src/, $(SRCS_BERZERKER))
FILES_MOJOJO 	=       $(addprefix ./src/, $(SRCS_MOJOJO))

INCLUDES        =       -I ./inc				\
			-I ../server/inc			\
			-I ../server/inc/Common			\
			-I ../server/inc/Components		\
			-I ../server/inc/Engine			\
			-I ../server/inc/Engine/Commands	\
			-I ../server/inc/Components/Abstracts	\
			-I ../server/inc/Factories		\
			-I ../common/inc			\
			-I ../common/JsonLoader/includes	\
			-I ../common/RessourcesLoader/inc	\
			-I ../server/inc/MapLoader		\

CPPFLAGS        =       -std=c++14 -fPIC ${INCLUDES}

LDFLAGS         =       -shared

OBJS_BERZERKER  =       $(FILES_BERZERKER:.cpp=.o)
OBJS_MOJOJO	=       $(FILES_MOJOJO:.cpp=.o)

all:                    $(BERZERKER) $(MOJOJO)

$(BERZERKER):           $(OBJS_BERZERKER)
			$(CXX) $(OBJS_BERZERKER) -o $(BERZERKER) $(LDFLAGS)
			cp ${BERZERKER} ../DLEnemies

$(MOJOJO):      	$(OBJS_MOJOJO)
			$(CXX) $(OBJS_MOJOJO) -o $(MOJOJO) $(LDFLAGS)
			cp ${MOJOJO} ../DLEnemies

clean:
			rm -f $(OBJS_BERZERKER)
			rm -f $(OBJS_MOJOJO)

fclean:                 clean
			rm -f $(BERZERKER)
			rm -f $(MOJOJO)
			rm -f ../DLEnemies/${BERZERKER}
			rm -f ../DLEnemies/${MOJOJO}

re:                     fclean all

.PHONY:                 all fclean re
