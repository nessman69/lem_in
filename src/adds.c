/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   adds.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 19:27:01 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 12:27:12 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_add_text(t_info *tab)
{
	char *tmp;

	if (tab->nb == 0)
		tab->text = ft_strdup("");
	else
	{
		tmp = ft_strdup(tab->text);
		ft_strdel(&tab->text);
		tab->text = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
	}
	tmp = ft_strdup(tab->text);
	ft_strdel(&tab->text);
	tab->text = ft_strjoin(tmp, tab->line);
	ft_strdel(&tmp);
}

t_salle	*add_donne(t_salle *colonie, char **salle)
{
	t_salle *ptr;
	t_salle *link;

	ptr = colonie;
	link = malloc(sizeof(t_salle));
	link->name = ft_strdup(salle[0]);
	link->x = ft_atoi(salle[1]);
	link->y = ft_atoi(salle[2]);
	link->next = NULL;
	link->co = NULL;
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = link;
	}
	else
		colonie = link;
	return (colonie);
}

void	add_liaison(t_salle *salle, char **tab, int first_liaison)
{
	t_salle		 *tmp;
	t_connection *new;
	t_connection *tmp_co;

	new = malloc(sizeof(t_connection));
	if (new == NULL)
		return ;
	new->connect = ft_strdup(tab[first_liaison == 1]);
	new->next = NULL;
	tmp = salle;
	while (ft_strcmp(tmp->name, tab[first_liaison == 0]) != 0)
		tmp = tmp->next;
	tmp_co = tmp->co;
	if (tmp->co == NULL)
		tmp->co = new;
	else
	{
		while (tmp_co->next != NULL)
			tmp_co = tmp_co->next;
		tmp_co->next = new;
	}
	if (first_liaison)
		add_liaison(salle, tab, 0);
}