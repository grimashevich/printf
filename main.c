/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:44:44 by EClown            #+#    #+#             */
/*   Updated: 2021/12/03 21:39:16 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void	printer(const char *c, va_list params)
{
	char	*pf_keys;
	char	*key;

	pf_keys = "cspdiuxX%";
	key = ft_strchr(pf_keys, *c);
	if (*key == 'c')
		ft_putchar_fd(va_arg(params, int), 1);
	else if (*key == 's')
		ft_putstr_fd(va_arg(params, char *), 1);
	else if (*key == 'p')
		printf("%p", (va_arg(params, int *)));
}

int	ft_printf(const char *input, ...)
{
	va_list	params;

	va_start(params, input);
	while (*input)
	{
		if (*input == '%')
			printer(++input, params);
		else
			ft_putchar_fd(*input, 1);
		input++;
	}
	va_end(params);
	return (0);
}

int	main(void)
{
	int	i;
	int	*pi;

	i = 1;
	pi = &i;
	ft_printf("%p", pi);
	return (0);
}

