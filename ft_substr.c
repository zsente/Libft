/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:20 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/11 15:16:13 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	dst_size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dst_size = 0;
	if (s_len < start)
	{
		ptr = (char *)malloc(sizeof(char) * (dst_size + 1));
		ptr[0] = '\0';
		return (ptr);
	}
	else
		dst_size = s_len - start;
	if (dst_size > len)
		dst_size = len;
	ptr = (char *)malloc(sizeof(char) * (dst_size + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, dst_size + 1);
	return (ptr);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*final_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		start = 0;
		len = 0;
	}
	if (len > len_s - start)
		len = len_s - start;
	final_s = (char *) malloc (len * sizeof(char) + 1);
	if (!final_s)
		return (NULL);
	i = ft_strlcpy(final_s, &s[start], len + 1);
	while (i < len + 1)
	{
		final_s[i] = '\0';
		i++;
	}
	return (final_s);
}