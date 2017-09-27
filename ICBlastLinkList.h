#include <stdio.h>
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

//link list
struct llink
{
	char	elem[20];
	int		elemint;
	float	elemfloat;
	char	elemchar;
	llink* next;

};


//link list class
class ICBlastLinkList {
public:
	llink* head;
	llink* curr;
	llink* tail;

	llink *firstelem;

	ICBlastLinkList();
	~ICBlastLinkList();

	float CreateListX();
	float CreateListY();
	void InitList();
	void AddNode( llink *item );

} ;

#endif