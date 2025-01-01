# --------------------------------------------
# Variables
# --------------------------------------------

NAME          = push_swap
NAME_BONUS    = checker_bonus
INCLUDE       = include
SRC_DIR       = src/
SRC_DIR_BONUS = src_bonus/
OBJ_DIR       = obj/
OBJ_DIR_BONUS = obj_bonus/
CC            = gcc
CFLAGS        = -Wall -Werror -Wextra -I$(INCLUDE)
RM            = rm -f
AR            = ar rcs

# --------------------------------------------
# Colors
# --------------------------------------------

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# --------------------------------------------
# Source and Object Files
# --------------------------------------------

SRC_FILES        = mini_libft push_swap special_cases \
				   sa_sb_ss_pa_pb ra_rb_rr rra_rrb_rrr \
				   turk_algo turk_algo_2 turk_algo_min_max turk_algo_final_rotation \
				   final_test
SRC_BONUS_FILES  = mini_libft_bonus checker_bonus execute_bonus \
                   sa_sb_ss_pa_pb_bonus ra_rb_rr_bonus rra_rrb_rrr_bonus \
				   gnl_bonus

SRC              = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRC_BONUS        = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_BONUS_FILES)))
OBJ              = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_BONUS        = $(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_BONUS_FILES)))

# --------------------------------------------
# Targets
# --------------------------------------------

# Default target
all: $(NAME)

# push_swap Compilation
$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

# push_swap Bonus Compilation
bonus: $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)push_swap bonus compiled!$(DEF_COLOR)"

# Object files compilation (Main)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Object files compilation (Bonus)
$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)Compiling Bonus: $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------
# Clean and Remove Object Files
# --------------------------------------------

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

# Full clean (objects and executables)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(CYAN)push_swap executables cleaned!$(DEF_COLOR)"

# Rebuild everything
re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

wasm: 
	docker run --rm -v $(shell pwd):/src emscripten/emsdk emcc $(SRC) -o $(NAME).wasm

# --------------------------------------------
# Norminette Check
# --------------------------------------------

# Norminette code style check
norm:
	@norminette $(SRC) $(SRC_BONUS) $(INCLUDE) | grep -v Norme -B1 || true

# --------------------------------------------
# Phony Targets
# --------------------------------------------

.PHONY: all clean fclean re norm bonus clean_bonus fclean_bonus

