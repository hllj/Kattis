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
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    int st, fi, se, th; 
    while (true) {
        cin >> st >> fi >> se >> th;
        if (st == 0 && fi == 0 && se == 0 && th == 0) return 0;
        //cout << st << " " << fi << " " << se << " " << th << "\n";
        int res = 360 * 2 + ((40 + st - fi) % 40) * 9 + 360 + ((40 + se - fi) % 40) * 9 + ((40 + se - th) % 40) * 9;
        cout << res << "\n";
    }
    return 0;
}
