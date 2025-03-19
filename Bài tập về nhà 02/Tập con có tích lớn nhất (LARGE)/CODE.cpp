#include <bits/stdc++.h>
#define N 100005
using namespace std;

const int mod = 1e9 + 7;

int n;
int A[N];
int neg = 0, pos = 0;
int have0 = 0;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        if (A[i] < 0) neg++;
        else if (A[i] > 0) pos++;
        else have0++;
    }

    if (n == 1){
        cout << A[1]; return 0;
    }
    sort(A + 1, A + n + 1);

    if (neg == 1 && have0 == n - 1){
        cout << 0; return 0;
    }

    long long res = 1;
    if (neg % 2) neg--;
    for (int i = 1; i <= neg; i++) {
        res *= (long long)A[i];
        res %= mod;

    }
    for (int i = n - pos + 1; i <= n; i++) {
        res *= (long long)A[i];
        res %= mod;
    }
    if (have0 == n) cout << 0;
    else cout << res;
    return 0;
}
/*
5
3 5 -2 -2 4

8
-3 -2 -1 0 1 2 3 4
*/