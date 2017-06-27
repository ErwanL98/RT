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
}

void	ft_ev_inter(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
			env->set.select = (env->set.select == 2) ? 1 : 2;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
			env->set.select = (env->set.select == 2) ? 1 : 2;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		env->set.tab = (env->set.select == 1) ? OBJECTS : LIGHTS;
		env->set.select = 1;
		env->set.pos = 0;
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 30)) == NULL)
			ft_error_sdl();
		SDL_DestroyTexture(env->sdl.tset[TINTER]);
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
		env->set.tab = INTERFACE;
		env->set.pos = 0;
		env->set.select = 1;
		env->set.obj[3] = env->obj;
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
			ft_error_sdl();
	}
}

void	ft_ev_at(t_env *env)
{
	t_obj	*start;

	start = env->obj;
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
			// DELETE TEST NOT WORKING
			else if (env->set.select == 2)
			{
				ft_delete_elem_obj(env);
				ft_init_set(env);
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
				env->parse.objects--;
				env->set.tab = OBJECTS;
			}
		}
	}
}
/*
void	ft_ev_light(t_env *env)
{

}*/
