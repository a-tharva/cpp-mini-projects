#include<iostream>
using namespace std;
int partition(float a[20],int p,int r)
{
int x=a[r],i,j;
float temp;
j=p;
i=p-1;
for(j=p;j<=r-1;j++)
{
if(a[j]<=x)
{
i=i+1;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[i+1];
a[i+1]=a[r];
a[r]=temp;
return i+1;
}
void quicksort(float a[20],int p,int r)
{
  int q;
  if(p<r)
  {
  q=partition(a,p,r);
  quicksort(a,p,q-1);
  quicksort(a,q+1,r);
  }
}
int main()
{
 float a[20];
 int i,n;
 cout<<"enter no of students";
 cin>>n;
 cout<<"enter percentage of students";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 int p=0,r=n-1;
 quicksort(a,p,r);
 cout<<"enter percentage of students in ascending order are";
 for(i=0;i<n;i++)
 {
  cout<<a[i];
 }
 return 0;
}

/*

OUTPUT:

enter no of students 
5
enter percentage of students
75

45
79
65
98
enter percentage of students in ascending order are
45
65
75
79
98

*/


