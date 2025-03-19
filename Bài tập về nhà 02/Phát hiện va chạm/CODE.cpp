#include <bits/stdc++.h>
#define int long long
const int N = 1e3 + 5;
using namespace std;

struct Circle{
    int x, y, r;
};

int n;
Circle A[N];
bool check[N];

int sqr(int x){
    return x*x;
}
int Dis(Circle a, Circle b){
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> A[i].x >> A[i].y >> A[i].r;
    }

    for (int i = 1; i <= n; i++){
//        cout << i << ":\n";
        int r1 = A[i].r;
        for (int j = i + 1; j <= n; j++){
            int d = Dis(A[i], A[j]);
            int r2 = A[j].r;
//            cout << d << " " << r1 + r2 << '\n';
            if (d <= sqr(r1 + r2)) {
                check[i] = check[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (check[i]) cnt++;
    }
    cout << cnt;
    return 0;
}