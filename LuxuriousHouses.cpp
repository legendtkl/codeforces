#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, mx=0;
	scanf("%d", &n);

	vector<int> house(n);
	vector<int> ret(n);
	for(int i=0; i<n; i++){
		scanf("%d", &house[i]);
	}

	mx = house[n-1];
	for(int i=n-2; i>=0; --i){
		if(house[i] > mx)
			mx = house[i];
		else{
			ret[i] = mx-house[i]+1;
		}
	}
	for(int i=0; i<n-1; ++i)
		printf("%d ", ret[i]);
	printf("%d\n", ret[n-1]);
	return 0;
}
