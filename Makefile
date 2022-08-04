##############################colors####################################################################
RED   := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE  := \033[0;34m
YELLOW := \033[0;33m
########################################################################################################

####
###########################TODO: create objects Directorie######################
####
######################################Directories#######################################################

draw = draw
HEADER_DIR = hedears
LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
PARSING_DIR = $(SRC_DIR)/parsing

SRC = 	$(SRC_DIR)/ft_shell.c $(SRC_DIR)/creat_lst.c $(SRC_DIR)/tokenizer.c $(SRC_DIR)/parser.c $(SRC_DIR)/lexer.c
main = 	$(SRC_DIR)/main.c
OBJ	= 	$(SRC:.c=.o)
CC = 	gcc
 GCCFLAGS = -Wall -Wextra -Werror \
         	-I $(shell brew --prefix readline)/include \
     		-L $(shell brew --prefix readline)/lib -lreadline \
        	-L $(shell brew --prefix readline)/lib -lhistory -g

###################################This flag includes readline && history library##########################

GCCFLAG = -Wall -Wextra -Werror \
        	-I $(shell brew --prefix readline)/include

HEADER   = $(HEADER_DIR)/minishell.h
NAME     = Minishell
RECOMPILING = echo "     $(YELLOW)Recompiling..........$(YELLOW)"

###################################TARGETS##############################################################

all : $(NAME)
	@echo""
	@echo " $(YELLOW)Welcome to$(YELLOW) "
	@echo "$(RED)"
	@cat $(draw)/minishell-art.ans
	@echo""
	@echo "                				$(YELLOW)By zrabhi && iayni $(YELLOW)                        "

$(NAME) : $(OBJ) $(main) $(HEADER) $(LIBFT)
	@echo "\n"
	@echo " $(YELLOW)Source files are compiled!\n$(YELLOW)"
	@echo  "Building $(NAME) for" "Mandatory" "..."
	@$(CC) $(GCCFLAGS) $(main) $(LIBFT) $(OBJ) -o $(NAME)
	@echo""
	@sleep 0.2
	@sleep 0.2
	@echo ""
	@echo  "$(NAME) is created!\n"

################# wild card used in this make file , im gonna change it later#########################################

$(LIBFT) : $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@$(MAKE) -C $(LIBFT_DIR)

######################################################################################################################

%.o: %.c	
	@echo "$(YELLOW)Compiling    $(GREEN)$(shell basename $<)$(GREEN)"
	@sleep 0.2
	@$(CC) $(GCCFLAG) -c $< -o $@   

#####################################################REMOVING ABJECTS FILE####################################

clean :
	@echo "$(YELLOW)Removing Objects file ....    $(GREEN)$(shell basename $(OBJ))$(GREEN)"
	@rm -rf $(OBJ)
	@echo "     $(YELLOW)Successfully Removed$(YELLOW)"

##############################REMOVING OBJECTS FILE AND EXE###################################################

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	@echo "$(YELLOW)Removing Minishell ....    $(GREEN)$(shell basename $(NAME))$(GREEN)"
	@rm -rf $(NAME)
	@echo "     $(YELLOW)Successfully Removed$(YELLOW)"

#################################################RECOMPILING####################################################

re: fclean all
	@echo "     $(YELLOW)Recompiling..........$(YELLOW)"
