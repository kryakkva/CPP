
NAME			= karen
SRCS			= main.cpp Karen.cpp
HEAD			= Karen.hpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
FL				= -Wall -Wextra -Werror -std=c++98
# FL				= -std=c++98

all:			$(NAME)

%.o: %.cpp
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJS) $(HEAD)
				$(CC) $(FL) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re