#include "../../../includes/rubbish.h"

/* Sub function for ft_split_str */
static int	ft_split_low(char **split, char const *s, char c)
{
	char	*str;
	char	*word;
	int		len;
	int		i;

	str = (char *)s;
	i = 0;
	while (i < ft_nbr_wrd(s, c))
	{
		len = ft_nxt_len(str, c);
		if (len > 0)
		{
			word = malloc(sizeof(char) * (len + 1));
			if (word == NULL)
				return (i + 1);
			word = ft_fill_word(word, str, len);
			split[i] = word;
			str += len + 1;
			i++;
		}
		else
			str++;
	}
	split[ft_nbr_wrd(s, c)] = NULL;
	return (0);
}

//Splits a String into a 2D string array, taking quotes into account"
char	**ft_split_str(char const *s, char c)
{
	char	**split;
	int		err;
	int		i;

	if (!ft_nbr_wrd(s, c))
		return (NULL);
	split = malloc(sizeof(char *) * (ft_nbr_wrd(s, c) + 1));
	if (split == NULL)
		return (error(MEM, NULL, 2));
	err = ft_split_low(split, s, c);
	if (err)
	{
		i = 0;
		while (i < err - 1)
		{
			free(split[i]);
			i++;
		}
		free (split);
		return (error(MEM, NULL, 2));
	}
	return (split);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}
