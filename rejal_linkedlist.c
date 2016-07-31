/*
Name: Rejal Dhakal
Roll no. 524
Batch of 2019
WAP in C to implement linked list
*/
	
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
 	int info;
 	struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void insertatfirst(nodeptr *, int);
int deletefromfirst(nodeptr *);
void displaylist(nodeptr);
int check_underflow(nodeptr *);

int main()
{
	nodeptr list;
	list=NULL;
	printf("List is:\n");
	insertatfirst(&list,1);
	insertatfirst(&list,4);
	insertatfirst(&list,5);
	insertatfirst(&list,3);
	insertatfirst(&list,2);
	displaylist(list);
	printf("\n");
	printf("\nList after deletion\n");
	deletefromfirst(&list);	
	deletefromfirst(&list);
	deletefromfirst(&list);
	deletefromfirst(&list);

	displaylist(list);
}

nodeptr getnode(){
	return (nodeptr)malloc(sizeof(struct node));
}

void freenode(nodeptr p){
	free(p);
}

void insertatfirst(nodeptr *p, int x){
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p){
	nodeptr ptr=p;
	while(ptr!=NULL){
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
}


int deletefromfirst (nodeptr *p) {
	if (check_underflow(p)) {
		printf ("\n Linked List Underflow \n");
		getch();
		exit(1);
	} else {
		int x;
		nodeptr q;
		q = *p;
		
		*p = q->next;
		x = q->info;
		
		return x;
		
		freenode(q);
	}
}

int check_underflow(nodeptr *p){
	return (*p == NULL);
}



