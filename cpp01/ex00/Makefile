CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -std=c++98
SRCS = 	Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = zombie

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	rm -rf $(SRCS:.cpp=.d)
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean