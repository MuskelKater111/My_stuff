/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:14:34 by fmira             #+#    #+#             */
/*   Updated: 2020/09/22 19:35:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024

int			ft_strcmp(char *s1, char *s2);
void		show_stdin(void);
void		ft_puterror(char *str);
void		show_err(char *argv);
void		ft_putstr(char *str);

void		check_close(int fd, int i, char **argv)
{
	if (close(fd))
	{
		ft_puterror(basename(argv[0]));
		show_err(argv[i]);
	}
}

void		do_this(int fd, char **argfile, char *zeroarg)
{
	int		size;
	char	buf[BUF_SIZE + 1];

	while ((size = read(fd, &buf, BUF_SIZE)) > 0)
	{
		buf[size] = '\0';
		ft_putstr(buf);
	}
	if (size < 0)
	{
		ft_puterror(basename(zeroarg));
		show_err(*argfile);
	}
}

void		show_files(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 1;
	while (i < argc)
	{
		fd = (open(argv[i], O_RDONLY));
		if (ft_strcmp(argv[i], "-") == 0)
		{
			show_stdin();
			i++;
			continue;
		}
		else if (fd < 0)
		{
			ft_puterror(basename(argv[0]));
			show_err(argv[i]);
			i++;
			continue;
		}
		else
			do_this(fd, &argv[i], argv[0]);
		check_close(fd, i, &argv[i]);
		i++;
	}
}
