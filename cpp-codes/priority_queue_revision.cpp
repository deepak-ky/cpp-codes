#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

void printPriorityQueue(priority_queue<int> pq){
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
}

void printPriorityQueue(priority_queue<int,vector<int>,greater<int>> pq){
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
}

void printPriorityQueue(priority_queue<pair<int,int>> pq){
	while(!pq.empty()){
		cout << "{" << pq.top().first << "," << pq.top().second << "},";
		pq.pop();
	}
}

void printPriorityQueue(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq){
	while(!pq.empty()){
		cout << "{" << pq.top().first << "," << pq.top().second << "},";
		pq.pop();
	}
}

class Person{
public:
	string name;
	int age;
	Person(string n,int a){
		name = n;
		age = a;
	}
};

class Person_Compare{
public:
	bool operator()(const Person &p1, const Person &p2) {
		if(p1.age > p2.age){
			return true;
		}
		else return false;
	}
};


void printPriorityQueue(priority_queue<Person,vector<Person>,Person_Compare> pq){
	while(!pq.empty()){
		cout << "{" << pq.top().name << "," << pq.top().age << "},";
		pq.pop();
	}
}


int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		priority_queue<int> pq;
		pq.push(1);
		pq.push(2);
		pq.push(3);


		priority_queue<int,vector<int>,greater<int>> pq2;
		pq2.push(1);
		pq2.push(2);
		pq2.push(3);

		printPriorityQueue(pq);
		cout << endl;
		printPriorityQueue(pq2);

		priority_queue<pair<int,int>> pq3;
		pq3.push({4,2});
		pq3.push({5,4});
		pq3.push({2,4});
		pq3.push({3,8});
		pq3.push({3,6});
		pq3.push({3,7});
		pq3.push({3,7});

		cout << endl;
		printPriorityQueue(pq3);

		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq4;
		pq4.push({4,2});
		pq4.push({5,4});
		pq4.push({2,4});
		pq4.push({3,7});
		pq4.push({3,8});
		pq4.push({3,6});
		pq4.push({3,6});



		cout << endl;
		printPriorityQueue(pq4);


		priority_queue<Person,vector<Person>,Person_Compare> pq5;
		Person p1("Deepak", 23);  pq5.push(p1);
		Person p2("Deepika", 21); pq5.push(p2);
		Person p3("Krishan", 46); pq5.push(p3);
		Person p4("Suman", 44);   pq5.push(p4);
		cout << endl;
		printPriorityQueue(pq5);




	}
	return 0;
}
