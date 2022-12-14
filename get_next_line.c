/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:30:34 by mthiry            #+#    #+#             */
/*   Updated: 2022/01/04 18:35:55 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_free_and_null(char	*args1, char	*args2)
{
	if (args1 && args2)
	{
		free(args1);
		free(args2);
	}
	else
		free(args1);
	return (NULL);
}

char	*ft_get_tmp(int fd, int rd, char	*buf, char	*save)
{
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		else if (!rd)
			break ;
		buf[rd] = '\0';
		save = ft_strjoin(save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (rd == 0 && &save[0] == '\0')
		return (NULL);
	return (save);
}

char	*ft_reading(int fd, char *save)
{
	int		rd;
	char	*buf;

	rd = 1;
	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	save = ft_get_tmp(fd, rd, buf, save);
	if (!save)
		return (ft_free_and_null(buf, NULL));
	free(buf);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	line = (char *) malloc (i + 2 * sizeof(char));
	if (!line)
		return (NULL);
	while (j != i)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*save = NULL;

	if (fd == -1)
		return (NULL);
	tmp = ft_reading(fd, save);
	if (!tmp)
		return (NULL);
	else if (tmp[0] == '\0')
		return (ft_free_and_null(tmp, NULL));
	line = ft_get_line(tmp);
	if (!line)
		return (ft_free_and_null(tmp, NULL));
	if (!ft_strchr(tmp, '\n'))
	{
		save = NULL;
		free(tmp);
		return (line);
	}
	save = ft_strdup(ft_strchr(tmp, '\n') + 1);
	if (!save)
		return (ft_free_and_null(tmp, line));
	free(tmp);
	return (line);
}

//#include <stdio.h>
//int	main(int argc, char **argv)
//{
//	char	*line;
//	int		fd;
//
//	(void)argc;
//	fd = open(argv[1], O_RDONLY);
//	
//	//(void)argv;
//	//fd = 0;
//
//	line = "";
//	for (int i = 1; line != NULL; i++)
//	{
//		line = get_next_line(fd);		
//		printf("Line %d: %s", i, line);
//	}
//	free(line);
//	close (fd);
//	return (0);
//} 
