#include <bits/stdc++.h>

using namespace std;
int n, sta, fin;

void Back(vector <long double > &vi, int l, int r){
    if (r - l < 2) return;
    long double val = (vi[l] + vi[r]) / 2.0;
    int m1 = l + (r - l) / 2;
    int m2 = r - (r - l) / 2;
    vi[m1] = vi[m2] = val;

    Back(vi, l, m1);
    Back(vi, m2, r);
}
int main(){
    cin >> n >> sta >> fin;
    vector <long double > vi(n);
    vi[0] = sta;
    vi[n - 1] = fin;
    Back(vi, 0, n - 1);
    cout.precision(20);
    for (int i = 0; i < n; i++){
        cout << vi[i] << '\n';
    }
    return 0;
}