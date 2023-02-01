#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}              t_data;

int	handle_no_event(void *event_data);
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);


#endif

