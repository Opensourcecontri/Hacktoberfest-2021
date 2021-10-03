//C++ program to generate binary numbers from to 1 to N using Queue

#include<bits/stdc++.h>
using namespace std;
vector<string> generateBinary(int n)
{
    vector<string> result;
    queue<string> num;
    num.push("1");
    for (int i = 0; i < n; i++)
    {

        string temp= num.front();
        result.push_back(temp);
        num.pop();
        num.push(temp + "0");
        num.push(temp + "1");
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int testcase;
    cout << "Enter the number of testcases: " << endl;

    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int n;
        cout << "Enter the number upto which you want binary number: " << endl;
        cin >> n;
        cout << "Binary numbers are :";
        vector<string> ans = generateBinary(n);

        for(auto it: ans)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}
