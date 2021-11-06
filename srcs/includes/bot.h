#ifndef BOT_H
# define BOT_H
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
#include  <stdlib.h>

typedef struct s_plateau
{
	unsigned short **map;
	unsigned short width;
	unsigned short height;
}		t_plateau;

typedef struct s_game
{
	t_plateau		*plateau;
	unsigned short	player;
	unsigned short	nb_piece; //for win
	unsigned short	finish;
}		t_game;

typedef struct s_pos
{
	int x;
	int y;
}		t_pos;

typedef struct s_line
{
	t_pos	*pos1;
	t_pos	*pos2;
	int		width;
	int		type;
}		t_line;


void		init_game(t_game *g);
t_pos		*init_pos(int x, int y);
t_line		*init_line(t_pos *pos1, t_pos *pos2, unsigned short width, unsigned short type);
int			get_score(unsigned short player_id, t_plateau *tab);
t_plateau	*get_posibility(t_plateau *tab, t_game *g);
t_plateau 	*init_plateau(int w, int h);
t_line		*search_line_vert(t_plateau *tab, t_game *g);
int			search_open(t_line *l, t_game *g);


#endif