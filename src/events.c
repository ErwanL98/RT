/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:49:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/12 16:30:57 by ele-cren         ###   ########.fr       */
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
	else if (env->set.tab == BASETAB)
		ft_ev_base(env);
}

void	ft_ev_base(t_env *env)
{
	static int	test = 0;

	ft_ev_base_rlb(env);
	ft_ev_base_down(env, &test);
	ft_ev_base_up(env, &test);
}
