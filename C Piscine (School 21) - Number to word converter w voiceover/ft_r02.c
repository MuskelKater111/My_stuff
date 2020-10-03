/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:44:18 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/26 13:44:20 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_r02.h"

char *ft_strdup(char *src)
{
	char *rv;
	char *retval;
	long i;

	i = 0;
	while (*(src + i) != 0)
		i++;
	rv = (char *)malloc((i + 1) * sizeof(char));
	if (rv == (void *)0)
		return (rv);
	retval = rv;
	while (*src != 0)
	{
		*rv = *src;
		rv++;
		src++;
	}
	*rv = 0;
	return (retval);
}

int read_dict(char *fname)
{
	int fd;
	int i;
	int l;
	int state;
	char c;
	long rdc;

	fd = open(fname, O_RDONLY);
	if (fd<0)
		return (-1);
	i = 0;
	state = -1; //-1 waiting key; 0  reading key; 1 waiting ':'; 2 waiting value; 3 value;
	rdc = read(fd, &c, 1);
	l = 0;
	while (rdc == 1)
	{
		if(state == -1)
		{
			if ('0'<= c && c<='9')
			{
				g_dict[i].key[l] = c;
				l++;
				state = 0;
			}
			else if(c != '\n')
			{
//				printf("state = %d\n", state);
				close(fd);
				return (-1);
			}
		}
		else if(state==0)
		{
			if ('0' <= c && c <= '9')
			{
				g_dict[i].key[l] = c;
				l++;
			}
			else if(l>0 && (c == ' ' || c == ':'))
			{
				g_dict[i].key[l] = 0;
				state = (c == ':') ? 2 : 1;
				l = 0;
			}
			else
			{
//				printf("state = %d\n", state);
				close(fd);
				return (-1);
			}
		}
		else if (state == 1)
		{
			if (c == ':')
				state = 2;
			else if (c != ' ')
			{
//				printf("state = %d\n", state);
				close(fd);
				return (-1);
			}
		}
		else if (state == 2)
		{
			if (33 <= c && c<= 126)
			{
				g_dict[i].value[l] = c;
				l++;
				state = 3;
			}
			else if (c != ' ')
			{
//				printf("state = %d\n", state);
				close(fd);
				return (-1);
			}
		}
		else if(state == 3)
		{
			if(32 <= c && c<= 126)
			{
				g_dict[i].value[l] = c;
				l++;
			}
			else if (l>0 && c=='\n')
			{
				while(g_dict[i].value[l-1]==' ')
					l--;
				g_dict[i].value[l] = 0;
				l = 0;
				i++;
				state = -1;
			}
			else
			{
//				printf("state = %d\n", state);
				close(fd);
				return (-1);
			}
		}
		rdc = read(fd, &c, 1);
	}
	if(state == 3 && l>0)
	{
		while (g_dict[i].value[l - 1] == ' ')
			l--;
		g_dict[i].value[l] = 0;
		i++;
	}
	else if (state != -1)
	{
		close(fd);
		return (-1);
	}
	g_dlen = i;
	close(fd);
	if(g_dlen < 10)
		return (-1);
	return (sort_dict());
}

