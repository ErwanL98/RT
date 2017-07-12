/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:51:05 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/12 17:12:19 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_base_rlb(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT || \
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
		if ((env->set.select % 3 == 0 && env->set.select < 12) || \
				env->set.select == 2 || env->set.select == 5 || \
				env->set.select == 8 || env->set.select == 13 || \
				env->set.select == 14 || env->set.select == 16 || \
				env->set.select == 17)
			env->set.select = (env->set.select == 2 || env->set.select == 5 \
			|| env->set.select == 8 || env->set.select == 13 || \
			env->set.select == 16) ? env->set.select + 1 : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.inc = 1;
		env->set.tab = ATTRIBUTES;
	}
}

void	ft_ev_base_down(t_env *env, int *test)
{
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 13 || env->set.select == 14)
			env->set.select += 3;
		else if (env->set.select == 8 || env->set.select == 9)
		{
			*test = env->set.select;
			env->set.select = (env->set.select == 8) ? env->set.select + 3 : \
			env->set.select + 2;
		}
		else if (env->set.select == 11)
		{
			if (env->set.obj[3]->finished == 0)
				env->set.select = 2;
			else
				env->set.select = (*test == 8 || *test == 13) ? \
					env->set.select + 2 : env->set.select + 3;
		}
		else if (env->set.select == 16 || env->set.select == 17)
			env->set.select -= 14;
	}
}

void	ft_ev_base_up(t_env *env, int *test)
{
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
	{
		if (env->set.select == 5 || env->set.select == 6 || env->set.select == \
				8 || env->set.select == 9 || env->set.select == 16 || \
				env->set.select == 17)
			env->set.select -= 3;
		else if (env->set.select == 13 || env->set.select == 14)
		{
			*test = env->set.select;
			env->set.select = (env->set.select == 13) ? env->set.select - 2 : \
			env->set.select - 3;
		}
		else if (env->set.select == 2 || env->set.select == 3)
		{
			if (env->set.obj[3]->finished == 0)
				env->set.select = (env->set.select == 2) ? env->set.select + 9 \
				: env->set.select + 8;
			else
				env->set.select += 14;
		}
		else if (env->set.select == 11)
			env->set.select = (*test == 8 || *test == 13) ? \
				env->set.select - 3 : env->set.select - 2;
	}
}
