NAME =  phonebook
CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g
SRC = Contact.cpp PhoneBook.cpp main.cpp
	
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus