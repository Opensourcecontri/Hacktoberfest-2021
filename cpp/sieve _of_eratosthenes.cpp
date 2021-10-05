#include<iostream>
#include<vector>
using namespace std;

class sieve{
    vector<bool> is_prime_num;
public:
    sieve(int n){
        vector<bool> tmp(n+1,1);
        is_prime_num.swap(tmp);
        
        is_prime_num[0] = false;
        is_prime_num[1] = false;
        for(int i = 2; i * i <= n; ++i)
            if(is_prime_num[i] == true)  
                for(int j = i * i; j <= n; j += i)
                    is_prime_num[j] = false;
    }

    bool isPrime(int n){
        return is_prime_num[n];
    }

    vector<int> primes(int n){
        vector<int> prime_nums;
        for(int i=0; i<is_prime_num.size() && i < n; i++)
            if(is_prime_num[i])
                prime_nums.push_back(i);
        return prime_nums;
    }
};

int main(){
    sieve s(100);
    cout << "5 is Prime - " << s.isPrime(5) << "\n";
    cout << "10 is Prime - " << s.isPrime(10) << "\n";
    vector<int> primes = s.primes(30);
    cout << "Prime numbers till 30 is : ";
    for(auto p:primes)
        cout << p << " ";
}