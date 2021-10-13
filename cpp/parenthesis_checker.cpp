/*
Parenthesis Checker 

Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.

*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not

bool ispar(string x)
{
    stack<char> s;
    for(int i=0; i<x.length(); i++){
        if(x[i] == '[' || x[i] == '{' || x[i] == '(')
            s.push(x[i]);
        else{
            if(s.empty())
                return false;
            char c = s.top();
            if(x[i] == '}' && c !='{')
                return false;
            else if(x[i] == ')' && c!='(')
                return false;
            else if(x[i] == ']' && c!='[')
                return false;
            s.pop();
        }
    }
    
    return s.empty();
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends