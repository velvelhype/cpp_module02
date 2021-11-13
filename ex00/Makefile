# === a.out ===

NAME			=	a.out
CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic
# INCLUDE			=	-I includes


# --- MAIN ---
MAIN_DIR		=	.
MAIN_FILE		=	$(addprefix $(MAIN_DIR)/, \
					main.cpp \
)

# --- SRCS ---
SRCS_DIR		=	./srcs
SRCS_FILES		=	$(addprefix $(SRCS_DIR)/, \
					Fixed.cpp \
)

# --- SRCS & OBJS ---
SRCS			=	$(MAIN_FILE) \
					$(SRCS_FILES)

OBJS_DIR		=	./_objs

OBJS			=	$(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

# --- VPATH ---
VPATH			=	$(MAIN_DIR) \
					$(SRCS_DIR)



# --- COLOR ---
RESET			=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
CYAAN			=	\033[0;36m
WHITE			=	\033[0;37m

# --- PERCENTAGE ---
T				=	$(words $(OBJS))
N				=	0
C				=	$(words $N)${eval N+= 1}
PERCENTAGE		=	"`expr $C '*' 100 / $T`%"
MESSAGE			=	"%-100b\r" "$(YELLOW)Compiling $(NAME) ... $(PERCENTAGE) $(CXX) $(CXXFLAGS) $(INCLUDE) $@ $(RESET)"




# --- MAKE ---
$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@printf "\n$(GREEN)CREATED $(NAME)$(RESET)\n"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<
	@printf $(MESSAGE)

all:		$(NAME)

clean:
	@rm -f $(OBJS)
	@echo "$(RED)CLEAN  : rm -f $(NAME) objs$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FCLEAN : rm -f $(NAME)$(RESET)"

re: fclean all

d: CXXFLAGS+= -g3 -fsanitize=address -D SANITIZER=1
d: re

.PHONY: all clean fclean re d
