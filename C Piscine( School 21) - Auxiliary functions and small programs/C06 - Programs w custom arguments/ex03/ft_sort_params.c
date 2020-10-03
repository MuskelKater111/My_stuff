/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:54:40 by fmira             #+#    #+#             */
/*   Updated: 2020/09/17 18:59:19 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr_mod(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int			ft_strcmp(char *s1, char *s2)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (s1[x] || s1[y])
	{
		if (s1[x] != s2[y])
		{
			return (s1[x] - s2[y]);
		}
		else
		{
			y++;
			x++;
		}
	}
	return (s1[x] - s2[y]);
}

void		ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			main(int argc, char **argv)
{
	int		c[2];

	c[0] = 1;
	while (c[0] < argc)
	{
		c[1] = c[0] + 1;
		while (c[1] < argc)
		{
			if (ft_strcmp(argv[c[0]], argv[c[1]]) > 0)
			{
				ft_swap(&argv[c[0]], &argv[c[1]]);
			}
			c[1]++;
		}
		c[0]++;
	}
	c[0] = 1;
	while (c[0] < argc)
	{
		ft_putstr_mod(argv[c[0]]);
		c[0]++;
	}
	return (0);
}
