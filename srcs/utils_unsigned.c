/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:35:34 by btiewcha          #+#    #+#             */
/*   Updated: 2022/08/24 01:35:35 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_ui_toa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_punsigned(unsigned int n)
{
	int		print_length;
	char *num;

	print_length = 0;
	if ( n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_ui_toa(n);
		print_length += ft_pstr(num);
		free(num);
	}
	return (print_length);
}
