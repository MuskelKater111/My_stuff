/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:00:01 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 17:51:37 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

void		ft_putstr(char *str);
void		arg_errors(int argc);
void		ft_puterr(char *str);

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		size;

	if (argc != 2)
	{
		arg_errors(argc);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((size = read(fd, &buf, BUF_SIZE)) > 0)
		{
			buf[size] = '\0';
			ft_putstr(buf);
		}
		if (size == -1)
		{
			ft_puterr("Cannot read file.\n");
		}
		close(fd);
		return (0);
	}
}
