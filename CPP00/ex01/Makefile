
NAME			= PhoneBook
SRCS			= main.cpp PhoneBook.cpp Contact.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
FL				= -Wall -Wextra -Werror -std=c++98


all:			$(NAME)

%.o: %.cpp PhoneBook.hpp
	$(CC) $(FL) -c -o $@ $< 

$(NAME):		$(OBJS) 
				$(CC) $(FL) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re