/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:26:12 by lumugot           #+#    #+#             */
/*   Updated: 2024/11/30 16:27:33 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Morpion.h"

int	check_rows(char board[size][size])
{
	int	row;

	row = 0;
	while (row < size)
	{
		if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2])
			return (1);
		row++;
	}
	return (0);
}

int	check_columns(char board[size][size])
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col])
			return (1);
		col++;
	}
	return (0);
}

int	check_diagonals(char board[size][size])
{
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return (1);
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return (1);
	return (0);
}

int	check_winner(char board[size][size])
{
	if (check_rows(board) == 1)
		return (1);
	if (check_columns(board) == 1)
		return (1);
	if (check_diagonals(board) == 1)
		return (1);
	return (0);
}
void clear_terminal(void)
{
    system("clear");
}

void print_rules(void)
{
    printf("\033[36;01m");
    printf("Bienvenue dans Tic-Tac-Toe !\n");
    printf("Voici les regles du jeux:\n\n");
    printf("\033[00m");
    printf("\033[31;01m- \033[36mSi vous jouez en 1 contre 1 le premier joueur aura les X et le deuxieme les O.\n\033[00m");
    printf("\033[31;01m- \033[36mSi vous avez decidez de jouer contre le bot le premier joueur sera attribuer de facon aleatoire.\n\033[00m");
    printf ("\n");
    printf("\033[31;01m- \033[36mLe mode de jeux choisi ne change rien a la maniere d'y jouer.\n\033[00m");
    printf("\033[31;01m- \033[36mVous devrez rentrez les coordonnees comme suit: 0 0, 0 1. L'espace est tres important pour le bon deroulement du jeux.\n\033[00m");
    printf("\033[31;01m- \033[36mSi vous ne mettez pas l'espace entre chaque chiffre et que le programme crash relancez le avec ./a.out.\n\n\033[00m");
    printf("\033[31;01m- \033[36mSi vous battez le bot une recompense vous sera attribuez.\n\033[00m");\
    printf("\033[31;01m- \033[36mAlors 1vs1 ou 1vsbot bon courage a vous et que le meilleur gagne !\n\033[00m");
    printf("\033[32;01mAppuyer sur entrer pour choisir le mode de jeux et commencer la partie...\n\033[00m");
    getchar();
}