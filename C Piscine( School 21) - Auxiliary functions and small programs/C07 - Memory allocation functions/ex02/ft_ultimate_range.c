/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 19:47:37 by fmira             #+#    #+#             */
/*   Updated: 2020/09/18 21:56:47 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *nmbarr;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	nmbarr = (int *)malloc(sizeof(*nmbarr) * (max - min));
	if (nmbarr == NULL)
	{
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		nmbarr[i] = min;
		min++;
		i++;
	}
	*range = nmbarr;
	return (i);
}
