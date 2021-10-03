//C++ program to reverse the first k lement of a queue

#include<bits/stdc++.h>
using namespace std;

void reverse(int k , queue<int>&q)
{
    if (q.empty()==true || k > q.size())
    {
        return;
    }
    if (k<=0)
    {
        return;
    }

    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();

    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < q.size()-k; i++)
    {
        q.push(q.front());
        q.pop();
    }

}
void printQ(queue<int>& qU)
{
    while (!qU.empty())
    {
        cout<< qU.front()<< " ";
        qU.pop();
    }
}
int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(90);
    q.push(100);
    int k = 5;
    
    reverse(k,q);
    cout << "Reversed queue: ";
    printQ(q);
    cout << endl;

    return 0;
}
