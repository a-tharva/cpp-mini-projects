#include<iostream>
using namespace std;
class mat
{
	int i,j,k,a[3][3],b[3][3],c[3][3];
	int sum,count,ch,m,n,temp;
	public:
	void get();
	void display();
	int add();
	int sub();
	int mul();
	int trans_A();
	int uppertri();
	int lowertri();
	int diagonal1();
	int diagonal2();
};
void mat::get()
{

        cout<<"Enter the number of rows:"<<"\n";
	cin>>m;


	cout<<"Enter the number of columns:"<<"\n";
	cin>>n;
    
     
	cout<<"Enter Elements of first matrix="<<"\n";
        for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cin>>a[i][j];
		}
	}
	cout<<"Enter Elements of second matrix"<<"\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cin>>b[i][j];
		}
	}





	cout<<" first matrix is:"<<"\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cout<<a[i][j]<<"\t";
		}
cout<<"\n";
	}

         cout<<" second matrix is:"<<"\n";
for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cout<<b[i][j]<<"\t";

		}
cout<<"\n";
	}
}


int mat::add()
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		c[i][j]=a[i][j]+b[i][j];
		}
	}
}
int mat::sub()
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
}
int mat::mul()
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<m;k++)
			{
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
}
int mat::trans_A()
{
	 
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{

temp=a[i][j];
a[i][j]=a[j][i];
a[j][i]=temp;}
}

cout<<"Transpose of matrix is(for A)="<<"\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cout<<a[j][i]<<"\t";

		}
        cout<<"\n";

	}
}
 
int mat::uppertri()
{
	sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(i<j)
sum=sum+a[i][j];

}
}
cout<<"Sum of  upper triangular matrix 'A' is:"<<sum<<"\n";
}

int mat::lowertri()
{

	sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(i>j)
sum=sum+a[i][j];

}
}
cout<<"Sum of  lower triangular matrix 'A' is:"<<sum<<"\n";
}
int mat::diagonal1()
{
sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(i==j)

sum=sum+a[i][j];
}
}
cout<<"Sum of diagonal elements (left to right) of 'A' is:"<<sum<<"\n";
}
int mat::diagonal2()
{
sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if((i+j==2))

sum=sum+a[i][j];
}
}
cout<<"Sum of diagonal elements (right to left) of 'A' is:"<<sum<<"\n";
}
void mat::display()
{
	
	cout<<"solution is="<<"\n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
	cout<<c[i][j]<<"\t";

		}
        cout<<"\n";

	}
	

}
int main()
{
mat m;
int ch;
char op,y;
do
{

   cout<<"\t\t\tCHOOSE OPERATION\n\n 1.Addition \n 2.Subtraction\n 3.Multiplication \n 4.Transpose of A \n 5.Sum of Upper triangular elements of A\n 6.Sum of Lower triangular elements of A\n 7.Sum of diagonal elements(left to right) of matrix A \n 8.Sum of diagonal elements(right to left) of matrix A \n ";
	cin>>ch;
	
	switch(ch)
	{
	case 1:
	m.get();
	m.add();
	m.display();
	break;
	case 2:
	m.get();
	m.sub();
	m.display();
	break; 
	case 3:
	m.get();
	m.mul();
	m.display();
	break;
	case 4:
        m.get();
	m.trans_A();
	break;
	case 5:
        m.get();
	m.uppertri();
	break;
	case 6:
        m.get();
	m.lowertri();
	break;
	case 7:
        m.get();
	m.diagonal1();
	break;
	case 8:
        m.get();
	m.diagonal2();
	break;
	default:
	cout<<"wrong choice"<<"\n";
	break;
	}
 cout<<"Press y to continue...."<<"\n";
cin>>op;

}while(op=='y');
return 0;                                               
 }



/*
           OUTPUT:

	CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 1
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
4
3
2
1
 first matrix is:
1	2	
3	4	
 second matrix is:
4	3	
2	1	
solution is=
5	5	
5	5	
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 2
Enter the number of rows:
23
Enter the number of columns:
^C
[sinhgad@localhost ~]$ clear
[3;J
[sinhgad@localhost ~]$ g++ matrixop.cpp
[sinhgad@localhost ~]$ ./a.out
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 1
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
solution is=
6	8	
10	12	
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 2
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
solution is=
-4	-4	
-4	-4	
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 3
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
solution is=
19	22	
43	50	
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 4
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
Transpose of matrix is(for A)=
1	3	
2	4	
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 5
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3

4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
Sum of  upper triangular matrix 'A' is:2
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 6
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
Sum of  lower triangular matrix 'A' is:3
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 7
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=

2
3
4
5
Enter Elements of second matrix
6
7
8
9
 first matrix is:
2	3	
4	5	
 second matrix is:
6	7	
8	9	
Sum of diagonal elements (left to right) of 'A' is:7
Press y to continue....
y
			CHOOSE OPERATION

 1.Addition 
 2.Subtraction
 3.Multiplication 
 4.Transpose of A 
 5.Sum of Upper triangular elements of A
 6.Sum of Lower triangular elements of A
 7.Sum of diagonal elements(left to right) of matrix A 
 8.Sum of diagonal elements(right to left) of matrix A 
 8
Enter the number of rows:
2
Enter the number of columns:
2
Enter Elements of first matrix=
1
2
3
4
Enter Elements of second matrix
5
6
7
8
 first matrix is:
1	2	
3	4	
 second matrix is:
5	6	
7	8	
Sum of diagonal elements (right to left) of 'A' is:4
Press y to continue....

*/
