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
	for (int i = 1; i <= 100000000; i++){
    res = -1;
    int l = 0, r = n - 1;
    while(l < r){
        int m = (l + r) / 2;
        if (k == a[m]) {
            res = m;
            break;
        }
        else if (k < a[m]) r = m - 1;
        else l = m + 1;
    }
	}
    cout << res << endl;
    return 0;
}

