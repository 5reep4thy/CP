#include<iostream>
using namespace std;
const int n=17;
void bfs(int adj[][n])
{
    int level[n];
    int current[n];
    int newcurrent[n];
    for(int c=0;c<n;c++)
    level[c]=9999;
    int parent[n];
    int i=1;
    level[1]=0;
    parent[1]=0;
    current[1]=1;
    int levelno=1;
    for(int v=1;v<n*n;v++)
    {
    for(int i=1;i<n;i++)
        {
            if(current[i]==1)
                {
                    for(int j=1;j<n;j++)
                        
                        {
                            if((adj[i][j]==1)&&(level[j]==9999))
                            {
                                newcurrent[j]=1;
                                parent[j]=i;
                                level[j]=levelno;


                            }
                        }

                }

        }
    for(int h=0;h<n;h++)
    current[h]=newcurrent[h];
    levelno++;

    }
    cout<<"No   level   parent";
    for(int h=1;h<n;h++)
    {cout<<"\n";
        cout<<h<<"      "<<level[h]<<"     "<<parent[h];
    }




}

void bfs(int s, vector<int> &d) {
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (d[to] == INF) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    
int adj[n][n];
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        adj[i][j]=0;

adj[1][4]=1;
adj[1][3]=1;
adj[1][2]=1;
adj[2][1]=1;
adj[2][3]=1;
adj[2][12]=1;
adj[3][1]=1;
adj[3][2]=1;
adj[3][4]=1;
adj[3][10]=1;
adj[3][11]=1;
adj[4][3]=1;
adj[4][5]=1;
adj[4][6]=1;
adj[4][7]=1;
adj[4][8]=1;
adj[4][9]=1;
adj[5][4]=1;
adj[6][4]=1;
adj[7][4]=1;
adj[8][4]=1;
adj[9][4]=1;
adj[10][3]=1;
adj[10][11]=1;
adj[11][3]=1;
adj[11][10]=1;
adj[11][14]=1;
adj[12][2]=1;
adj[12][13]=1;
adj[13][12]=1;
adj[13][14]=1;
adj[14][11]=1;
adj[14][15]=1;
adj[14][16]=1;
adj[15][14]=1;
adj[16][14]=1;
// for(int i=1;i<n;i++)
//     {for(int j=1;j<n;j++)
//         cout<<adj[i][j]<<" ";
//     cout<<"\n";
//     }
bfs(adj);



    return 0;
}