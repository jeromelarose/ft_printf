/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:30:31 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 20:56:01 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_d(t_tab *tab)
{
	int		nbs;
	int		nbz;
	char	*str;

	str = NULL;
	if (!(str = ft_itoa(va_arg(tab->list, int))))
		return (0);
	if (tab->preci == 0 && *str == '0')
	{
		if (str)
			ft_free_str(str);
		if (!(str = ft_strdup("")))
			return (0);
	}
	if (tab->preci >= ft_strlen(str) && tab->preci > 0 && *str == '-')
		tab->preci++;
	nbz = (tab->preci > (ft_strlen(str))) ? tab->preci - ft_strlen(str) : 0;
	nbs = ((tab->larg - nbz - ft_strlen(str)) > 0)
	? tab->larg - nbz - ft_strlen(str) : 0;
	print_arg(tab, str, nbs, nbz);
	ft_free_str(str);
	return (1);
}

int		printf_u(t_tab *tab)
{
	int		nbs;
	int		nbz;
	char	*str;

	str = NULL;
	if (!(str = ft_itoa_u(va_arg(tab->list, unsigned int))))
		return (0);
	if (tab->preci == 0 && *str == '0')
	{
		if (str)
			ft_free_str(str);
		if (!(str = ft_strdup("")))
			return (0);
	}
	nbz = (tab->preci > ft_strlen(str)) ? tab->preci - ft_strlen(str) : 0;
	nbs = ((tab->larg - nbz - ft_strlen(str)) > 0)
	? tab->larg - nbz - ft_strlen(str) : 0;
	print_arg(tab, str, nbs, nbz);
	ft_free_str(str);
	return (1);
}

int		printf_lo(t_tab *tab)
{
	int		nbs;
	int		nbz;
	char	*str;

	str = NULL;
	ft_ret_base((long)va_arg(tab->list, unsigned int),
	&str, "0123456789abcdef");
	if (!str)
		return (0);
	if (tab->preci == 0 && *str == '0')
	{
		if (str)
			ft_free_str(str);
		if (!(str = ft_strdup("")))
			return (0);
	}
	nbz = (tab->preci > ft_strlen(str)) ? tab->preci - ft_strlen(str) : 0;
	nbs = ((tab->larg - nbz - ft_strlen(str)) > 0)
	? tab->larg - nbz - ft_strlen(str) : 0;
	print_arg(tab, str, nbs, nbz);
	ft_free_str(str);
	return (1);
}

int		printf_up(t_tab *tab)
{
	int		nbs;
	int		nbz;
	char	*str;

	str = NULL;
	ft_ret_base((long)va_arg(tab->list, unsigned int),
	&str, "0123456789ABCDEF");
	if (!str)
		return (0);
	if (tab->preci == 0 && *str == '0')
	{
		if (str)
			ft_free_str(str);
		if (!(str = ft_strdup("")))
			return (0);
	}
	nbz = (tab->preci > ft_strlen(str)) ? tab->preci - ft_strlen(str) : 0;
	nbs = ((tab->larg - nbz - ft_strlen(str)) > 0)
	? tab->larg - nbz - ft_strlen(str) : 0;
	print_arg(tab, str, nbs, nbz);
	ft_free_str(str);
	return (1);
}

int		printf_c(t_tab *tab)
{
	int		nbs;
	int		nbz;

	nbz = 0;
	nbs = ((tab->larg - nbz - 1) > 0) ? tab->larg - nbz - 1 : 0;
	if (tab->flag[1][1] == '0' && tab->flag[0][1] != '-')
	{
		nbz = nbs;
		nbs = 0;
	}
	tab->len += 1 + nbs + nbz;
	if (tab->flag[0][1] != '-')
		while (nbs-- > 0)
			ft_putchar(' ');
	while (nbz-- > 0)
		ft_putchar('0');
	ft_putchar((unsigned int)va_arg(tab->list, int));
	if (tab->flag[0][1] == '-')
		while (nbs-- > 0)
			ft_putchar(' ');
	return (1);
}