int check_number(char *number)
{
	char c;
	int i;

	i = 0;
	while (number[i])
	{
		c = number[i];
		if (!((i == 0 && (('0' <= c && c <= '9') || c == '+'))
			|| (i > 0 && ('0' <= c && c <= '9'))))
			return (-1);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int retval;

	retval = 0;
	while (*str != 0)
	{
		str++;
		retval++;
	}
	return (retval);
}

char *norm_number(char *number)
{
	while (number[1] && (number[0]=='+' || number[0]=='0'))
		number++;
	return number;
}

int ft_strcmp(char *s1, char *s2)
{
	int retval;

	retval = 0;
	while (retval == 0)
	{
		retval = (unsigned char)*s1 - (unsigned char)*s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	}
	return (retval);
}

int dict_cmp(char *key1, char *key2)
{
	int l1;
	int l2;

	l1 = ft_strlen(key1);
	l2 = ft_strlen(key2);
	if (l1 != l2)
		return (l1 - l2);
	return (ft_strcmp(key1, key2));
}

char *ft_strcpy(char *dest, char *src)
{
	char *retval;

	retval = dest;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (retval);
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *retval;

	retval = dest;
	while (n > 0)
	{
		*dest = *src;
		dest++;
		if (*src != 0)
			src++;
		n--;
	}
	return (retval);
}

void str_swap(char *s1, char *s2)
{
	char t[250];

	ft_strcpy(t, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, t);
}

void dict_swap(int i, int j)
{
	str_swap(g_dict[i].key, g_dict[j].key);
	str_swap(g_dict[i].value, g_dict[j].value);
}

int sort_dict()
{
	int i;
	int j;
	int cmp;

	i = 1;
	while (i < g_dlen)
	{
		j = 0;
		while (j < g_dlen - i)
		{
			cmp = dict_cmp(g_dict[j].key, g_dict[j + 1].key);
			if (cmp > 0)
				dict_swap(j, j + 1);
			else if (cmp==0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

long allocsize(char *number)
{
	int i;
	int l;
	int maxl;
	int li;

	l = ft_strlen(number);
	i = 0;
	maxl = 0;
	while (i < g_dlen && ft_strlen(g_dict[i].key) <= l)
	{
		li = ft_strlen(g_dict[i].value);
		if(li > maxl)
			maxl = li;
		i++;
	}
	return (l * (maxl + 1));
}

int find_dict(char *rest)
{
	int i;
	int cmp;

	i = 0;
//	printf("rest='%s' key='%s'\n", rest, g_dict[i].key);
	while (i<g_dlen && (cmp=dict_cmp(rest, g_dict[i].key)) > 0)
		i++;
//	printf("i=%d\n", i);
	return (i - ((cmp == 0) ? 0 : 1));
}

int is_dict_key_order(char *key)
{
	int i;

	i = 0;
	while (key[i]!=0)
	{
		if (!((i==0 && key[i]=='1')||(i>0 && key[i]=='0')))
			return (0);
		i++;
	}
	if(i>2)
		return (1);
	return (0);
}

char *rush02(char *out, int lout, char *number)
{
	int nl;
	int pout;
	int ppout;//previous pout
	int didx;
	int l;
	int i;
	char *diff;
	char *nout;
	char *res;

	i = 1;
	nl = ft_strlen(number) - 1;
	pout = lout - 1;
	ppout = pout;
	while (nl >= 0)
	{
		if(number[nl]=='0')
			ppout = pout;
		else
		{
			didx = find_dict(number + nl);
//			printf("didx=%d\n", didx);
			if(ft_strlen(g_dict[didx].key)==i)
			{
				if (ft_strcmp(g_dict[didx].key, number + nl) == 0)
				{
					ppout = lout - 1;
					l = ft_strlen(g_dict[didx].value);
	//				printf("'%s' l=%d pout=%d didx=%d\n", g_dict[didx].value, l, pout, didx);
					pout = lout - l - 1;
					ft_strncpy(out + pout, g_dict[didx].value, l);
				}
				else
				{
					ppout = pout;
					if(pout!=lout-1)
					{
						pout--;
						out[pout] = ' ';
					}
					l = ft_strlen(g_dict[didx].value);
	//				printf("'%s' l=%d pout=%d didx=%d out+pout='%s'$\n",
	//					g_dict[didx].value, l, pout, didx, out + pout);
					pout -= l;
					ft_strncpy(out + pout, g_dict[didx].value, l);
	//				printf("'%s' l=%d pout=%d didx=%d out+pout='%s'$\n",
	//					g_dict[didx].value, l, pout, didx, out + pout);
				}
	//			printf("key_order = %d\n", is_dict_key_order(g_dict[didx].key));
				if (is_dict_key_order(g_dict[didx].key))
				{
					diff = ft_strdup(number + nl);
					diff[1] = 0;
	//				printf("diff =  '%s'\n", diff);
					didx = find_dict(diff);
					pout--;
					out[pout] = ' ';
					l = ft_strlen(g_dict[didx].value);
					pout -= l;
					ft_strncpy(out + pout, g_dict[didx].value, l);
	//				printf("'%s' l=%d pout=%d didx=%d out+pout='%s'$\n",
		//				   g_dict[didx].value, l, pout, didx, out + pout);
				}
			}
			else
			{
				pout = ppout;
				if (pout != lout - 1)
				{
					pout--;
					out[pout] = ' ';
				}
				l = ft_strlen(g_dict[didx].value);
	//			printf("'%s' l=%d pout=%d didx=%d out+pout='%s'$\n",
		//			g_dict[didx].value, l, pout, didx, out + pout);
				pout -= l;
				ft_strncpy(out + pout, g_dict[didx].value, l);
				diff = ft_strdup(number + nl);
				diff[i - ft_strlen(g_dict[didx].key) + 1] = 0;
				if(!(nout = (char *)malloc(lout)))
					return (NULL);
				res = rush02(nout, lout, diff);
				pout--;
				out[pout] = ' ';
				l = ft_strlen(res);
	//			printf("'%s' l=%d pout=%d didx=%d out+pout='%s'$\n",
	//				g_dict[didx].value, l, pout, didx, out + pout);
				pout -= l;
				ft_strncpy(out + pout, res, l);
				free(nout);
			}
		}
		nl--;
		i++;
	}
	return (out + pout);
}

void ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	main(int argc, char *argv[])
{
	char *number;
	char *dict_fname;
	char *out;
	int lout;
	char *res;

	if (argc > 3)
		return (0);
	if (argc < 2)
		return (0);//здес надо читать из fd=1
	if (argc == 2)
	{
		number = argv[1];
		dict_fname = ft_strdup("numbers.dict");
		//сделать обработку /rus
	}
	if (argc == 3)
	{
		number = argv[2];
		dict_fname = argv[1];
	}
	if (read_dict(dict_fname) < 0)
	{
		ft_putstr(2, "Dict Error\n");
		return (1);
	}
	if (check_number(number) < 0)
	{
		ft_putstr(2, "Error\n");
		return (1);
	}
	number = norm_number(number);
	if(ft_strcmp(number,"0")==0)
	{
		ft_putstr(1, g_dict[0].value);
		ft_putstr(1, "\n");
		return (0);
	}
	lout = allocsize(number);
//	printf("number=%s lout=%d\n", number, lout);
	if (!(out = (char *)malloc(lout)))
	{
		write(2, "Memory Error\n", 13);
		return (1);
	}
	out[lout - 1] = 0;
	res = rush02(out, lout, number);
	ft_putstr(1, res);
	ft_putstr(1, "\n");
	free(out);

	//for (int i = 0; i < g_dlen; i++)
	//	printf("%s : %s\n", g_dict[i].key, g_dict[i].value);

	//21
	//1:   1 - "one"
	//2:   21 - "twenty one"

	//424
	//1:	4 - "four"
	//2:    24 - "twenty four"
	//3:    424 - "four hundred twenty four"

	//404
	//1:	4 - "four"
	//2:	04 - "four"
	//3: 	404 - "four hundred four"

	//13013:
	//1:	3 - "three"
	//2:	13 - "thirteen"
	//3:	013 - "thirteen"
	//4:	3013 - "three thousand thirteen"
	//5:	13013 - "thirteen thousand thirteen"

	//10000:
	//1:	0 - ""
	//2:	00 - ""
	//3: 	000 - ""
	//4:	0000 - ""
	//5:	10000 - "ten thousand"

	//11324:
	//1:	4 - four
	//2:	24 - twenty four
	//3:	324 - three hundred twenty four
	//4:	1324 - one thousand three hundred twenty four
	//5:	11324 - 

	//20 : hey everybody !$
	return (0);
}
