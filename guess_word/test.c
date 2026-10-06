#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define HELP 'y'
#define CI 7
#define YES_SYMBOL ' '
#define NO_SYMBOL 'X'
#define LIKE_SYMBOL '^'

// >>>>> care
#define CH_LEN 5
#define WORD_FILE "word_ans"
#define WORD_NUM 4667
// >>>>> care

char ans[CH_LEN+1];

void setAn();
void help();
char comCh(const char,const int);
int handleGuess(char[], char[]);

int main(int argc,char *argv[]) {
	setAn();
	help();
	printf("guess word:\n");

	for (int i = 1; i <= CI; ++i) {
		char guess[CH_LEN + 1], word[CH_LEN + 1];

		//input guess word
		printf("%d>\t",i);
		char buffer[1024];
		fgets(buffer,sizeof(buffer),stdin);
		if(strlen(buffer)<=CH_LEN){
			printf("put a word with %d letter\n",CH_LEN);
			--i;
			continue;
		}
		buffer[CH_LEN] = '\0';
		strcpy(guess,buffer);

		//output result
		if(handleGuess(guess, word)==5){
			printf("you win!!!\n");
			return 0;
		}
		printf("\t%s\n", word);
	}
	printf("an: %s\n",ans);
	printf("you lost\n");
	return 0;
}

void setAn(){
	srand(time(NULL));
	int n=rand()%WORD_NUM;
	FILE *infile=fopen(WORD_FILE,"r");
	for(int i=0;i<=n;++i){
		fgets(ans,CH_LEN+1,infile);
		getc(infile);
	}
}

#if HELP=='y'
void help(){
	printf("Rules:\n" \
			"You can input %d word.The promma will print a %d chars result.\n" \
			"Redo %d ci.A result has one of chars in there:\n" \
			"  \'%c\': this char is right.\n" \
			"  \'%c\': this char is be in this word but not right.\n" \
			"  \'%c\': this char is not be in this word.\n" \
			"If all right,than you win.\n" \
			"If ci become 0,than you lost.\n", \
			CH_LEN,CH_LEN,CI,YES_SYMBOL,LIKE_SYMBOL,NO_SYMBOL);
}
#else
void help(){}
#endif

char comCh(char com,int index){
	char a=ans[index];
	if(a=='\0')
		return NO_SYMBOL;
	if(com==a)
		return YES_SYMBOL;

	char ch;
	ans[index]='\0';
	if(index+1 == CH_LEN) ch=comCh(com,0);
	else ch=comCh(com,index+1);
	ans[index]=a;

	switch(ch){
		case YES_SYMBOL:
		case LIKE_SYMBOL:
			return LIKE_SYMBOL;
		case NO_SYMBOL:
			return NO_SYMBOL;
	}

	return com;
}

int handleGuess(char guess[], char word[]) {
	int sum=0;
	for(int i = 0;i<CH_LEN;++i){
		word[i]=comCh(guess[i],i);
		if(word[i]==YES_SYMBOL) ++sum;
	}
	return sum;
}

