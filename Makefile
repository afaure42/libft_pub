
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c\
		ft_isascii.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_strchr.c  \
		ft_strlen.c  \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_isprint.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_calloc.c  \
		ft_memset.c  \
		ft_strdup.c  \
		ft_memchr.c  \
		ft_memcpy.c  \
		ft_memccpy.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_bzero.c   \
		ft_memcmp.c  \
		ft_split.c	 \
		ft_itoa.c	\
		ft_substr.c \
		ft_strtrim.c\
		ft_strmapi.c \
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)

SRCBONUS = ft_lstnew.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_front.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstclear.c\
		ft_lstmap.c

OBJBONUS = $(SRCBONUS:.c=.o)

all : $(NAME)

bonus : $(OBJ) $(OBJBONUS)
	ar rc $(NAME) $(OBJ) $(OBJBONUS)
	ranlib $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $^ -o $@

clean : $(OBJ) $(OBJBONUS)
	rm -rf $^

fclean : $(NAME) clean
	rm -f $<

re : fclean
	make all 

