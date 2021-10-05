#include<bits/stdc++.h>

using namespace std;

class dsu{
    vector<int> parent;
public:
    dsu(int n){
        vector<int> tmp(n);
        parent.swap(tmp);
        for(int i=0; i<n; i++)
            parent[i] = -1;
    }
    int find_parent(int a){
        if(parent[a] < 0)
            return a;
        else
            return parent[a] = find_parent(parent[a]);
    }

    void myUnion(int a, int b){
        int par_a = find_parent(a);
        int par_b = find_parent(b);
        if(par_a != par_b){
            if(parent[par_a] < parent[par_b]){
                parent[par_b] += parent[par_a];
                parent[par_a] = par_b;
            }
            else{
                parent[par_a] += parent[par_b];
                parent[par_b] = par_a;
            }
        }
    }

    bool in_same_group(int a, int b){
        return find_parent(a) == find_parent(b);
    }
};

int main(){
    dsu d1(100);
    d1.myUnion(20,30);
    d1.myUnion(10,20);
    
    if(d1.in_same_group(10,30))
        cout << "10 and 30 are in same group\n";
    else
        cout << "10 and 30 are not in same group\n";

    if(d1.in_same_group(10,40))
        cout << "10 and 40 are in same group\n";
    else
        cout << "10 and 40 are not in same group\n";
}