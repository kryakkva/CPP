
NAME			= Bureaucrat
SRCS			= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEAD			= Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
OBJS_D			= objs/
OBJS			= $(SRCS:.cpp=.o)
OBJ_D			= $(addprefix $(OBJS_D), $(OBJS))


CC				= c++
RM				= rm -rf
FL				= -Wshadow -Wall -Wextra -Werror -std=c++98

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