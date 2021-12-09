/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:44:44 by EClown            #+#    #+#             */
/*   Updated: 2021/12/04 17:21:24 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(char *s, int need_free, int zero_c)
{
	int	len;

	if (s == NULL)
	{
		s = ft_strdup("(null)");
		need_free = 1;
	}
	ft_putstr_fd2(s, 1, zero_c);
	len = (int) ft_strlen(s) + zero_c;
	if (need_free)
		free(s);
	return (len);
}

char *char_to_str(char c)
{
	char	*c_str;

	c_str = malloc(2);
	if (! c_str)
		return (NULL);
	c_str[0] = c;
	c_str[1] = 0;
	return (c_str);
}

int	printer(const char *c, va_list *params)
{
	char	*pf_keys;
	char	*key;

	pf_keys = ft_printf_keys;
	key = ft_strchr(pf_keys, *c);
	if (*key == 'c')
		return (process_sym(params));
	else if (*key == 's')
		return (print_str(va_arg(*params, char *), 0, 0));
	else if (*key == 'p')
		return (print_str(pointer_to_str(va_arg(*params, unsigned long)), 1, 0));
	else if (*key == 'd' || *key == 'i')
		return(print_str(ft_itoa(va_arg(*params, int)), 1, 0));
	else if (*key == 'u')
		return (print_str(ui_to_str(va_arg(*params, int)), 1, 0));
	else if (*key == 'x')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)), 16, 87), 1, 0));
	else if (*key == 'X')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)), 16, 55), 1, 0));
	else if (*key == '%')
		return(print_str("%", 0, 0));
	return (0);
}
/*Копирует бонусные флаги и сдвигает указатель стрки параметров на после флагов*/
size_t copy_bonus_flags(char **params, char *bonus_flags)
{
	int		i;
	char	*flags;

	flags = ft_printf_flags;
	i = 0;
	while (ft_strchr(flags, **params))
		bonus_flags[i++] = *(*params)++;
	bonus_flags[i] = 0;
	return (ft_strlen(bonus_flags));
}

const char *first_num_zero(const char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (ft_isdigit(*str) && *str != '0' )
			return (NULL);
		if (*str == '.')
			return (NULL);
		if (*str == '0')
			return (str);
		str++;
	}
	return (NULL);
}

void	fill_sf_element(s_flags *el, const char *flags, char sym)
{
	char	*pf_keys;

	pf_keys = ft_printf_keys;

	if (! ft_strchr(pf_keys, sym))
		return ;
	el->sym = sym;
	if (ft_strchr(pf_keys, '-'))
		el->l_align = 1;
}

s_flags *create_sf_element(const char *flags, char sym)
{
	s_flags	*el;

	if (flags == NULL || *flags == 0 || sym == 0)
		return (NULL);
	el = malloc(sizeof(s_flags));
	if (el == NULL)
		return (NULL);
	el->sym = 0;
	el->l_align = 0;
	el->min_width = 0;
	el->mod_hex = 0;
	el->precision = 0;
	el->space_filling = 0;
	el->zero_fill = 0;
	return (el);
}

int	ft_printf(const char *input, ...)
{
	va_list	params;
	int		result;
	char	flags[128];

	result = 0;
	va_start(params, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			copy_bonus_flags((char **) &input, flags);
			result += printer(input, &params);
			print_str("\t\t", 0, 0);
			print_str(flags, 0, 0);
		}
		else
		{
			ft_putchar_fd(*input, 1);
			result++;
		}

		input++;
	}
	va_end(params);
	return (result);
}