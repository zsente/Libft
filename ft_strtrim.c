/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:34:31 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:20:07 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_strcheck(s1[start], set))
		start++;
	while (end > start && ft_strcheck(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (i < end - start)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
