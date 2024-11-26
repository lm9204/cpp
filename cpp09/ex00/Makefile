CC = c++
FLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -std=c++98
SRCS = 	main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = btc

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

-include $(SRCS:.cpp=.d)

.PHONY: all clean re fclean