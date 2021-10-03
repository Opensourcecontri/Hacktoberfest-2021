//C++ program to solve the LRUQ problem

#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
    list<int> lst;
    unordered_map<int, list<int>::iterator> unmap;
    int csize;

public:
    LRUCache(int);
    void refer(int);
    void display();

};

LRUCache :: LRUCache(int n)
{
    csize = n;

}
void LRUCache :: refer(int x)
{
    //Element not found in cache
    if (unmap.find(x) == unmap.end())
    {
        //Cache is full
        if (lst.size()==csize)
        {
            int last = lst.back();
            lst.pop_back();

            unmap.erase(last);
        }

    }
    //Element found in cache
    else
    {
        lst.erase(unmap[x]);//Erase old reference of unordered map
    }

    //Update reference
    lst.push_front(x);
    unmap[x] = lst.begin();
}
void LRUCache::  display()
{
    for (auto it = lst.begin(); it != lst.end();  it++)
    {
        cout << (*it) << " ";

    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    LRUCache cacheSize(3);//# is the size of cache memory
    cacheSize.refer(1);
    cacheSize.refer(2);
    cacheSize.refer(3);
    cacheSize.refer(2);
    cacheSize.refer(4);
    cacheSize.refer(5);
    cacheSize.refer(4);
    cacheSize.refer(8);
    cacheSize.display();
    return 0;
}

