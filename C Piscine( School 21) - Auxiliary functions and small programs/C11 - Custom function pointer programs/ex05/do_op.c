/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:21:37 by fmira             #+#    #+#             */
/*   Updated: 2020/09/23 23:46:09 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include <stdio.h>      // 4debug
#include <unistd.h>

void		ft_sum(int x1, int x2)
{
	ft_putnbr(x1 + x2);
}

void		ft_min(int x1, int x2)
{
	ft_putnbr(x1 - x2);
}

void		ft_div(int x1, int x2)
{
	if (x2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	else
		ft_putnbr(x1 / x2);
}

void		ft_mod(int x1, int x2)
{
	ft_putnbr(x1 % x2);
}

void		ft_mul(int x1, int x2)
{
	ft_putnbr(x1 * x2);
}

int			main(int argc, char **argv)
{
	int		x1;
	int		x2;
	char	op;
	void	(*fun[5])(int, int);

	fun[0] = &ft_sum;
	fun[1] = &ft_min;
	fun[2] = &ft_div;
	fun[3] = &ft_mod;
	fun[4] = &ft_mul;	
	if (argc < 4)
		return (1);

	x1 = ft_atoi(argv[1]);
	x2 = ft_atoi(argv[3]);	
	op = *argv[2];

	printf("%d %d %c\n", x1, x2, op); 

	if(argv[2][1] != 0)
	{
		write (1, "0", 1);
		return (2);
	}
	if (op == '+')
	{
		(*fun[0])(x1, x2);
		return (0);
	}
	if (op == '-')
	{
		(*fun[1])(x1, x2);
		return (0);
	}
	if (op == '/')
	{
		(*fun[2])(x1, x2);
		return (0);
	}
	if (op == '%')
	{
		if (argv[3] == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		else (*fun[3])(x1, x2);
			return (0);
	}
	if (op == '*')
	{
		(*fun[4])(x1, x2);
		return (0);
	}
}
