/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:24:46 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/07 15:07:31 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static unsigned int	in_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static void	free_split(char **splitted)
{
	unsigned int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static unsigned int	count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;
	unsigned int	in;

	i = 0;
	words = 0;
	in = 0;
	while (s[i] && in_charset(s[i], c))
		i++;
	while (s[i])
	{
		if (!in_charset(s[i], c) && !in)
		{
			in = 1;
			words++;
		}
		else if (in_charset(s[i], c) && in)
			in = 0;
		i++;
	}
	return (words);
}

static char	*write_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	size;
	char			*word;

	size = 0;
	while (s[size] && !in_charset(s[size], c))
		size++;
	if (size == 0)
		return (NULL);
	word = malloc(sizeof(char) * (size + 1));
	if (word)
	{
		i = 0;
		while (i < size)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}

char	**split_string(char const *s, char c)
{
	unsigned int	words;
	unsigned int	i;
	unsigned int	word;
	char			**splitted;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	splitted = malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] && word < words)
	{
		while (s[i] && in_charset(s[i], c))
			i++;
		splitted[word] = write_word(s + i, c);
		if (!splitted[word])
			return (free_split(splitted), NULL);
		i += string_length(splitted[word]);
		word++;
	}
	splitted[words] = 0;
	return (splitted);
}
