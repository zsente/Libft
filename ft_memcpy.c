/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:53:18 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/03 23:30:03 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_char;
	char	*src_char;
	size_t	i;

	i = 0;
	dst_char = (char *)dst;
	src_char = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
