CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98
NAME = ex03
SRCS = Weapon.cpp \
		HumanB.cpp \
		HumanA.cpp \
		main.cpp
OBJS = $(SRCS:%cpp=%o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(SRCS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all