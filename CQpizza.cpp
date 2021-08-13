#include<iostream>
using namespace std;
#define size 5
class pizza
{
 int porder[size];
 int front,rear;
 public:
 pizza()
 {
  front=rear=-1;
  }
  int qfull()
  {
   if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
    return 1;
    else
     return 0;
     }
     
  int qempty()
  {
   if(front==-1)
    return 1;
    else
     return 0;
     }
  void accept_order(int);
  void make_payment(int);
  void order_in_queue();
  };
  
  void pizza::accept_order(int item)
  {
   if(qfull())
    cout<<"No More Orders\n";
    else
    {
     if(front==-1)
     {
      front=rear=0;
      }
      else
      {
       rear=(rear+1)%size;
       }
       porder[rear]=item;
        }
       }
       
  void pizza::make_payment(int n)
  {
   int item;
   char ans;
   if(qempty())
    cout<<"SORRY!!!Order is not there\n";
    else
    {
     cout<<"Delieverd orders are as follows\n";
     for(int i=0;i<n;i++)
     {
      item=porder[front];
      if(front==rear)
      {
       front=rear=-1;
       }
       else
       {
        front=(front+1)%size;
        }
       cout<<item<<"\t";
       }
       cout<<"\n Total amount to pay:"<<n*100;
       cout<<"\n THANK YOU VISIT AGAIN\n";
         }
       } 
 void pizza::order_in_queue()
 {
  int temp;
  if(qempty())
  {
   cout<<"SORRY!!!order is not there\n";
   }
   else
   {
    temp=front;
    cout<<"you order in process\n";
    while(temp!=rear)
    {
     cout<<porder[temp]<<"\n";
     temp=temp+1%size;
     }
     cout<<porder[temp]<<"\n";
     }
     }
     
     int main()
  {
  int ch,k,n;
  char ch1;
   pizza p;
   do
   {
    cout<<"Enter\n1.Accept Order\n2.To Make Payment\n3.Ortder In Queue\n";
    cin>>ch;
    switch(ch)
    {
     case 1:
      cout<<"please choose your favourite pizza\n";
      cout<<"1.cheese pizza\n2.corn pizza\n3.masala pizza\n";
      cin>>k;
      p.accept_order(k);
      break;
      
      case 2:
      cout<<"for how many order you want to pay\n";
      cin>>n;
      p.make_payment(n);
      break;
      
      case 3:
      cout<<"following orders are in queue to deliever......as follows...."<<"\t";
      p.order_in_queue();
      break;
   } 
   cout<<"Enter y to continue\n";
   cin>>ch1;
   }
   while(ch1=='y');
   }              


/*

OUTPUT:

Enter
1.Accept Order
2.To Make Payment
3.Ortder In Queue
1
please choose your favourite pizza
1.cheese pizza
2.corn pizza
3.masala pizza
1
Enter y to continue
y
Enter
1.Accept Order
2.To Make Payment
3.Ortder In Queue
1
please choose your favourite pizza
1.cheese pizza
2.corn pizza
3.masala pizza
2
Enter y to continue
y
Enter
1.Accept Order
2.To Make Payment
3.Ortder In Queue
3
following orders are in queue to deliever......as follows....	you order in process
1
2
Enter y to continue
y
Enter
1.Accept Order
2.To Make Payment
3.Ortder In Queue
2
for how many order you want to pay
2
Delieverd orders are as follows
1	2	
 Total amount to pay:200
 THANK YOU VISIT AGAIN
*/
