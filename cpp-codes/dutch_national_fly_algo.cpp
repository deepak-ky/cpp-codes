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

void sortColors(vector<int> &nums){
	int n = nums.size();

	int low = 0;
	int mid = 0;
	int high = n-1;

	// This is not required as the while will take an extra iteration
	// but take into consideration all these cases 
	/*while(low < n && nums[low] == 0){
		low++;
	}

	mid = low;
	while(mid < n && nums[mid] == 1){
		mid++;
	}

	while(high >= 0 && nums[high] == 2){
		high--;
	}*/

	while(mid <= high){
		if(nums[mid] == 0){
			swap(nums[mid],nums[low]);
			low++;
			/*The below mid++ is required, as we cannot assume that low would always pointing to 1
			what if low == mid and both are 0, in this case, if we don't do a mid++
			low will move ahead, and forwarding of mid will not be taken care by else if(a[mid] == 1)

			The condition that striver mentioned will be violated

			Apart from this if we do not keep mid++ here, than if my array does not contain 1, then my mid     
            would never move only, which is an issue
			*/
			//mid++; 
		}else if(nums[mid] == 1){
			mid++;
		}else if(nums[mid] == 2){
			swap(nums[mid],nums[high]);
			high--;
		}
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<int> nums = {2,0,0,0,0,0,0,0};
		sortColors(nums);
		for(auto &x : nums) cout << x << " ";
	}
	return 0;
}
