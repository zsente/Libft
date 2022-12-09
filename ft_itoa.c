/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:10:13 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:29:54 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_signnb(int *n, int *temp, int *sign)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*temp = 1;
		*n *= -1;
		*sign = -1;
	}
	else if (*n < 0)
	{
		*temp = 0;
		*n *= -1;
		*sign = -1;
	}
	else
	{
		*temp = 0;
		*sign = 1;
	}
}

static int	ft_longnb(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static void	ft_putnb(char *str, int n, int digit_len, int temp)
{
	while (n > 9)
	{
		str[digit_len - 1] = (n % 10) + '0' + temp;
		n = n / 10;
		temp = 0;
		digit_len--;
	}
	str[digit_len - 1] = n + '0';
}

char	*ft_itoa(int n)
{
	int		digit_len;
	int		temp;
	int		sign;
	char	*str;

	ft_signnb(&n, &temp, &sign);
	digit_len = ft_longnb(n);
	if (sign == -1)
	{
		digit_len++;
		str = (char *)malloc(sizeof(char) * (digit_len + 1));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = (char *)malloc(sizeof (char) * (digit_len + 1));
		if (!str)
			return (NULL);
	}
	str[digit_len] = '\0';
	ft_putnb(str, n, digit_len, temp);
	return (str);
}
