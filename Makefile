NAME = libftprintf.a

SERVER = server

CLIENT = client

SRC = ft_printf/ft_putchar.c ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c 

SRC_S = server.c 

SRC_C = client.c

OBJ = $(SRC:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

BONUS = 

FLAG = -Wall -Wextra -Werror

HEADER = mini_talk.h

all: $(NAME) $(SERVER) $(CLIENT)

%.o: %.c $(HEADER)
	$(CC) $(FLAG) -c $< -o $@ #Generate object files in the same directory as source files#

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(SERVER): $(OBJ_S)
	$(CC) $(NAME) $(OBJ_S) -o $(SERVER)

$(CLIENT): $(OBJ_C)
	$(CC) $(NAME) $(OBJ_C) -o $(CLIENT)

clean:
	rm -rf $(OBJ) $(OBJ_S) $(OBJ_C)

fclean: clean
	rm -rf $(NAME) $(SERVER) $(CLIENT)

re: fclean all
