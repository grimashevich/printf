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
	char	space_filling;
	size_t	min_width;
	size_t	precision;
	char	sym;
} s_flags;

int		ft_printf(const char *input, ...);
char	*i_to_base_str(unsigned long num, int base, char a_move);
char	*pointer_to_str(unsigned long p);
char	*ui_to_str(unsigned n);
int		print_str(char *s, int need_free, int zero_c);
void	str_reverse(char *s, int last);
size_t	copy_bonus_flags(char **params, char *bonus_flags);
void	ft_putstr_fd2(char *s, int fd, int byte_n_diff);
char	*char_to_str(char c);
int		process_sym(va_list *params);
const	char *first_num_zero(const char *str);

#endif
