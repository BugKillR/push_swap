/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:28:29 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 15:28:30 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

# ifndef INT_MIN
#  define INT_MIN (-2147483647 - 1)
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_abs(int n);
void	ft_realloc(char **ptr1, char *ptr2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
