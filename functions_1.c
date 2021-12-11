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

int max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int process_sym(va_list *params, s_flags *flags)
{
	char	sym;
	sym = (char) va_arg(*params, int);
	if (sym == 0)
		return (print_str(char_to_str(sym), 1, 1, flags));
	return (print_str(char_to_str(sym), 1, 0, flags));
}

void	ft_putstr_fd2(char *s, int fd, int byte_n_diff)
{
	if (!s)
		return;
	write(fd, &s[0], ft_strlen(s) + byte_n_diff);
}

char *ui_to_str(unsigned n)
{
	char			*digs;
	int				i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	digs = malloc(11);
	while (n)
	{
		digs[i] = (char) ((n % 10) + 48);
		n = n / 10;
		i++;
	}
	digs[i--] = 0;
	str_reverse(digs, i);
	return (digs);
}


char	*pointer_to_str(unsigned long p)
{
	char	*hex;
	char	*result;

	if (p == 0)
		return ft_strdup("0x0");
	hex = i_to_base_str(p, 16, 87);
	if (hex == NULL)
		return (NULL);
	result = ft_strjoin("0x", hex);
	if (result == NULL)
	{
		free(hex);
		return (NULL);
	}
	free(hex);
	return (result);

}

