
NAME			= Polymorphism
SRCS			= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
HEAD			= Animal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJS_D			= objs/
OBJS			= $(SRCS:.cpp=.o)
OBJ_D			= $(addprefix $(OBJS_D), $(OBJS))


CC				= c++
RM				= rm -rf
# FL				= -Wshadow -Wall -Wextra -Werror -std=c++98
FL				= -Wall -Wextra -Werror -std=c++98

all:			$(OBJS_D) $(NAME)

$(OBJS_D): 
	mkdir -p $(OBJS_D)

$(OBJS_D)%.o: %.cpp $(HEAD)
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJ_D)
				$(CC) $(FL) -o $(NAME) $(OBJ_D)

clean:
				$(RM) $(OBJ_D) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re