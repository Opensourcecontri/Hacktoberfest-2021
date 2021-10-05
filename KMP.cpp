#include<iostream>
using namespace std;

void findPrefix(string pattern, int m, int prefArray[]) {
   int length = 0;
   prefArray[0] = 0;     //first place is always 0 as no prefix

   for(int i = 1; i<m; i++) {
      if(pattern[i] == pattern[length]) {
         length++;
         prefArray[i] = length;    
      }else {
         if(length != 0) {
            length = prefArray[length - 1];
            i--;     //decrease i to avoid effect of increasing after iteration
         }else
            prefArray[i] = 0;
      }
   }
}

void kmpPattSearch(string mainString, string pattern, int *locArray, int &loc) {
   int n, m, i = 0, j = 0;
   n = mainString.size();
   m = pattern.size();
   int prefixArray[m];    //prefix array as same size of pattern
   findPrefix(pattern, m, prefixArray);
   loc = 0;
  while(i < n) {
      if(mainString[i] == pattern[j]) {
         i++; j++;
      }

      if(j == m) {
         locArray[loc] = i-j;      //item found at i-j position.
         loc++;
         j = prefixArray[j-1];    //get the prefix length from array
      }else if(i < n && pattern[j] != mainString[i]) {
         if(j != 0)
            j = prefixArray[j-1];
         else
            i++;
      }
   }
}

int main() {
   string str = "AAAABAAAAABBBAAAAB";
   string patt = "AAAB";
   int locationArray[str.size()];
   int index;
   kmpPattSearch(str, patt, locationArray, index);

   for(int i = 0; i<index; i++) {
      cout << "Pattern found at location: " <<locationArray[i] << endl;
   }
}
