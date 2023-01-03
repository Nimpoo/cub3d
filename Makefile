# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 14:53:38 by Palmi             #+#    #+#              #
#    Updated: 2023/01/03 15:06:42 by mayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CC		:= gcc
FLAGS	:= -framework Opengl -framework Appkit -lmlx
CFLAGS	:= -Werror -Wextra -Wall -g

# Name of the final executable
NAME	:= cub3d

# All needed files
SRC		:=	src/main.c			\

OBJ		:= $(SRC:.c=.o)

# All needed library
LIB		:=	src/libft/libft.a	\

# Colors for differents prints
GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

# Compile all .c files
.c.o: $(SRC)
	@printf $(GREEN)"\r\033[KCompiling objects... "$(YELLOW)"<$<> ⏳ "$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Compile all .o files
$(NAME): vendor/readline $(OBJ)
	@printf $(GREEN)"\r\033[KObjects compiled succesfully ✅\n"$(RESET)
	@make -C src/libft
	@printf $(CYAN)"\r\033[KCompiling '$(NAME)'... ⏳"$(RESET)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -I include/ -o $(NAME)
	@printf $(GREEN)"\r\033[KSuccess compiling '$(NAME)' ✅\n"$(RESET)

# Default command to launch
all: $(NAME) # load

# Compile and run minishell
run: all
	@./$(NAME)

shortcut:
	@open https://www.google.com/search?q=how+to+become+a+good+developer+%3\
	F&rlz=1C5CHFA_enFR1031FR1031&ei=typxY8mBN-yUxc8Pm6CB4Ak&ved=0ahUKEwiJud\
	LQ2Kv7AhVsSvEDHRtQAJwQ4dUDCA8&uact=5&oq=how+to+become+a+good+developer+\
	%3F&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIHCAAQgAQQEzIGCAAQHhATMgYIABAeEBMyBggA\
	EB4QEzIICAAQCBAeEBMyCAgAEAgQHhATMggIABAIEB4QEzIICAAQCBAeEBMyCAgAEAgQHhA\
	TMggIABAIEB4QEzoKCAAQRxDWBBCwAzoJCAAQgAQQDRATOggIABAeEA0QEzoICAAQFhAeEB\
	NKBAhNGAFKBAhBGABKBAhGGABQhgpYnDJgvTdoAXABeACAAWaIAe0BkgEDMi4xmAEAoAEBy\
	AEIwAEB&sclient=gws-wiz-serp

# Just a cute loading bar
load:
	@printf '\r █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 0%%\r'
	@sleep .1
	@printf '\r ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 5%%\r'
	@sleep .1
	@printf '\r ███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 10%%\r'
	@sleep .1
	@printf '\r ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 15%%\r'
	@sleep .1
	@printf '\r █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 20%%\r'
	@sleep .1
	@printf '\r ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 25%%\r'
	@sleep .1
	@printf '\r ███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 30%%\r'
	@sleep .1
	@printf '\r ████████▒▒▒▒▒▒▒▒▒▒▒▒▒ - 35%%\r'
	@sleep .1
	@printf '\r █████████▒▒▒▒▒▒▒▒▒▒▒▒ - 40%%\r'
	@sleep .1
	@printf '\r ██████████▒▒▒▒▒▒▒▒▒▒▒ - 45%%\r'
	@sleep .1
	@printf '\r ███████████▒▒▒▒▒▒▒▒▒▒ - 50%%\r'
	@sleep .1
	@printf '\r ████████████▒▒▒▒▒▒▒▒▒ - 55%%\r'
	@sleep .1
	@printf '\r █████████████▒▒▒▒▒▒▒▒ - 60%%\r'
	@sleep .1
	@printf '\r ██████████████▒▒▒▒▒▒▒ - 65%%\r'
	@sleep .1
	@printf '\r ███████████████▒▒▒▒▒▒ - 70%%\r'
	@sleep .1
	@printf '\r ████████████████▒▒▒▒▒ - 75%%\r'
	@sleep .1
	@printf '\r █████████████████▒▒▒▒ - 80%%\r'
	@sleep .1
	@printf '\r ██████████████████▒▒▒ - 85%%\r'
	@sleep .1
	@printf '\r ███████████████████▒▒ - 90%%\r'
	@sleep .1
	@printf '\r ████████████████████▒ - 95%%\r'
	@sleep .1
	@printf '\r █████████████████████ - 100%%\r'
	@sleep .8

# Clean all .o and .a files
clean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft clean
	@printf $(GREEN)"\r\033[Kcleaned 🗑\n"$(RESET)

# Same as 'clean' but clean minishell too
fclean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft fclean
	@printf $(GREEN)"\r\033[KObjects cleaned 🗑\n"$(RESET)
	@printf $(CYAN)"\r\033[KErasing binary file... "$(RESET)"⏳ "
	@rm -rdf $(NAME) test_parser
	@printf $(GREEN)"\r\033[KBinary file cleaned 🗑\n"$(RESET)
	@printf $(GREEN)"\r\033[KForce cleaned 🗑\n"$(RESET)

# Clean all and recompile minishell
re: fclean all

.PHONY: all clean fclean re load run