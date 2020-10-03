/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:13:23 by fmira             #+#    #+#             */
/*   Updated: 2020/09/23 21:34:57 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int sort_up;
	int sort_down;

	i = -1;
	sort_up = 1;
	sort_down = 1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			sort_up = 0;
	i = -1;
	if (sort_up == 0)
		while (++i < length - 1)
			if (f(tab[i], tab[i + 1]) < 0)
				sort_down = 0;
	if (sort_up == 1 || sort_down == 1)
		return (1);
	return (0);
}
