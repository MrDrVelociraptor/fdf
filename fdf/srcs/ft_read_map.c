/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:26:18 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/20 15:11:37 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	<stdio.h>
#include	"libft.h"
#include	<fcntl.h>

int	main(void)
{
	int		fd;
	char *line;

	fd = open("./test_maps/pylone.fdf", O_RDONLY);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
	}
	return (0);
}
