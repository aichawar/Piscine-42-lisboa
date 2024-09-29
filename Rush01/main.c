/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoybou- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:01:16 by hsoybou-          #+#    #+#             */
/*   Updated: 2024/09/28 22:02:38 by hsoybou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve_rush(int num_views[16]);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
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
				break ;
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
	int		num_views[16];

	if (argc != 2 || !check_input(argv[1], num_views))
	{
		ft_putstr("Error of input\n");
		return (0);
	}
	solve_rush(num_views);
	return (0);
}
