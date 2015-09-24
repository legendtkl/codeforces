#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Strength{
	int val;
	int mem1, mem2;
	Strength(int a, int b, int c):val(a),mem1(b),mem2(c){}
};

bool cmp(Strength s1, Strength s2){
	return s1.val > s2.val;
}

int main(){
	int n;
	cin >> n;
	vector<Strength> nums;
	vector<int> hash(2*n, 0);
	for(int i=1; i<2*n; ++i){
		for(int j=0; j<i; j++){
			int x;
			cin >> x;
			nums.push_back(Strength(x,i,j));
		}
	}
	sort(nums.begin(), nums.end(), cmp);
	for(size_t i=0; i!=nums.size(); ++i){
		if(hash[nums[i].mem1]==0 && hash[nums[i].mem2]==0){
			hash[nums[i].mem1] = nums[i].mem2+1;
			hash[nums[i].mem2] = nums[i].mem1+1;
		}
	}
	cout << hash[0];
	for(size_t i=1; i!=hash.size(); ++i)
		cout << ' ' << hash[i];
	cout << endl;
	return 0;
}
