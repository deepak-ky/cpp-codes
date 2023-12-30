#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
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

long long wPowern(long long w,long long n,long long m){
	long long ans = 1;
	for(int i=0;i<n;i++){
		ans = ans*w;
		if(ans > m){
			return ans;
			// What is the purpose of multiplying more?
			// If this condition is not there it will lead to out of bounds of c++ length
		}
	}
	return ans;
}

int solveForNthRoot(int l,int h,int n1,int m){
	if(m == 1) return 1;
	long long n = (long long)n1;
 	while(l <= h){
 		//wer(l);
 		//wer(h);
		int w = l + ((h-l)/2);
		//wer(w);
		long long val = wPowern(w,n,(long long)m);
		//wer(val);
		if(val == m){
			return w;
		}else if(val < m){
			l = w+1;
		}else{
			h = w-1;
		}
	}
	return -1;
}

int NthRoot(int n,int m){
	return solveForNthRoot(1,m,n,m);
}

int findNumberOfElementsLess(vector<vector<int>> &matrix,int k){
	int ans = 0;
	for(int i=0;i<matrix.size();i++){
		// Would have to take upper bound only because this logic will fail for 1,2,3,7,7,8
		// lower bound will point to first 7 and I want it to point to 8

		// auto lb = lower_bound(matrix[i].begin(),matrix[i].end(),k);
		// int index = lb - matrix[i].begin();
		// if(matrix[i][index] == k){
		// 	ans += index+1;
		// }else{
		// 	ans += index;
		// }

		auto ub = upper_bound(matrix[i].begin(),matrix[i].end(),k);
		ans += (ub-matrix[i].begin());
	}
	return ans;
}

int median(vector<vector<int>> &matrix,int n,int m){
	int smallest = INT_MAX;
	int biggest = INT_MIN;
	for(int i=0;i<n;i++){
		smallest = min(smallest,matrix[i][0]);
		biggest = max(biggest,matrix[i][m-1]);
	}

	int l = smallest;
	int h = biggest;

	// n * m would always be odd
	int smallerElementsNeeded = (n*m)/2;
	smallerElementsNeeded += 1;

	while(l < h){
		int m  = l + ((h-l)/2);
		int numElementsLessThanM = findNumberOfElementsLess(matrix,m);
		if(numElementsLessThanM < smallerElementsNeeded){
			l = m + 1;
		}else{
			h = m;
			// we are going down in this case because
			// numElementsLessThanM will be greater than smallerElementsNeeded, only in cases 
			// when m >= median, that is why I want to go low
			// if m < median, then always numElementsLessThanM < smallerElementsNeeded
		}

		// whenever we are not doing ( l = m + 1 && h = m-1) , like in this case
		// the while condition changes to while(l<h) form while(l<=h)
	}

	return h;
}

int singleNonDuplicate(vector<int> &nums){
	// Other approaches -> 1. Sorting , 2. Hashing, 3. XOR

	// Crux : 
	// consecutive pairs on the left side of single element start on even index
	// and on the right side start on odd index

	// Approach 4
	//I will always play on even index
	//If a[i] == a[i+1], then I am on the left side of single element, move to l = i+2
	//If a[i] != a[i+1], then single element definitely does not exist on my right, so make h = i;

	int n = nums.size();
	int l = 0;
	int h = n-1;
	while(l < h){
		int m = l + ((h-l)/2);
		if(m&1) m--; // always play on even index
		if(nums[m] == nums[m+1]) {
			l = m+2;
		}else{
			h = m;
		}
	}

	return nums[l]; // l or h does not matter, // when the loop breaks they both are equal
}

int searchInRotatedArray(int l,int h,vector<int> &a,int k){
	wer(l);
	wer(h);
	if(l == h){
		cout << "here";
		wer(a[l]);
		wer(k);
		if(a[l] == k) {
			return l;
		}
		else{
			return -1;
		} 
	}
	if(l > h) return -1;

	int m = l + ((h-l)/2);

	if(a[l] <= a[m]){
		//First part is sorted
		// Check if k lies in that part
		if(k >= a[l] && k <= a[m]){
			return searchInRotatedArray(l,m,a,k);
		}else{
			return searchInRotatedArray(m+1,h,a,k);
		}
	}else{
		// If the first part is unsorted then the second part is by default sorted
		if(k >= a[m+1] && k <= a[h]){
			return searchInRotatedArray(m+1,h,a,k);
		}else{
			return searchInRotatedArray(l,m,a,k);
		}
	}

	return -1;

}

