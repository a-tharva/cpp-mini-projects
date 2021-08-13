#include<iostream>
#include<stdlib.h>
using namespace std;
 
class node
{
	int data;
	node *next;
	friend class sll;
 
};
 
class sll
{
	node *head1, *head2,*last;
	public:
	sll()	
	{	
		head1=head2=NULL;
	}
	void insert();
	void display1();
	void delnegative();
	void split();
	void merge();
	void display2();
	void sortlists();
	void sort(node *t);
};
 
 
void sll::insert()
{
	int n,i,j;
	node *t,*p;
	cout<<"\nEnter total nodes of insert: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		t=new node; 
		j=i+1;
		cout<<"\nEnter data "<<j<<" : " ;
		cin>>t->data;
		t->next=NULL;
		if(head1==NULL)
			head1=t;
		else
		{	
			p=head1; 
			while(p->next!=NULL)
				p=p->next; 
			p->next=t; 
		}
	}
} 
void sll::display1()
{
	node *t;
	cout<<"List is shown below"<<endl;
	if (head1==NULL)
		cout<<"\nList is EMPTY";
	else
		t=head1;
	
		
	do
	{
		cout<<t->data<<endl;
		t=t->next;
	}
	while(t!=NULL);
}
 
void sll::display2()
{
	node *t;
	cout<<"list is shown below"<<endl;
	if (head1==NULL)
		cout<<"\nEMPTY";
	else
		t=head2;
	do
	{
		cout<<t->data<<endl;
		t=t->next;
	}
	while(t!=NULL);
}
 
void sll::delnegative()
{
	node *t,*p;
	if (head1==NULL)
		cout<<"\nEmpty list..... nothing to be delete"<<endl;
	else
	{
		
		t=head1->next; 
		p=head1; 
		while(t!=NULL)
		{
			if (t->data<0) 
			{
				p->next=t->next;
				delete t;
				t=p->next;
			}
			else
			{
				p=t;
				t=p->next;
			}
		}
 
		if(head1->data<0) 
		{
			t=head1;
			head1=head1->next;
			delete t;
		}
	}
}//
 
void sll::split()
{
	node *t,*p;
	if (head1==NULL)
		cout<<"\nEmpty list..... nothing to be split"<<endl;
	else
	{
		
		t=head1->next; 
		p=head1; 
		while(t!=NULL)
		{
			if (t->data<0) 
			{
				p->next=t->next;
				if(head2==NULL)
				{
					head2=t;
					last=t;
					last->next=NULL;
				}
				else
				{
					last->next=t;
					last=t;
					last->next=NULL;
				}
				t=p->next;
			}
			else
			{
				p=t;
				t=p->next;
			}
		}
 
		if(head1->data<0) 
		{
			t=head1;
			head1=head1->next;
			if(head2==NULL)
			{
				head2=t;
				last=t;
				last->next=NULL;
			}
			else
			{
				t->next=head2;
				head2=t;
			}
		}
 	}
}//
 
void sll::sortlists()
{
	sort(head1);
	cout<<"\nAfter sorting first List of +ve no.:\n ";
	display1();
	sort(head2);
	cout<<"\nAfter sorting second List of -ve no.:\n ";
	display2();
}//
 
void sll::sort(node *t)
{
	node *t1,*t2;
	int temp;
	if(t==NULL)
		return;
	for(t1=t;t1->next!=NULL;t1=t1->next)
	{
		for(t2=t1->next;t2!=NULL;t2=t2->next)
		{
			if(t1->data > t2->data)
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
 	}
}//
 
void sll::merge()
{
	last->next=head1; 
	head1=head2;
	head2=NULL;
	cout<<"\nMerged ";
	display1();
}
 
int main()
{
	sll obj;
	int ch;
	while(1)
	{	
		cout<<"\n---------MENU---------"<<endl;
		cout<<"\n1.INSERT \n2.DISPLAY \n3.DELETE NEGATIVE \n4.SPLIT \n5.SORT & MERGE \n6.EXIT"<<endl;
		cout<<"\nEnter your choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.insert();
				break;
			case 2:
				obj.display1();
				break;
			case 3 :
				obj.delnegative();
				cout<<"\nAfter deletion of -Ve no: ";
				obj.display1();
				break;
			case 4:
				obj.split();
				cout<<"\nAfter splitting:"<<endl;
				cout<<"\nFirst List of +ve no.:";
				obj.display1();
				cout<<"\nSecond List of -ve no.: ";
				obj.display2();
				break;
			case 5:
				obj.sortlists();
				obj.merge();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nWrong choice";
		}
	}
	return 0;
}
 



/*
OUTPUT:

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :

1

Enter total nodes of insert: 4

Enter data 1 : 2

Enter data 2 : -4

Enter data 3 : 3

Enter data 4 : -6

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
2
List is shown below
2
-4
3
-6

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
4

After splitting:

First List of +ve no.:List is shown below
2
3

Second List of -ve no.: list is shown below
-4
-6

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
5

After sorting first List of +ve no.:
 List is shown below
2
3

After sorting second List of -ve no.:
 list is shown below
-6
-4

Merged List is shown below
-6
-4
2
3

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
3

After deletion of -Ve no: List is shown below
2
3

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
2
List is shown below
2
3

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
3

After deletion of -Ve no: List is shown below
2
3

---------MENU---------

1.INSERT 
2.DISPLAY 
3.DELETE NEGATIVE 
4.SPLIT 
5.SORT & MERGE 
6.EXIT

Enter your choice :
6
*/
