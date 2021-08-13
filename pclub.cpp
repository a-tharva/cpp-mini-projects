#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
public:
int prn;
string name;
node *next;
};
class pclub
{
public:
node *pres,*sec,*mem;
pclub();
void getnode();
void display();
void addmember();
void addpres();
void addsec();
void delmem();
void delpres();
void delsec();
int len(node *);
void rev(node *);
void concat(pclub,pclub);
};
pclub::pclub()
{
pres=NULL;
sec=NULL;
}
int pclub::len(node *temp)
{
int count=0;
while(temp!=NULL)
{
    temp=temp->next;
    count++;
}
return count;
}
void pclub::getnode()
{
pres=new node;
cout<<"\nEnter name of the president:";
cin>>pres->name;
cout<<"\nEnter PRN:";
cin>>pres->prn;

sec=new node;
cout<<"\nEnter name of the Secretary:";
cin>>sec->name;
cout<<"\nEnter PRN:";
cin>>sec->prn;


mem=new node;
cout<<"\nEnter name of the member:";
cin>>mem->name;
cout<<"\nEnter PRN:";
cin>>mem->prn;

pres->next=mem;
mem->next=sec;
sec->next=NULL;

}
void pclub::display()
{
node *temp=pres;
if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{cout<<"\nNAME"<<"\t\tPRN";
while(temp!=NULL)
{
cout<<"\n"<<temp->name;
cout<<"\t\t"<<temp->prn;
if(temp==pres)
    cout<<"(President)";
else if(temp==sec)
    cout<<"(secretary)";
temp=temp->next;
}
}
cout<<"\n\nMember Strength is::"<<len(pres)<<"\n";
}
void pclub::rev(node *temp)
{
    if(temp!=NULL)
    {
    rev(temp->next);
    cout<<"\n"<<temp->name;
    cout<<"\t\t"<<temp->prn;
    if(temp==pres)
    cout<<"(President)";
    else if(temp==sec)
    cout<<"(secretary)";
    }
}
void pclub::addmember()
{char i;
node *temp1=new node,*temp=new node;
temp=pres;
if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{
cout<<"\nEnter name of the member:";
cin>>temp1->name;
cout<<"\nEnter PRN:";
cin>>temp1->prn;
while((temp->next)->next!=NULL)
{
    temp=temp->next;
}
temp1->next=sec;
temp->next=temp1;
}
}
void pclub::addpres()
{int d,prn2;
    cout<<"\n1.Existing member appointed\n2.New member appointed\n";
	cin>>d;
switch(d)
{
    case 1:
    {
        node*temp1=new node;
        node *temp=new node; 
		temp=pres;
if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{
        cout<<"Enter prn of member::";
		cin>>prn2;
         if(prn2==sec->prn)
    {
        cout<<"\nSorry please select another member:";
        cout<<"\nEnter prn of member::";
		cin>>prn2;
    }
    while(temp->next!=NULL)
    {
        if(temp->prn==prn2)
            break;
        else
            {
                temp1=temp;
                temp=temp->next;
            }
    }
    temp1->next=temp->next;
    temp->next=pres;
    pres=temp;
 }   }break;
case 2:
    {
    node *temp1=new node;
    cout<<"\nEnter name of the new president:";
    cin>>temp1->name;
    cout<<"\nEnter PRN:";
    cin>>temp1->prn;
    temp1->next=pres;
    pres=temp1;
    }break;
}
}
void pclub::addsec()
{int d,prn2;
    cout<<"\n1.Existing member appointed\n2.New member appointed\n";cin>>d;
switch(d)
{
    case 1:
    {
        node *temp=new node;
        node *temp1=new node;
        temp=pres;
if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{   cout<<"Enter prn of member::";
	cin>>prn2;
    if(prn2==pres->prn)
    {
        cout<<"\nSorry please select another member:";
        cout<<"\nEnter prn of member::";
		cin>>prn2;
    }
    while(temp->next!=NULL)

    {
        if(temp->prn==prn2)
            break;
        else
            {
                temp1=temp;
                temp=temp->next;
            }
    }
    temp1->next=temp->next;
	temp->next=NULL;
    sec->next=temp;
    temp->next=NULL;
    sec=temp;
   } }break;
case 2:
    {
    node *temp1=new node;
    cout<<"\nEnter name of the new Secretary:";
    cin>>temp1->name;
    cout<<"\nEnter PRN:";
    cin>>temp1->prn;
    sec->next=temp1;temp1->next=NULL;
    sec=temp1;
    }break;
}
}
void pclub::delmem()
{
  node *temp=new node,*temp1=new node;int prn2;
  temp=pres;
 if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{
  cout<<"Enter prn of member::";cin>>prn2;
    while(temp->next!=NULL)
    {
        if(temp->prn==prn2)
            break;
        else
            {
                temp1=temp;
                temp=temp->next;
            }
    }
    temp1->next=temp->next;
        delete temp;
}
}
void pclub::delpres()
{
    node *temp=new node;
    temp=pres;
 if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{
   pres=pres->next;
    delete temp;
}
}
void pclub::delsec()
{
    node *temp=new node;
    temp=pres;
 if(temp==NULL)
{cout<<"\nList is empty!!!";}

else
{
   while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }
    sec=temp;
    sec->next=NULL;
    delete (temp->next);
}
}
void pclub::concat(pclub a,pclub b)
{
    if(a.pres==NULL||b.pres==NULL)
        cout<<"\nData required is unavailable!!";
    else
    {
    node *temp=new node,*temp1=new node;
    temp=a.pres;temp1=b.pres;
    pres=temp;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=temp1;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    sec=temp1->next=NULL;
    }
}
int main()
{
pclub p,p1,p2;int c,a;char ch,ch1;
while(1)
 {
     cout<<"\t\t\tPINNACLE CLUB\n";
     cout<<"\t\tDEPARTMENT OF COMPUTER ENGINEERING";
     cout<<"\n1.Division A\n2.Division B\n3.Concatenate A and B\n4.Exit\n";cin>>a;
 switch(a)
 {
     case 1:
     {
     do{ch='y';
     cout<<"\n1.create\n2.display\n3.Request membership\n4.New President\n5.New Secretary\n6.President resigns\n7.Secretary resigns\n8.Member resigns\n9.Display in reverse order\n0.Exit\n";cin>>c;
switch(c)
{
    case 1:
    {p.getnode();break;}
    case 2:
    {p.display();break;}
    case 3:
    {char i='y';
        do{
          p.addmember();
          cout<<"Enter another?(y/n)::";cin>>i;
          }while(i!='n');break;}
    case 4:
    {p.addpres();break;}
    case 5:
    {p.addsec();break;}
    case 6:
    {p.delpres();break;}
    case 7:
    {p.delsec();break;}
    case 8:
    {p.delmem();break;}
    case 9:
        {cout<<"\nNAME"<<"\t\tPRN";
            p.rev(p.pres);
            cout<<"\n\nMember Strength is::"<<p.len(p.pres);break;}
    case 0:
    {ch='n';break;}
}
}while(ch!='n');
}break;
 case 2:
   {
    do
    {ch='y';
    cout<<"\n1.create\n2.display\n3.Request membership\n4.New President\n5.New Secretary\n6.President resigns\n7.Secretary resigns\n8.Member resigns\n9.Display in reverse order\n0.Previous menu\n";cin>>c;
switch(c)
{
    case 1:
    {p1.getnode();break;}
    case 2:
    {p1.display();break;}
    case 3:
    {char i='y';
        do{
          p1.addmember();
          cout<<"Enter another?(y/n)::";cin>>i;
          }while(i!='n');break;}
    case 4:
    {p1.addpres();break;}
    case 5:
    {p1.addsec();break;}
    case 6:
    {p1.delpres();break;}
    case 7:
    {p1.delsec();break;}
    case 8:
    {p1.delmem();break;}
    case 9:
        {cout<<"\nNAME"<<"\t\tPRN";
        p1.rev(p1.pres);
        cout<<"\n\nMember Strength is::"<<p1.len(p1.pres);break;}
    case 0:
    {ch='n';break;}

}
}while(ch!='n');
}break;
case 3:
    {
	cout<<"New president of which division?(A/B)";cin>>ch1;
    if(ch1=='A')
    p2.concat(p,p1);
    else if(ch1=='B')
    p2.concat(p1,p);
    else
        {
		cout<<"\nEnter valid data!!!\n";}
    p2.display();break;
	}
case 4:exit(0);
}
}
return 0;
}


