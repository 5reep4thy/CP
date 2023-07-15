#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   int modifyBit(int n, int p, int b) 
{ 
    int mask = 1 << p; 
    return (n & ~mask) | ((b << p) & mask); 
} 
  


    int rangeBitwiseAnd(int m, int n) {
        int res=2147483647;
        for(int i=0;i<31;i++){
        	if(int(pow(2,i))<=(n-m))
        		res=modifyBit(res,i,0);
        }
        return res&m&n;

    }
};

int main(){

	Solution A;
	cout<<"\n"<<A.rangeBitwiseAnd(2147483646,2147483647);


	return 0;
}