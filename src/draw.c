/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/08/18 15:36:42 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_display(t_env *env)
{
	SDL_SetRenderDrawColor(env->sdl.rend, 255, 255, 255, 255);
	SDL_RenderClear(env->sdl.rend);
	env->sdl.rt.x = 0;
	env->sdl.rt.y = 0;
	env->sdl.rt.w = WIDTHR;
	env->sdl.rt.h = HEIGHT;
	env->sdl.rset[DINTER].x = WIDTHR;
	env->sdl.rset[DINTER].y = 0;
	env->sdl.rset[DINTER].w = WIDTHS;
	env->sdl.rset[DINTER].h = HEIGHT;
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TINTER], NULL, \
			&env->sdl.rset[DINTER]);
	SDL_RenderCopy(env->sdl.rend, env->sdl.draw, NULL, &env->sdl.rt);
	SDL_DestroyTexture(env->sdl.tset[TINTER]);
	SDL_RenderPresent(env->sdl.rend);
}

void	ft_refresh(t_env *env)
{
	SDL_DestroyTexture(env->sdl.draw);
	ft_browse_pixels(env);
}

Uint32	ft_chose_color(t_env *env)
{
	Uint32	color;
	int		col[3];

	col[0] = env->tmp.current->color.red * env->light->power * \
		env->tmp.darkness;
	col[1] = env->tmp.current->color.green * env->light->power * \
		env->tmp.darkness;
	col[2] = env->tmp.current->color.blue * env->light->power * \
		env->tmp.darkness;
	if (env->filters.bw[0] == 1)
	{
		env->filters.bw[1] = (col[0] + col[1] + col[2]) / 3 + \
			env->filters.bw[2];
		env->filters.bw[1] = (env->filters.bw[1] > 255) ? 255 : \
			env->filters.bw[1];
		env->filters.bw[1] = (env->filters.bw[1] < 0) ? 0 : \
			env->filters.bw[1];
		color = SDL_MapRGBA(env->sdl.format, env->filters.bw[1], \
			env->filters.bw[1], env->filters.bw[1], 255);
	}
	else if (env->filters.neg == 1)
		color = SDL_MapRGBA(env->sdl.format, 255 - col[0], 255 - col[1], \
			255 - col[2], 255);
	else
		color = SDL_MapRGBA(env->sdl.format, col[0], col[1], col[2], 255);
	if (env->filters.mo[0] || env->filters.mo[1] || env->filters.mo[2])
	{
		color = (env->filters.mo[0] == 1) ? \
			SDL_MapRGBA(env->sdl.format, col[0], 0, 0, 255) : color;
		color = (env->filters.mo[1] == 1) ? \
			SDL_MapRGBA(env->sdl.format, 0, col[1], 0, 255) : color;
		color = (env->filters.mo[2] == 1) ? \
			SDL_MapRGBA(env->sdl.format, 0, 0, col[2], 255) : color;
	}
	return (color);
}
