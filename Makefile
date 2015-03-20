##
## Makefile for my_ftp in /home/girard_x/GITREP/PSU_2014_myftp
## 
## Made by ALEXIS GIRARDEY
## Login   <girard_x@epitech.net>
## 
## Started on  Mon Mar  9 10:40:18 2015 ALEXIS GIRARDEY
## Last update Fri Mar 20 11:18:44 2015 ALEXIS GIRARDEY
##

CC	= gcc

RM	= @rm -vf

SERVEUR = serveur

CLIENT	= client

S_SRC	= ./Serveur/serveur.c \
	  ./Serveur/fct-annexe.c \
	  ./Serveur/exec-cmd.c \
	  ./Serveur/fct-ftp-1.c \
	  ./Serveur/fct-ftp-2.c \
	  ./Serveur/fct-ftp-3.c \
	  ./Serveur/get_args.c

C_SRC	= ./Client/client.c \
	  ./Serveur/fct-annexe.c

S_OBJ	= $(S_SRC:.c=.o)

C_OBJ	= $(C_SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -I./Includes

$(SERVEUR): $(S_OBJ) $(C_OBJ)
	$(CC) -o $(SERVEUR) $(S_OBJ) $(CFLAGS)
	$(CC) -o $(CLIENT) $(C_OBJ) $(CFLAGS)

all: $(SERVEUR)

clean:
	$(RM) ./Serveur/*.o
	$(RM) ./Client/*.o
	$(RM) ./Client/*~
	$(RM) ./Client/*#
	$(RM) ./Serveur/*~
	$(RM) ./Serveur/*#
	$(RM) ./Includes/*~

fclean: clean
	$(RM) $(SERVEUR)
	$(RM) $(CLIENT)

re: fclean all

.PHONY: clean fclean re all
