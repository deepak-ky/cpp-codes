int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
  cin>>a[i];
}

cout<<"\nWithout sorting : ";
for(int i=0;i<n;i++)
{
  cout<<a[i];
}
for(int i=0;i<n;i++)
{

   for(int j=i+1;j<n;j++)
   {

     if(a[j]<a[i])
     {
      swap(a[j],a[i]);

     }
   }
}

cout<<"\nAfter sorting : ";
for(int i=0;i<n;i++)
{
  cout<<a[i];
}



