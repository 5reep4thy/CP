#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;




int main()
{
     freopen("input.txt", "r", stdin); 
int test;

cin>>test;
int r0,r1,sum;

for(int test_cases=0;test_cases<test;test_cases++)
    { 
      cin>>r0>>r1;
         sum=r0+r1;
        cout<<"36\n";
        cout<<sum/2<<" "<<sum/2<<"\n";
        cout<<"1 "<<"1\n";
        cout<<"2 "<<"2\n";
        cout<<"3 "<<"1\n";
        cout<<"4 "<<"2\n";
        cout<<"5 "<<"1\n";
        cout<<"6 "<<"2\n";
        cout<<"7 "<<"1\n";
        cout<<"8 "<<"2\n";
        
        cout<<"7 "<<"3\n";
        cout<<"8 "<<"4\n";
        cout<<"7 "<<"3\n";
        cout<<"6 "<<"4\n";
        cout<<"5 "<<"3\n";
        cout<<"4 "<<"4\n";
        cout<<"3 "<<"3\n";
        cout<<"2 "<<"4\n";
        cout<<"1 "<<"3\n";

        cout<<"2 "<<"4\n";
        cout<<"1 "<<"5\n";
        cout<<"2 "<<"6\n";
        cout<<"3 "<<"5\n";
        cout<<"4 "<<"6\n";
        cout<<"5 "<<"5\n";
        cout<<"6 "<<"6\n";
        cout<<"7 "<<"5\n";
        cout<<"8 "<<"6\n";

        cout<<"7 "<<"7\n";
        cout<<"8 "<<"8\n";
        cout<<"7 "<<"7\n";
        cout<<"6 "<<"8\n";
        cout<<"5 "<<"7\n";
        cout<<"4 "<<"8\n";
        cout<<"3 "<<"7\n";
        cout<<"2 "<<"8\n";
        cout<<"1 "<<"7\n";

    }



    return 0;
}