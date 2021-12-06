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

int		ft_printf(const char *input, ...);
char	*i_to_base_str(unsigned long num, int base, char a_move);
int		print_pointer(unsigned long p);
int		ft_putui_fd(unsigned int n, int fd);
int		print_str(char *s, int need_free);
void	str_reverse(char *s, int last);

#endif
