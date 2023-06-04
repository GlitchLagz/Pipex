NAME = pipex
X86 = arch -x86_64
SRC = cfiles/*.c
CMP = gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)

all: $(NAME)
	@echo "Successful Make"

$(NAME):
	$(X86) $(CMP)

clean:

fclean: clean
		rm -rf $(NAME)

re: fclean all
