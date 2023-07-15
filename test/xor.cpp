#include<iostream>
#include<vector>
using namespace std;
int loop[10]={0,0,0,0,0,0,0,0,0,0};
int n=4;


int cs(int n)
{int count=0;
   for(int i=0;i<n;i++)
   count+=loop[i];
   return count;

}


 void search(int k) 
 { int b =cs(4);

  if(b==n)
    {for(int i=0;i<n;i++)
      cout<<loop[i]<<" ";
   cout<<"\n";
    }
    if(k==-1)
    {
   
      return;
    }
     for(loop[k]=0;loop[k]<2;loop[k]++)
     {
       search(k-1);
     }


 }


int main()
{
    search(n-1);
   // cout<<x<<"\n";


    return 0;
}