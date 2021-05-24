/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:02 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:04 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_cube *c)
{
	if (key == (int)KEY_W)
		c->mov.up = 1;
	else if (key == (int)KEY_A)
		c->mov.left = 1;
	else if (key == (int)KEY_S)
		c->mov.down = 1;
	else if (key == (int)KEY_D)
		c->mov.right = 1;
	else if (key == (int)KEY_RIGHT)
		c->view.right = 1;
	else if (key == (int)KEY_LEFT)
		c->view.left = 1;
	else if (key == (int)KEY_ESCAPE)
		exit_success(c);
	return (1);
}

int	key_release(int key, t_cube *c)
{
	if (key == (int)KEY_W)
		c->mov.up = 0;
	else if (key == (int)KEY_A)
		c->mov.left = 0;
	else if (key == (int)KEY_S)
		c->mov.down = 0;
	else if (key == (int)KEY_D)
		c->mov.right = 0;
	else if (key == (int)KEY_RIGHT)
		c->view.right = 0;
	else if (key == (int)KEY_LEFT)
		c->view.left = 0;
	else if (key == (int)KEY_ESCAPE)
		exit_success(c);
	return (1);
}

int	exit_success(t_cube *c)
{
	exit_program(c, "Closing program...\n", 0);
	return (0);
}

static void	destroy_textures(t_cube *c)
{
	if (c->wall[N].img)
		mlx_destroy_image(c->lib.mlx, c->wall[N].img);
	if (c->wall[S].img)
		mlx_destroy_image(c->lib.mlx, c->wall[S].img);
	if (c->wall[W].img)
		mlx_destroy_image(c->lib.mlx, c->wall[W].img);
	if (c->wall[E].img)
		mlx_destroy_image(c->lib.mlx, c->wall[E].img);
	if (c->spr.img)
		mlx_destroy_image(c->lib.mlx, c->spr.img);
	if (c->tex.n)
		free(c->tex.n);
	if (c->tex.s)
		free(c->tex.s);
	if (c->tex.e)
		free(c->tex.e);
	if (c->tex.w)
		free(c->tex.w);
	if (c->tex.spr)
		free(c->tex.spr);
	free_map(c);
}

void	exit_program(t_cube *c, char *str, int error)
{
	int	len;

	len = ft_strlen(str);
	if (error)
		write(1, "Error\n", 6);
	if (!str)
		perror("");
	else
		write(1, str, len);
	if (c != NULL)
	{
		if (c->lib.mlx_win)
			mlx_destroy_window(c->lib.mlx, c->lib.mlx_win);
		if (c->win.img)
			mlx_destroy_image(c->lib.mlx, c->win.img);
		destroy_textures(c);
		if (c->line != NULL)
			free(c->line);
		if (c->spr_p)
			free(c->spr_p);
		if (c->r.l)
			free(c->r.l);
	}
	exit(1);
}
