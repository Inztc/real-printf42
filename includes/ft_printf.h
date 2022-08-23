/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:31:06 by btiewcha          #+#    #+#             */
/*   Updated: 2022/08/24 01:31:09 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_pchar(int c);
int	ft_pstr(char *str);
int	ft_ppointer(unsigned long ptr);
int	ft_pnbr(int n);
int	ft_punsigned(unsigned int n);
int	ft_phex(unsigned int num, const char format);
int	ft_ppercent(void);

#endif
