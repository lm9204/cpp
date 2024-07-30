CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -MP -Wshadow -g3 -std=c++98
SRCS = 	Animal.cpp	\
		Dog.cpp		\
		Cat.cpp		\
		Brain.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex01

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	rm -rf $(SRCS:.cpp=.d)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean