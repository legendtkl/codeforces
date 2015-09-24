#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	
	scanf("%d", &n);
	if(n==0)
		return 0;
	vector<int> seq(n);
	for(int i=0; i<n; ++i)
		scanf("%d", &seq[i]);

	int len=1, pos=0, local=1;
	for(int i=1; i<n; ++i){
		if(seq[i]>=seq[i-1])
			local += 1;
		else
			local = 1;
		len = max(len, local);
	}
	printf("%d\n", len);
	return 0;
}
