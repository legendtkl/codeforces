#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,k;
	scanf("%d %d",&n, &k);

	vector<int> skills(n);
	for(int i=0; i<n; i++)
		scanf("%d", &skills[i]);

	int max_unit = 0, developed = 0;
	for(int i=0; i<n; i++){
		developed += skills[i]/10;
		max_unit += 100-(skills[i]+9)/10*10;
		if(skills[i]%10 == 0)
			skills[i] = 0;
		else
			skills[i] = (skills[i]/10+1)*10 - skills[i];
	}
//	printf("max units is %d\n", max_unit);
	sort(skills.begin(), skills.end());
	for(int i=0; i<n; i++){
//		printf("%d %d\n", i, skills[i]);
		if(skills[i]==0)
			continue;
		if(k<skills[i])
			break;
		k -= skills[i];
		developed += 1;
	}
	if(k>0){
		developed += min(k,max_unit)/10;
	}
	printf("%d\n", developed);
	return 0;
}
