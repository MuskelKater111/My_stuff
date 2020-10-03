/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:21:11 by fmira             #+#    #+#             */
/*   Updated: 2020/09/12 21:47:29 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		src[i] = dest[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);

}

int main()
{
	char src[] = {40, 50, 51, 52, 53, 54};
	char dest[] = {77, 78, 79, 80, 81, 82, 83 ,84, 85};
	unsigned int n = 4;
	ft_strncpy(dest, src, n);
	printf("%s", dest);
}
