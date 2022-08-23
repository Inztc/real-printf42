/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:35:06 by btiewcha          #+#    #+#             */
/*   Updated: 2022/08/24 01:35:08 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /=  16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, const char ret)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, ret);
		ft_put_hex(num % 16, ret);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (ret == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (ret == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	 ft_phex(unsigned int num, const char ret)
{
	if (num == 0)
		return (ft_pchar('0'));
	else
		ft_put_hex(num, ret);
	return (ft_hex_len(num));
}

