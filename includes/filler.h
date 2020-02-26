/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asusan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:29:09 by asusan            #+#    #+#             */
/*   Updated: 2019/08/07 15:29:11 by asusan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# include "../includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct			s_att
{
	int					map_heigh;
	int					map_width;

	int					figure_heigh;
	int					figure_width;
	int					figure_left;
	int					figure_up;

	char				player;
	int					for_player;

	int					result_i;
	int					result_j;

	int					i;
	int					j;

	int					sum;

	char				enemy;
}						t_att;

char					**return_free_list(char **a, t_att *attr, char symbol);
void					free_memory(char ***map);
void					free_int(int ***arr);
char					**copy(char ***map, t_att *attr, int ors);
void					install(char *from, char **to, int ors);
void					change_map(int ***arr, t_att *attr, int inst);
void					change_map_2(int ***arr, t_att *attr, char **map);
int						**free_memory_for_int(t_att attr, char **map);
void					give_me_players(char *line, t_att *attr);
void					input_map(char ***map, t_att *attr, int ors);
void					give_me_map(char ***map,
		t_att *attr, int ors, char *line);
void					install_on_the_map(char **map,
		char **figure, t_att *attr);
void					start_install(t_att *attr);
void					null(char **line, char ***map, char ***figure);
void					output(t_att *attr, int result, int ***arr);

#endif
