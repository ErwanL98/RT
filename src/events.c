	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   events.c                                           :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2017/06/22 15:52:34 by ele-cren          #+#    #+#             */
	/*   Updated: 2017/06/27 14:34:17 by ele-cren         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include <rt.h>

void	ft_event(t_env *env)
{
	if (env->set.tab == INTERFACE)
		ft_ev_inter(env);
	else if (env->set.tab == OBJECTS)
		ft_ev_obj(env);
	else if (env->set.tab == ATTRIBUTES)
		ft_ev_at(env);
	else if (env->set.tab == POSTAB)
		ft_ev_pos(env);
	else if (env->set.tab == DIRTAB)
		ft_ev_dir(env);
	else if (env->set.tab == COLTAB)
		ft_ev_col(env);
}

void	ft_ev_col(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
		env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
		env->set.select + 9 : env->set.select - 3;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.select == 2 || env->set.select == 3)
		{
			env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : env->set.inc / 2;
			env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
			env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
		}
		if (env->set.select == 5 || env->set.select == 6)
		{
			if ((env->set.select == 5 && env->set.obj[3]->color.red < 255) || \
				(env->set.select == 6 && env->set.obj[3]->color.red > 0))
			{
				env->set.obj[3]->color.red = (env->set.select == 5) ? env->set.obj[3]->color.red + \
					env->set.inc : env->set.obj[3]->color.red - env->set.inc;
				env->set.obj[3]->color.red = (env->set.obj[3]->color.red >= 255) ? 255 : env->set.obj[3]->color.red;
				env->set.obj[3]->color.red = (env->set.obj[3]->color.red <= 0) ? 0 : env->set.obj[3]->color.red;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
			}
		}
		if (env->set.select == 8 || env->set.select == 9)
		{
			if ((env->set.select == 8 && env->set.obj[3]->color.green < 255) || \
				(env->set.select == 9 && env->set.obj[3]->color.green > 0))
			{
				env->set.obj[3]->color.green = (env->set.select == 8) ? env->set.obj[3]->color.green + \
					env->set.inc : env->set.obj[3]->color.green - env->set.inc;
				env->set.obj[3]->color.green = (env->set.obj[3]->color.green >= 255) ? 255 : env->set.obj[3]->color.green;
				env->set.obj[3]->color.green = (env->set.obj[3]->color.green <= 0) ? 0 : env->set.obj[3]->color.green;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
			}
		}
		if (env->set.select == 11 || env->set.select == 12)
		{
			if ((env->set.select == 11 && env->set.obj[3]->color.blue < 255) || \
				(env->set.select == 12 && env->set.obj[3]->color.blue > 0))
			{
				env->set.obj[3]->color.blue = (env->set.select == 11) ? env->set.obj[3]->color.blue + \
					env->set.inc : env->set.obj[3]->color.blue - env->set.inc;
				env->set.obj[3]->color.blue = (env->set.obj[3]->color.blue >= 255) ? 255 : env->set.obj[3]->color.blue;
				env->set.obj[3]->color.blue = (env->set.obj[3]->color.blue <= 0) ? 0 : env->set.obj[3]->color.blue;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
			}
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.inc = 1;
		env->set.tab = ATTRIBUTES;
	}
}

void	ft_ev_pos(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
		env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
		env->set.select + 9 : env->set.select - 3;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.select == 2 || env->set.select == 3)
		{
			env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : env->set.inc / 2;
			env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
			env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
		}
		if (env->set.select == 5 || env->set.select == 6)
		{
			env->set.obj[3]->pos.x = (env->set.select == 5) ? env->set.obj[3]->pos.x + \
				env->set.inc : env->set.obj[3]->pos.x - env->set.inc;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
		if (env->set.select == 8 || env->set.select == 9)
		{
			env->set.obj[3]->pos.y = (env->set.select == 8) ? env->set.obj[3]->pos.y + \
				env->set.inc : env->set.obj[3]->pos.y - env->set.inc;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
		if (env->set.select == 11 || env->set.select == 12)
		{
			env->set.obj[3]->pos.z = (env->set.select == 11) ? env->set.obj[3]->pos.z + \
				env->set.inc : env->set.obj[3]->pos.z - env->set.inc;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.inc = 1;
		env->set.tab = ATTRIBUTES;
	}
}

void	ft_ev_dir(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
			env->set.select == 5 || env->set.select == 6 || \
			env->set.select == 8 || env->set.select == 9 || \
			env->set.select == 11 || env->set.select == 12)
				env->set.select = (env->set.select == 2 || \
				env->set.select == 5 || env->set.select == 8 || \
				env->set.select == 11) ? env->set.select + 1 \
				: env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 11 || env->set.select == 12) ? \
		env->set.select - 9 : env->set.select + 3;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 2 || env->set.select == 3) ? \
		env->set.select + 9 : env->set.select - 3;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.select == 2 || env->set.select == 3)
		{
			env->set.inc = (env->set.select == 2) ? env->set.inc * 2 : env->set.inc / 2;
			env->set.inc = (env->set.inc >= 100) ? 100 : env->set.inc;
			env->set.inc = (env->set.inc <= 1) ? 1 : env->set.inc;
		}
		if (env->set.select == 5 || env->set.select == 6)
		{
			env->set.obj[3]->angles.x = (env->set.select == 5) ? env->set.obj[3]->angles.x + \
				env->set.inc : env->set.obj[3]->angles.x - env->set.inc;
			env->set.obj[3]->angles.x = (env->set.obj[3]->angles.x >= 360) ? \
				env->set.obj[3]->angles.x - 360 : env->set.obj[3]->angles.x;
			env->set.obj[3]->angles.x = (env->set.obj[3]->angles.x <= -360) ? \
				env->set.obj[3]->angles.x + 360 : env->set.obj[3]->angles.x;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
		if (env->set.select == 8 || env->set.select == 9)
		{
			env->set.obj[3]->angles.y = (env->set.select == 8) ? env->set.obj[3]->angles.y + \
				env->set.inc : env->set.obj[3]->angles.y - env->set.inc;
			env->set.obj[3]->angles.y = (env->set.obj[3]->angles.y >= 360) ? \
				env->set.obj[3]->angles.y - 360 : env->set.obj[3]->angles.y;
			env->set.obj[3]->angles.y = (env->set.obj[3]->angles.y <= -360) ? \
				env->set.obj[3]->angles.y + 360 : env->set.obj[3]->angles.y;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
		if (env->set.select == 11 || env->set.select == 12)
		{
			env->set.obj[3]->angles.z = (env->set.select == 11) ? env->set.obj[3]->angles.z + \
				env->set.inc : env->set.obj[3]->angles.z - env->set.inc;
			env->set.obj[3]->angles.z = (env->set.obj[3]->angles.z >= 360) ? \
				env->set.obj[3]->angles.z - 360 : env->set.obj[3]->angles.z;
			env->set.obj[3]->angles.z = (env->set.obj[3]->angles.z <= -360) ? \
				env->set.obj[3]->angles.z + 360 : env->set.obj[3]->angles.z;
			SDL_DestroyTexture(env->sdl.draw);
			ft_browse_pixels(env);
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.inc = 1;
		env->set.select = 1;
		env->set.tab = ATTRIBUTES;
	}
}

void	ft_ev_obj(t_env *env)
{
	int		i;

	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == (env->set.nb[2] - \
			env->set.nb[0])) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 1) ? (env->set.nb[2] - \
			env->set.nb[0]) : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		i = 0;
		while (env->set.obj[3] && ++i < (6 * env->set.p[0] + env->set.select))
			env->set.obj[3] = env->set.obj[3]->next;
		env->set.tab = ATTRIBUTES;
		env->set.pos = 0;
		env->set.id_o = 6 * env->set.p[0] + env->set.select;
		env->set.select = 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT && env->parse.objects - \
			env->set.nb[0] > 6)
	{
			env->set.p[0]++;
			env->set.block = 0;
			env->set.pos = 0;
			env->set.obj[0] = env->set.obj[2];
			env->set.obj[1] = env->set.obj[0];
			env->set.select = 1;
			env->set.nb[0] = env->set.nb[2];
			env->set.nb[1] = env->set.nb[0];
			SDL_DestroyTexture(env->sdl.tset[TINTER]);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT && env->set.obj[0] != env->obj)
	{
		env->set.p[0]--;
		i = 0;
		while (env->set.obj[0] && i <= 5)
		{
			env->set.obj[0] = env->set.obj[0]->prev;
			env->set.nb[0]--;
			i++;
		}
		env->set.block = 0;
		env->set.pos = 0;
		env->set.obj[1] = env->set.obj[0];
		env->set.select = 1;
		env->set.nb[1] = env->set.nb[0];
		SDL_DestroyTexture(env->sdl.tset[TINTER]);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
			ft_error_sdl();
		env->set.tab = INTERFACE;
		env->set.pos = 0;
		env->set.select = 1;
		env->set.obj[3] = env->obj;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_u && env->set.del == 1)
	{
		ft_undelete(env);
		ft_init_set(env);
		env->set.tab = OBJECTS;
		SDL_DestroyTexture(env->sdl.draw);
		env->parse.objects++;
		ft_browse_pixels(env);
	}
}

void	ft_ev_at(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == 6) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)	
		env->set.select = (env->set.select == 1) ? 6 : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		ft_init_set(env);
		env->set.tab = OBJECTS;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.p[1] == 0)
		{
			if (env->set.select == 1)
			{
				ft_add_elem_obj(env);
				env->tmp.current = NULL;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
				env->parse.objects++;
				ft_init_set(env);
				env->set.tab = OBJECTS;
			}
			else if (env->set.select == 2)
			{
				ft_stock_elem(env);
				ft_delete_elem_obj(env);
				ft_init_set(env);
				env->set.del = 1;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
				env->parse.objects--;
				env->set.tab = OBJECTS;
				if (env->parse.objects == 0)
				{
					if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
						ft_error_sdl();
					env->set.tab = INTERFACE;	
				}
			}
			else if (env->set.select == 3)
			{
				env->set.tab = POSTAB;
				env->set.select = 2;
			}
			else if (env->set.select == 4)
			{
				env->set.tab = DIRTAB;
				env->set.select = 2;
			}
			else if (env->set.select == 5)
			{
				env->set.tab = COLTAB;
				env->set.select = 2;
			}
		}
	}
}
	/*
	void	ft_ev_light(t_env *env)
	{

	}*/
