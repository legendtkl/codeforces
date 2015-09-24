#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int ret;

void DFS(vector<int>num, int pos, int sum, int target){
	if(pos>num.size() || ret)
		return;
	if(sum && sum%target==0){
		ret = 1;
		return;
	}
	DFS(num, pos+1, sum, target);
	DFS(num, pos+1, sum+num[pos], target);
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	vector<int> num(n);
	for(int i=0; i<n; i++)
		scanf("%d", &num[i]);
	if(n>m)
		printf("YES\n");
	else{
		DFS(num, 0, 0, m);
		if(ret)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
