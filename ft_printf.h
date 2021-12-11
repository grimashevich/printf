/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:25:19 by EClown            #+#    #+#             */
/*   Updated: 2021/12/02 18:43:26 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	"libft/libft.h"
# include	<stddef.h>
# include	<stdarg.h>

# define ft_printf_keys "cspdiuxX%";
# define ft_printf_flags "-0.# +123456789";

typedef struct st_flags
{
	char	l_align;
	char	zero_fill;
	char	mod_hex;
	char	space;
	char	plus;
	size_t	min_width;
	size_t	precision;
	char	precision_on;
	char	sym;
} s_flags;

int		ft_printf(const char *input, ...);
char	*i_to_base_str(unsigned long num, int base, char a_move);
char	*pointer_to_str(unsigned long p);
char	*ui_to_str(unsigned n);
int print_str(char *s, int need_free, int zero_c, s_flags *flags);
void	str_reverse(char *s, int last);
char	*copy_bonus_flags(const char **params);
void	ft_putstr_fd2(char *s, int fd, int byte_n_diff);
char	*char_to_str(char c);
int process_sym(va_list *params, s_flags *flags);
const	char *pf_get_zero(const char *str);
int		pf_get_min_width(char *str);
int pf_get_precision(char *str, s_flags *el);
s_flags	*create_sf_element(const char *params, char sym);
s_flags	*get_pf_flags(char *params, char sym);
char *apply_flags(char *s, s_flags *flags);
char *mp_char(char c, size_t n, char *add_str);
int		max_int(int a, int b);
char	*str_to_str(char *s);
char	*mod_hex(char *s, s_flags *flags);


#endif
