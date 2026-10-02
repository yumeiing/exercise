#ifndef STACK_H
#define STACK_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef Node Stack;

Node *sCreate(int root_data){
	Node *s=(Node*)malloc(sizeof(Node));
	s->data=root_data;
	s->next=NULL;
	return s;
}

void sPop(Stack **s){
	Node *tmp=*s;
	*s=(*s)->next;
	free(tmp);
}

int sTop(Stack *s){
	return s->data;
}

void sPush(Stack **s,int next_data){
	Node *n=sCreate(next_data);
	n->next=*s;
	*s=n;
}

void sFree(Stack *s){
	while(s->next!=NULL){
		sPop(&s);
	}
	free(s);
}

void sPrint(Stack *s){
	Node *n=s;
	while(n!=NULL){
		printf("%d ",n->data);
		n=n->next;
	}
	putchar('\n');
}

Stack *sNew(int n,...){
	va_list args;
	va_start(args,n);
	int result=va_arg(args,int);
	Stack *s=sCreate(result);
	for(int i=1;i<n;++i){
		result=va_arg(args,int);
		sPush(&s,result);
	}
	return s;
}

#endif
