/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:28:11 by asusan            #+#    #+#             */
/*   Updated: 2019/08/07 15:28:13 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	char	*line;
	char	**map;
	t_att	attr;
	char	**figure;

	null(&line, &map, &figure);
	start_install(&attr);
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "exec") && attr.for_player == 1)
			give_me_players(line, &attr);
		if (ft_strstr(line, "Plateau"))
			give_me_map(&map, &attr, 1, line);
		if (ft_strstr(line, "Piece "))
			give_me_map(&figure, &attr, 0, line);
		if (figure != NULL)
		{
			install_on_the_map(map, figure, &attr);
			free_memory(&map);
			free_memory(&figure);
		}
		if (*line)
			ft_strdel(&line);
	}
}
