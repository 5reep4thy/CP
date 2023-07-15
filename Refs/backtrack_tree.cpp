
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
	vector<int> check;
	vector<int> temp;
	bool found=0;
	void dfs(TreeNode* root){
		if(root==NULL)
			return;
		if(root->left==NULL&&root->right==NULL){
			temp.push_back(root->val);
			if(check==temp)
				found=1;
			temp.pop_back();
			return; 
		}
		temp.push_back(root->val);
		dfs(root->left);
		dfs(root->right);
		temp.pop_back();
	}
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        bool ans=0;
        check=arr;
        dfs(root);
        ans=found;
    
    	return ans;
	}
};

int main(){

struct TreeNode root=TreeNode();
Solution A;
vector<int> vec={0,1,0,1};
A.isValidSequence(&root,vec);



	return 0;
}