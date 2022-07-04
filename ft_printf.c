/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:35:57 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 23:13:06 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	init_tab(t_tab *tab)
{
	tab->preci = -1;
	tab->larg = 0;
	tab->flag[0][0] = '-';
	tab->flag[0][0] = '-';
	tab->flag[1][0] = '0';
	tab->flag[0][1] = '\0';
	tab->flag[1][1] = '\0';
	tab->conv = 0;
	tab->string_conv = "cspdiuxX%";
}

int		select_func(t_tab *tab)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab->conv == 'd' || tab->conv == 'i')
			return (printf_d(tab));
		if (tab->conv == 'c')
			return (printf_c(tab));
		if (tab->conv == 's')
			return (printf_s(tab));
		if (tab->conv == '%')
			return (printf_pcent(tab));
		if (tab->conv == 'p')
			return (printf_p(tab));
		if (tab->conv == 'u')
			return (printf_u(tab));
		if (tab->conv == 'x')
			return (printf_lo(tab));
		if (tab->conv == 'X')
			return (printf_up(tab));
		i++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	t_tab	tab;

	tab.str = str;
	tab.i = 0;
	tab.len = 0;
	va_start(tab.list, str);
	if (!str || !ft_strncmp(str, "%\0", 2) || !ft_strncmp(str, "%\n", 2))
		return (0);
	while (tab.str[tab.i])
	{
		if (tab.str[tab.i] == '%')
		{
			init_tab(&tab);
			tab.i++;
			if (!(parsing(&tab)))
				return (-1);
		}
		else
		{
			ft_putchar(tab.str[tab.i++]);
			tab.len++;
		}
	}
	va_end(tab.list);
	return (tab.len);
}
