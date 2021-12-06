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

int print_int(int num)
{
	int	len;

	if (num >= 0)
		len = 0;
	else
		len = 1;
	ft_putnbr_fd(num, 1);
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int print_str(char *s, int need_free)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	len = (int) ft_strlen(s);
	if (need_free)
		free(s);
	return (len);
}

int print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printer(const char *c, va_list *params)
{
	char	*pf_keys;
	char	*key;

	pf_keys = "cspdiuxX%";
	key = ft_strchr(pf_keys, *c);
	if (*key == 'c')
		return (print_char(va_arg(*params, int)));
	else if (*key == 's')
		return (print_str(va_arg(*params, char *), 0));
	else if (*key == 'p')
		return (print_pointer(va_arg(*params, unsigned long)));
	else if (*key == 'd' || *key == 'i')
		return(print_int(va_arg(*params, int)));
	else if (*key == 'u')
		return (ft_putui_fd(va_arg(*params, int), 1));
	else if (*key == 'x')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)), 16, 87), 1));
	else if (*key == 'X')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)),16, 55), 1));
	else if (*key == '%')
		return(print_str("%", 0));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	params;
	int result;

	result = 0;
	va_start(params, input);
	while (*input)
	{
		if (*input == '%')
			result += printer(++input, &params);
		else
			result += print_char(*input);
		input++;
	}
	va_end(params);
	return (result);
}