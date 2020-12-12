NAME	=	libasm.a

BIN		= 	run_libasm		

HEADER	= 	libasm.h

SRC		=	ft_strlen 	\
			ft_strcpy 	\
			ft_write	\
			ft_strcmp	\
			ft_read		\
			ft_strdup	\
			
ASM		= 	/usr/local/bin/nasm

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

FIL = $(addsuffix .s, $(addprefix srcs/, $(SRC)))

OBJS = $(FIL:.s=.o)

%.o	: %.s
	$(ASM) -g -fmacho64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

run: all
	@$(CC) -g -save-temps $(CFLAGS) -I./$(HEADER) libasm.a main.c -o $(BIN)
	@./run_libasm

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BIN)

re: fclean all

norm:
	norminette $(FIL) main.c $(HEADER)

debug:
	$(CC) -g -o disassembly.S $(CFLAGS) -S main.c
	objdump -d $(OBJS) -l > main.S
