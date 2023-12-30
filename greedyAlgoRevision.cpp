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


//Ques 1 : N meetings in a room :: sort on the basis of ending time, 
// if you sort on the basis of starting time, ( if a meeting starts very early and ends very late)
// hence the answer would be only 1

// Ques 2 : Minimum Platforms Required
// Approach - 1 :: Put all the events in a single array, and increment counter when arrival event and decrement counter when departure event
// Approach - 2 :: Maintain a priority queue which will tell you what is the earliest departure time
// Approach - 3 :: Make an array of time, and increment on arrival and decrement on departure take sum, the array length can be 2361 (23:59 is the max time possible)
// Approach - 4 :: Striver Approach :: Sort both the arrays independently , and do two pointer approach ( less intituite but works)
int min_platforms_required_approach_1(vector<int> &a,vector<int> &d,int n){
	vector<pair<int,int>> p;
	for(int i=0;i<n;i++){
		p.push_back({a[i],1});
		p.push_back({d[i],2});
	}

	sort(p.begin(),p.end());

	int platforms = 0;
	int ans = platforms;
	for(int i=0;i<(2*n);i++){
		if(p[i].second == 1){
			platforms++;
		}else{
			platforms--;
		}

		ans = max(ans,platforms);
	}

	return ans;
}



int min_platforms_required_approach_2(vector<int> &a,vector<int> &d,int n){
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		v.push_back({a[i],d[i]});
	}

	sort(v.begin(), v.end());

	int plat_count = 1;
	pq.push(v[0].second);
	for(int i=1;i<n;i++){
		if(v[i].first <= pq.top()){
			// No need to decrease the counter 
			plat_count++;
		}else{
			pq.pop();
		}
		pq.push(v[i].second);

	}

	return plat_count;
}

class job{
public:

	int id;
	int deadline;
	int profit;

	job(int i,int d,int p){
		id = i;
		deadline = d;
		profit = p;
	}
};

bool custom_compare(job &j1,job &j2){
	if(j1.profit < j2.profit){
		return true;
	}
	else if(j1.profit == j2.profit && j1.deadline < j2.deadline){
		return true;
	}
	else{
		return false;
	}
}
// o(nlog(n)) + o(n*m)
int job_sequencing_problem(job jobs[],int n){
	sort(jobs,jobs+n,custom_compare);
	vector<bool> time(n+1,false);
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		for(int j=jobs[i].deadline;j>=1;j--){
			if(time[j] == false){
				time[j] = true;
				ans += jobs[i].profit;
				break;
			}
		}
	}

	return ans;
}

double fractional_knapsack(int w,vector<pair<int,int>> &v,int n){
	vector<pair<double,int>> unitValues(n);
	for(int i=0;i<n;i++){
		double oneUnitValue = (double)v[i].first/v[i].second;
		unitValues[i] = {oneUnitValue,v[i].second};
	}

	sort(unitValues.begin(),unitValues.end());
	double weight = (double)w;

	double ans = 0;

	for(int i=n-1;i>=0;i--){
		double oneUnitValue = unitValues[i].first;
		double maxValue;
		if((double)unitValues[i].second < weight)
		{
			maxValue = oneUnitValue * (double)unitValues[i].second;
			weight -= (double)unitValues[i].second;
			ans += maxValue;
		}else{
			maxValue = oneUnitValue * weight;
			ans += maxValue;
			break;
		}
	}

	return ans;
}

vector<int> minimum_number_of_coins(int n){
	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int size = sizeof(coins)/sizeof(int);
	vector<int> ans;
	for(int i=size-1;i>=0;i--){
		if(coins[i] > n){
			continue;
		}else{
			while(coins[i] <= n ){
				ans.push_back(coins[i]);
				n -= coins[i];
			}
		}
	} 

	return ans;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		v.push_back({end[i],i});
	}
	
	sort(v.begin(),v.end());
	
	int activites = 1;
	int current_end_day = v[0].first;
	
	for(int i=1;i<v.size();i++){
		int start_day = start[v[i].second];
		if(start_day <= current_end_day) continue;
		else{
			activites++;
			current_end_day = v[i].first;
		}
	}
	
	return activites;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		// vector<int> a = {900,940,950,1100,1500,1800};
		// vector<int> d = {910,1200,1120,1130,1900,2000};
		// cout << min_platforms_required_approach_1(a,d,5) << endl;
		// cout << min_platforms_required_approach_2(a,d,5) << endl;

		// job jobs[] =  {job(1,2,100),job(2,1,19),job(3,2,27),job(4,1,25),job(5,1,15)};
        // int n = 5;
		// cout << job_sequencing_problem(jobs,n);

		//vector<pair<int,int>> v = {{60,10},{100,20},{120,30}};
		// vector<pair<int,int>> v = {{60,10},{100,20}};
		// cout << fractional_knapsack(50,v,2);


		vector<int> v  = minimum_number_of_coins(43);
		for(auto &x : v) cout << x << " ";
			cout << endl;
	}
	return 0;
}
