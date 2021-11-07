#include "./includes/bot.h"

t_plateau 	*init_plateau(int w, int h)
{
	t_plateau *p;
	unsigned short **map;
	size_t i;
	size_t j;

	p = malloc(sizeof(t_plateau));
	if (p == NULL)
		return(p);
	p->width = w;
	p->height = h;
	map = malloc(sizeof(unsigned short*)* h);
	i = -1;
	while (++i < h)
		map[i] = malloc(sizeof(unsigned short) * w);
	if (map == NULL)
	{
		free(p);
		return (NULL);
	}
	i = -1;
	while(++i < h)
	{
		j = -1;
		while(++j < w)
			map[i][j] = 0;
	}
	p->map = map;
	return (p);
}

void	init_game(t_game *g)
{
	scanf("%hu%hu%hu%hu%hu%hu", &g->plateau->width, &g->plateau->height, &g->nb_piece, &g->player, &g->total_time, &g->time_gain);
	g->plateau = init_plateau(g->plateau->width, g->plateau->height);
	g->finish = 0;
}

t_pos		*init_pos(int x, int y)
{
	t_pos *tmp;
	tmp = malloc(sizeof(t_pos));
	if (tmp == NULL)
		return (tmp);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

t_line		*init_line(t_pos *pos1, t_pos *pos2, unsigned short type)
{
	t_line *tmp;
	tmp = malloc(sizeof(t_line));
	if (tmp == NULL)
		return (tmp);
	tmp->pos1 = pos1;
	tmp->pos2 = pos2;
	tmp->width = sqrt(pow(pos2->x - pos1->x, 2)+ pow(pos2->y - pos1->y, 2));
	tmp->type = type;
	return (tmp);
}
void print_map(t_plateau *p)
{
	int i = -1;
	int j = -1;
	while (++i < p->height)
	{
		j = -1;
		while(++j < p->width)
			printf("%d ", p->map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void copy_map(t_plateau *dest, t_plateau *src)
{
	size_t i;
	size_t j;

	i = -1;
	while (++i < src->height)
	{
		j = -1;
		while (++j < src->width)
			dest->map[i][j] = src->map[i][j];
	}
}

