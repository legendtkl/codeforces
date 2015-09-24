#include <iostream>
#include <cstdio>

using namespace std;


int main(){
	int x,ret=0;
	scanf("%d", &x);

	while(x){
		ret++;
		x = x&(x-1);
	}

	printf("%d\n",ret);
	return 0;
}

