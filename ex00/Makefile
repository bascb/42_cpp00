NAME = megaphone
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g
SRC = megaphone.cpp
	
all: $(NAME)

$(NAME):
	$(CC) $(CXXFLAGS) -o $(NAME) $(SRC)
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus