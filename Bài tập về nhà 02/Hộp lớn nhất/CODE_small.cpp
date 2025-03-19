#include <bits/stdc++.h>
const int f = 1e9;
using namespace std;

long long x, y;
int main(){
    cin >> x >> y;
    long long res = 0;
    long long lim = min((long long)f, min(x, y) / 2);
    for (int h = 1; h <= lim; h++){
        long long a = x - 2*h;
        long long b = y - 2*h;
        res = max(res, a*b*h);
    }
    cout << res;
    return 0;
}