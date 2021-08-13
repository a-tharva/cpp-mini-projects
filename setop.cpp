 #include<iostream>
using namespace std;
class student
{
 int a[20],b[20],c[40],d[30],u[20],e[10],f[10]; 
 int i,j,k,p,m,n,l,g,flag;
 	public:
	void get();
	void display();
	void intersection();
	void uni();
	void only_c();
	void only_b();

};
void student::get()
{
	cout<<"\nEnter No. Of Students In Class\n";
	cin>>p;
     cout<<"\nEnter Roll Number of Students In Class\n";
	for( i=0;i<p;i++)
     	{
      		cin>>a[i];
		}	
     
     cout<<"\nEnter No. Of Students Playing Cricket\n";
		cin>>m;
     cout<<"\nEnter Roll Number of Students Playing Cricket\n";
		for( i=0;i<m;i++)
    		 {
      			cin>>c[i];
			}   

	cout<<"\nEnter No. Of Students Playing Badminton\n";
	cin>>n;
     cout<<"\nEnter Roll Number of Students Playing Badmiton\n";
		for( j=0;j<n;j++)
     		{
      			cin>>b[j];
			}	
}
	   		
void student::display()
{
	cout<<"\nTotal  Students Are:"<<p<<"\n";
	
	for( i=0;i<p;i++)
	{
		cout<<a[i]<<" "<<"\t";
    }
     
   	cout<<"\nTotal  Students Playing Cricket Are:"<<m<<"\n";
   	
    for(i=0;i<m;i++)
    {
    	cout<<c[i]<<" "<<"\t";
	}
	cout<<"\nTotal  Students Playing Badminton Are:"<<n<<"\n"; 
	
	for(j=0;j<n;j++)
	{
		cout<<b[j]<<" "<<"\t";
	}
	
}


void student::intersection()
{
	k=0;
	for( i=0;i<m;i++)
	{
		for( j=0;j<n;j++)
		{
			if(c[i]==b[j])
			{
				d[k]=c[i];
				k++;	
			}	
		}
	}
	cout<<"\nstudents Playing Both Games Are:"<<k<<"\n";
	for( i=0;i<k;i++)
	{
		cout<<"  "<<d[i];
		if(i!=k-1)
		{
		  cout<<"\t";
		}
	}
	
}
void student::uni()
{
	l=0;
	for(i=0;i<m;i++)
	  {
	   flag=0;
	   for(j=0;j<n;j++)
	   {
	    if(c[i]==b[j])
	     {
	      flag=1;
	      }
	    }
	    if(flag==0)
	    {
	     u[l]=c[i];
	     l++;
	     }
	   }
	  
	  for(j=0;j<n;j++)
	   {
	   u[l]=b[j];
	   l++;
	    }
	    cout<<"\nUNION Students:"<<l<<"\n";
	   for(i=0;i<l;i++)
	   {
	   
	  cout<<u[i]<<"\t";
	    }
	    
 }
	   		

void student::only_c()
{
 l=0;
 for(i=0;i<m;i++)
  {
   flag=0;
   for(j=0;j<n;j++)
   {
    if(c[i]==b[j])
   {
    flag=1;
    }
   }
  if(flag==0)
  {
   e[l]=c[i];
   l++;
   }
  }
  cout<<"\nRoll no of Students who Play only CRICKET:"<<"\n";
  for(i=0;i<l;i++)
  {
  cout<<" "<<e[i]<<"\t";
   }
 }
 void student::only_b()
 {
  g=0;
 for(i=0;i<m;i++)
  {
   flag=0;
   for(j=0;j<n;j++)
   {
    if(b[i]==c[j])
   {
    flag=1;
    }
   }
  if(flag==0)
  {
   f[g]=b[i];
   g++;
   }
  }
  cout<<"\n Roll no of Students who Play only BADMINTON:"<<"\n";
  for(i=0;i<g;i++)
  {
  cout<<" "<<f[i]<<"\t";
   }
   
 }

	   
int main()
{
	student s;
	s.get();
	s.display();
	s.intersection();
	s.uni();
	
	s.only_c();
	s.only_b();
	return 0;
	
}
/*  
output:

Enter No. Of Students In Class
5

Enter Roll Number of Students In Class
1
2
3
4
5

Enter No. Of Students Playing Cricket
2

Enter Roll Number of Students Playing Cricket
1
2

Enter No. Of Students Playing Badminton
3

Enter Roll Number of Students Playing Badmiton
3
4
5

Total  Students Are:5
1 	2 	3 	4 	5 	
Total  Students Playing Cricket Are:2
1 	2 	
Total  Students Playing Badminton Are:3
3 	4 	5 	
students Playing Both Games Are:0

UNION Students:5
1	2	3	4	5	
Roll no of Students who Play only CRICKET:
 1	 2	
 Roll no of Students who Play only BADMINTON:
 3	 4	*/
