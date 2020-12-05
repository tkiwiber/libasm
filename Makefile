NAME	=	libasm.a

SRCS	=	hello.s \
			ft_strlen.s \

ASM		= 	/usr/local/bin/nasm

OBJS = $(SRCS:.s=.o)

%.o	: %.s
	$(ASM) -fmacho64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

run: all
	@touch test
	@echo "Ceci est un test" > test
	@gcc -g -Wall -Wextra -Werror -I./libasm.h libasm.a main.c -o run_libasm
	@./run_libasm

fclean: clean
	@rm -f $(NAME)
	@rm -f run_libasm
	@rm -f test

re: fclean all