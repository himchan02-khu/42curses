/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:59:31 by hyunjunl          #+#    #+#             */
/*   Updated: 2024/01/30 19:19:36 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

int	process_file(int fd)
{
	char	*content;
	int		len;
	char	**lines;

	content = read_file(fd);
	if (content == 0)
		return (1);
	len = ft_strlen(content);
	if (len == 0 || content[len - 1] != '\n')
	{
		free(content);
		return (1);
	}
	lines = ft_split(content, '\n');
	free(content);
	if (lines == 0 || !is_valid(lines))
	{
		free_strs(lines);
		return (1);
	}
	ft_strlcpy(lines[0], lines[0] + ft_strlen(lines[0]) - 3, 4);
	solve(lines, count_lines(lines + 1), ft_strlen(lines[1]));
	print_lines(lines + 1);
	free_strs(lines);
	return (0);
}

int	process(char *file_name)
{
	int	ret;
	int	fd;

	if (file_name)
		fd = open(file_name, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		return (1);
	ret = process_file(fd);
	close(fd);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i == 1 || i < argc)
	{
		if (process(argv[i]))
			ft_puterr();
		if (i++ < argc - 1)
			ft_putstr("\n");
	}
	return (0);
}
