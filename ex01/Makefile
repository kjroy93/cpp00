###########################################
#             VARIABLES                   #
###########################################

NAME			=	phonebook
SRC				=	src/Contact.cpp		\
					src/PhoneBook.cpp	\
					src/print.cpp		\
					src/utils.cpp		\
					main.cpp
OBJ_DIR			=	obj
INCLUDES		=	include
CPP				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 -I$(INCLUDES) -MMD -MP
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

###########################################
#                 RULES                   #
###########################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling Phonebook 42"
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