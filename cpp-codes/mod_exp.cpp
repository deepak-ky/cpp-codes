#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int val=a%c;
	int w=pow(val,b);
	cout<<w%c;
	return 0;
}
