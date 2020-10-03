/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:12:51 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 16:31:38 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

void		ft_puterror(char *str);

void		show_err(char *argv)
{
	char *errbuf;

	errbuf = strerror(errno);
	write(2, ": ", 2);
	ft_puterror(argv);
	write(2, ": ", 2);
	ft_puterror(errbuf);
	write(2, "\n", 1);
}
