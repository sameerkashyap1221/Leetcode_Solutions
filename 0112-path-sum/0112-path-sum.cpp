class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        stack<pair<TreeNode*,int>> st;
        st.push({root,root->val});
        while(!st.empty()){
            TreeNode* temp=st.top().first;
            int sum=st.top().second;
            st.pop();
            if(temp->left==NULL && temp->right==NULL){
                if(sum==targetSum) return true;
            }
            if(temp->left!=NULL){
                st.push({temp->left,sum+temp->left->val});
            }
            if(temp->right!=NULL){
            st.push({temp->right,sum+temp->right->val});
            }
        }
        return false;
    }
};