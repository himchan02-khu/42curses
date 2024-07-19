/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaildator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:25:50 by hchoo             #+#    #+#             */
/*   Updated: 2023/08/09 00:34:28 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	check_height(char *str, int len, int height)
{
	--len;
	while (len >= 0)
	{
		if (height % 10 != str[len] - '0')
			return (0);
		height /= 10;
		--len;
	}
	return (height == 0);
}

int	check_line(char *line, int width, char empty, char obstacle)
{
	int	len;

	len = 0;
	while (line[len] == empty || line[len] == obstacle)
		++len;
	return (len == width && line[len] == '\0');
}

int	check_chrs(char *chrs)
{
	if (!ft_str_is_printable(chrs))
		return (0);
	if (chrs[0] == chrs[1] || chrs[1] == chrs[2] || chrs[2] == chrs[0])
		return (0);
	return (1);
}

int	is_valid(char **lines)
{
	int		first_len;
	int		width;
	int		row;
	char	empty;
	char	obstacle;

	if (lines[0] == 0 || lines[1] == 0)
		return (0);
	first_len = ft_strlen(lines[0]);
	if (first_len < 4 || !check_chrs(lines[0] + first_len - 3))
		return (0);
	empty = lines[0][first_len - 3];
	obstacle = lines[0][first_len - 2];
	row = 1;
	width = ft_strlen(lines[1]);
	if (width == 0)
		return (0);
	while (lines[row] && check_line(lines[row], width, empty, obstacle))
		++row;
	if (lines[row])
		return (0);
	return (check_height(lines[0], first_len - 3, row - 1));
}
