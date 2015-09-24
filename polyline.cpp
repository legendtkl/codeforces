#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	long double a,b,x=-1;
	cin >> a >> b;
	if(a-b<0){
		x = -1;
	}
	else if(a==b){
		x = a;
	}else {
		int div = (a-b)/b;
		if(div%2)
			x = (a-b)/(div-1);
		else
			x = (a-b)/div;
		div = (a+b)/b;
		if(div%2)
			x = min(x, (a+b)/(div-1));
		else
			x = min(x, (a+b)/div);
	}
	cout.precision(10);
	cout << x << endl;
	return 0;
}
