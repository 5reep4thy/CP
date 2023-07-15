#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin); 
    vector<char> A;
    int n,k;
    int test;
    char a;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int count=0;
    cin>>n>>k;
    A.clear();
    for(int j=0;j<n;j++)
    {cin>>a;
     A.push_back(a);
    }
    

   for(int j=0;j<k;j++)
    {
        if(A[n-1]=='H')
            {
                for(int k=0;k<n-1;k++)
                    {
                        if(A[k]=='H')
                            A[k]='T';
                        else
                            A[k]='H';
                    }
            }
        A.pop_back();
        n--;
        
    }
    for(int j=0;j<n;j++)
        {
            if(A[j]=='H')
            count++;
        }
    cout<<count<<"\n";
    
    }

    return 0;
}