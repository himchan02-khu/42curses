/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:21:12 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/22 00:54:44 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char base)
{
	int	tf;
	int	index;
	int	count;

	count = 0;
	index = 0;
	tf = 0;
	while (str[index] != '\0')
	{
		if (str[index] == base && tf == 1)
		{
			count++;
			tf = 0;
		}
		else if (str[index] != base && tf == 0)
			tf = 1;
		index++;
	}
	if (tf == 1)
		return (count + 1);
	else
		return (count);
}

static int	find_index(char const *str, char base, int x_index, int s_e)
{
	int	index;

	index = 0;
	if (s_e == 1)
	{
		while (str[x_index + index] != '\0')
		{
			if (str[x_index + index] == base)
				index++;
			else
				break ;
		}
		return (x_index + index);
	}
	else
	{
		while (str[x_index + index] != '\0')
		{
			if (str[x_index + index] != base)
				index++;
			else
				break ;
		}
		return (x_index + index);
	}
}

static char	*add_strs(int start, int end, char *strs, char const *str)
{
	int	tmp_str;

	tmp_str = 0;
	while (tmp_str < end - start)
	{
		strs[tmp_str] = str[tmp_str + start];
		tmp_str++;
	}
	strs[tmp_str] = 0;
	return (strs);
}

static void	*free_split(char **split, int row)
{
	while (row >= 0)
		free(split[row--]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *str, char charset)
{
	char	**str_return;
	int		s_e_r_m[4];

	s_e_r_m[2] = 0;
	s_e_r_m[3] = count_word(str, charset);
	str_return = (char **)malloc(sizeof(char *) * (s_e_r_m[3] + 1));
	if (!(str_return))
	{
		free(str_return);
		return (NULL);
	}
	s_e_r_m[1] = 0;
	while (s_e_r_m[2] < s_e_r_m[3])
	{
		s_e_r_m[0] = find_index(str, charset, s_e_r_m[1], 1);
		s_e_r_m[1] = find_index(str, charset, s_e_r_m[0], 0);
		str_return[s_e_r_m[2]] = (char *)malloc(s_e_r_m[1] - s_e_r_m[0] + 1);
		if (!str_return[s_e_r_m[2]])
			return (free_split(str_return, s_e_r_m[2]));
		str_return[s_e_r_m[2]] = add_strs(s_e_r_m[0], s_e_r_m[1], \
			str_return[s_e_r_m[2]], str);
		s_e_r_m[2]++;
	}
	str_return[s_e_r_m[2]] = 0;
	return (str_return);
}
