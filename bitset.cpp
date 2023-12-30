#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
//#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl

const int N = 10;

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//1. when a bitset is declared all the bits are by default set to zero;
	bitset<N> b1;

	//2.Indexing is similiar to that of the bits , from the right starting with 0;
	b1[2] = 1;

	cout << "b1 now : " <<  b1 << endl;

	//3.Initialize the bits of a number into a bitset

	bitset<N> b2(15);
	bitset<N> b3(string("11011"));

	cout << "b2 now : " <<  b2 << endl;
	cout << "b3 now : " <<  b3 << endl;

	//4. Can also count the number of set bits in a number

	cout << "number of set bits in b2 is : " <<  b2.count() << endl;

	//5.To find the number of unset of zero bits we can do

	cout << "number of unset bits (zero) in b2 is : " << b2.size() - b2.count() << endl;

	//6. Test function returns the bit that index , similar to b2[i];

	cout << "b2[4] is : " <<  b2.test(4) << endl;

	//7. any function returns true if atleast one bit is set

	if (b2.any()) cout << "b2 has atleast one bit set\n";
	bitset<N> b4;
	if (!b4.any()) cout << "b4 has no bit set\n";

	//8. None returns true if none of the bit is set
	if (b4.none()) cout << "b4 has no bit set\n";

	//9. To set all the bits of the bitset
	b3.set();
	cout << "b3 now is : " << b3 << endl;

	//10.b2.set(pos,b) makes b2[pos] = b
	b1.set(1, 1);
	cout << "b1 now is : " <<  b1 << endl;

	//11.To set a particular bit
	b1.set(3);
	cout << "b1 now is : " << b1 << endl;

	//12.reset function makes all the bits equal to zero;
	b1.reset(2); //->makes a particular bit zero
	cout << "b1 now is : " << b1 << endl;
	b1.reset(); //->makes all the bits equal to zero
	cout << "b1 now is : " << b1 << endl;

	b4.reset(); //-> does not create a error

	//13. Flip all the bits of bitset
	cout << "b2 without flip : " << b2 << endl;
	b2.flip();
	cout << "b2 after flip : " << b2 << endl;

	//can work for a particular bit also
	cout << "b2[1] without flip : " << b2[1] << endl;
	b2.flip(1);
	cout << "b2[1] after flip : " << b2[1] << endl;

	//14.convert a number into its binary reprentation
	int n = 7;
	bitset<8> b5(n);
	cout << "binary reprentation of " << n << " is : " << b5 << endl;

	return 0;
}
