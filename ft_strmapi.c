/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:18:42 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:31:19 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!res)
		return (NULL);
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
