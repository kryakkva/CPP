
NAME			= diamondtrap
SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HEAD			= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
FL				= -Wshadow -Wall -Wextra -Werror -std=c++98

all:			$(NAME)

%.o: %.cpp $(HEAD)
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJS)
				$(CC) $(FL) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re