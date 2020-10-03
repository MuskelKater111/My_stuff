/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:58:49 by fmira             #+#    #+#             */
/*   Updated: 2020/09/16 19:48:21 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int rnb;

	rnb = nb;
	if (power < 0)
	{
		return (0);
	}
	else if (nb == 0 && power == 0)
	{
		return (1);
	}
	else if (power == 0)
	{
		return (1);
	}
	{
		while (power > 1)
		{
			power--;
			rnb = rnb * nb;
		}
		return (rnb);
	}
}
