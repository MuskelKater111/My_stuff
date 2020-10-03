/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:04:35 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 18:58:54 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		show_files(int argc, char **argv);
void		show_stdin(void);

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		show_stdin();
	}
	else
		show_files(argc, argv);
}
