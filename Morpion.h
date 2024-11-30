/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Morpion.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumugot <lumugot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:23:07 by lumugot           #+#    #+#             */
/*   Updated: 2024/11/30 16:30:53 by lumugot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORPION_H
# define MORPION_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

# define size 3

int	    check_rows(char board[size][size]);
int	    check_columns(char board[size][size]);
int	    check_diagonals(char board[size][size]);
int	    check_winner(char board[size][size]);
void    print_board(char board[size][size]);
void	make_move(char board[size][size], char player);
void	ai_move(char board[size][size], char ai, char human);
int	    minimax(char board[size][size], int depth, int is_max, char ai, char human);
int	    evaluate_board(char board[size][size], char ai, char human);
int	    evaluate_board(char board[size][size], char ai, char human);
int	    minimax(char board[size][size], int depth, int is_max, char ai, char human);
void 	ia_move(char board[size][size], char player, char opponent);
int     scan_board(char board[size][size]);
void	print_rules(void);
void	clear_terminal(void);
int	    main(void);

#endif