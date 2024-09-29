/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoybou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:12:47 by hsoybou-          #+#    #+#             */
/*   Updated: 2024/09/28 23:12:55 by hsoybou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_rows(int **grid, int num_views[16], int row);
int		check_cols(int **grid, int num_views[16], int col);
void	print(int **grid);
void	ft_putstr(char *str);

int	is_safe(int **grid, int row, int col)
{
	int	x;
	int	y;

	x = 0;
	while (x < col)
	{
		if (grid[row][x] == grid[row][col])
			return (0);
		x++;
	}
	y = 0;
	while (y < row)
	{
		if (grid[y][col] == grid[row][col])
			return (0);
		y++;
	}
	return (1);
}

int	check_clues(int **grid, int num_views[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_rows(grid, num_views, i) || !check_cols(grid, num_views, i))
			return (0);
		i++;
	}
	return (1);
}

int	solve_sudoku(int **grid, int num_views[16], int row, int col)
{
	int	num;

	if (row == 4)
		return (check_clues(grid, num_views));
	if (col == 4)
		return (solve_sudoku(grid, num_views, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		grid[row][col] = num;
		if (is_safe(grid, row, col))
		{
			if (solve_sudoku(grid, num_views, row, col + 1))
				return (1);
		}
		num++;
	}
	grid[row][col] = 0;
	return (0);
}

void	solve_rush(int num_views[16])
{
	int	**grid;
	int	row;
	int	col;
	int	i;

	grid = (int**)malloc(4 * sizeof(int *));
	i = 0;
	while(i < 4)
	{
		grid[i] = malloc(4 * sizeof(int));
		i++;
	}
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	if (solve_sudoku(grid, num_views, 0, 0))
		print(grid);
	else
		ft_putstr("Not a solvable grid");
	i = 0;
	while(i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
