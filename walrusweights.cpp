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
const int nmax = 1010;
const int smax = 5000;
int n;
int a[nmax];
int f[smax][nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) 
        f[a[i]][i] = 1;
    for (int s = 1; s <= smax; s++) {
        for (int i = 1; i <= n; i++) 
            if (s >= a[i]) f[s][i] = f[s][i] | f[s - a[i]][i - 1] | f[s][i - 1];
            else f[s][i] = f[s][i] | f[s][i - 1];
    }
    int res = 0;
    for (int i = 1; i <= smax; i++)
        if (f[i][n] && (abs(1000 - i) <= abs(1000 - res))) res = i;
    cout << res;
    return 0;
}
