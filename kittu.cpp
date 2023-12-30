#include<iostream>
using namespace std;
class Array
{
private:
int *A;
int l;
int s;
public:
Array(int si,int le)
{
    l=le;
    s=si;
    A=new int[s];
}
void fillarray();
void append(int data);
void insertt(int index,int data);
void deletee(int in);
void lsearch(int key);
void bsearch(int);
void display();
};
void Array::bsearch(int key)
{
int low,high,mid,found=0;
low=0;
high=l-1;
mid=((low+high)/2);
while(low<=high)
{
if(key>A[mid])
{
   low=mid+1;
}
else if(key<A[mid])
{
    high=mid-1;
}
else if(key==A[mid])
{
cout<<"the element "<<key<<" is found at index "<<mid<<endl;
break;
}
mid=((low+high)/2);
}
if(low>high)
{
    cout<<"the element is not found"<<endl;
}

}

void Array::lsearch(int key)
{
  /*  for(int i=0;i<l;i++)
    {
        if(key==A[i])
            cout<<"element is found at index "<<endl <<" "<<i<<"and the key is "<<A[i]<<endl;
    }
    for (int i=0;i<l;i++)
    {
        if(key==A[i])
        {
        cout<<"element is found at index "<<endl <<" "<<i<<"and the key is "<<A[i]<<endl;
        swap(A[i],A[i-1]);
        }*/
        for (int i=0;i<l;i++)
    {
        if(key==A[i])
        {
        cout<<"element is found at index "<<endl <<" "<<i<<"and the key is "<<A[i]<<endl;
        swap(A[i],A[0]);
        }
    }
    }
void Array::deletee(int index)
{
    int x=0;
    if(index>=0 && index<=l)
    {
    x=A[index];
    cout<<"the deleted element is "<<x<<endl;
    for(int i=index;i<l-1;i++)
       {
       A[i]=A[i+1];
       }
       l--;
    }
}
void Array::insertt(int index,int data)
{
    int i;
if(index>=0 && index<=l)
{
    for(int i=l;i>index;i--)
    {
        A[i]=A[i-1];
    }
    A[index]=data;
    l++;
}
}
void Array::append(int data)
{
if(l<s)
{
    A[l]=data;
    l++;
}
}
void Array::fillarray()
{
    cout<<"entering the array elements"<<endl;
    for(int i=0;i<l;i++)
    {
        cin>>A[i];
    }
}
 void Array::display()
{
    cout<<"the array elements are"<<endl;
    for(int i=0;i<l;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int length,si;
    cout<<"enter the length"<<endl;
    cin>>length;
    cout<<"enter the size"<<endl;
    cin>>si;
    Array a(si,length);
    a.fillarray();
   /* int ele;
    cout<<"enter the element you want to add"<<endl;
    cin>>ele;
    a.append(ele);
    int index,data;
    cout<<"enter the index at which you want to insert the number"<<endl;
    cin>>index;
    cout<<"enter the data that is to added at the index we want to insert"<<endl;
    cin>>data;
    a.insertt(index,data);
    int in;
    cout<<"enter the index at which you want to delete"<<endl;
    cin>>in;
    a.deletee(in);
    int key;
    cout<<"enter the key element you are looking for"<<endl;
    cin>>key;
   a.lsearch(key); */
   int key;
   cout<<"enter the key element which you want ot find"<<endl;
   cin>>key;
   a.bsearch(key);
   // a.display();
    return 0;
}

