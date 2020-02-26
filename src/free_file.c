/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:40:22 by asusan            #+#    #+#             */
/*   Updated: 2019/08/13 18:40:24 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_memory(char ***map)
{
	int i;

	i = 0;
	while ((*map)[i] != NULL)
	{
		ft_strdel(&((*map)[i]));
		i++;
	}
	free(*map);
	*map = NULL;
}

void	free_int(int ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i] != NULL)
		free((*arr)[i++]);
	free(*arr);
}

char	**copy(char ***map, t_att *attr, int ors)
{
	char	**arr;
	int		i;
	int		heigh;

	i = -1;
	if (ors == 1)
		heigh = attr->map_heigh;
	else
		heigh = attr->figure_heigh;
	if (!(arr = (char**)malloc(sizeof(char*) * (heigh + 1))))
		exit(1);
	arr[heigh] = NULL;
	while (++i != heigh)
		arr[i] = ft_strdup((*map)[i]);
	return (arr);
}

void	install(char *from, char **to, int ors)
{
	int i;

	i = 0;
	if (ors == 1)
	{
		from = ft_strstr(from, " ");
		(from)++;
	}
	while (*from != '\0')
	{
		(*to)[i] = *from;
		(from)++;
		i++;
	}
}

int		**free_memory_for_int(t_att attr, char **map)
{
	int	**arr;

	attr.i = -1;
	arr = (int**)malloc(sizeof(int*) * (attr.map_heigh + 1));
	arr[attr.map_heigh] = NULL;
	while (++attr.i != attr.map_heigh)
		arr[attr.i] = (int*)malloc(sizeof(int) * attr.map_width);
	attr.i = -1;
	while (arr[++attr.i] != NULL)
	{
		attr.j = -1;
		while (++attr.j != attr.map_width)
		{
			if (map[attr.i][attr.j] == attr.enemy
			|| map[attr.i][attr.j] == attr.enemy + 32)
				arr[attr.i][attr.j] = 1;
			else if (map[attr.i][attr.j] == '.' ||
			map[attr.i][attr.j] == attr.player ||
			map[attr.i][attr.j] == attr.player + 32)
				arr[attr.i][attr.j] = 0;
		}
	}
	return (arr);
}
