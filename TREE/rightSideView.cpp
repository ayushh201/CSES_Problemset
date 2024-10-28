class Solution {
public: //node right left rev preorder
    void rightSideViewHelper(TreeNode* root,int level,vector<int> &res){
        if(root==nullptr) return;
        if(level==res.size()) res.push_back(root->val);
        rightSideViewHelper(root->right,level+1,res);
        rightSideViewHelper(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideViewHelper(root,0,res);
        return res;
    }
};
