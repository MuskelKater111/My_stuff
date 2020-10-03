/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:45:06 by fmira             #+#    #+#             */
/*   Updated: 2020/09/16 20:54:38 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	unsigned int	i;
	int				j;
	unsigned int	nbu;

	i = 2;
	j = 0;
	nbu = nb;
	if (nbu <= 1)
		return (0);
	else if (nbu == 2)
		return (1);
	else
	{
		while (i * i <= nbu && j != 1)
		{
			if (nbu % i == 0)
				j = 1;
			i++;
		}
		if (j == 1)
			return (0);
		else
			return (1);
	}
}
