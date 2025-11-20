# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 19:55:16 by jungslee          #+#    #+#              #
#    Updated: 2024/09/28 23:43:32 by jungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Werror -Wall -Wextra
NAME = phonebook
SRCS = Contact.cpp \
		PhoneBook.cpp \
		Main.cpp
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