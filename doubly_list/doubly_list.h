#ifndef DOUBLY_LIST_H
# define DOUBLY_LIST_H

typedef struct s_list
{
    void			*content;
    struct s_list	*next;
	struct s_list	*prev;
}



#endif