#include <iostream>
using namespace std;
#define size 10

class stackexp
{
    int top;
    char stk[size];
public:
    stackexp()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stackexp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stackexp::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stackexp::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stackexp s1;
    char exp[20],ch;
    int i=0,j;
    cout << "\n\t!!Well Parentized or not ass C1..!!!!" << endl; // prints !!!Hello World!!!
    cout<<"\nEnter the expression to check whether it is in well form or not :  \n";
    cin>>exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}'))
    {
        cout<<"\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while(exp[i]!='\0')
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);break;
            
            case '[':s1.push(ch);break;
            
            case '{':s1.push(ch);break;
            
            case ')':
				{
					for(j=0;j<i;j++)
					{
						if(exp[j]=='{'||exp[j]=='[')
						{
							s1.push(ch);
							break;
						}
						else
						if(exp[j]=='(')
						{
							s1.pop();
						}
					}
					break;
				}
		
            
            case ']':
				{
					for(j=0;j<i;j++)
					{
						if(exp[j]=='{'||exp[j]=='(')
						{
							s1.push(ch);
							break;
						}
						else if(exp[j]=='[')
						{
						s1.pop();
						}
					}
					break;
				}
            
            case '}':
				{	
					for(j=0;j<i;j++)
					{
						if(exp[j]=='('||exp[j]=='[')
						{
							s1.push(exp[i]);
							break;
						}
						else	
						if(exp[j]=='{')
						{
							s1.pop();
						}
					}
					break;
				}
            }
            i++;
        }
    }
    if(s1.isempty())
    {
        cout<<"\nExpression is well parenthesis...\n";
    }
    else
    {
        cout<<"\nSorry !!! Invalid Expression or not well parenthesized....\n";
    }
    return 0;
}


/*
OUTPUT:

	!!Well Parentized or not ass C1..!!!!

Enter the expression to check whether it is in well form or not :  
(a+b]

Sorry !!! Invalid Expression or not well parenthesized....


	!!Well Parentized or not ass C1..!!!!

Enter the expression to check whether it is in well form or not :  
(a+b)

Expression is well parenthesis...
*/

