/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::   	 */
/*   functions_0.c									  :+:	  :+:	:+:      */
/*													+:+ +:+		 +:+	 */
/*   By: eclown <eclown@student.21-school.ru>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/04 13:36:01 by eclown			#+#	#+#			 */
/*   Updated: 2021/12/04 17:20:27 by eclown		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putui_fd(unsigned int n, int fd)
{
	char					digs[20];
	int						i;
	unsigned int			n2;

	n2 = n;
	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	else if (n > 0)
	while (n)
	{
		digs[i] = (char) ((n % 10) + 48);
		n = n / 10;
		i++;
	}
	digs[i] = 0;
	while (i)
	{
		write(fd, &digs[i - 1], 1);
		i--;
	}
	if (n2 == 0)
		return (1);
	return ((int) ft_strlen(digs));
}

int	print_and_free(char **str)
{
	int	len;

	if (str == NULL || *str == NULL)
		return (0);
	len = (int) ft_strlen(*str);
	ft_putstr_fd(*str, 1);
	free(*str);
	*str = NULL;
	return (len);
}


int	print_pointer(unsigned long p)
{
	char	*hex;

	if (p == 0)
		return (print_str("0x0", 0));
	ft_putstr_fd("0x", 1);
	hex = i_to_base_str(p, 16, 87);
	return (print_and_free(&hex) + 2);
}

