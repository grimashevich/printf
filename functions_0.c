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


/*Возвращает строку состоящую из n символов "с"*/
char *mp_char(char c, size_t n, char *add_str)
{
	char	*result;
	char	*result2;

	if (n == 0)
		return (NULL);
	result = malloc(n + 1);
	if (! result)
		return (NULL);
	result[n--] = 0;
	while (n > 0)
		result[n--] = c;
	result[0] = c;
	if (add_str && *add_str)
	{
		result2 = ft_strjoin(add_str, result);
		free(result);
		return (result2);
	}
	return result;
}

char *str_width_align_zero2(s_flags *flags, char *s, char *fill_str, char *add_str)
{
	char	*result;
	size_t	move;

	move = 0;
	if (add_str[0])
		move = 1;
	if (flags->l_align)
		result = ft_strjoin(s + move, fill_str);
	else
		result = ft_strjoin(fill_str, s + move);
	return (result);
}


/*В эту функцию мы попадаем только тогда, когда мин. ширина > длины строки*/
char *str_width_align_zero(s_flags *flags, char *s)
{
	size_t	len_diff;
	char	fill_char;
	char	*fill_str;
	char	*result;
	char	add_str[2];

	len_diff = flags->min_width - ft_strlen(s);
	add_str[0] = '-';
	add_str[1] = 0;
	fill_char = ' ';
	if (flags->zero_fill && !flags->l_align && !flags->precision_on && ft_strchr("diuxX", flags->sym))
		fill_char = '0';
	if (s[0] != '-' || fill_char == '0' || flags->precision_on)
		add_str[0] = 0;
	fill_str = mp_char(fill_char, len_diff, add_str);
	if (! fill_str)
		return (NULL);
	result = str_width_align_zero2(flags, s, fill_str, add_str);
	free(fill_str);
	free(s);
	return (result);
}

char *str_precision(char *s, s_flags *flags)
{
	char	*result;
	char	*fill_str;
	size_t 	s_len;

	s_len = ft_strlen(s);
	result = s;
	if (ft_strchr("diuxX", flags->sym) && flags->precision > s_len)
	{
		if (s[0] == '-')
		{
			fill_str = mp_char('0', flags->precision - s_len, "-");
			result = ft_strjoin(fill_str, result + 1);
		}
		else
		{
			fill_str = mp_char('0', flags->precision - s_len, NULL);
			result = ft_strjoin(fill_str, result);
		}
		free(fill_str);
	}
	else if (flags->sym == 's' && s_len > flags->precision)
		result[flags->precision] = 0;
	if (result != s)
		free(s);
	return (result);
}

char	*mod_hex(char *s, s_flags *flags)
{
	char	*result;

	if (flags->sym == 'X')
		result = ft_strjoin("0X", s);
	else
		result = ft_strjoin("0x", s);
	free(s);
	return (result);
}

char *add_plus(char *s)
{
	return (s);
}

/*Применяет флаги форматирования к строке*/
char *apply_flags(char *s, s_flags *flags)
{
	char	*result;

	if (! flags)
		return (s);
	result = s;
	if (flags->precision)
		result = str_precision(s, flags);
	if (flags->mod_hex && ft_tolower(flags->sym) == 'x')
		result = mod_hex(result, flags);
	if (flags->plus && ft_strchr("diuxX", flags->sym))
		result = add_plus(result);
	if (flags->min_width > ft_strlen(result))
		result = str_width_align_zero(flags, result);
	return (result);
}

