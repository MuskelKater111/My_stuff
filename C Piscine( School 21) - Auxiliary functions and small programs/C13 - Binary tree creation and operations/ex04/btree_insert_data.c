/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:09:41 by fmira             #+#    #+#             */
/*   Updated: 2020/09/25 23:06:57 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	if (!root)
	{
		btree_create_node(item);
	}
	else if ((*cmpf)(item, (*root)->item) < 0)
	{
		btree_insert_data(&((*root)->left), item, cmpf);
	}
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}
