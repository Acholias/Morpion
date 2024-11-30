# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 16:41:23 by lumugot           #+#    #+#              #
#    Updated: 2024/11/30 16:48:54 by lumugot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = morpion


SRC = board.c IA.c parsing.c
OBJ = $(SRC:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

define ASCII_ART
  
  
  __  __  ____  _____  _____ _____ ____  _   _ 
 |  \/  |/ __ \|  __ \|  __ \_   _/ __ \| \ | |
 | \  / | |  | | |__) | |__) || || |  | |  \| |
 | |\/| | |  | |  _  /|  ___/ | || |  | | . ` |
 | |  | | |__| | | \ \| |    _| || |__| | |\  |
 |_|  |_|\____/|_|  \_\_|   |_____\____/|_| \_|
                                               
  

endef
export ASCII_ART

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$$ASCII_ART"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@sleep 2
	@echo "$(BLUE)✔️ Tous les fichiers ont été compilés avec succès !$(RESET)"
	@sleep 2 
	@echo "$(GREEN)🎉 Le jeu Morpion est prêt à jouer !$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Nettoyage des fichiers objets...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Suppression de l'exécutable...$(RESET)"
	@rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
