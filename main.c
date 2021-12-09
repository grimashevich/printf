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
	char	**pstr;
	int		i;
	char	*str = ft_strdup("#0+10.5d");
	char	u_params2[64] = "";

	char *flags = copy_bonus_flags(&str);
	printf("flags =\t%20s\n", flags);
	printf("zero =\t%20p\n", pf_get_zero(flags));
	printf("width =\t%20d\n", pf_get_min_width(flags));
	printf("prec =\t%20d\n", pf_get_precision(flags));
	return (0);
}