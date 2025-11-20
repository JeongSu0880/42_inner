CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = ex02
SRCS = Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp
OBJS = $(SRCS:%cpp=%o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(SRCS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	rm -rf $(OBJS)
	find . -type f -name "*_shrubbery" -exec rm -f {} \;

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all