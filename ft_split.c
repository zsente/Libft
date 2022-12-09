/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:33:50 by zoesente          #+#    #+#             */
/*   Updated: 2022/12/06 17:28:02 by zoesente         ###   ########.fr       */
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


static char **ft_free_tab(char **res, int word)
{
	int i; 

	i = 0; 

	while(i <= word)
	{
		free(res[i]);
		i++; 
	}
	free(res); 
	return(NULL);
}

/*static char	**ft_last_tab(char **tab, size_t j)
{
	tab[j] = NULL;
	return (tab);
}*/

/*static char	**ft_fill_tab(char const *s, char c, char **tab, size_t	cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		cnt = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i+1] != c && s[i+1])
			{
				cnt++;
				i++;
			}
			tab[j] = (char *) malloc(cnt * sizeof(char) + 2);
			if (!tab[j])
				return (ft_free_tab(tab, j));
			tab[j][cnt+1] = '\0';
			ft_memcpy(tab[j], &s[i - cnt], cnt +1);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}*/

static char	**ft_cutword(char **res, char const *s, char c, int word_nb, int word_len)
{
	int	i;
	int	word;
	word_nb = 0;
	word = 0 + word_nb;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i + 1] && s[i + 1] != c)
		{
			i++;
			word_len++;
		}
		res[word] = (char *)malloc(sizeof(char) * (word_len + 2));
		if (!res[word])
			return(ft_free_tab(res, word));
		res[word][word_len + 1] = '\0';
		ft_memcpy(res[word], &s[i - word_len], word_len + 1);
		word_len = 0;
		word++;
		i++; 
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_word;
	int		word_len; 

	word_len = 0; 
	if (!s)
		return (NULL);
	nb_word = fct_nbword(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!res)
		return (NULL);
	return (ft_cutword(res, s, c, nb_word, word_len));
	//return(ft_fill_tab(s, c, res, 0)); 
}

/*#include "libft.h"

static int	ft_len_tab(char const *s, char c)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 1;
	if (s[0] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i == 0)
			{
				while (s[i] == c)
				{
					if (!s[++i])
						return (1);
				}
			}
			else if (s[i + 1] && s[i +1] != c)
				cpt++;
		}
		i++;
	}
	return (cpt + 1);
}

static char	**ft_free_all(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_last_tab(char **tab, size_t j)
{
	tab[j] = NULL;
	return (tab);
}

static char	**ft_fill_tab(char const *s, char c, char **tab, size_t	cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		cnt = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + 1] != c && s[i + 1])
			{
				cnt++;
				i++;
			}
			tab[j] = (char *) malloc(cnt * sizeof(char) + 2);
			if (!tab[j])
				return (ft_free_all(tab, j));
			tab[j][cnt + 1] = '\0';
			ft_memcpy(tab[j], &s[i - cnt], cnt + 1);
			j++;
		}
		i++;
	}
	return (ft_last_tab(tab, j));
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (NULL);
	tab = (char **) malloc(ft_len_tab(s, c) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(s, c, tab, cnt));
}*/