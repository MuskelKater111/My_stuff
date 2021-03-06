/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:40:20 by fmira             #+#    #+#             */
/*   Updated: 2020/09/15 22:43:18 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int c[2];
	int i;

	c[0] = 1;
	c[1] = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			c[0] = c[0] * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[1] = c[1] * 10 + str[i] - '0';
		i++;
	}
	return (c[1] * c[0]);
}
