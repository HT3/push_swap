TAG		= 	gcc
NAME1	= 	push_swap
NAME2	=	checker
FLAG	= 	-g -Wall -Werror -Wextra

SRC1 	= 	push_swap.c sort_tools.c sort_tools2.c sorter.c sorter_1.c \
			tools.c ./Libft/ft_freearray.c ./Libft/ft_freemem.c \
			./Libft/ft_lstlen.c ./Libft/ft_newintlist.c \

SRC2 	= 	push_swap.o sort_tools.o sort_tools2.o sorter.o sorter_1.o \
			tools.o ft_freearray.o ft_freemem.o ft_lstlen.o \
			ft_newintlist.o \

SRC3	=	checker.c sort_tools.c sort_tools2.c sorter.c sorter_1.c \
			tools.c read_ps.c ./Libft/ft_freearray.c \
			./Libft/ft_freemem.c ./Libft/ft_lstlen.c \
			./Libft/ft_newintlist.c \

SRC4	=	checker.o sort_tools.o sort_tools2.o sorter.o sorter_1.o \
			tools.o read_ps.o ft_freearray.o ft_freemem.o ft_lstlen.o \
			ft_newintlist.o \

all		: lib $(NAME1) $(NAME2)

lib		: 
	make re -C ./Libft

$(NAME1)	:
	@echo "Compiling Push_Swap..."
	@$(TAG) $(FLAG) -c $(SRC1)
	@$(TAG) -o $(NAME1) $(SRC2) -L. ./Libft/libft.a 
	@echo "Push_Swap Created"

$(NAME2)	:
	@echo "Compiling Checker..."
	@$(TAG) $(FLAG) -c $(SRC3)
	@$(TAG) -o $(NAME2) $(SRC4) -L. ./Libft/libft.a 
	@echo "Checker Created"


clean	:
	@rm -f *.o $(NAME1) $(NAME2)
	@echo "Flushing Push_Swap & Checker..."

fclean: clean
	@echo "Reseting Push_swap & Checker..."
	@make fclean -C ./Libft
	@rm -f $(NAME1) $(NAME2)

re:			fclean all