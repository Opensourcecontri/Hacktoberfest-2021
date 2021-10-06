#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter the Number\n";
    cin >> s;
    bool flag = true;
    int len = s.size();
    for(int i=0; i<(len+1)/2; i++)
        if(s[i] != s[len-1-i]){
            flag = false;
            break;
        }
    if(flag)
        printf("\nNumber \"%s\" is palindrome\n", s.c_str());
    else
        printf("Number \"%s\" is not palindrome\n", s.c_str());
}