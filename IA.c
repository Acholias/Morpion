/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IA.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:46:04 by lumugot           #+#    #+#             */
/*   Updated: 2024/11/2size 15:4size:55 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Morpion.h"

int	evaluate_board(char board[size][size], char ia, char human)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == ia)
				return (10);
			else if (board[i][0] == human)
				return (-10);
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == ia)
				return (10);
			else if (board[0][i] == human)
				return (-10);
		}
		i++;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == ia)
			return (10);
		else if (board[0][0] == human)
			return (-10);
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == ia)
			return (10);
		else if (board[0][2] == human)
			return (-10);
	}
	return (0);
}

int	minimax(char board[size][size], int depth, int is_max, char ia, char human)
{
	int	i;
	int	j;
	int	best_score;
	int	score;

	if ((score = evaluate_board(board, ia, human)) != 0)
		return (score - depth);
	if (!scan_board(board))
		return (0);
	if (is_max == 1)
	{
		best_score = -1000;
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = ia;
					score = minimax(board, depth + 1, 0, ia, human);
					if (score > best_score)
						best_score = score;
					board[i][j] = ' ';
				}
			}
		}
	}
	else
	{
		best_score = 1000;
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = human;
					score = minimax(board, depth + 1, 1, ia, human);
					if (score < best_score)
						best_score = score;
					board[i][j] = ' ';
				}
			}
		}
	}
	return (best_score);
}

void ia_move(char board[size][size], char player, char opponent)
{
    int i, j;
    int best_score = -1000;
    int best_move_i = -1;
    int best_move_j = -1;
    int score;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = player;
                score = minimax(board, 0, 0, player, opponent);
                if (score > best_score)
                {
                    best_score = score;
                    best_move_i = i;
                    best_move_j = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[best_move_i][best_move_j] = player;
}

int scan_board(char board[size][size])
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (board[i][j] == ' ')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}