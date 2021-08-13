#include <iostream>
#include <string.h>

using namespace std;


void dynamic(string str, int str_len){
	//int count=0;
	cout<<"dynamic: ";
	for(int i=0; i<str_len; i){
		int count = 1;
		for(int j=0; j<str_len;j++){
			
			if(str[i]==str[j]){
				count +=1;
			}
		}
		cout<<str[i]<<count-1;
		i = i+count-1; 
	}
	
}
int main()
{
    cout<<"Hello World\n";
    string s;
    cin>>s;
    int a,b,c,d,e,f;
    a=b=c=d=e=f=0;
    int len = s.length();
	cout<<"leng:"<<len;
    for(int i=0; i<len;i++){
        if(s[i]=='a')
        	 a = a+1;
        if(s[i]=='b')
            b +=1;
        if(s[i]=='c')
            c +=1;
        if(s[i]=='d')
            d +=1;
        if(s[i]=='e')
            e +=1;
        if(s[i]=='f')
            f +=1;
        
    }
    cout<<"\n"<<"a"<<a<<"b"<<b<<"c"<<c<<"d"<<d<<"e"<<e<<"f"<<f<<"\n";
    dynamic(s,len);
    return 0;
}



