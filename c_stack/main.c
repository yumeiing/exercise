#include "Stack.h"

int main(void){
	Stack *s=sNew(5,22,33,44,55,66);
	sPush(&s,10);
	sPush(&s,-19);
	sPrint(s);
	sPop(&s);
	sPop(&s);
	sPush(&s,40);
	sPrint(s);
}
