/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:34:49 by btiewcha          #+#    #+#             */
/*   Updated: 2022/08/24 01:34:51 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_pstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
		i += ft_pchar(str[i]);
	return (i);
}

int	ft_pnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_pstr(num);
	free(num);
	return (len);
}

int	ft_ppercent(void)
{
	return (ft_pchar('%'));
}
