#include <bits/stdc++.h>
using namespace std;

long long x, y;
long long limit = 0;
typedef __int128 big;

big Cal(long long h) {
    big a = (big)x - 2 * h;
    big b = (big)y - 2 * h;
    return a * b * h;
}
bool check(long long h) {
    big l = (h == 1 ? -1 : Cal(h - 1));
    big r = (h == limit ? -1 : Cal(h + 1));
    return (l > r);
}
string Out(big n) {
    if (n == 0) return "0";
    bool neg = 0;
    if (n < 0){
        neg = 1;
        n = -n;
    }
    string s;
    while(n){
        s.push_back('0' + (int)(n % 10));
        n /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y;
    big res = 0;
    limit = min(x, y) / 2;
    long long l = 1, r = min(x, y) / 2;
    int t = 50;
    while(l < r && t--){
        long long h = (l + r) / 2;
        res = max(res, Cal(h));
        if (check(h))
            r = h;
        else
            l = h;
    }
    res = max({res, Cal(l), Cal(r)});
    cout << Out(res);
    return 0;
}