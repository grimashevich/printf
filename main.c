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
    char 	*str;
	char	**pstr;
	int		i;
	char	u_params[64] = "A-20.5d";
	char	u_params2[64] = "";


	printf("%s\n", first_num_zero(u_params));
	printf("%d", ft_atoi(u_params));
	return (0);

	str = ft_strdup("sTring1");
	pstr = &str;

	printf("%-20.5d\n", 5);
	printf("%c\n", **(pstr+1));
    return (0);
}