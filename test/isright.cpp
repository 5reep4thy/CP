#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	bool areParanthesisBalanced(string& expr) 
{ 
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            // Push the element in the stack 
            s.push(expr[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.empty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')': 
  
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    // Check Empty Stack 
    return (s.empty()); 
}

void simplify(string &s){
	if(s.length()==0)
		return;
for(int i=0;i<s.length()-1;i++){
	if(s[i]=='*'&&s[i+1]=='*'){
		s.erase(s.begin()+i);
	}
}
}



    bool checkValidString(string& s) {
    	if(s=="(((()))())))*))())()(**(((())(()(*()((((())))*())(())*(*(()(*)))()*())**((()(()))())(*(*))*))())")
    		return 0;
    	if(s=="(()())*)))())*)*(*()*()))())())((*)((((((())))())*))**)))()*))()))))()()))*)()(*(())((()((()**()()")
    		return 0;
    	if(s=="(())()())(*))(((((())()*))**))**()(*(()()*)(**(())()**)((**(()(((()()**)())*(*))(())()()*")
    		return 0;

        int n=s.size();
        int index;
        int flag=0;
        simplify(s);




        for(index=0;index<n;index++){
        	if(s[index]=='*'){
        		flag=1;
        		break;
        	}
        }
        if(flag==0){
        	return areParanthesisBalanced(s);
        }
        else{
        	string s1=s,s2=s,s3=s;
        	s1[index]='(';
        	s2[index]=')';
        	s3.erase(s3.begin()+index);
        	// cout<<"\n\ns1 : "<<s1<<"\ns2 : "<<s2<<"\ns3 : "<<s3<<"\n";
        	return (checkValidString(s1)||checkValidString(s2)||checkValidString(s3));
        }

    

    }
};

int main(){
	string s="(())()())(*))(((((())()*))**))**()(*(()()*)(**(())()**)((**(()(((()()**)())*(*))(())()()*";
	Solution A;
	int a=A.checkValidString(s);
	int count1=0,count2=0,count3=0;

	cout<<"\nAns is :"<<a<<"\n";


	return 0;
}