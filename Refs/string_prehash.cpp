#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"\n"<<#x<<" : "<<x<<"\n"; 
void debug_vector(vector<int>& a,string s){	
	if(a.size()==0){
		cout<<"\nEmpty vector "<<s<<"\n";
		return;
	}
	cout<<"Vector "<<s<<"  Size : "<<a.size()<<"\n";
	cout<<"[";
	for(int i=0;i<a.size()-1;i++){
		cout<<a[i]<<", ";
	}
	cout<<a[a.size()-1];
	cout<<"]\n";
}

int a=3;
int mod=1e9+7;

vector<int> p(100000);


void initialiser(){
	p[0]=1;
	for(int i =1;i <100000; i++){
		long temp=p[i-1];
		p[i]=(temp*(long) a)%mod;
	}
}

vector<int> prehasher(string s){
	int n=s.length();
	vector<int> hash(n);
	hash[0]=(int) s[0]-'a';
	for(int i=1;i<n;i++){
		
		long temp=hash[i-1];
		hash[i]=(temp*a+(long) (s[i]-'a'))%mod;
	}
	return hash;


}

int main(){
	string s="alaksdjalkjsdnzxcjzxcabcdefghaisjdaknsdmasldkjzxjcmnzxaabcdefsdajlkd";
	string t="abcdefg";
	vector<int> prehash=prehasher(s);
	debug_vector(prehash,"prehash");
	initialiser();
	vector<int> m=prehasher(t);
	cout<<"\n"<<s[27]<< " "<<s[20]<<"\n";
	long x=prehash[27];
	long y=prehash[20];
	cout<<x<<" "<<y*p[7]<<" "<<"\n";
	cout<<((x-y*p[7])%mod+mod)%mod<<"\n";
	cout<<m[6]<<"\n";





	return 0;
}