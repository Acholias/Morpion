/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:41:54 by lumugot           #+#    #+#             */
/*   Updated: 2024/11/30 16:27:24 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Morpion.h"

void make_move(char board[size][size], char player)
{
    int row;
    int col;
    int result;
    
    while (1)
    {
        printf("Player %c, entrez une case (ligne colonne): ", player);
        result = scanf("%d %d", &row, &col);
        if (result != 2)
        {
            while (getchar() != '\n');
            printf("\033[31;01mEntrée invalide ! Veuillez entrer deux entiers pour la ligne et la colonne.\n\033[00m");
            continue;
		}
        if (row < 0 || row >= size || col < 0 || col >= size)
            printf("\033[31;01mMouvement invalide ! Essaie encore.\n\033[00m");
        else if (board[row][col] != ' ')
            printf("\033[31;01mCette case est déjà prise ! Essaie encore.\n\033[00m");
        else
        {
            board[row][col] = player;
            break ;
        }
    }
}


void	print_board(char board[size][size])
{
	int	row;
	int	col;

	row = 0;
	printf("\033[0;0fPlateau de jeu         Coordonees\n");
	while (row < size)
	{
		col = 0;
		printf("|");
		while (col < size)
		{
			printf(" %c |", board[row][col]);
			col++;
		}
		printf("       |");
		col = 0;
		while (col < size)
		{
			printf("(%d,%d)|", row, col);
			col++;
		}
		printf("\n");
		if (row < size - 1)
			printf("-------------       -------------------\n");
		row++;
	}
}


int main(void)
{
    char board[size][size] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player;
    int moves;
	int starting_player;
    char game_mode[0];

    clear_terminal();
	print_rules();
	printf("\033[33;01mEcrivez 'P' pour jouer en 1contre1. \n\033[00m");
	printf("\033[33;01mEcrivez n'importe quelle lettre pour jouer contre le bot. \n\033[00m");
    printf("\033[37;01mEntrez le mode de jeu: \033[00m");
    scanf("%s", game_mode);
    srand(time(NULL));
    starting_player = rand() % 2;
    if (starting_player == 0)
        player = 'X';
    else
        player = 'O';
    moves = 0;
    while (1)
    {
        clear_terminal();
        print_board(board);
        if (game_mode[0] == 'P')
            make_move(board, player);
        else
        {
            if (player == 'X')
                make_move(board, player);
            else
                ia_move(board, player, (player == 'X' ? 'O' : 'X'));
        }
        moves++;
        if (check_winner(board) || moves == 9) 
            break;
        player = (player == 'X') ? 'O' : 'X';
    }
    clear_terminal();
    print_board(board);
    if (check_winner(board))
        printf("\033[32;01mLe joueur %c a gagne ! \n\033[00m", player);
	else
        printf("\033[33;01mMatch nul !\n\033[00m");
    return 0;
}

//printf("\033[31;01mLe joueur %c a gagne ! \n\033[00m", player);
