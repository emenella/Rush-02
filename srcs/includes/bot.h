#ifndef BOT_H
# define BOT_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_plateau
{
	int **map;
	int width;
	int height;
}		t_plateau;

typedef struct s_game
{
	t_plateau		*plateau;
	unsigned int	player;
	unsigned int	nb_piece; //for win
	unsigned int	finish;
}		t_game;

void	init_game(t_game &g);
void	start_game(t_game &g);
int		get_score()


#endif