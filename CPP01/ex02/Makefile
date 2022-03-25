
NAME			= main
SRCS			= main.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
RM				= rm -f
FL				= -Wall -Wextra -Werror -std=c++98
# FL				=  -std=c++98


all:			$(NAME)

%.o: %.cpp
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJS) 
				$(CC) $(FL) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re