#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const int nmax = 1e6 + 10;
int n;
int row[nmax], col[nmax];
ll cnt(int a[], int n) {
    int i = 1, j = 1;
    ll c = 0;
    while (i <= n && j <= n) {
        while (a[i] != 0 && i <= n) i++;
        while (a[j] < 2 && j <= n) j++;
        c += abs(j - i);
        i++;
        a[j]--; 
    }
    return c;
}
int main() {
    IO;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) row[i] = 0, col[i] = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        row[x]++;
        col[y]++;
    }
    ll res = cnt(row, n) + cnt(col, n);
    printf("%lld", res);
    return 0;
}