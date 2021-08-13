#include<iostream>
using namespace std;
#define MAX 20
class stack
{
	int top,topeval;
	char infix[MAX],postfix[MAX],stck[MAX];
	float stckeval[MAX];
	public:
	stack();
	int isempty();
	int isemptyeval();
	void push(char);
	void pusheval(float);
	char pop();
	char popeval();
	void read();
	void convert_infix_postfix();
	int priority(char x);
	float evaluatepostfix();
	
};
	stack::stack()
	{
		top=-1;
		topeval=-1;
	}
	int stack::isempty()
	{
		if(top==-1)
		return (-1);
		else
		return (1);
	}
	int stack::isemptyeval()
	{
		if(topeval==-1)
		return (-1);
		else
		return (1);
	}
	void stack::push(char temp)
	{	
		top++;	
		if(top==MAX)
		{
		cout<<"stack is full";
		
		}
		else
		{
			stck[top]=temp;
		}
	}
	void stack::pusheval(float temp)
	{
		topeval++;
		if(topeval==MAX)
		{
		 cout<<"stack is full";	
			
		}
		else
		{
			stckeval[topeval]=temp;
		}
	}
	char stack::pop()
	{
		int status;
		char temp;
		status=isempty();
		if(status==-1)
		{
			
			return ('@');
		}
		else
		{
		temp=stck[top--];
		return(temp);
		}
	}
	char stack::popeval()
	{
		int status;
		char temp;
		status=isemptyeval();
		if(status==-1)
		{
			
			return (-99);
		}
		else
		{
		temp=stckeval[topeval--];
		return(temp);
		}
	}
	void stack::read()
	{
		cout<<"ENTER INFIX EXPRESSION:";
		cin>>infix;
	}
	void stack::convert_infix_postfix()
	{
		int i,k=0;
		char sop;
		for(i=0;infix[i]!='\0';i++)
		{
			if(infix[i]>='0' && infix[i]<='9')
			{
				postfix[k++]=infix[i];
			}
			else if( infix[i]== '(' )
			{
				push(infix[i]);
			}
			else if(infix[i]==')' )
			{
				while( (sop=pop())!='(' )
				postfix[k++]=sop;
			}
			else
			{
				while(priority(infix[i])<=priority(sop=pop()))
				{
					postfix[k++]=sop;
					if(top==-1)
					break;
				}
		         if(priority(infix[i])>priority(sop))
				{
				push(sop);
				}
				push(infix[i]);
				}
				}
				while(top!=-1)
				{
				sop=pop();
				postfix[k++]=sop;
				}
				postfix[k-1]='\0';
				cout<<"\n The postfix is:"<<postfix;
	}
	
	int stack::priority(char x)
	{
		switch(x)
		{
			case'@':
			return -1;
			
			case'(':
			return 0;
			
			case'+':
			return 1;
			
			case'-':
			return 1;
				
			case'*':
			return 2;
			
			case'/':
			return 2;
					
		}
	}
	float stack::evaluatepostfix()
	{
	float value,operand1,operand2,result;
	for(int i=0;postfix[i]!='\0';i++)
	{
	if(postfix[i]>='0' && postfix[i]<='9')
	{
	 value=postfix[i]-48;
	 pusheval(value);
	}
	else
	{
	 operand2=popeval();			
	 operand1=popeval();
	switch(postfix[i])
	{
	 case '+':
	 result=operand1+operand2;
	 break;
	 				
	  case '-':
	  result=operand1-operand2;
	  break;
	  
	   case '*':
	   result=operand1*operand2;
	   break;	
	   		
	    case '/':
	     result=operand1/operand2;
	     break;										
        }
        pusheval(result);
        }
        }
        result=popeval();
        return (result);
        }
	
	
int main()
{
	stack s;
	float answer;
	s.read();
	s.convert_infix_postfix();
	answer=s.evaluatepostfix();
	cout<<endl<<"the answer is:"<<answer;
	return 0;
	}



/*

OUTPUT:

	
ENTER INFIX EXPRESSION:(4+5)/2+9

 The postfix is:45+2/9+
the answer is:13	
	
*/	


		

