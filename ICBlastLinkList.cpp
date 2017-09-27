#include "ICBlastLinkList.h"
#include <stdio.h>
#include <string.h>


ICBlastLinkList::ICBlastLinkList()
{
    head=NULL;
}

ICBlastLinkList::~ICBlastLinkList()
{

}


//initialize a link list
void ICBlastLinkList::InitList()
{
	//strcpy(head->elem, "Visual Mask Designer");                                   ");
	
}

void ICBlastLinkList::AddNode( llink *item )
{
	llink *node = new llink;  //create node
	node = item;              //set node = the added item
	node->next = head;        //point next to the head
	head = node;              //change head to the next ptr
}

//fills a string buffer with each list item
//so that a list member may insert them as text/data
float ICBlastLinkList::CreateListX()
{
	llink* currentelem= firstelem;
	while (currentelem!= NULL)
	{
		currentelem= currentelem->next;
	}
	return currentelem->elemfloat;
}

float ICBlastLinkList::CreateListY()
{
	llink* currentelem= firstelem;
	while (currentelem!= NULL)
	{
		currentelem= currentelem->next;
	}
	return currentelem->elemfloat;
}