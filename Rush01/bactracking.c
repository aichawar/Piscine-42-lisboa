/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bactracking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoybou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:51:38 by hsoybou-          #+#    #+#             */
/*   Updated: 2024/09/29 13:51:40 by hsoybou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_boxes(int *line)
{
	int	count;
	int	max;
	int	pos;

	count = 1;
	max = line[0];
	pos = 1;
	while (pos < 4)
	{
		if (line[pos] > max)
		{
			max = line[pos];
			count++;
		}
		pos++;
	}
	return (count);
}

int	check_rows(int grid[4][4], int num_views[16], int row)
{
	int	left_nums;
	int	right_nums;
	int	line[4];
	int	pos;

	left_nums = num_views[8 + row];
	right_nums = num_views[12 + row];
	pos = 0;
	while (pos < 4)
	{
		line[pos] = grid[row][pos];
		pos++;
	}
	if (count_visible_boxes(line) != left_nums)
		return (0);
	pos = 0;
	while (pos < 4)
	{
		line[pos] = grid[row][3 - pos];
		pos++;
	}
	if (count_visible_boxes(line) != right_nums)
		return (0);
	return (1);
}

int	check_cols(int grid[4][4], int num_views[16], int col)
{
	int	up_nums;
	int	down_nums;
	int	line[4];
	int	pos;

	up_nums = num_views[col];
	down_nums = num_views[4 + col];
	pos = 0;
	while (pos < 4)
	{
		line[pos] = grid[pos][col];
		pos++;
	}
	if (count_visible_boxes(line) != up_nums)
		return (0);
	pos = 0;
	while (pos < 4)
	{
		line[pos] = grid[3 - pos][col];
		pos++;
	}
	if (count_visible_boxes(line) != down_nums)
		return (0);
	return (1);
}
