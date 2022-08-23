/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:34:27 by btiewcha          #+#    #+#             */
/*   Updated: 2022/08/24 01:34:28 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	format(va_list args, const char ret)
{
	int	p_len;

	p_len = 0;
	if (ret == 'c')
		p_len += ft_pchar(va_arg(args, int));
	else if (ret == 's')
		p_len += ft_pstr(va_arg(args, char *));
	else if (ret == 'd' || ret == 'i')
		p_len += ft_pnbr(va_arg(args, int));
	else if (ret == 'x' || ret == 'X')
		p_len += ft_phex(va_arg(args, unsigned int), ret);
	else if (ret == 'u')
		p_len += ft_punsigned(va_arg(args, unsigned int));
	else if (ret == 'p')
		p_len += ft_ppointer(va_arg(args, unsigned long));
	else if (ret == '%')
		p_len += ft_ppercent();
	return (p_len);
}

int	ft_printf(const char *str, ...)
{
	int 		i;
	va_list	args;
	int	    len;
	
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += format(args, str[i + 1]);
			i++;
		}
		else
		{
			len += ft_pchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
