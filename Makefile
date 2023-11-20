NAME		= server

NAME1		= client

SRC0		= server.c utilities.c utilities_2.c

SRC1		= client.c utilities.c utilities_2.c

OBJ0		= $(SRC0:.c=.o)

OBJ1		= $(SRC1:.c=.o)

CFLAGS		= -Wextra -Wall -Werror -g3

CC			= cc

all: $(NAME) $(NAME1)

$(NAME):
	
	$(CC) $(CFLAGS) -c $(SRC0) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ0)

$(NAME1):
	$(CC) $(CFLAGS) -c $(SRC1) 
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) 

clean:
	rm -f $(OBJ0)
	rm -f $(OBJ1)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME1)

re: fclean all

.PHONY: all clean fclean re
