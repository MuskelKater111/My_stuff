/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:10:42 by fmira             #+#    #+#             */
/*   Updated: 2020/09/18 22:22:29 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(ft_strlen(src) + 1);
	while (i != ft_strlen(src))
	{
		res[i] = src[i];
		i++;
	}
	res[ft_strlen(src)] = '\0';
	return (res);
}
