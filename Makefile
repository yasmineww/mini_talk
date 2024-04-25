NAME = libftprintf.a

SERVER = server

CLIENT = client

SERVER_B = server_bonus

CLIENT_B = client_bonus

SRC = ft_printf/ft_putchar.c ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c

SRC_S = server.c

SRC_C = client.c

OBJ = $(SRC:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

BONUS_S = server_bonus.c utils_bonus.c

BONUS_C = client_bonus.c utils_bonus.c

OBJ_BONUS_S = $(BONUS_S:.c=.o)

OBJ_BONUS_C = $(BONUS_C:.c=.o)

FLAG = -Wall -Wextra -Werror

HEADER = mini_talk.h

all: $(NAME) $(SERVER) $(CLIENT)

bonus: $(NAME) $(SERVER_B) $(CLIENT_B)

%.o: %.c $(HEADER)
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(SERVER): $(OBJ_S)
	$(CC) $(FLAG) $(NAME) $(OBJ_S) -o $(SERVER)

$(CLIENT): $(OBJ_C)
	$(CC) $(FLAG) $(NAME) $(OBJ_C) -o $(CLIENT)

$(CLIENT_B): $(OBJ_BONUS_C)
	$(CC) $(NAME) $(OBJ_BONUS_C) -o $(CLIENT_B)

$(SERVER_B): $(OBJ_BONUS_S)
	$(CC) $(NAME) $(OBJ_BONUS_S) -o $(SERVER_B)

clean:
	rm -rf $(OBJ) $(OBJ_S) $(OBJ_C) $(OBJ_BONUS_S) $(OBJ_BONUS_C)

fclean: clean
	rm -rf $(NAME) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re: fclean all
