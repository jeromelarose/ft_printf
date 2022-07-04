/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:39:01 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/15 23:20:13 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_tab
{
	int			i;
	int			len;
	int			preci;
	int			larg;
	char		flag[2][2];
	char		*string_conv;
	char		conv;
	va_list		list;
	const char	*str;
}				t_tab;

int				ret_nbc(long long int nbr);
char			*ft_itoa(long long int n);
char			*ft_itoa_u(unsigned long long int nbr);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strdup(char *src);
char			*ft_charjoint(char *s1, char c);
void			print_arg(t_tab *tab, char *str, int nbs, int nbz);
int				printf_d(t_tab *tab);
int				printf_u(t_tab *tab);
void			ft_ret_base(unsigned long long int nb, char **adr, char *base);
int				printf_lo(t_tab *tab);
int				printf_up(t_tab *tab);
int				printf_c(t_tab *tab);
int				printf_p(t_tab *tab);
int				printf_pcent(t_tab *tab);
char			*ft_strndup(char *str, int nb);
int				printf_s(t_tab *tab);
void			init_tab(t_tab *tab);
void			parse_flag(t_tab *tab);
void			parse_larg(t_tab *tab);
void			parse_preci(t_tab *tab);
void			parse_conv(t_tab *tab);
int				select_func(t_tab *tab);
int				parsing(t_tab *tab);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_printf(const char *str, ...);
void			ft_free_str(char *str);

#endif
