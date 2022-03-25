
NAME			= Zombie
SRCS			= main.cpp zombieHorde.cpp Zombie.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
FL				= -Wall -Wextra -Werror -std=c++98


all:			$(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJS) 
				$(CC) $(FL) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re