#include "./includes/bot.h"

void		start_game(t_game *g)
{

}

int			get_score(unsigned short player_id, t_plateau *tab)
{

}

t_plateau	**get_posibility(t_plateau *tab, t_game *g)
{
	unsigned short i;
	unsigned short j;
	t_plateau *tmp;
	t_plateau **result;

	i = -1;
	result = malloc(sizeof(t_plateau*) * g->plateau->width);
	while (++i < tab->width)
		if (tab->map[0][i] == 0)
		{
			j = -1;
			while (++j < tab->height - 1 && (tab->map[j + 1][i] != 1 && tab->map[j + 1][i] != 2));
			tmp = init_plateau(g->plateau->width, g->plateau->height);
			if (tmp == NULL)
			{
				free(result);
				return (NULL);
			}
			copy_map(tmp, tab);
			tmp->map[j][i] = g->player;
			result[i] = tmp;

		}
		else
			result[i] = NULL;
	return(result);
}

t_lines		*search_line_vert(t_plateau *tab, t_game *g)
{
	unsigned short i;
	unsigned short j;
	unsigned short posX;
	unsigned short posY;
	unsigned short nb_lines;
	t_lines *result;

	i = -1;
	nb_lines = 0;
	result = malloc(sizeof(t_lines));
	result->lines = malloc(sizeof(t_line*) * tab->height);
	while(++i < tab->width)
	{
		j = -1;
		while (++j < tab->height)
			if(tab->map[j][i] == g->player)
			{
				posX = i;
				posY = j;
				while(j < tab->height && tab->map[j++][i] == g->player);
				if (posX != i || posY != --j)
					result->lines[nb_lines++] = init_line(init_pos(posX, posY), init_pos(i, j), 1);
			}
	}
	result->nb_lines = nb_lines;
	return (result);
}

t_lines		*search_line_hori(t_plateau *tab, t_game *g)
{
	unsigned short i;
	unsigned short j;
	unsigned short posX;
	unsigned short posY;
	unsigned short nb_lines;
	t_lines *result;

	i = -1;
	nb_lines = 0;
	result = malloc(sizeof(t_lines));
	result->lines = malloc(sizeof(t_line*) * tab->height);
	print_map(tab);
	while(++i < tab->height)
	{
		j = -1;
		while (++j < tab->width)
			if(tab->map[i][j] == g->player)
			{
				posX = j;
				posY = i;
				while(j < tab->width && tab->map[i][j++] == g->player);
				if (posX != --j || posY != i)
					result->lines[nb_lines++] = init_line(init_pos(posX, posY), init_pos(j, i), 2);
			}
	}
	result->nb_lines = nb_lines;
	return (result);
}

t_lines		*search_line_diag(t_plateau *tab, t_game *g)
{
	unsigned short	i;
	int				nb_lines;
	t_lines			*result;

	nb_lines = 0;
	result = malloc(sizeof(t_lines));
	if (tab->height > tab->width)
		result->lines = malloc(sizeof(t_line*) * ((tab->height - 1) * 2));
	if (tab->height < tab->width)
		result->lines = malloc(sizeof(t_line*) * ((tab->width - 1) * 2));
	else
		result->lines = malloc(sizeof(t_line*) * (4 * tab->width - 6));
	i = -1;
	while (++i < tab->width)
		going_to_diag(tab, g, i, 0, result, &nb_lines);
	i = 0;
	while (++i < tab->height)
		going_to_diag(tab, g, 0, i, result, &nb_lines);
	i = -1;
	while(++i < tab->height)
		going_to_diag2(tab, g, tab->width - 1, i, result, &nb_lines);
	i = tab->width;
	while (--i != 0);
		going_to_diag2(tab, g, i, 0, result, &nb_lines);
	result->nb_lines = nb_lines;
	return (result);
}

void	going_to_diag(t_plateau *tab, t_game *g, unsigned short x, unsigned short y, t_lines *result, int *nb_lines)
{
	unsigned short	posX;
	unsigned short	posY;

	printf("start: x=%d y=%d\n", x, y);
	while (x < tab->width && y < tab->height)
	{
		printf("x=%d y=%d\n", x, y);
		if (x < tab->width - 1 && y < tab->height - 1 && tab->map[y][x] == g->player)
		{
			posX = x;
			posY = y; 
			while (x < tab->width - 1 && y < tab->height - 1 && tab->map[y++][x++] == g->player);
			if (posX != x || posY != y)
					result->lines[(*nb_lines)++] = init_line(init_pos(posX, posY), init_pos(x, y), 4);
		}
		else
		{
			x++;
			y++;
		}
	}

}

