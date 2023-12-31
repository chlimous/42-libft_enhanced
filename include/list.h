/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 04:41:49 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/31 04:43:13 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>

// Regular - Structures
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Advanced - Structures
typedef struct s_advlist
{
	t_list	*head;
	t_list	*tail;
	size_t	size;
}	t_advlist;

// Regular - Prototypes
t_list		*ft_lstnew(void *content);
t_list		*ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Advanced - Prototypes
void		ft_advlst_init(t_advlist *advlst);
int			ft_advlstadd_back(t_advlist *advlst, t_list *new);
int			ft_advlstadd_front(t_advlist *advlst, t_list *new);
void		ft_advlstclear(t_advlist *advlst);

#endif
