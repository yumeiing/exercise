#include <cstdio>
#include "AutoLog.h"

template<class T=int>
T foo(T a,int b){
	AutoLog _al(__func__);
	if(b==0) return 1;
	T sum=a;
	while(--b)
		sum*=a;
	return sum;
}

int main(int argc, char **argv) {
	AutoLog _al;
	const float di=5;
	const int zhi=3;
	float an=foo(di,zhi);
	printf("%f^%d= %f\n",di,zhi,an);
    return 0;
}
