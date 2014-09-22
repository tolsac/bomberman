##
## Makefile for makefile in /home/boyer_b/Documents/Epitech/
##
## Made by bertrand boyer
## Login   <boyer_b@epitech.net>
##
## Started on  Wed Oct 26 09:52:13 2011 bertrand boyer
## Last update Sun Jun  3 21:33:45 2012 nerevarine


#Généralité.
NAME		= bomberman
RM		= rm -f

#Compilation
CC		= g++
CFLAGS		= -Wall -Wextra -W
INC		= -I ./lib/include
LIB		= -L ./lib/lib/ -Wl,--rpath=./lib/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lgdl_gl -lGL -lGLU

#Fichiers
HDR		= $(wildcard *.hh)
SRC		= $(wildcard *.cpp)
OBJ		= $(SRC:.cpp=.o)

$(NAME):	$(HDR) $(OBJ)
	@echo -n "Compilation de $(NAME)."
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIB)
	@echo " Terminée."

all:		$(HDR) $(NAME)

%.o:		%.cpp $(HDR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ $(LIB)

clean:
	@$(RM) *~
	@echo -n "Suppression des fichiers objets."
	@$(RM) $(OBJ)
	@echo " Terminée."

fclean:		clean
	@echo -n "Suppression du programme $(NAME)."
	@$(RM) $(NAME)
	@echo " Terminée."

re:		fclean all

.PHONY:	all clean fclean re