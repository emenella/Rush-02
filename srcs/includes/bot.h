#ifndef BOT_H
# define BOT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

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
	unsigned short	total_time;
	unsigned short	time_gain;
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

typedef struct s_lines
{
	t_line	**lines;
	int		nb_lines;
}		t_lines;


void		init_game(t_game *g);
t_pos		*init_pos(int x, int y);
t_line		*init_line(t_pos *pos1, t_pos *pos2, unsigned short type);
int			get_score(unsigned short player_id, t_plateau *tab);
t_plateau	**get_posibility(t_plateau *tab, t_game *g);
t_plateau 	*init_plateau(int w, int h);
t_lines		*search_line_vert(t_plateau *tab, t_game *g);
int			search_open(t_line *l, t_game *g);
void		print_map(t_plateau *p);
void		copy_map(t_plateau *dest, t_plateau *src);
t_lines		*search_line_hori(t_plateau *tab, t_game *g);
t_lines		*search_line_diag(t_plateau *tab, t_game *g);
void		going_to_diag(t_plateau *tab, t_game *g, unsigned short x, unsigned short y, t_lines *result, int *nb_lines);
void		going_to_diag2(t_plateau *tab, t_game *g, unsigned short x, unsigned short y, t_lines *result, int *nb_lines);


#endif