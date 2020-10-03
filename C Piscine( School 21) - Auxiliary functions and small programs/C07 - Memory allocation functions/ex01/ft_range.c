/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:11:02 by fmira             #+#    #+#             */
/*   Updated: 2020/09/18 20:00:13 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *nmbarr;
	int i;

	if (min >= max)
	{
		return (NULL);
	}
	nmbarr = (int *)malloc(sizeof(*nmbarr) * (max - min));
	i = 0;
	while (min < max)
	{
		nmbarr[i] = min;
		min++;
		i++;
	}
	return (nmbarr);
}
