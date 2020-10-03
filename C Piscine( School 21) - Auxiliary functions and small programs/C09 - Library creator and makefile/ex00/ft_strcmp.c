/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:56:28 by fmira             #+#    #+#             */
/*   Updated: 2020/09/20 13:28:36 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (s1[x] || s1[y])
	{
		if (s1[x] != s2[y])
		{
			return (s1[x] - s2[y]);
		}
		else
		{
			y++;
			x++;
		}
	}
	return (s1[x] - s2[y]);
}
