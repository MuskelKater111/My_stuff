/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:25:54 by fmira             #+#    #+#             */
/*   Updated: 2020/09/17 17:09:20 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			main(int argc, char *argv[])
{
	int i;

	i = 0;
	argc = 0;
	while (argv[argc][i] != '\0')
	{
		ft_putchar(argv[argc][i]);
		i++;
	}
	return (0);
}
