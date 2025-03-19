#include <bits/stdc++.h>
#define int long long
#define N 1005
using namespace std;

int n, f0, d;
struct Point{
    int x, y;
};
Point A[N];
int sqr(int x){
    return x*x;
}
int Dis(Point a, Point b){
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool check1[N], check2[N];

signed main(){
    cin >> n >> f0 >> d;
    for (int i = 1; i <= n; i++){
        cin >> A[i].x >> A[i].y;
    }

    for (int i = 1; i <= n; i++){
        if (i == f0) continue;
        int r = Dis(A[f0], A[i]);
        if (r < d) check1[i] = 1;
    }

    for (int i = 1; i <= n; i++){
        if (check1[i]) {
            for (int j = 1; j <= n; j++){
                if (j == f0) continue;
                int r = Dis(A[i], A[j]);
                if (!check1[j] && r < d) check2[j] = 1;
            }
        }
    }

    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++){
        if (check1[i]) res1++;
        if (check2[i]) res2++;
    }
    cout << res1 << ' ' << res2;
    return 0;
}