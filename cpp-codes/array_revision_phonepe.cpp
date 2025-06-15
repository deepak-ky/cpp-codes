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

 void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      if(n == 1) {
      	return;
      }

      bool found = false;
      int i = n-2;
      for(i=n-2;i>=0;i--){
      	if(nums[i] < nums[i+1]){
      		found = true;
      		break;
      	}
      }

      if(!found){
      	// the array is in descending order
      	sort(nums.begin(),nums.end());
      	return;
      }


      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
      pq.push({nums[i+1],i+1});

      //optimization: start from the back, then no need for pq
      for(int j=i+1;j<n;j++){
      	if(nums[j] > nums[i]){
      		pq.push({nums[j],j});
      	}
      }

      int idxToSwap = pq.top().second;
      swap(nums[i],nums[idxToSwap]);
      sort(nums.begin()+i+1,nums.end());
      return;
 }

 vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int numberTwice = -1;
    int numberAbsent = -1;
    
    for(int i=0;i<a.size();i++){
        int num = abs(a[i]);
        // I will go and make the value at num-1 (-ve)
        // so a value is negative at index i, that means, i+1, is present 
        // in the array

        int value = a[num-1];

        if(value < 0) {
            numberTwice = num;
        }else{
            a[num-1] = -value;
        }
    }

    for(int i=0;i<a.size();i++){
        if(a[i] > 0){
            numberAbsent = i+1;
            break;
        }
    }

    return {numberTwice, numberAbsent};
}

/* vector<int> findMissingRepeatingNumbers(vector < int > a) {
   long long int n = a.size();
   long long int sumOfFirstN = (n*(n+1))/2;
    long long int sum = 0;
    for(auto &x : a) sum += long(x);

    long long int xMINUSy = sum - sumOfFirstN;
    //cout << "xMINUSy" << xMINUSy << endl;

    long long int sumOfFirstNSquares = (n*(n+1)*(2*n+1))/6;
    long long int sumSquares = 0;
    for(auto &x : a) sumSquares += long(x * x);

    long long int x2MINUSy2 = sumSquares - sumOfFirstNSquares;
    //cout << "x2MINUSy2" << x2MINUSy2 << endl;

    long long int xPLUSy = x2MINUSy2/xMINUSy;

    long long int x = (xMINUSy + xPLUSy)/2;
    long long int y = xPLUSy - x;

    return {x,y};
}*/

vector<int> findMissingRepeatingNumbers3(vector < int > a) {
   int n = a.size();
   int numXor = 0;
   for(int i=1;i<=n;i++) numXor = numXor ^ i;

   for(int i=0;i<n;i++) numXor = numXor ^ a[i];

   int firstDifferentBitIndex = -1;
   for(int i=0;i<32;i++){
   		if((numXor>>i)&1){
   			firstDifferentBitIndex = i;
   			break;
   		}
   }

   int bit1Club = 0;
   int bit0Club = 0;

   for(int i=1;i<=n;i++){
   	if((i>>firstDifferentBitIndex)&1){
   		bit1Club = bit1Club ^ i;
   	}else{
   		bit0Club = bit0Club ^ i;
   	}
   }

   for(int i=0;i<n;i++){
   	if((a[i]>>firstDifferentBitIndex)&1){
   		bit1Club = bit1Club ^ a[i];
   	}else{
   		bit0Club = bit0Club ^ a[i];
   	}
   }

   int cnt = 0;
   for(auto &x : a){
   	if(x == bit1Club){
   		cnt++;
   	}
   }


   if(cnt == 0){
   	return {bit0Club,bit1Club};
   }else if(cnt==2){
   	return {bit1Club,bit0Club};
   }

   return {};
}

int mergeSortedArrays(vector<int> &a,int l,int m,int e){
	vector<int> tempVector;
	int i = l;
	int j = m+1;

	while(i <= m && j <= e){
		if(a[i] <= a[j]){
			tempVector.push_back(a[i]);
			i++;
		}else{
			tempVector.push_back(a[j]);
			j++;
		}
	}

	while(i <= m){
		tempVector.push_back(a[i]);
		i++;
	}

	while(j <= e){
		tempVector.push_back(a[j]);
		j++;
	}

	int k = 0;
	for(int i=l;i<=e;i++){
		a[i] = tempVector[k];
		k++;
	}
}

int sortArrayAndCntInversions(vector<int>& a,int l,int e){
	if(l > e) {
		return 0;
	}

	if(l == e){
		return 0;
	}

	int m = (l+e)/2;
	int leftInversions = sortArrayAndCntInversions(a,l,m);
	int rightInversions = sortArrayAndCntInversions(a,m+1,e);


	int conversionCnt = 0;
	int i = l;
	int j = m+1;
	while(i <= m && j <= e){
		if(a[i] <= a[j]){
			i++;
		}else{
			conversionCnt += (m-i+1);
			j++;
		}
	}

	mergeSortedArrays(a,l,m,e);
	return conversionCnt + leftInversions + rightInversions;
}

int numberOfInversions(vector<int>&a, int n) {
    return sortArrayAndCntInversions(a,0,n-1);
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		/*vector<int> a = {5,1,4,3,2};
		nextPermutation(a);
		for(auto &x : a) cout << x << " ";*/

		/*vector<int> a = {1,3,2,3};
		vector<int> v = findMissingRepeatingNumbers3(a);
		cout << "Repeating: " << v[0] << endl;
		cout << "Missing: " << v[1] << endl;*/

		vector<int> a = {5,3,2,1,4};
		cout <<"Inverson Count : " <<  numberOfInversions(a,5) << endl;
	}
	return 0;
}


pair<bool,node*> detectCycle(node *head){
	if(head == NULL || head->next == NULL){
		return {false,NULL};
	}

	node *slow = head;
	node *fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast){
			break;
		}
	}

	if(slow != fast){
		return {false,NULL};
	}else{
		node *temp = head;
		while(fast != temp){
			fast = fast->next;
			temp = temp->next;

		}

		return {true,fast};
	}
}