/*

OUTPUT:

	PINNACLE CLUB
		DEPARTMENT OF COMPUTER ENGINEERING
1.Division A
2.Division B
3.Concatenate A and B
4.Exit
1

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
1

Enter name of the president:sami

Enter PRN:456

Enter name of the Secretary:reva

Enter PRN:789

Enter name of the member:tara

Enter PRN:123

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
2

NAME		PRN
sami		456(President)
tara		123
reva		789(secretary)

Member Strength is::3

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
3

Enter name of the member:bhagu

Enter PRN:147
Enter another?(y/n)::n

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
2

NAME		PRN
sami		456(President)
tara		123
bhagu		147
reva		789(secretary)

Member Strength is::4

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
4

1.Existing member appointed
2.New member appointed
2

Enter name of the new president:roi

Enter PRN:258

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
2

NAME		PRN
roi		258(President)
sami		456
tara		123
bhagu		147
reva		789(secretary)

Member Strength is::5

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
5

1.Existing member appointed
2.New member appointed
1
Enter prn of member::789

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
2

NAME		PRN
roi		258(President)
sami		456
tara		123
bhagu		147(secretory)

Member Strength is::4

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
5

1.Existing member appointed
2.New member appointed
2

Enter name of the new Secretary:prt

Enter PRN:156

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
2

NAME		PRN
roi		258(President)
sami		456
tara		123
bhagu		147(secretory)

Member Strength is::4

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
9

NAME		PRN
bhagu		147(secretory)
tara		123
sami		456
roi		258(President)

Member Strength is::4
1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Exit
0
			PINNACLE CLUB
		DEPARTMENT OF COMPUTER ENGINEERING
1.Division A
2.Division B
3.Concatenate A and B
4.Exit
2

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Previous menu
1

Enter name of the president:rt

Enter PRN:12

Enter name of the Secretary:we

Enter PRN:45

Enter name of the member:op

Enter PRN:65

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Previous menu
2

NAME		PRN
rt		12(President)
op		65
we		45(secretary)

Member Strength is::3

1.create
2.display
3.Request membership
4.New President
5.New Secretary
6.President resigns
7.Secretary resigns
8.Member resigns
9.Display in reverse order
0.Previous menu
0
			PINNACLE CLUB
		DEPARTMENT OF COMPUTER ENGINEERING
1.Division A
2.Division B
3.Concatenate A and B
4.Exit
3
New president of which division?(A/B)
A

NAME		PRN
roi		258(President)
sami		456
tara		123
bhagu		147
rt		12
op		65
we		45(secretory)

Member Strength is::7
			PINNACLE CLUB
		DEPARTMENT OF COMPUTER ENGINEERING
1.Division A
2.Division B
3.Concatenate A and B
4.Exit
4
*/

