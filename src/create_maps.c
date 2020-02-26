/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:49:57 by asusan            #+#    #+#             */
/*   Updated: 2019/08/13 18:49:58 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	install_heigh(int ors, t_att *attr, int i)
{
	if (ors == 1)
		attr->map_heigh = i;
	else
		attr->figure_heigh = i;
}

void	install_width(int ors, t_att *attr, int j)
{
	if (ors == 1)
		attr->map_width = j;
	else
		attr->figure_width = j;
}

void	input_map(char ***map, t_att *attr, int ors)
{
	char **arr;
	char *line;

	if (ors == 1)
		attr->j = attr->map_heigh;
	else
		attr->j = attr->figure_heigh;
	attr->i = 0;
	while (attr->i < attr->j)
	{
		get_next_line(0, &(line));
		if ((((line)[0] == '0' || (line)[0] == '1') &&
		ft_strstr(line, " ")) || ors == 0)
			install(line, &(*map)[attr->i++], ors);
		if (*line != '\0')
			ft_strdel(&line);
	}
	if (ors == 0)
	{
		arr = copy(map, attr, ors);
		free_memory(map);
		*map = return_free_list(arr, attr, '*');
		free_memory(&arr);
	}
}

void	maps_borning(int i, char ***map, int j)
{
	int k;
	int x;

	k = 0;
	while (k != i)
	{
		(*map)[k] = (char*)malloc(j + 1);
		(*map)[k][j] = '\0';
		k++;
	}
	(*map)[k] = NULL;
	x = j;
	k = 0;
	while (k != i)
	{
		j = 0;
		while (x != j)
		{
			(*map)[k][j] = '.';
			j++;
		}
		k++;
	}
}

void	give_me_map(char ***map, t_att *attr, int ors, char *line)
{
	int i;
	int j;

	if (*map != NULL)
		free_memory(map);
	if (ors == 1 && (line[0] > '9' || line[0] < '0'))
		line += 8;
	else
		line += 6;
	i = ft_atoi(line);
	install_heigh(ors, attr, i);
	*map = (char**)malloc(sizeof(char*) * (i + 1));
	while (*line != ' ')
		(line)++;
	j = ft_atoi(line);
	install_width(ors, attr, j);
	maps_borning(i, map, j);
	input_map(map, attr, ors);
}
