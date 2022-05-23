/*
Given a root of a binary tree return a order of the trees levels in zig zag order(1.)l to r 2.)r to l 3.) l to right, etc;
so level 
            1
      2     ->    3
   4  -> 5  ->  6  ->  7
8->9->10-11->12->13->14->15
          becomes
            1
      3     ->    2
   7  -> 6  ->  5  ->  4
15->14->13-12->11->10->9->8

*/
class Solution {
public:
    void getValues(TreeNode* root, vector<vector<int>>& vals, int level){ //recursive Pre-order Traversal adding each value to vector[level-1] = {};
        if (root == NULL)return;
        vals[level-1].push_back(root->val); //1 is the starting level so level-1 will be the first vector in the container
        getValues(root->left, vals, level + 1);//go left first add a level. return container will be in l to r order
        getValues(root->right, vals,level + 1);
}


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};  //empty container if top root null
        vector<vector<int>> vals(25,vector<int>());  //2^h-1 so 25 should be plenty of levels for the result
        getValues(root, vals, 1);//run recursive helper at root
        while(vals.back().empty()){  //find all initated vectors and delete them
            vals.pop_back();
        }
        
        bool flag = vals.size()%2==1; //if the value is odd, use boolean int to add one when odd
        for(int i = 1; i + flag < vals.size() ; i+=2){
            reverse(vals[i].rbegin(),vals[i].rend()); //reverse all odd vectors in the container
        }
        
        return vals;
    }
};
