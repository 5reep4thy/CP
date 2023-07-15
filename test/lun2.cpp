#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define P2(n) n, n ^ 1, n ^ 1, n 
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n) 
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n) 
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)
unsigned int table[256] = { LOOK_UP };

int Parity(int num) 
{ 
    // Number is considered to be of 32 bits 
    int max = 16; 
  
    // Dividing the number into 8-bit 
    // chunks while performing X-OR 
    while (max >= 8) { 
        num = num ^ (num >> max); 
        max = max / 2; 
    } 
  
    // Masking the number with 0xff (11111111) 
    // to produce valid 8-bit result 
    return table[num & 0xff]; 
} 

int main()
{
     freopen("input.txt", "r", stdin); 
int test;
int q,n;
 int r;
    int bits;
    int oddcount;
cin>>test;
int temp;
vector<int> A;

for(int test_cases=0;test_cases<test;test_cases++)
    { 
        A.clear();
       
   
    cin>>n>>q;
    //inputs
    for(int i=0;i<n;i++)
    {cin>>temp;
        A.push_back(temp);
    }

    for(int i=0;i<q;i++)
    {cin>>temp;
        

        oddcount=0;
        for(int j=0;j<n;j++)
        {
             r=temp^A[j];
             bits=Parity(r);
            if(bits==1)
                oddcount++;


        }
        cout<<n-oddcount<<" "<<oddcount<<"\n";
    }
   
   
        


    


        
    }



    return 0;
}