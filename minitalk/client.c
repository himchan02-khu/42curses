/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:54:52 by hchoo             #+#    #+#             */
/*   Updated: 2024/07/19 16:03:34 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *pid, char *str)
{
	int	save;

	save = 0;
	while (*pid >= '0' && *pid <= '9')
	{
		save = save * 10 + (*pid - 48);
		pid++;
	}
	while (!(*str >= 128 || *str <= 0))
		str++;
	if (*str || *pid)
		return (-1);
	else
		return (save);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1], argv[2]);
	if (pid == -1)
		return (0);
	printf("%d",pid);
	
	return (0);


}
