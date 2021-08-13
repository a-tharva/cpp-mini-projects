#include <iostream>
using namespace std;
#define size 5

class spq
{
    int f,r,job,djob;           
    int simpq[size],prioq[size];
public:
    spq()
    {
     f=r=-1; 
     job=djob=0;
     prioq[-1]=0;
    }
    
    int isQfull()
    {
        if(r==size-1)
            return 1;
        else
            return 0;
    }
    int isQempty()
    {
        if((f==-1)||(f>r))
            return 1;
        else
            return 0;
    }
    void simpqadd();
    void showsimpleQ();
    void delsimpleQ();
    void prioqadd();
    void delprioQ();
    void showprioQ();
};

void spq::simpqadd()
{
    cout<<"\nEnter the Job: ";
    cin>>job;
    if(isQfull())
        cout<<"\nSorry !! Queue is full....\n";
    else
    {
        if(f==-1)
        {
            f=0;
            r=0;
            simpq[r]=job;
        }
        else
        {
            r=r+1;
            simpq[r]=job;
        }
    }

}

void spq::delsimpleQ()
{
    if(isQempty())
        cout<<"\nSorry Q is empty...\n";
    else
    {
        djob=simpq[f];
        f=f+1;
        cout<<"\nDeleted job is: "<<djob;
    }
}

void spq::showsimpleQ()
{
    cout<<"\nThe simple Queue job are as follows....\n";
    int temp;
    for(temp=f;temp<=r;temp++)
    {
        cout<<"\t"<<simpq[temp];
    }
}

void spq::delprioQ()
{
    if(isQempty())
        cout<<"\nSorry Q is empty...\n";
    else
    {
        djob=prioq[f];
        f=f+1;
        cout<<"\nDeleted job is: "<<djob;
    }
}

void spq::showprioQ()
{
    cout<<"\nThe priority Queue job are as follows....\n";
    int temp;
    for(temp=f;temp<=r;temp++)
    {
        cout<<"\t"<<prioq[temp];
    }
}

void spq::prioqadd()
{
    int t=0;
    cout<<"\nEnter the job: ";
    cin>>job;
    if(isQfull())
        cout<<"\nSorry!! Priority Queue is full...\n";
    else
    {
        if(f==-1)
        {
            f=r=0;
            prioq[r]=job;
        }
        else if(job<prioq[r])
        {
         t=r;
         while(job<prioq[t])
         {
            prioq[t+1]=prioq[t];
            t=t-1; 
         }
         t=t+1;
         prioq[t]=job;
         r=r+1;
        }
        else
        {
            r=r+1;
            prioq[r]=job;
        }
    }
}

int main()
{
    spq s1,s2;
    int ch;
    do
    {
     cout<<"\n1.Q Add Job\n2.Q Del Job\n3.Show Q\n4.PrioQ Add Job\n5.PrioQ Del Job\n6.Show PrioQ";
     cout<<"\nEnter Your Choice:";
     cin>>ch;
     switch(ch)
     {
      case 1:s1.simpqadd();break;
      case 2:s1.delsimpleQ();break;
      case 3:s1.showsimpleQ();break;
      case 4:s2.prioqadd();break;
      case 5:s2.delprioQ();break;
      case 6:s2.showprioQ();break;
     }
    }while(ch!=7);
    return 0;
}


/*
OUTPUT:

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:
1

Enter the Job: 
12

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:
2

Deleted job is: 12
1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:^Z
[3]+  Stopped                 ./a.out
[sinhgad@localhost ~]$ clear
[3;J
[sinhgad@localhost ~]$ g++ linear.cpp
[sinhgad@localhost ~]$ ./a.out

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:
1

Enter the Job: 12

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:1

Enter the Job: 14

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:1

Enter the Job: 16

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:3

The simple Queue job are as follows....
	12	14	16
1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:2

Deleted job is: 12
1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:14

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:4

Enter the job: 
23

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:4

Enter the job: 25

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:4

Enter the job: 26

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:6

The priority Queue job are as follows....
	23	25	26
1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:5

Deleted job is: 23
1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:25

1.Q Add Job
2.Q Del Job
3.Show Q
4.PrioQ Add Job
5.PrioQ Del Job
6.Show PrioQ
Enter Your Choice:3

The simple Queue job are as follows....
	14	16
*/
