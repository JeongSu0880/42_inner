CC = cc
NAME_C = client
NAME_S = server
CFLAGS = -Wextra -Wall -Werror
SUB_DIR = ./ft_printf
SUB_LIB = ftprintf
CLIENT_OBJ_DIR = obj_client/
SERVER_OBJ_DIR = obj_server/
CLIENT_SRC_DIR = src_client/
SERVER_SRC_DIR = src_server/
DEP_DIR = dep/

ifdef MAKE_BONUS
	SRCS_NAME_C = client_main_bonus mini_atoi utils_c
	SRCS_NAME_S = server_main_bonus utils_s
else
	SRCS_NAME_C = client_main mini_atoi utils_c
	SRCS_NAME_S = server_main utils_s
endif

SRCS_C = $(addprefix $(CLIENT_SRC_DIR), $(addsuffix .c, $(SRCS_NAME_C)))
OBJS_C = $(addprefix $(CLIENT_OBJ_DIR), $(addsuffix .o, $(SRCS_NAME_C)))
DEPS_C = $(addprefix $(DEP_DIR), $(addsuffix .d, $(SRCS_NAME_C)))

SRCS_S = $(addprefix $(SERVER_SRC_DIR), $(addsuffix .c, $(SRCS_NAME_S)))
OBJS_S = $(addprefix $(SERVER_OBJ_DIR), $(addsuffix .o, $(SRCS_NAME_S)))
DEPS_S = $(addprefix $(DEP_DIR), $(addsuffix .d, $(SRCS_NAME_S)))

all :
	@mkdir -p obj_client
	@mkdir -p obj_server
	@$(MAKE) -sC $(SUB_DIR)
	@$(MAKE) $(NAME_C)
	@$(MAKE) $(NAME_S)

bonus :
	@make MAKE_BONUS=1 all

$(NAME_C) : $(OBJS_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) -L$(SUB_DIR) -l$(SUB_LIB)

$(NAME_S) : $(OBJS_S)
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S) -L$(SUB_DIR) -l$(SUB_LIB)

$(CLIENT_OBJ_DIR)%.o : $(CLIENT_SRC_DIR)%.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(SERVER_OBJ_DIR)%.o : $(SERVER_SRC_DIR)%.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean :
	rm -rf $(CLIENT_OBJ_DIR)
	rm -rf $(SERVER_OBJ_DIR)
	@rm -rf $(DEPS)
	@$(MAKE) -C $(SUB_DIR) clean

fclean : clean
	rm -rf $(NAME_C)
	rm -rf $(NAME_S)
	@$(MAKE) -C $(SUB_DIR) fclean

re :
	@$(MAKE) -C $(SUB_DIR) re
	$(MAKE) fclean
	$(MAKE) all

FORCE :

-include $(DEPS)

.PHONY: all clean fclean re bonus