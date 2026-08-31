#include <stdio.h>

void hanoi(int n,char source,char temp,char target);

int main()
{
    hanoi(3,'A','B','C');
    return 0;
}

void hanoi(int n, char source, char temp, char target)
{
    if(n == 0) return ;

    hanoi(n-1,source,target,temp);
    printf("%c > %c\n",source,target);
    hanoi(n-1,temp,source,target);
}
