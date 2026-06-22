###########################################
#             VARIABLES                   #
###########################################

NAME			=	book
SRC_FILES		= 	src/Contact.cpp		\
					src/main.cpp		\
					src/PhoneBook.cpp
INCLUDES		=	include
CPP				=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 -I$(INCLUDES)

###########################################
#                 RULES                   #
###########################################

all: $(NAME)

$(NAME):
	@echo "Compiling Phonebook 42"
	@$(CPP) $(CPPFLAGS) $(SRC_FILES) -o $(NAME)

###########################################
#               CLEANING                  #
###########################################

fclean:
	@echo "Removing executables"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re