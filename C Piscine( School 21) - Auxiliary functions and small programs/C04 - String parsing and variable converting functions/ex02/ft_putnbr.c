/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:02:55 by fmira             #+#    #+#             */
/*   Updated: 2020/09/14 17:36:42 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	unsigned int nbt;

	if (nb < 0)
	{
		nbt = nb * -1;
		ft_putchar('-');
	}
	else
	{
		nbt = nb;
	}
	if (nbt >= 10)
	{
		ft_putnbr(nbt / 10);
		ft_putnbr(nbt % 10);
	}
	else
	{
		ft_putchar(nbt + '0');
	}
}
