###########################################
#             VARIABLES                   #
###########################################

NAME			=	megaphone
SRC_FILES		= 	megaphone.cpp
CPP				=	g++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98

###########################################
#                 RULES                   #
###########################################

all: $(NAME)

$(NAME):
	@echo "Compiling Megaphone 42"
	@$(CPP) $(CPPFLAGS) $(SRC_FILES) -o $(NAME)

###########################################
#               CLEANING                  #
###########################################

fclean:
	@echo "Removing executables"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re