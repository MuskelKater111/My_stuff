/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblastoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:18:10 by eblastoi          #+#    #+#             */
/*   Updated: 2020/09/13 14:58:36 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		mkstr(int l, char edge, char mid)
{
	int i;

	i = 0;
	while (i < l)
	{
		if (i == 0 || i == l - 1)
		{
			ft_putchar(edge);
		}
		else
		{
			ft_putchar(mid);
		}
		i++;
	}
	write(1, "\n", 1);
}

void		rush(int w, int h)
{
	int j;

	j = 0;
	if (w <= 0 || h <= 0)
	{
		write(1, "Pos!", 4);
	}
	while (j < h)
	{
		if (j == 0 || j == h - 1)
		{
			mkstr(w, 'o', '-');
		}
		else
		{
			mkstr(w, '|', ' ');
		}
		j++;
	}
}
