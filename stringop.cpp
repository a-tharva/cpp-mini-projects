#include<iostream>
using namespace std;
class strn
{
	int i,j,k;
	int count,count1,count2;
	string a,b,c,d,e;
	public:
	void get();
	void display();
	void copy();
	void concat(); 
	void rev();
	void length();
	void equal();
	void substr();
};


void strn::get()
{
	cout<<"Enter the string\n";
	cin>>a;
}


void strn::display()
{
	cout<<"The entered string is"<<"\n"<<a<<"\n";
}


void strn::copy()
{
	b=a;
	cout<<"The copied string is"<<"\n"<<b<<"\n";
}


void strn::concat()
{
	cout<<"Enter the second String \n";
	cin>>c;

	d=a+c;
	cout<<"The full string is"<<"\n"<<d<<"\n";
}

void strn::length()
{
	count=0;
	for(i=0;a[i]!='\0';i++)
	{
	count++;
	}
	cout<<"The length of the string 1 is"<<"\n"<<count<<"\n";
	count1=0;
	for(i=0;c[i]!='\0';i++)
	{
	count1++;
	}
	cout<<"The length of the string 2 is"<<"\n"<<count1<<"\n";
	count2=0;
	for(i=0;d[i]!='\0';i++)
	{
	count2++;
	}
	cout<<"The length of the concated string is"<<"\n"<<count2<<"\n";
}

void strn::rev()
{
	cout<<"Reversed string 1 is"<<"\n";
	for(i>count;i>=0;i--)
	{
	cout<<a[i];
	}
	cout<<"\n";


}

void strn::equal()
{
	if(a==c)
	{
		cout<<"Strings are EQUAL"<<"\n";
	}
	else
	{
		cout<<" Strings are NOT Equal "<<"\n";
	}
}
 
void strn::substr()
{
    i=0;
    j=0;
    k=0;
    cout<<"Enter a string to find it is present or absent"<<"\n";
    cin>>e;
    
    while(a[i]!='\0')
    {
        if(a[i]!=e[j])
            i++;
        else if(a[i]==e[j])
        {
            while(e[j]!='\0')
            {
                if(a[i]==e[j])
                {
                    i++;
                    j++;
                    k++;
                }
                
                else
                {
                    k=0;
                    break;
                }
            }
        }
    }
     if(k!=0)
     cout<<"\n substring  is present \n ";
     else
     cout<<"\nsubstring  is absent \n ";
}
int main()
{
	strn s;
	s.get();
	s.display();
	s.copy();
	s.concat();
	s.length();
	s.rev();
	s.equal();
	s.substr();
	return 0;
}


/*
  OUTPUT:

Enter the string
abc
The entered string is
abc
The copied string is
abc
Enter the second String 
efg
The full string is
abcefg
The length of the string 1 is
3
The length of the string 2 is
3
The length of the concated string is
6
Reversed string 1 is
cba
 Strings are NOT Equal 
Enter a string to find it is present or absent
abc

 substring  is present 
*/
