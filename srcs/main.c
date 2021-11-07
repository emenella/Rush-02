#include "./includes/bot.h"


int main(void)
{	
	t_plateau *plateau = init_plateau(4, 6);
	t_game g;
	g.finish = 0;
	g.nb_piece = 3;
	g.plateau = plateau;
	g.player = 1;
	t_plateau **posible = get_posibility(plateau, &g);
	posible = get_posibility(posible[1], &g);
	posible = get_posibility(posible[1], &g);
	posible = get_posibility(posible[2], &g);
	posible = get_posibility(posible[2], &g);
	posible = get_posibility(posible[0], &g);
	print_map(posible[1]);
	t_lines *lines = search_line_vert(posible[1], &g);
	printf("%d\n", lines->nb_lines);
	printf("%d\n", lines->lines[0]->width);
	return 0;
}