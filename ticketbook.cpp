#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
 public:
 char data;
 Node *prev,*next,*n1;
 };
class ticket
{
 int i,j,k,m,n,a,b,t,x;
 char seat[2];
 char r[8];
 char c[10];
 Node *head[10],*last[10],*temp,*n1;
 public:
  void create()
  {
   for(i=0;i<10;i++)
   {
    head[i]=last[i]=NULL;
    for(j=0;j<10;j++)
    {
     n1=new Node;
     n1->next=n1;
     n1->prev=n1;
     n1->data='_';
     if(head[i]==NULL)
     {
      head[i]=n1;
      last[i]=n1;
      }
      else
      {
       last[i]->next=n1;
       n1->prev=last[i];
       n1->next=head[i];
       last[i]=n1;
       }
      }
     }
    }
 void display()
 {
  char r[8]={' ','1','2','3','4','5','6','7'};
  char c[10]={'A','B','C','D','E','F','G','H','I','J'};   
  cout<<"\n\t\tENTRY\t\t\n";
  cout<<"\t";
  cout<<r[0]<<"  ";
  for(i=1;i<8;i++)
   cout<<""<<r[i]<<"  ";
   cout<<"\n\t";
    for(i=0;i<10;i++)
    {
     cout<<c[i]<<"  ";
     temp=head[i];
     for(j=0;j<7;j++)
     {
      cout<<"["<<temp->data<<"]";
      temp=temp->next;
      }
       cout<<"\n\t";
       }
       cout<<"_________\n\t\t SCREEN______"<<"\n";
       }
 void book()
 {
  cout<<"Enter total number of seats to book\n";
  cin>>t;
  for(i=0;i<t;i++)
  {
   cout<<"\n Enter seat number\n"<<i<<":";
   cin>>seat;
   m=seat[0]%65;
   n=seat[1]%48;
   temp=head[m];
   for(j=0;j<n-1;j++)
   {
    temp=temp->next;
    }
    temp->data='x';
    }
    } 
 void cancel()
 {
  cout<<"Enter total number of seats to cancel\n";
  cin>>t;
  for(i=0;i<t;i++)
  {
   cout<<"\nEnter seat number:\n"<<a<<":";
   cin>>seat;
   m=seat[0]%65;
   n=seat[1]%48;
   temp=head[m];
   for(j=0;j<n-1;j++)
   {
    temp=temp->next;
    }
    if(temp->data=='x')
    {
    temp->data='_';
     }
     else
    {
     cout<<"\n Ticket not booked to cancel\n";
     }
     }
     }
    }; 
       
int main()
{
	int o;
	char ch;
 ticket t;
 t.create();
 t.display();
 do 
 {
   cout<<"choose\n 1.BOOK\n2.CANCEL\n3.END"<<"\n";
   cin>>o;
   switch(o)
   {
   	case 1:
   		{
		   
   		t.book();
   		t.display();
   		break;
   	   }
   	   case 2:
   	   	{
   	   		t.cancel();
   	   		t.display();
   	   		break;
   	   	}
   	   	case 3:
   	   		{
   	   			exit(0);
   	   			break;
				  }
				  default:cout<<"ENTER VALID CHOICE!!!";
			  }
			  cout<<"enter y to continue\n";
			  cin>>ch;
  }
  while(ch=='y'||ch=='Y');
  return 0;	   	
 }
 /*

OUTPUT:


     		ENTRY		
	   1  2  3  4  5  6  7  
	A  [_][_][_][_][_][_][_]
	B  [_][_][_][_][_][_][_]
	C  [_][_][_][_][_][_][_]
	D  [_][_][_][_][_][_][_]
	E  [_][_][_][_][_][_][_]
	F  [_][_][_][_][_][_][_]
	G  [_][_][_][_][_][_][_]
	H  [_][_][_][_][_][_][_]
	I  [_][_][_][_][_][_][_]
	J  [_][_][_][_][_][_][_]
	_________
		 SCREEN______
choose
 1.BOOK
2.CANCEL
3.END
1
Enter total number of seats to book
2

 Enter seat number
0:A2

 Enter seat number
1:B2

		ENTRY		
	   1  2  3  4  5  6  7  
	A  [_][x][_][_][_][_][_]
	B  [_][x][_][_][_][_][_]
	C  [_][_][_][_][_][_][_]
	D  [_][_][_][_][_][_][_]
	E  [_][_][_][_][_][_][_]
	F  [_][_][_][_][_][_][_]
	G  [_][_][_][_][_][_][_]
	H  [_][_][_][_][_][_][_]
	I  [_][_][_][_][_][_][_]
	J  [_][_][_][_][_][_][_]
	_________
		 SCREEN______
enter y to continue
y
choose
 1.BOOK
2.CANCEL
3.END
2
Enter total number of seats to cancel
1

Enter seat number:
32631:B2

		ENTRY		
	   1  2  3  4  5  6  7  
	A  [_][x][_][_][_][_][_]
	B  [_][_][_][_][_][_][_]
	C  [_][_][_][_][_][_][_]
	D  [_][_][_][_][_][_][_]
	E  [_][_][_][_][_][_][_]
	F  [_][_][_][_][_][_][_]
	G  [_][_][_][_][_][_][_]
	H  [_][_][_][_][_][_][_]
	I  [_][_][_][_][_][_][_]
	J  [_][_][_][_][_][_][_]
	_________
		 SCREEN______
enter y to continue
Y
choose
 1.BOOK
2.CANCEL
3.END
3

*/
