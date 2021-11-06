#include "./includes/bot.h"

t_line		*search_line_vert(t_plateau *tab, t_game *g)
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	temp_y;
	unsigned short player;
	unsigned short count_piece;
	t_pos			pos1;
	t_pos			pos2;

	y = 0;
	while (y < tab->height)
	{
		x = 0;
		while (x < tab->width)
		{
			printf("%d %d\n", y,x);
			if (tab->map[y][x] != 0)
			{
				temp_y = y;
				player = tab->map[y][x];
				count_piece = 0;
				while (tab->map[y][x] == player && y < tab->height)
				{
					if (count_piece == g->nb_piece)
					{
						pos1.x = x;
						pos1.y = y;
						result.pos1 = &pos1;
						pos2.x = x;
						pos2.y = temp_y;
						result.pos2 = &pos2;
						result.width = g->nb_piece;
						result.type = 2;
						return (init_line());
					}
					y++;
					count_piece++;
				}
				y = temp_y; 
			}
			x++;
		}
		y++;
	}
	return (NULL);
}


int main(void)
{	
	t_plateau *plateau = init_plateau(4 , 6);
	t_game game;
	game.finish = 0;
	game.plateau = plateau;
	game.nb_piece = 3;
	game.player = 1;
	t_line test_win_line = *search_line_vert(plateau, &game);
	printf("width : %d | type : %d", test_win_line.width, test_win_line.type);
	return 0;
}