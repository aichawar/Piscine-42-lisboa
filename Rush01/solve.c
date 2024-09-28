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

int	isSafe(int grid[4][4], int row, int col, int num)
{
	int x = 0;
	int y = 0;

	while (x < 4)
	{
		if (grid[row][x] == num)
			return (0);
		x++;
	}
	while (y < 4)
        {
                if (grid[y][col] == num)
                        return (0);
                y++;
        }
	return (1);
}


int	Solve(int grid[4][4], int row, int col)
{
	int num;

	if (row == 4)
		return (1);
	if (col == 4)
	{
		row++;
		col = 0;
	}
	if (grid[row][col] > 0)
		return Solve(grid, row, col + 1);
	num = 1;
	while( num <= 4)
	{
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (Solve(grid, row, col + 1))
				return (1);
		}
		num++;
		grid[row][col] = 0;
	}
	return (0);
}
