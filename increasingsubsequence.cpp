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
const int nmax = 210;
int n;
ll a[nmax];
int f[nmax];
int trace[nmax];
void solve() {
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int lmax = 0;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        trace[i] = -1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i]) 
                f[i] = max(f[i], f[j] + 1);
        int jmin = -1;
        ll vmin = LINF + 1;
        for (int j = i - 1; j >= 1; j--)
            if (f[j] + 1 == f[i] && a[j] < a[i])
                if (a[j] < vmin) {
                    jmin = j;
                    vmin = a[j];
                }
        trace[i] = jmin;
        if (f[i] > lmax) {
            lmax = f[i];
            pos = i;
        }
        else if (f[i] == lmax && a[i] < a[pos]) pos = i;
    }
    printf("%d ", lmax);
    vector <int> res;
    while (pos != -1) {
        res.push_back(pos);
        pos = trace[pos];
    }
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d ", a[res[i]]);
    printf("\n");
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        solve();
    }
    return 0;
}
