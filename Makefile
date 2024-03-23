NAME = server

NAME_C = client

SRC =

SRC_C =

OBJ = $(SRC:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

BONUS = 

FLAG = -Wall -Wextra -Werror

HEADER = mini_talk.h

all: $(NAME) $(NAME_C)

%.o: %.c $(HEADER)
	$(CC) $(FLAG) -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME_C): $(OBJ_C)
	$(CC) $(OBJ_C) -o $(NAME_C)

clean:
	rm -rf $(OBJ) $(OBJ_C)

fclean: clean
	rm -rf $(NAME) $(NAME_C)

re: fclean all
