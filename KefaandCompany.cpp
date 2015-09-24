#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Friend{
	int money;
	int friendship;
	Friend(int m, int f): money(m), friendship(f) {}
};

bool cmp(Friend f1, Friend f2){
	return f1.money<f2.money;
}

int main(){
	int n, d;
	scanf("%d %d", &n, &d);

	if(n==0)
		return 0;

	vector<Friend> friends;
	for(int i=0; i<n; i++){
		int m, f;
		scanf("%d %d", &m, &f);
		friends.push_back(Friend(m,f));
	}
	sort(friends.begin(), friends.end(), cmp);
	int money=friends[0].money, friendship=friends[0].friendship, max_friendship=friendship;
	for(int i=1; i!=n; ++i){
		if(friends[i].money-money < d)
			friendship += friends[i].friendship;
		else{
			money = friends[i].money;
			friendship = friends[i].friendship;
		}
		printf("friendship: %d\n", friendship);
		max_friendship = max(max_friendship, friendship);
	}
	printf("%d\n", max_friendship);
	return 0;
}
