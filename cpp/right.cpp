class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void getAns(Node *root, int level, vector<int>& ans) {
    if(!root) return;
    if(ans.size() < level) {
        ans.push_back(root->data);
    }
    getAns(root->right, level+1, ans);
    getAns(root->left, level+1, ans);
}
vector<int> rightView(Node *root) {
   vector<int> ans;
   getAns(root, 1,ans);
   return ans;
}
};
