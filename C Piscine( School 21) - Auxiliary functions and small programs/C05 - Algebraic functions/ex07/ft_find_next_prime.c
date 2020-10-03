/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:27:05 by fmira             #+#    #+#             */
/*   Updated: 2020/09/16 21:55:08 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime1(int nb)
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

int		ft_find_next_prime(int nb)
{
	unsigned int	nbu;

	nbu = nb;
	if (ft_is_prime1(nbu) == 1)
	{
		return (nbu);
	}
	else
	{
		while (ft_is_prime1(nbu) != 1)
		{
			nbu++;
		}
		return (nbu);
	}
}
