/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:39:23 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 17:52:35 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_puterr(char *str);

void	arg_errors(int argc)
{
	if (argc < 2)
	{
		ft_puterr("File name missing.\n");
	}
	else if (argc > 2)
	{
		ft_puterr("Too many arguments.\n");
	}
}
