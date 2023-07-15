#include<iostream>
#include<vector>
#include<algorithm>

#include<cstdio>
using namespace std;


int main()
{
     freopen("input.txt", "r", stdin); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        A.push_back(Parity(temp));
    }

    for(int i=0;i<q;i++)
    {cin>>temp;
        temp=Parity(temp);

        oddcount=0;
        for(int j=0;j<n;j++)
        {
            //  r=temp^A[j];
            
             
            if(temp^A[j])
                oddcount++;


        }
        cout<<n-oddcount<<" "<<oddcount<<"\n";
    }
   
   
        


    


        
    }



    return 0;
}