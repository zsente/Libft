/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:50 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/10 16:58:17 by zoesente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fct_nbword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
		}
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_last_res(char **res, int word)
{
	res[word] = NULL;
	return (res);
}

static char	**ft_free_res(char **res, int word)
{
	int	i;

	i = 0;
	while (i <= word)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**ft_fillres(char **res, char const *s, char c, int word_len)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			while (s[i + 1] && s[i + 1] != c)
			{
				i++;
				word_len++;
			}
			res[word] = (char *)malloc(sizeof(char) * (word_len + 2));
			if (!res[word])
				return (ft_free_res(res, word));
			res[word][word_len + 1] = '\0';
			ft_memcpy(res[word], &s[i - word_len], word_len + 1);
			word_len = 0;
			word++;
		}
		i++;
	}
	return (ft_last_res(res, word));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_nb;
	int		word_len;

	word_len = 0;
	if (!s)
		return (NULL);
	word_nb = fct_nbword(s, c);
	res = (char **)malloc(sizeof(char *) * (word_nb + 1));
	if (!res)
		return (NULL);
	return (ft_fillres(res, s, c, word_len));
}
