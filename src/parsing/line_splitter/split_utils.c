#include "../../../includes/rubbish.h"

// 'move to quote'
// move 'i' to the next quote found in s
void	ft_mtoq(char const *s, unsigned int *i)
{
	char			quote;

	if (s[*i] == '\"' || s[*i] == '\'')
	{
		quote = s[*i];
		(*i)++;
		while (s[*i])
		{
			if (s[*i] == quote)
				break ;
			(*i)++;
		}
	}
}

//Returns the number of different words you have in s
int	ft_nbr_wrd(char const *s, char c)
{
	unsigned int	i;
	unsigned int	flag;
	int				num;

	i = 0;
	flag = 0;
	num = 0;
	while (s[i])
	{
		ft_mtoq(s, &i);
		if (s[i] != c)
			flag = 1;
		else if (flag && s[i] == c)
		{
			num++;
			flag = 0;
		}
		i++;
	}
	if (flag)
		num++;
	return (num);
}

//Returns the length of the next word
int	ft_nxt_len(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		ft_mtoq(s, &i);
		i++;
	}
	return (i);
}

//Fills the wrd string with str and a specific length
char	*ft_fill_word(char *wrd, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		wrd[i] = str[i];
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}
