##
## Makefile for my_ftp in /home/girard_x/GITREP/PSU_2014_myftp
## 
## Made by ALEXIS GIRARDEY
## Login   <girard_x@epitech.net>
## 
## Started on  Mon Mar  9 10:40:18 2015 ALEXIS GIRARDEY
## Last update Mon Mar  9 11:43:29 2015 ALEXIS GIRARDEY
##

CC	= gcc

RM	= @rm -vf

SERVEUR = serveur

CLIENT	= client

S_SRC	= serveur.c

C_SRC	= client.c

S_OBJ	= $(S_SRC:.c=.o)

C_OBJ	= $(C_SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

$(SERVEUR): $(S_OBJ) $(C_OBJ)
	$(CC) -o $(SERVEUR) $(S_OBJ) $(CFLAGS)
	$(CC) -o $(CLIENT) $(C_OBJ) $(CFLAGS)

all: $(SERVEUR)

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)
	$(RM) *~
	$(RM) *#

fclean: clean
	$(RM) $(SERVEUR)
	$(RM) $(CLIENT)

re: fclean all

.PHONY: clean fclean re all
