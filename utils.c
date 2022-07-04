/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:34:30 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 22:22:11 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			ft_putchar(*str++);
}

char	*ft_strdup(char *src)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!src)
		return (NULL);
	if (!(ret = malloc(sizeof(*ret) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strndup(char *str, int nb)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = (ft_strlen(str) < nb) ? ft_strlen(str) : nb;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (str)
	{
		while (i < len)
		{
			ret[i] = str[i];
			i++;
		}
		ft_free_str(str);
	}
	ret[i] = '\0';
	return (ret);
}
