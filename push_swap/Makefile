CC = cc
NAME_B = checker
NAME_M = push_swap
CFLAGS = -Wextra -Wall -Werror
SUB_DIR = ./libft
SUB_LIB = ft
OBJ_DIR = obj/
SRC_DIR = src/
DEP_DIR = dep/

ifdef MAKE_BONUS
	SRCS_NAME = main_bonus operation_bonus stack_a utils
	NAME = $(NAME_B)
else
	SRCS_NAME = main operation stack_a utils pivot main_algorithm base_case hard_coding base_case_2
	NAME = $(NAME_M)
endif
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS_NAME)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS_NAME)))
DEPS = $(addprefix $(DEP_DIR), $(addsuffix .d, $(SRCS_NAME)))

all :
	@mkdir -p obj
	@$(MAKE) -sC $(SUB_DIR)
	@$(MAKE) $(NAME)

bonus :
	@make MAKE_BONUS=1 all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(SUB_DIR) -l$(SUB_LIB)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)
	@rm -rf $(DEPS)
	@$(MAKE) -C $(SUB_DIR) clean

fclean : clean
	rm -rf $(NAME_B)
	rm -rf $(NAME_M)
	@$(MAKE) -C $(SUB_DIR) fclean

re :
	@$(MAKE) -C $(SUB_DIR) re
	$(MAKE) fclean
	$(MAKE) all

FORCE :

-include $(DEPS)

.PHONY: all clean fclean re bonus