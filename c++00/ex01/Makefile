NAME			=	megaphone

CXX				=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
# CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC_DIR			=	./src
OBJ_DIR			=	./obj
INCLUDE			=	-Iinclude

# find . -type f -name "*.cpp" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/' | pbcopy
SRCS			=	./contact.cpp \
					./phoneBook.cpp \
					./main.cpp \

OBJS			=	${addprefix ${OBJ_DIR}/, ${SRCS:.cpp=.o}}
DEPS			=	${OBJS:.o=.d}
RM				=	rm -rf
MKDIR			=	mkdir -p
FORMAT			=	clang-format

.DEFAULT_GOAL = all
all		:	${NAME}

${NAME}:	${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

${OBJ_DIR}/%.o : %.cpp
	${MKDIR} $(@D)
	${CXX} ${CXXFLAGS} ${INCLUDE} -MMD -MP -o $@ -c $<

clean	:
	${RM} ${OBJ_DIR}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

format	:
	${FORMAT} -i ${SRCS}

-include ${DEPS}

.PHONY: all clean fclean re format
