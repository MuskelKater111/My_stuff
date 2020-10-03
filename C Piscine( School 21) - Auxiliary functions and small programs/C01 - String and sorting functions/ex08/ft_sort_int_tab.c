/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 22:01:42 by fmira             #+#    #+#             */
/*   Updated: 2020/09/11 22:08:20 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_sort_int_tab(int *tab, int size)
{
	int a;
	int b;
	int temp;

	a = 0;
	b = 0;
	while (tab[a] < (size - 1))
	{
		while (tab[b] < (size - 1))
		{
			if (tab[a] < tab[b])
			{
				temp = tab[a];
				tab[i] = tab[b];
				tab[b] = temp;
			}
			b++;
		}
		a++;
		b = 0;
	}
}
