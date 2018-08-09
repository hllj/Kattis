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
const int nmax = 110;
int n, m;
char a[nmax][nmax];
int fre[nmax][nmax];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
void dfs(int u, int v) {
    fre[u][v] = 0;
    for (int k = 0; k < 4; k++) {
        int ux = u + dx[k], vx = v + dy[k];
        if (ux >= 0 && ux < n && vx >= 0 && vx < m) {
            if (fre[ux][vx] && a[ux][vx] == '-') dfs(ux, vx);
        }
    }
}
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int test = 0;
    while (cin >> n >> m) {
        test++;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            fre[i][j] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fre[i][j] == 1 && a[i][j] == '-') {
                cnt++;
                dfs(i, j);
            }
        cout << "Case " << test << ": " << cnt << "\n";
        //if (test == 2) return 0;
    }
    return 0;
}
