/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:49:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/11 13:49:37 by ele-cren         ###   ########.fr       */
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
