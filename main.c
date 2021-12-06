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
#include <stdio.h>

int	main(void)
{
    long int    a = 9999;
    char *      str;

	str = malloc(10);
	int a1 = ft_printf("%s", ft_strjoin("0   ", "123"));
	printf("\n");
	int a2 = printf("%#x", -2);

	printf("\na1 = %d\na2 = %d\n", a1, a2);

    return (0);
	int	i;
	int	*pi;

	i = 1;
	pi = &i;
	ft_printf("%p", pi);
	return (0);
}
