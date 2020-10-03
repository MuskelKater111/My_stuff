/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:51:24 by fmira             #+#    #+#             */
/*   Updated: 2020/09/15 13:06:15 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int anb;

	if (nb < 1)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	anb = ft_recursive_factorial(nb - 1) * nb;
	return (anb);
}
