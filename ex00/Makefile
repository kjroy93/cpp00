###########################################
#             VARIABLES                   #
###########################################

NAME			=	megaphone
SRC				= 	MegaPhone.cpp
OBJ_DIR			=	obj
CPP				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC)) -MMD -MP

###########################################
#                 RULES                   #
###########################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling Megaphone 42"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

###########################################
#               INCLUDE                   #
###########################################

-include $(OBJ:.o=.d)

###########################################
#               CLEANING                  #
###########################################

clean:
	@echo "Removing objects"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing executables"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re