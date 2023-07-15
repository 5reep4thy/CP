#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>

using namespace std;

int main()
{
     freopen("input.txt", "r", stdin); 
 int test;
 cin>>test;
 int temp,temp1,temp2,temp3;
 int N,Q;
 int count;
 

 for(int test_cases=0;test_cases<test;test_cases++)
    {   
    // q1.clear();
    // q2.clear();
    // q3.clear();
     
        // map<int,int> A;
        int A[100001];
        cin>>N>>Q;
        for(int i=1;i<=N;i++)
        {
            cin>>temp;
            // A.insert(pair<int,int>(i,temp));
            A[i]=temp;
        }
        for(int i=0;i<Q;i++)
        {
            cin>>temp1>>temp2>>temp3;
            // q1.push_back(temp1);
            // q2.push_back(temp2);
            // q3.push_back(temp3);
            
              
              {   count=0;
         
            
            
            // for(int j=temp1;j<temp2;j++)
            //     {

            //         if(((A[j]>=temp3)&&(A[j+1]<=temp3))||((A[j]<=temp3)&&(A[j+1]>=temp3)))
            //             {
            //                 count++;
            //             }
                   
                   
            //     }
            int j;
            for(j=temp1;j<temp2-1;j+=2)
                {

                    if(((A[j]>=temp3)&&(A[j+2]<=temp3))||((A[j]<=temp3)&&(A[j+2]>=temp3)))
                    count++;
                    else
                    {
                        if(((A[j]>=temp3)&&(A[j+1]<temp3))||((A[j]<=temp3)&&(A[j+1]>temp3)))
                        count+=2;
                        else if(((A[j]==temp3)&&(A[j+1]=temp3))||((A[j]==temp3)&&(A[j+1]=temp3)))
                        {
                            count+=2;
                        }
                        else
                        {
                            count++;
                        }
                        
                        
                        

                    }
                    
                   
                   
                }
            if((j==(temp2-1))&&(((A[temp2-1]>=temp3)&&(A[temp2]<=temp3))||((A[temp2-1]<=temp3)&&(A[temp2]>=temp3))))
            count++;
            
        cout<<count<<"\n";
        }

        }

        // for(int i=0;i<Q;i++)
      


    }



    return 0;
}