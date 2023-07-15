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
   
int test,n,q,temp;
cin>>test;
for(int test_cases=0;test_cases<test;test_cases++)
    { 
       
        int B[100000],tot[100000];
        for(int l=0;l<n;l++)
        tot[l]=0;
   
    cin>>n>>q;

    //inputs
    for(int i=0;i<n;i++)
    {
       cin>>B[i];
      
    }

    for(int i=0;i<q;i++)
    {char c;
    int x,y;
     for(int l=0;l<n;l++)
        tot[l]=0;
         cin>>c>>x>>y;
         x=x-1;
         y=y-1;
            if(c=='Q')
            { 
                int tot1=0;
         int tot2=0;
         for(int j=x-1;j>=0;j--)
            {tot1=tot1+B[j];
                tot[j]=tot1;
            }
             for(int j=y+1;j<n;j++)
            {tot2=tot2+B[j];
                tot[j]+=tot2;
            }
            int inbet=0;
            for(int j=x;j<=y;j++)
            inbet+=B[j];
            int st=0;
            int mid=0;
            int nd=0;
        for(int j=0;j<x;j++)
        {
            
            
                {
                    if(tot[j]>st)
                    st=tot[j];
                }

        }
         for(int j=x;j<=y;j++)
        {
            
            mid+=B[j];

        }
         for(int j=y+1;j<n;j++)
        {
            
            
                {
                    if(tot[j]>nd)
                    nd=tot[j];
                }

        }
int y=0;
y=y+mid;
        if(st>=0)
        y=y+st;
        if(nd>=0)
        y=y+nd;

        cout<<y<<"\n";

// cout<<"tot\n";
//         for(int k=0;k<n;k++)
        // cout<<tot[k]<<" ";
// cout<<"\n";
        // cout<<st<<" "<<mid<<" "<<nd<<"\n";

        }
        else
        {B[x]=y+1;
        // for(int l=0;l<n;l++)
        // cout<<B[l]<<" ";
        // cout<<"\n";
        
        }



    }
   
   
        


    


        
    }



    return 0;
}