int print_str(char *s, int need_free, int zero_c, s_flags *flags)
{
	int		len;

	if (s == NULL)
	{
		s = ft_strdup("(null)");
		need_free = 1;
	}
	s = apply_flags(s, flags);
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

char *str_to_str(char *s)
{
	if (s == NULL)
		return ft_strdup("(null)");
	return (ft_strdup(s));
}

int printer(char *b_flags, const char *c, va_list *params)
{
	char	*pf_keys;
	char	*key;
	s_flags	*flags;

	pf_keys = ft_printf_keys;
	key = ft_strchr(pf_keys, *c);
	flags = get_pf_flags(b_flags, *key);
	if (b_flags)
		free(b_flags);
	if (*key == 'c')
		return (process_sym(params, flags));
	else if (*key == 's')
		return (print_str(str_to_str(va_arg(*params, char *)), 1, 0, flags));
	else if (*key == 'p')
		return (print_str(pointer_to_str(va_arg(*params, unsigned long)), 1, 0, flags));
	else if (*key == 'd' || *key == 'i')
		return(print_str(ft_itoa(va_arg(*params, int)), 1, 0, flags));
	else if (*key == 'u')
		return (print_str(ui_to_str(va_arg(*params, int)), 1, 0, flags));
	else if (*key == 'x')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)), 16, 87), 1, 0, flags));
	else if (*key == 'X')
		return(print_str(i_to_base_str((va_arg(*params, unsigned int)), 16, 55), 1, 0, flags));
	else if (*key == '%')
		return(print_str("%", 0, 0, flags));
	return (0);
}

/*Возвращает структуру с флагами c printf*/
s_flags		*get_pf_flags(char *params, char sym)
{
	char	*pf_keys;
	s_flags	*el;

	el = create_sf_element(params, sym);
	if (el == NULL)
		return (NULL);
	pf_keys = ft_printf_keys;

	if (! ft_strchr(pf_keys, sym))
		return (NULL);
	el->sym = sym;
	if (ft_strchr(params, '-'))
		el->l_align = 1;
	if (ft_strchr(params, '#'))
		el->mod_hex = 1;
	if (ft_strchr(params, ' '))
		el->space = 1;
	if (ft_strchr(params, '+'))
		el->plus = 1;
	if (pf_get_zero(params))
		el->zero_fill = 1;
	el->min_width = pf_get_min_width(params);
	el->precision = pf_get_precision(params, el);
	return (el);
}

/*Копирует бонусные флаги из строки параметров printf и сдвигает указатель
 * на символ, находящийс после флагов. На вход подается строка с указателем
 * на симвлол, следующая сразу за %*/
char	*copy_bonus_flags(const char **params)
{
	int		i;
	char	*flags;
	char	*bonus_flags;

	bonus_flags = malloc(256);
	if (! bonus_flags)
		return (NULL);
	flags = ft_printf_flags;
	i = 0;
	while (ft_strchr(flags, **params))
		bonus_flags[i++] = *(*params)++;
	bonus_flags[i] = 0;
	return (bonus_flags);
}

/*Возвращает точность из строки формата printf*/
int pf_get_precision(char *str, s_flags *el)
{
	if (ft_strchr(str, '.'))
		el->precision_on = 1;
	while (*str != '.')
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (ft_atoi(++str));
}

/*Возвращает минимальную длину из строки формата printf*/
int pf_get_min_width(char *str)
{
	while (! ft_isdigit(*str) || *str == '0')
	{
		if (*str == '.' || *str == 0)
			return (0);
		str++;
	}
	return (ft_atoi(str));
}

/*Ищет флаг '0' в строке формата для print_f и возвращает указатель
* на него или NULL если ничего не находит */
const char *pf_get_zero(const char *str)
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

/*Создает элемент, содержащий список флагов printf и зануляет его*/
s_flags *create_sf_element(const char *params, char sym)
{
	s_flags	*el;

	if (params == NULL || *params == 0 || sym == 0)
		return (NULL);
	el = malloc(sizeof(s_flags));
	if (el == NULL)
		return (NULL);
	el->sym = 0;
	el->l_align = 0;
	el->min_width = 0;
	el->mod_hex = 0;
	el->precision = 0;
	el->precision_on = 0;
	el->space = 0;
	el->zero_fill = 0;
	return (el);
}

int	ft_printf(const char *input, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, input);
	while (*input)
	{
		if (*input == '%' && input++ != NULL)
			result += printer(copy_bonus_flags(&input), input, &params);
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