int search(vector<int> &nums,int target){
	return searchInRotatedArray(0,nums.size()-1,nums,target);
}

double findMedianSortedArrays(vector<int> &nums1,vector<int> &nums2){
	int n1 = nums1.size();
	int n2 = nums2.size();

	if(n1 == 0){
		if(n2&1){
			return double(nums2[n2/2]);
		}else{
			return double((nums2[(n2/2)-1] + nums2[n2/2])/2.0);
		}
	}else if(n2 == 0){
		if(n1&1){
			return double(nums1[n1/2]);
		}else{
			return double((nums1[(n1/2)-1] + nums1[n1/2])/2.0);
		}
	}else if(n1 == 0 && n2 == 0){
		return 0;
	}

	int leftElementsRequired = (n1+n2+1)/2;
	int l = max(0,(leftElementsRequired - n2));
	int h = min(leftElementsRequired,n1);

	// To avoid this l and h confusion, do the binary search on smaller array only
	// add a condition like this in the beginninig
	// If we do not maintain the above two conditions then the following cases will fail
	// If we have l = 0 and h = n
	/*Then the case like 
	a1 = {3,4,5,6,7,8}
	a2 = {1,2}
	now we only need 4 elements on the left, but if we l = 0 and not l = 2, then it would require 
	in edge case that we pick 0 elements from a1 and 4 elements from a2 which is not possible

	that is why l should be max = (0, (leftElementsRequired - n2));*/

	/*Consider this case
	a1 = {2,3,4,5,6,7,8,9};
	a2 = {1};

	in this case we require 5 elements on left, if we keep l = 4 and h = 7, but do we in the worst case
	ever require 7 elements

	and in this case 
	a1 = {1}
	a2 = {2,3,4,5,6,7,8,9};

	in this case we require 5 elements on left and if we keep l = 0 and h = 5 , but we do not have 5 elements in the right array 
	so h should be min(leftElementsRequired,n1);*/

	// All of this can be avoided if we directly do things on smaller array only , in that case l can be 0 
	// and h can be n1 

	// if(n1 > n2) return findMedianSortedArrays(nums2,nums1);

	wer(leftElementsRequired);

	int leftElement1,leftElement2,rightElement1,rightElement2;

	while(l <= h){
		wer(l);
		wer(h);
		int m = l + ((h-l)/2);
		wer(m);
		int elementsRequiredFromOtherArray = leftElementsRequired - m;
		wer(elementsRequiredFromOtherArray);
		leftElement1 = INT_MIN;
		if((m-1) >= 0) leftElement1 = nums1[m-1];

		rightElement1 = INT_MAX;
		if(m < n1) rightElement1 = nums1[m];

		leftElement2 = INT_MIN;
		if((elementsRequiredFromOtherArray - 1) >= 0) leftElement2 = nums2[elementsRequiredFromOtherArray - 1];

		rightElement2 = INT_MAX;
		if(elementsRequiredFromOtherArray < n2) rightElement2 = nums2[elementsRequiredFromOtherArray];


		wer(leftElement1);
		wer(rightElement1);
		wer(leftElement2);
		wer(rightElement2);

		if(leftElement1 <= rightElement2 && leftElement2 <= rightElement1){
			break;
		}
		else if(leftElement1 > rightElement2){
			h = m-1;
		}else{
			l = m+1;
		}
	}

	if((n1+n2)&1){
		return double(max(leftElement1,leftElement2));
	}else{
		double w1 = double(max(leftElement1,leftElement2));
		double w2 = double(min(rightElement1,rightElement2));
		double w = (w1+w2)/2.0;
		return w;
	}
}

int kthElementOfTwoSortedArrays(vector<int> &nums1,vector<int> &nums2,int k){
	int n1 = nums1.size();
	int n2 = nums2.size();
	if(n1 > n2) return kthElementOfTwoSortedArrays(nums2,nums1,k);

	int leftElementsRequired = k;
	int l = max(0,(leftElementsRequired - n2));
	int h = min(leftElementsRequired,n1);

	wer(n1);
	wer(n2);
	wer(l);
	wer(h);
	wer(leftElementsRequired);

	int leftElement1,leftElement2,rightElement1,rightElement2;

	while(l <= h){
		wer(l);
		wer(h);

		int m = l + ((h-l)/2);

		wer(m);

		int elementsRequiredFromOtherArray = leftElementsRequired - m;

		leftElement1 = INT_MIN;
		if(m-1 >= 0) leftElement1 = nums1[m-1];

		rightElement1 = INT_MAX;
		if(m < n1) rightElement1 = nums1[m];

		leftElement2 = INT_MIN;
		if((elementsRequiredFromOtherArray - 1) >= 0) leftElement2 = nums2[elementsRequiredFromOtherArray-1];

		rightElement2 = INT_MAX;
		if(elementsRequiredFromOtherArray < n2) rightElement2 = nums2[elementsRequiredFromOtherArray];

		wer(leftElement1);
		wer(rightElement1);

		wer(leftElement2);
		wer(rightElement2);


		if((leftElement1 <= rightElement2) && (leftElement2 <= rightElement1)){
			break;
		}else if(leftElement1 > rightElement2){
			h = m - 1;
		}else{
			l = m + 1;
		}
	}

	return max(leftElement1,leftElement2);
}

