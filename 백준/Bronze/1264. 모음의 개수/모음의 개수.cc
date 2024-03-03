#include <iostream>
#include <string>
using namespace std;
int main() {
cin.tie(0); ios::sync_with_stdio(0);
    string s;
    int res=0;
    char c[10] = {'a','e','i','o','u','A','E','I','O','U'};
    while(true) {
    getline(cin,s);
        if(s == "#") break;
        for(auto i : s) {
            for(auto k : c) {
                if(i == k) {++res;
                            break;
                           }
            }  
        }
        cout << res << "\n";
        res = 0;
        
    }
    
    
}