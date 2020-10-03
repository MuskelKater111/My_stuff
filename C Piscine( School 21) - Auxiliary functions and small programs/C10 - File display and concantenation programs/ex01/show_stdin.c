/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:12:11 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 16:12:35 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		show_stdin(void)
{
	char buf;

	while (read(0, &buf, 1))
	{
		write(1, &buf, 1);
	}
}
