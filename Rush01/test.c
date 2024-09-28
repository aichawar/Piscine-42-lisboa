#include <stdio.h>
#include <stdlib.h>

void	print(int arr[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

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

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);

}

int	check_input(char *argv, int num_views[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (is_digit(argv[i]))
		{
			num_views[j] = argv[i] - '0';
			if (num_views[j] < 1 || num_views[j] > 4)
				return (0);
			j++;
			if (j == 16)
				break;
			if (argv[i + 1] != ' ')
				return (0);
		}
		else if (argv[i] != ' ')
			return (0);
		i++;
	}
	if (j != 16 || argv[i + 1] != '\0')
		return (0);
	return (1);
}
 
int	main(int argc, char **argv)
{
	int num_views[16];

	if (argc != 2 || !check_input(argv[1], num_views))
	{
		printf("ERROR INPUT\n");
		return (0);
	}
	int i = 0;
	while (i < 16)
	{
		printf("%d, ", num_views[i]);
		i++;
	}
	printf("\ninput correct\n");
	return (0);
}
