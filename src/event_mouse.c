/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:57:35 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 18:46:26 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_rot_cam_x(t_env *env)
{
	if (env->sdl.in.buttons[SDL_BUTTON_LEFT] == 1 && env->sdl.in.mouse_rel_x > 0)
	{
		env->cam.dir.x += 0.1;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
}

void		ft_update_mouse(t_env *env)
{
	if (env->sdl.event.type == SDL_MOUSEMOTION)
	{
		env->sdl.in.mouse_x = env->sdl.event.motion.x;
		env->sdl.in.mouse_y = env->sdl.event.motion.y;
		env->sdl.in.mouse_rel_x = env->sdl.event.motion.xrel;
		env->sdl.in.mouse_rel_y = env->sdl.event.motion.yrel;
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN)
		env->sdl.in.buttons[env->sdl.event.button.button] = 1;
	if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
		env->sdl.in.buttons[env->sdl.event.button.button] = 0;
}

void		ft_cam_mouse(t_env *env)
{
	ft_rot_cam_x(env);
}
