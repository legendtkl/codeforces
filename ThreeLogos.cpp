#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


void output(int x1, int y1, int x2, int y2, int y3, char a, char b, char c){
	vector<vector<char> > layout(x1,vector<char>(x1)); 
	for(int i=0; i<y1; i++)
		for(int j=0; j<x1; j++)
			layout[i][j] = a;
	for(int i=y1; i<x2+y1; i++){
		for(int j=0; j<x1; j++){
			if(j<y2)
				layout[i][j] = b;
			else
				layout[i][j] = c;
		}
	}
	for(int i=0; i<x1; i++){
		for(int j=0; j<x1; j++)
			printf("%c", layout[i][j]);
		printf("\n");
	}
}

void generate(int x1, int y1, int x2, int y2, int x3, int y3, char a, char b, char c){
	if(x2==x1 && x3==x1){
		if(y1+y2+y3!=x1)
			printf("-1\n");
		else{
			for(int i=0; i<y1; i++){
				for(int j=0; j<x1; j++)
					printf("%c",a);
				printf("\n");
			}
			for(int i=0; i<y2; i++){
				for(int j=0; j<x1; j++)
					printf("%c",b);
				printf("\n");
			}
			for(int i=0; i<y3; i++){
				for(int j=0; j<x1; j++)
					printf("%c",c);
				printf("\n");
			}
		}
	}else if(x2==x1-y1 && x3==x1-y1 && y2+y3==x1){
		output(x1,y1,x2,y2,y3,a,b,c);
	}else if(y2==x1-y1 && y3==x1-y1 && x2+x3==x1){
		output(x1,y1,y2,x2,x3,a,b,c);
	}else if(x2==x1-y1 && y3==x1-y1 && y2+x3==x1){
		output(x1,y1,x2,y2,x3,a,b,c);
	}else if(y2==x1-y1 && x3==x1-y1 && x2+y3==x1){
		output(x1,y1,y2,x2,y3,a,b,c);
	}
	else{
		printf("-1\n");
	}
}

int main(){
	vector<int> num(6);
	for(int i=0; i<6; i++)
		scanf("%d", &num[i]);
	int x1,y1,x2,y2,x3,y3;
	x1 = max(num[0],num[1]);
	y1 = min(num[0],num[1]);
	x2 = max(num[2],num[3]);
	y2 = min(num[2],num[3]);
	x3 = max(num[4],num[5]);
	y3 = min(num[4],num[5]);
	int area = x1*y1 + x2*y2 +x3*y3;
	int root = sqrt(area);
	if(root*root != area)
		printf("-1\n");
	else{
		if(x1==root)
			generate(x1,y1,x2,y2,x3,y3,'A','B','C');
		else if(x2==root)
			generate(x2,y2,x1,y1,x3,y3,'B','A','C');
		else if(x3==root)
			generate(x3,y3,x1,y1,x2,y2,'C','A','B');
		else
			printf("-1\n");
	}
	return 0;
}
