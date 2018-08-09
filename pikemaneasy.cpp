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
const int nmax = 1e4 + 10;
const int modulo = 1e9 + 7;
int n, t;
ll a,b,c;
ll ti[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> t;
    cin >> a >> b >> c >> ti[0];
    for (int i = 1; i < n; i++)
        ti[i] = ((a * ti[i - 1] + b) % c) + 1;
    sort(ti, ti + n);
    ll s = 0, p = 0, t_p = 0;
    for (int i = 0; i < n; i++)
        if (t_p + ti[i] <= t) {
            p = (p + t_p + ti[i]) % modulo;
            t_p += ti[i];
            s++;
        }
        else break;
    cout << s << " " << p;
    return 0;
}
