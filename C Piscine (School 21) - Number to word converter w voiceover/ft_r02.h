/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:41:00 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/26 13:41:02 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_R02_H
# define FT_R02_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//не забыть убрать!

typedef struct	s_dict{
	char key[100];
	char value[250];
}				t_dict;

char *ft_strdup(char *src);
int read_dict(char *fname);
int check_number(char *number);
int ft_strlen(char *str);
char *norm_number(char *number);
int ft_strcmp(char *s1, char *s2);
int dict_cmp(char *key1, char *key2);
char *ft_strcpy(char *dest, char *src);
void str_swap(char *s1, char *s2);
void dict_swap(int i, int j);
int sort_dict();
t_dict g_dict[1000];
int g_dlen;

#endif
