/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:20:45 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:21:22 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s_len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_len = s1_len + s2_len;
	s = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, s1_len + 1);
	ft_strlcat(s, s2, s_len + 1);
	return (s);
}