void	going_to_diag2(t_plateau *tab, t_game *g, unsigned short x, unsigned short y, t_lines *result, int *nb_lines)
{
	unsigned short	posX;
	unsigned short	posY;

	while (x > 0 && y < tab->height)
	{
		if (x != 0 && y < tab->height - 1 && tab->map[y][x] == g->player)
		{
			posX = x;
			posY = y; 
			while (x != 0 && y < tab->height - 1 && tab->map[y++][x--] == g->player);
			if (posX != x && posY != y)
					result->lines[(*nb_lines)++] = init_line(init_pos(x, y), init_pos(posX, posY), 3);
		}
		else
		{
			x--;
			y++;
		}
	}

}

int	search_open(t_line *l, t_game *g)
{
	int result = 0;
	t_pos pos_pos1[2];
	t_pos pos_pos2[2];

	if (l->type == 1)
	{
		if (l->pos1->x > 0)
		{
			pos_pos1[0].x = l->pos1->x - 1;
			pos_pos1[0].y = l->pos1->y;
			pos_pos1[1].y = pos_pos1[0].y + 1;
			pos_pos1[1].x = pos_pos1[0].x;
			if (pos_pos1[1].x < g->plateau->width || pos_pos1[1].x < g->plateau->width || g->plateau->map[pos_pos1[1].y][pos_pos1[1].x] == g->player)
				result++;
		}
		if (l->pos2->x < g->plateau->width - 1)
		{
			pos_pos2[0].x =l->pos1->x + 1;
			pos_pos2[0].y = l->pos1->y;
			pos_pos2[1].y = pos_pos2[0].y + 1;
			pos_pos2[1].x = pos_pos2[0].x;
			if (pos_pos2[1].x < g->plateau->width || pos_pos2[1].x < g->plateau->width || g->plateau->map[pos_pos2[1].y][pos_pos2[1].x] == g->player)
				result++;
		}
	}
	else if (l->type == 2)
	{
		if (l->pos1->y > 0 && g->plateau->map[l->pos1->y - 1][l->pos1->x] == 0)
			result++;
		return (1);
	}
	else if (l->type == 3)
	{
		if (l->pos1->x > 0 && l->pos1->y < g->plateau->height - 1)
		{
			pos_pos1[0].x = l->pos1->x - 1;
			pos_pos1[0].y = l->pos1->y + 1;
			pos_pos1[1].y = pos_pos1[0].y + 1;
			pos_pos1[1].x = pos_pos1[0].x;
			if (pos_pos1[1].x < g->plateau->width || pos_pos1[1].x < g->plateau->width || g->plateau->map[pos_pos1[1].y][pos_pos1[1].x] == g->player)
				result++;
		}
		if (l->pos2->x < g->plateau->width - 1 && l->pos2->y > 0)
		{
			pos_pos2[0].x = l->pos2->x + 1;
			pos_pos2[0].y = l->pos2->y - 1;
			pos_pos2[1].y = pos_pos2[0].y + 1;
			pos_pos2[1].x = pos_pos2[0].x;
			if (pos_pos2[1].x < g->plateau->width && pos_pos2[1].x < g->plateau->width && g->plateau->map[pos_pos2[1].y][pos_pos2[1].x] == g->player)
				result++;
		}
		
	}
	else if (l->type == 4)
	{
		if (l->pos1->x > 0 && l->pos1->y > 0)
		{
			pos_pos1[0].x = l->pos1->x - 1;
			pos_pos1[0].y = l->pos1->y - 1;
			pos_pos1[1].y = pos_pos1[0].y + 1;
			pos_pos1[1].x = pos_pos1[0].x;
			if (g->plateau->map[pos_pos1[1].y][pos_pos1[1].x] == g->player)
				result++;
		}
		if (l->pos2->x < g->plateau->width - 1 && l->pos2->y < g->plateau->height)
		{
			pos_pos2[0].x = l->pos2->x + 1;
			pos_pos2[0].y = l->pos2->y + 1;
			pos_pos2[1].x = pos_pos2[0].x;
			pos_pos2[1].y = pos_pos2[0].y + 1;
			if (pos_pos2[1].x < g->plateau->width && pos_pos2[1].y < g->plateau->height && g->plateau->map[pos_pos2[1].y][pos_pos2[1].x] == g->player)
				result++;
		}
	}
	return (result);
}
