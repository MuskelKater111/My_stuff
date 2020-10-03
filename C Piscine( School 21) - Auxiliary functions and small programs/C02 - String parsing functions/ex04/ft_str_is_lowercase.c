/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:19:14 by fmira             #+#    #+#             */
/*   Updated: 2020/09/12 23:25:22 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	if (*str == '\0')
	{
		return (1);
	}
	while (*(str + i) != 0)
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}