#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,x,ret=0;
	scanf("%d %d", &n, &x);
	for(int i=1; i<=x && i<=n; i++){
		if(x%i)
			continue;
		if(x/i<=n){
			ret += 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}
