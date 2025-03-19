#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3+5;

bool check(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if (s[l] != s[r]) return 0;
        l++; r--;
    }
    return 1;
}
int main(){
    string s;
    getline(cin, s);

    if (check(s)){
        return 0;
    }

    string rev = s;
    reverse(rev.begin(), rev.end());

    for (int i = 0; i < s.size(); i++){
        string tmp = rev.substr(rev.size() - i);
        if (check(s + tmp)) {
            cout << tmp;
            return 0;
        }
    }
    cout << rev;
    return 0;
}