/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:34:24 by fmira             #+#    #+#             */
/*   Updated: 2020/09/25 19:16:36 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree			*btree_create_node(void *item)
{
	t_btree		*new_tree;

	new_tree = NULL;
	new_tree = (t_btree*)malloc(sizeof(t_btree));
	(new_tree)->item = item;
	(new_tree)->left = NULL;
	(new_tree)->right = NULL;
	return (new_tree);
}
