/*
Perfect Sum problem:
Given an array of elements and a sum, print all subsets
which adds upto the given sum.
Example: arr = [1, 7, 3, 5, 6] and sum = 8, the solutions possible
are [1, 7], [3, 5].
*/

#include<bits/stdc++.h>
using namespace std;

int fllag = 0;
int mincount[100];
int j=0;
void isSubsetSum(int arr[], int subset[], int N, int subsetSize,
                             int subsetSum, int index ,int sum)
{
    if (subsetSum == sum)
    {
        fllag = 1;
        int count=0;

        for (int i = 0; i < subsetSize; i++)
        {
            count++;
            cout << subset[i] << " :  ";
        }
            mincount[j++]=count;
            cout<<" and the size of this subset is : "<<count;
            cout << endl;
    }
    else
    {
        for (int i = index; i < N; i++)
        {
            subset[subsetSize] = arr[i];
            isSubsetSum(arr, subset, N, subsetSize + 1,
                        subsetSum + arr[i], i + 1, sum);
        }
    }
}

int main()
{
    cout << "Enter size of array" << endl;
    int N;
    cin >> N;
    cout << "Enter elements of array" << endl;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout<< "Enter sum" << endl;
    int sum;
    cin >> sum;
    int *subset = new int[N];
    isSubsetSum(arr, subset, N, 0, 0, 0, sum);
    if (fllag == 0) {
        cout << "No such subset present" << endl;
    }
    cout<<endl<<endl;
    cout<<"The array of counts is : ";

for(int d=0;d<j;d++)
{
    cout<<" "<<mincount[d];
}
    return 0;
}

/*
INPUT:
N = 5
arr = [1 2 3 4 5]
sum = 7
OUTPUT:
1  2  4
2  5
3  4
*/
