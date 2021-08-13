#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int i,h,l,mid,key,flag,size,ch;
	char r;
	
	do
	{
		cout<<"Enter your choice \n 1.Binary Search \n 2.Sentinental Linear Search \n";
		cin>>ch;
		switch(ch)
		{
		
		case 1:
			cout<<"Enter the size"<<"\n";
			cin>>size;
			cout<<"Enter sorted data"<<"\n";
	
			for(i=0;i<size;i++)
			{
				cin>>a[i];
			}
			cout<<"Enter key"<<"\n";
			cin>>key;
	
			l=0;
			h=size;
	
			for(i=0;i<=size;i++)
			{
				mid=((l+h)/2);
		
				if(a[mid]==key)
				{
					flag=0;
					break;
				}
				else if(a[mid]<key)
				{
					l=mid;
					//flag=1;
					continue;
				}
				else 
				{
					h=mid;
					//flag=1;
					continue;
				}
		
			}
			
			if(flag==0)
			{
			cout<<"Found"<<"\n";
			}
			else
			{
			cout<<"Not Found"<<"\n";
			}
		break;
		
		case 2:
		
		
			cout<<"Enter the size"<<"\n";
			cin>>size;
			cout<<"Enter sorted data"<<"\n";
	
			for(i=0;i<size;i++)
			{
				cin>>a[i];
			}
			cout<<"Enter key"<<"\n";
			cin>>key;
			
			a[size]=key;
			
			for(i=0;i<size;i++)
			{
				if(a[i]==key)
				{
					//cout<<"Found"<<"\n";
					flag=0;
					break;
				}
				else
				{
					//cout<<"Not found"<<"\n";
					flag=1;
				}
			}
			
			if(flag==0)
			{
			cout<<"Found"<<"\n";
			}
			else
			{
			cout<<"Not found"<<"\n";
			}
		break;
		
		default:
			cout<<"Wrong choice"<<"\n";
		break;
		}
		
	cout<<"Do you want to continue?(y/n)"<<"\n";
	cin>>r;
	}while(r=='y');
	
	return 0;
}
		

/*

OUTPUT:

Enter your choice 
 1.Binary Search 
 2.Sentinental Linear Search 
1
Enter the size
2
Enter sorted data
2
4
Enter key
2
Found
Do you want to continue?(y/n)
y
Enter your choice 
 1.Binary Search 
 2.Sentinental Linear Search 
1
Enter the size
2
Enter sorted data
2
4
Enter key
5
Found
Do you want to continue?(y/n)
y
Enter your choice 
 1.Binary Search 
 2.Sentinental Linear Search 
2
Enter the size
2
Enter sorted data
2
3
Enter key
2
Found
Do you want to continue?(y/n)
y
Enter your choice 
 1.Binary Search 
 2.Sentinental Linear Search 
2
Enter the size
2
Enter sorted data
2
3
Enter key
5
Not found
*/
