/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:32:13 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 23:20:14 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_tab *tab, char *str, int nbs, int nbz)
{
	tab->len += nbs + nbz + ft_strlen(str);
	if (tab->flag[1][1] == '0' && tab->flag[0][1] != '-' && tab->preci < 0)
	{
		nbz += nbs;
		nbs = 0;
	}
	if (tab->flag[0][1] != '-')
		while (nbs-- > 0)
			ft_putchar(' ');
	if (*str == '-')
		ft_putchar(*str++);
	if (tab->conv == 'p')
		ft_putstr("0x");
	while (nbz-- > 0)
		ft_putchar('0');
	ft_putstr(str);
	if (tab->flag[0][1] == '-')
		while (nbs-- > 0)
			ft_putchar(' ');
}

void	ft_ret_base(unsigned long long int nb, char **adr, char *base)
{
	int ba;

	ba = ft_strlen(base);
	if (nb < 0)
		ft_putchar('-');
	if (nb / ba)
		ft_ret_base(nb / ba, adr, base);
	if (!(*adr = ft_charjoint(*adr, base[nb % ba])))
		return ;
}

int		printf_p(t_tab *tab)
{
	int		nbs;
	int		nbz;
	char	*str;

	str = NULL;
	ft_ret_base(va_arg(tab->list, unsigned long int), &str, "0123456789abcdef");
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
	nbs = ((tab->larg - nbz - ft_strlen(str) - 2) > 0)
	? tab->larg - nbz - ft_strlen(str) - 2 : 0;
	tab->len += 2;
	print_arg(tab, str, nbs, nbz);
	ft_free_str(str);
	return (1);
}

int		printf_pcent(t_tab *tab)
{
	int		nbs;
	int		nbz;

	nbz = 0;
	nbs = ((tab->larg - 1) > 0) ? tab->larg - 1 : 0;
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
	ft_putchar('%');
	if (tab->flag[0][1] == '-')
		while (nbs-- > 0)
			ft_putchar(' ');
	return (1);
}

int		printf_s(t_tab *tab)
{
	char	*str;
	int		nbs;

	str = NULL;
	if (!(str = ft_strdup(va_arg(tab->list, char*))))
		if (!(str = ft_strdup("(null)")))
			return (0);
	if (tab->preci >= 0 && tab->preci < ft_strlen(str))
		if (!(str = ft_strndup(str, tab->preci)))
			return (0);
	nbs = ((tab->larg - ft_strlen(str)) > 0) ? tab->larg - ft_strlen(str) : 0;
	print_arg(tab, str, nbs, 0);
	ft_free_str(str);
	return (1);
}
