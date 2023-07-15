#include<bits/stdc++.h>
using namespace std;

void debug_vector(vector<int>& a,string s){	
	if(a.size()==0){
		cout<<"\nEmpty vector "<<s<<"\n";
		return;
	}
	cout<<"Vector "<<s<<"  Size : "<<a.size()<<"\n";
	cout<<"[";
	for(int i=0;i<a.size()-1;i++){
		cout<<a[i]<<", ";
	}
	cout<<a[a.size()-1];
	cout<<"]\n";
}


class Solution {
public:
	vector<vector<int>> edges;
	vector<int> count_incoming_edges;
	void Print_Queue(queue <int> Q) {
		while(!Q.empty()){
		cout<<" "<<Q.front();
		Q.pop();
	}cout<< "\n";
	}

    bool canFinish(int N, vector<vector<int>>& prerequisites) {
    	    edges.resize(N);
    	    count_incoming_edges.resize(N);
    	    bool ans=1;
    	    for (auto &i: prerequisites) {
    	    	
    	    	edges[i[1]].push_back(i[0]);
    	    	count_incoming_edges[i[0]]++;
    	    }
    	    queue<int> q;
    	       int num  = 0;
    	    for(int i=0; i<N; i++) {
    	    	if(count_incoming_edges[i] == 0) {
    	    		q.push(i);
    	    		
    	    	}
    	    }
    	    
    	   //  debug_vector(count_incoming_edges, "count edges");
    	   //  cout << "\nedge vector \n";
    	   //  for (int i = 0; i<edges.size(); i++) {
    	   //  	cout << "\n for " << i << " : ";
    	   //  	for (int j=0; j<edges[i].size(); j++) {
    	   //  		cout << edges[i][j] << " ";
    	   //  	}
    	   //  	cout << endl;
    	   //  }
    	    
    	   // cout<<"\n Before \n";
    	   // Print_Queue(q);
    	    if(q.empty())
    	    	return 0;
    	 	
    	    while(!q.empty()) {
    	    	// cout << "\n Loop " << num << " : ";
    	    	// Print_Queue(q);
    	    	int top=q.front();
    	    	
    	    	for(int i=0; i<edges[top].size(); i++) {
    	    		count_incoming_edges[edges[top][i]]--;
    	    		if(count_incoming_edges[edges[top][i]] ==0) {
    	    			q.push(edges[top][i]);
    	    		}
    	    	}
    	    		// cout << "\n Loop end " << num << " : ";
    	    	// Print_Queue(q);
    	    	q.pop();
    	    	num++;
    	    }
    	    // cout << "\n num is : " << num;
    	    if(num == N)
    	    	return 1;
    	    else
    	    	return 0;



    return ans;
    }

};

int main() {
	vector<vector<int>> pre_requisites {{0, 1}, {1, 2}, {2, 0}};
	int NumOfCourses = 3;
	Solution A;
	bool ans = A.canFinish(NumOfCourses, pre_requisites);
	cout << "\n" <<ans;



	return 0;
}