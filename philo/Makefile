CC = cc
NAME = philo
# CFLAGS = -Wextra -Wall -Werror
SRC_DIR = srcs/
OBJ_DIR = objs/
DEP_DIR = dep/

SRCS_NAME = main argument_check_and_init error

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS_NAME)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS_NAME)))
DEPS = $(addprefix $(DEP_DIR), $(addsuffix .d, $(SRCS_NAME)))

all :
	@mkdir -p objs
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)
	@rm -rf $(DEPS)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

FORCE :

-include $(DEPS)

.PHONY: all clean fclean re