bool checkIfEachStudentCanReadAtmostMPages(long long pages,vector<int> &a,int students){
	int studentsNeeded = 1;
	long long currentPageCount = 0;
	for(int i=0;i<a.size();i++){
		currentPageCount += (long long)a[i];
		if(currentPageCount > pages){
			studentsNeeded++;
			currentPageCount = 0;
			i--;
			if(studentsNeeded > students) {
				return false;
			}
		}
	}
	return true;
	// Don't worry about if all the students would be able to read or not
	// Consider b1,b2,b3,b4,b5,b6 and we have 5 students, and we have a certain m 
	// in which it gets distributed like this, [b1,b2] [b3,b4] [b5,b6] because b1+b2 <= m && b3+b4 <= m and b5+b6 <= m
	// now we can say that, in this case also we will return true, it looks like only 3 students are getting a book to read
	// but we can always in this case do that, [b1,b2] , b3 , b4 , b5 , b6, // now the books are distrbuted in 5 students
	// and as b3 + b4 <=m therefoe b3 <= m and also b4 <= m similiary for b5 and b6
	// that is why we return true
}

int allocateMinimumNumberOfPages(vector<int> &a,int n,int students){
	long long l = 0;
	long long h = 0;
	for(auto &x : a){
		h += (long long)(x);
	}

	int ans = -1;

	if(students > a.size()){
		return -1;
	}

	while(l <= h){
		wer(l);
		wer(h);
		long long m = l + ((h-l)/2);
		wer(m);
		if(checkIfEachStudentCanReadAtmostMPages(m,a,students)){
			ans = m;
			h = m-1;
		}else{
			l = m+1;
		}
	}

	return ans;
}

bool canPlaceCowsAtDistanceM(vector<int> &pos,int cows,int m){
	int cowsPlaced = 1;
	int lastPosition = pos[0];
	for(int i=1;i<pos.size();i++){
		if((pos[i] - lastPosition) >= m){
			lastPosition = pos[i];
			cowsPlaced++;
			if(cowsPlaced == cows) return true;
		}
	}
	return false;
}

int aggressiveCows(vector<int> &pos,int cows){
	sort(pos.begin(),pos.end());
	int l = 1;
	int h = pos[pos.size()-1] - pos[0];
	int ans = 0;
	while(l <= h){
		int m = l + ((h-l)/2);
		if(canPlaceCowsAtDistanceM(pos,cows,m)){
			ans = m;
			l = m + 1;
		}else{
			h = m - 1;
		}
	}

	return ans;
}

int main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		//cout << NthRoot(9,1953125);

		// vector<vector<int>> v = {{1,2,3},{8,8,11},{4,5,8}};
		// cout << median(v,3,3);

		// vector<int> v = {1,1,2,3,3,4,4,8,8};
		// cout << singleNonDuplicate(v);

		// vector<int> v = {5,1,3};
		// cout << search(v,1);

		// vector<int> v1 = {1};
		// vector<int> v2 = {2,3,4,5,6,7};
		// cout << findMedianSortedArrays(v1,v2);


		// vector<int> v1 = {20,28,37};
		// vector<int> v2 = {1,2,4,5,5,6,6,9,10,12,13,14,15,16,16,17,17,17,20,22,22,22,23,23,23,24,27,29,30,31,33,37,38,38,40,41,42,45,47,52,52,52,56,56,57,62,63,64,65,66,66,66,67,67,72,74,77,78,79,83,83,84,84,87,88,88,89,90,90,92,95,95,97,97,100,100};
		// cout << kthElementOfTwoSortedArrays(v1,v2,78);

		vector<int> books = {5,10,19,10,5,18,7};
		cout << allocateMinimumNumberOfPages(books,7,5);

		// vector<int> pos = {8,4,9,1,2};
		// cout << aggressiveCows(pos,3);

	}
	return 0;
}
  