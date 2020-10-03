/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:28:41 by fmira             #+#    #+#             */
/*   Updated: 2020/09/15 16:35:34 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
	{
		return (1);
	}
	else if (power > 1)
	{
		nb = nb * ft_recursive_power(nb, power - 1);
	}
	else if (power < 0)
	{
		return (0);
	}
	return (nb);
}
