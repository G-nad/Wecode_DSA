#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int > a(n);
    for (auto &x : a) cin >> x;
    int k;
    cin >> k;

    int res = -1;
    long long j = 1;
	while(j <= 1000){
//	while(j <= 200){
        for (int i = 0; i < n; i++){
            if (a[i] == k) {
                res = i;
                break;
            }
        }
	j++;
    }
    cout << res;
    return 0;
}

