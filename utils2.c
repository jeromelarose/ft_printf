/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:35:09 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 20:56:03 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ret_nbc(long long int nbr)
{
	int		nbc;

	nbc = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		nbc++;
	}
	if (nbr == 0)
		nbc++;
	while (nbr)
	{
		nbc++;
		nbr /= 10;
	}
	return (nbc);
}

char	*ft_itoa(long long int nbr)
{
	char	*ret;
	int		nbc;

	nbc = ret_nbc(nbr);
	if (!(ret = malloc(sizeof(char) * (nbc + 1))))
		return (NULL);
	ret[nbc] = '\0';
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr = -nbr;
	}
	nbc--;
	if (nbr == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		ret[nbc--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}

char	*ft_itoa_u(unsigned long long int nbr)
{
	char	*ret;
	int		nbc;

	nbc = ret_nbc(nbr);
	if (!(ret = malloc(sizeof(char) * (nbc + 1))))
		return (NULL);
	ret[nbc] = '\0';
	nbc--;
	if (nbr == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		ret[nbc--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}

char	*ft_charjoint(char *s1, char c)
{
	char	*ret;
	int		i;

	if (c == '\0')
		return (s1);
	i = 0;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		free(s1);
		s1 = NULL;
	}
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
