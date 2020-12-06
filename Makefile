NAME	=	libasm.a

BIN		= 	run_libasm		
HEADER	= 	libasm.h

SRC		=	ft_strlen \
			ft_strcpy \
			ft_write	\
			

ASM		= 	/usr/local/bin/nasm

FIL = $(addsuffix .s, $(addprefix srcs/, $(SRC)))
OBJS = $(FIL:.s=.o)

%.o	: %.s
	$(ASM) -fmacho64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

run: all
	@gcc -Wall -Wextra -Werror -I./$(HEADER) libasm.a main.c -o $(BIN)
	@./run_libasm

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BIN)

re: fclean all

norm:
	norminette $(FIL) main.c $(HEADER)