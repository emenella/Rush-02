#include "./includes/bot.h"

void		start_game(t_game *g)
{

}

int			get_score(unsigned short player_id, t_plateau *tab)
{
	search_line(tab);
}

t_plateau	*get_posibility(t_plateau *tab, t_game *g)
{
	unsigned short	i;
	unsigned short	j;
	int				lenght;
	t_plateau		*posibility;
	t_plateau		temp;

	lenght = 0;
	i = 0;
	temp = *tab;
	posibility =  malloc(sizeof(t_plateau) * (int)tab->height);
	if (posibility == NULL)
		return (NULL);
	while (i < tab->width)
	{
		j = 0;
		while (j < tab->height)
		{
			if (tab->map[i][j] == 0 && (tab->map[i][j + 1] != 0 || j == tab->height))
			{
				temp.map[i][j] = g->player;
				posibility[lenght] = temp;
				temp = *tab;
				lenght++;
			}
			j++;
		}
		i++;
	}
	return (posibility);
}

t_line		*search_line_vert(t_plateau *tab, t_game *g)
{
	unsigned short	i;
	unsigned short	j;
	unsigned short	temp_j;
	unsigned short player;
	unsigned short count_piece;
	t_line			result;
	t_pos			pos1;
	t_pos			pos2;

	i = 0;

	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			if (tab->map[i][j] != 0)
			{
				temp_j = j;
				player = tab->map[i][j];
				count_piece = 0;
				while (tab->map[i][j] == player && j < tab->height)
				{
					if (count_piece == g->nb_piece)
					{
						pos1.x = i;
						pos1.y = j;
						result.pos1 = &pos1;
						pos2.x = i;
						pos2.y = temp_j;
						result.pos2 = &pos2;
						result.width = g->nb_piece;
						result.type = 2;
						return (&result);
					}
					
					j++;
					count_piece++;
				}
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	search_open(t_line *l, t_game *g)
{
	int result;
	t_pos pos_pos1[2];
	t_pos pos_pos2[2];

	if (l->type == 1)
	{
		if (l->pos1->x > 0)
		{
			pos_pos1[0].x = l->pos1->x - 1;
			pos_pos1[0].y = l->pos1->y;
			pos_pos1[1].y = pos_pos1[0].y - 1;
			pos_pos1[1].x = pos_pos1[0].x;
		}
		if (l->pos2->x < g->plateau->width - 1)
		{
			pos_pos2[0].x =l->pos1->x + 1;
			pos_pos2[0].y = l->pos1->y;
			pos_pos1[1].y = pos_pos1[0].y - 1;
			pos_pos1[1].x = pos_pos1[0].x;
		}
		if (&& g->plateau->map[pos_pos1[1].y][pos_pos1[1].x] == g->player)
			result++;
		if (g->plateau->map[pos_pos2[1].y][pos_pos2[1].x] == g->player)
			result++;
	}
	else if (l->type == 2)
	{
		if (l->pos1->y > 0 && g->plateau->map[l->pos1->y - 1][l->pos1->x] == 0)
		{
			result[0]->x = l->pos1->x;
			result[0]->y = l->pos1->y - 1;
		}
		return (1);
	}
	else if (l->type == 3)
	{
		if (l->pos1->x > 0 && l->pos1->y < g->plateau->height - 1)
		{
			pos_pos1[0].x = l->pos1->x - 1;
			pos_pos1[0].y = l->pos1->y + 1;
			pos_pos1[1].y = pos_pos1[0].y - 1;
			pos_pos1[1].x = pos_pos1[0].x;
		}
		
	}
	else if (l->type == 4)
	{
		
	}
	
	return (result);
}
