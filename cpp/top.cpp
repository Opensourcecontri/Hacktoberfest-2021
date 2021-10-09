 vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL)return ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            int line =it.second;
            if(mp.find(line)==mp.end()){
                mp[line]=temp->data;
            }
            if(temp->left!=NULL){
                q.push({temp->left,line-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,line+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
