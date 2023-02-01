#include "../so_long.h"

int	main(void)
{
	t_data	data;
	void 	*img;

	// initialize the MLX Lib
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
 	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So long");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

	img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	handle_key_press();


	// keeps the window open through a loop
	mlx_loop(data.mlx);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}