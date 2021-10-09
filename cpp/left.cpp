void getAns(Node *root, int level, vector<int>& ans) {
    if(root==NULL) return;
    if(ans.size() < level) {
        ans.push_back(root->data);
    }
    getAns(root->left, level+1, ans);
    getAns(root->right, level+1, ans);
}
vector<int> leftView(Node *root) {
   vector<int> ans;
   getAns(root, 1,ans);
   return ans;
}
