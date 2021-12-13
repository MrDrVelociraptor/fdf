/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:58:45 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/28 17:17:24 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*dest;

	if (!s1 || !s2)
		return (0);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) + (slen1 + slen2 + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, slen1 + 1);
	ft_strlcat(dest + slen1, s2, slen2 + 1);
	return (dest);
}
