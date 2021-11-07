#include "./includes/bot.h"


int main(void)
{	
	t_plateau *plateau = init_plateau(6, 6);
	t_game g;
	g.finish = 0;
	g.nb_piece = 3;
	g.plateau = plateau;
	g.player = 2;
	t_plateau **posible = get_posibility(plateau, &g);
	posible = get_posibility(posible[0], &g);
	posible = get_posibility(posible[1], &g);
	posible = get_posibility(posible[2], &g);
	posible = get_posibility(posible[3], &g);
	posible = get_posibility(posible[4], &g);
	posible = get_posibility(posible[5], &g);
	posible = get_posibility(posible[0], &g);
	posible = get_posibility(posible[1], &g);
	posible = get_posibility(posible[3], &g);
	posible = get_posibility(posible[4], &g);
	print_map(posible[5]);
	t_lines *lines = search_line_hori(posible[5], &g);
	printf("%d\n", lines->nb_lines);
	printf("x=%d y=%d\n", lines->lines[0]->pos1->x, lines->lines[0]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[0]->pos2->x, lines->lines[0]->pos2->y);
	printf("x=%d y=%d\n", lines->lines[1]->pos1->x, lines->lines[1]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[1]->pos2->x, lines->lines[1]->pos2->y);
	printf("x=%d y=%d\n", lines->lines[2]->pos1->x, lines->lines[2]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[2]->pos2->x, lines->lines[2]->pos2->y);
	lines = search_line_vert(posible[5], &g);
	printf("%d\n", lines->nb_lines);
	printf("x=%d y=%d\n", lines->lines[0]->pos1->x, lines->lines[0]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[0]->pos2->x, lines->lines[0]->pos2->y);
	printf("x=%d y=%d\n", lines->lines[1]->pos1->x, lines->lines[1]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[1]->pos2->x, lines->lines[1]->pos2->y);
	printf("x=%d y=%d\n", lines->lines[2]->pos1->x, lines->lines[2]->pos1->y);
	printf("x=%d y=%d\n", lines->lines[2]->pos2->x, lines->lines[2]->pos2->y);
	return 0;
}