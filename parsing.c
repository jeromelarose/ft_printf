/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:42:16 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 23:14:17 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parsing(t_tab *tab)
{
	parse_flag(tab);
	parse_larg(tab);
	parse_preci(tab);
	parse_conv(tab);
	return (select_func(tab));
}

void	parse_flag(t_tab *tab)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (tab->flag[i][0] == tab->str[tab->i])
		{
			while (tab->flag[i][0] == tab->str[tab->i])
			{
				tab->flag[i][1] = tab->str[tab->i++];
			}
			i = -1;
		}
		i++;
	}
}

void	parse_larg(t_tab *tab)
{
	if (tab->str[tab->i] == '*')
	{
		tab->larg = va_arg(tab->list, int);
		if (tab->larg < 0)
		{
			if (tab->flag[0][1] != '-')
				tab->flag[0][1] = '-';
			tab->larg = -tab->larg;
		}
		tab->i++;
	}
	else
	{
		if (tab->str[tab->i] >= '0' && tab->str[tab->i] <= '9')
		{
			while (tab->str[tab->i] >= '0' && tab->str[tab->i] <= '9')
				tab->larg = tab->larg * 10 + (tab->str[tab->i++] - '0');
		}
	}
}

void	parse_preci(t_tab *tab)
{
	if (tab->str[tab->i] == '.')
	{
		tab->i++;
		tab->preci = 0;
		if (tab->str[tab->i] == '*')
		{
			tab->preci = va_arg(tab->list, int);
			tab->i++;
		}
		else
		{
			if (tab->str[tab->i] >= '0' && tab->str[tab->i] <= '9')
			{
				while (tab->str[tab->i] >= '0' && tab->str[tab->i] <= '9')
					tab->preci = tab->preci * 10 + (tab->str[tab->i++] - '0');
			}
		}
	}
}

void	parse_conv(t_tab *tab)
{
	int i;

	i = 0;
	while (tab->string_conv[i])
	{
		if (tab->string_conv[i] == tab->str[tab->i])
		{
			tab->conv = tab->str[tab->i++];
			break ;
		}
		i++;
	}
}
