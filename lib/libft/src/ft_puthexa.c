/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:12:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/04 21:32:08 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(int n, char c)
{
	int		count;
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 0 && n < 16)
	{
		ft_putchar(base[n]);
		count++;
	}
	else
	{
		count += ft_puthexa(n / 16, c);
		count += ft_puthexa(n % 16, c);
	}
	return (count);
}
