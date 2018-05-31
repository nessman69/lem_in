/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strwlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 14:06:08 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 14:45:15 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwlen(wchar_t *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb += ft_putwlen(str[i]);
		i++;
	}
	return (nb);
}