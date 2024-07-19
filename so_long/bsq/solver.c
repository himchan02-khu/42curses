/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:21:40 by hyunjunl          #+#    #+#             */
/*   Updated: 2023/08/09 17:01:21 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "bsq.h"

void	update_result(int *dp, int width, int row, t_result *res)
{
	int	i;

	i = width - 1;
	while (i >= 0)
	{
		if (res->size <= dp[i])
		{
			res->size = dp[i];
			res->x = row;
			res->y = i;
		}
		--i;
	}
}

t_result	solve_with_dp(char **lines, int **dp, int height, int width)
{
	t_result	res;
	int			row;
	int			col;
	int			*tmp;

	res.size = 0;
	row = height;
	while (row > 0)
	{
		dp[0][width - 1] = (lines[row][width - 1] == lines[0][0]);
		col = width - 2;
		while (col >= 0)
		{
			dp[0][col] = min(dp[0][col + 1], dp[1][col], dp[1][col + 1]) + 1;
			if (lines[row][col] == lines[0][1])
				dp[0][col] = 0;
			--col;
		}
		update_result(dp[0], width, row--, &res);
		tmp = dp[0];
		dp[0] = dp[1];
		dp[1] = tmp;
	}
	return (res);
}

void	fill_square(char **lines, t_result res)
{
	int	i;
	int	j;

	i = 0;
	while (i < res.size)
	{
		j = 0;
		while (j < res.size)
		{
			lines[res.x + i][res.y + j] = lines[0][2];
			++j;
		}
		++i;
	}
}

void	solve(char **lines, int height, int width)
{
	int			*dp[2];
	t_result	res;

	dp[0] = alloc_int_arr(width);
	dp[1] = alloc_int_arr(width);
	if (dp[0] == 0 || dp[1] == 0)
	{
		free(dp[0]);
		free(dp[1]);
		return ;
	}
	res = solve_with_dp(lines, dp, height, width);
	free(dp[0]);
	free(dp[1]);
	fill_square(lines, res);
}
