#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
typedef long long ll;
using namespace std;
struct bbb{
int x,y;
};
bool comp(bbb a,bbb b)
{
    
    return (a.x)*(a.y)<(b.x)*(b.y);

}
int main()
{
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);

    string s;
    ll n;
    vector<bbb> mmm;
    cin>>n;
    // getline(cin,s);
    vector<int> A;
    bbb temp;
    temp.x=10;
    temp.y=13;
    mmm.push_back(temp);
   temp.x=14;
    temp.y=13;
    mmm.push_back(temp);
    temp.x=40;
    temp.y=73;
    mmm.push_back(temp);
    temp.x=20;
    temp.y=13;
    mmm.push_back(temp);
    for(int i=0;i<n;i++)
    A.push_back(1000-i);
    sort(A.begin(),A.end());
    vector<bbb>::iterator it;
    for (it=mmm.begin();it<mmm.end();it++)
    cout<<(it->x)*(it->y)<<" ";
    sort(mmm.begin(),mmm.end(),comp);
    cout<<"\n";
    
    for (it=mmm.begin();it<mmm.end();it++)
    cout<<(it->x)*(it->y)<<" ";
    vector<int> vect;
    for(int j=0;j<100;j++)
    {
        vect.push_back(j);
    }
    vect[46]=45;
    // auto l=equal_range(vect.begin(),vect.end(),45);
    // cout<<"Lsecond- Lfirst :"<<l.second-l.first;
    cout<<"K is \n";
    // for(auto k=vect.begin();k<vect.end();k++)
    // {
    //     (*k)++;
    // }
    cout<<"\nmmmm";
    
       for(auto &x:vect)
    {
        cout<<" "<<x;
    }
    return 0;

}