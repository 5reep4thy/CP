#include<iostream>

#include<cstdio>
using namespace std;



int main()
{
    //  freopen("input.txt", "r", stdin); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int test;
cin>>test;


for(int test_cases=0;test_cases<test;test_cases++)
    { int x=0;int y=0;
        int n;
      cin>>n;
      char moves[n];char lastmove;
      
      for(int i=0;i<n;i++)
      cin>>moves[i];
      if(moves[0]=='L')
      lastmove='V';
      else if (moves[0]=='R')
      {
          lastmove='V';
      }
      else if(moves[0]=='U')
      {
          lastmove='H';
      }
      else
      {
          lastmove='H';
      }
      
      

    //   cout<<moves;
        for(int i=0;i<n;i++)
            {   if((((moves[i]=='L')||(moves[i]=='R'))&&(lastmove=='V'))||(((moves[i]=='U')||(moves[i]=='D'))&&(lastmove=='H')))
            {
                if(moves[i]=='L')
               { x=x-1;
               lastmove='H';}
                else if(moves[i]=='R')
                {x=x+1;
                lastmove='H';}
                else if(moves[i]=='U')
                {y=y+1;
                lastmove='V';}
                else
                
                    {y=y-1;
                    lastmove='V';}
                
                

            }
            }
    cout<<x<<" "<<y<<"\n";

    }
   
   
        


    


        
    



    return 0;
}