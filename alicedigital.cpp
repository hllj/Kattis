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
const int nmax = 1e5 + 10;
int n, m;
int a[nmax];
int f[nmax];
int main() {
    IO;
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
    int test;
    scanf("%d", &test);
    while (test-- > 0) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == m) {
                int sum = a[i];
                for (int j = i - 1; j >= 1; j--)
                    if (a[j] > a[i]) sum += a[j];
                    else break;
                for (int j = i + 1; j <= n; j++)
                    if (a[j] > a[i]) sum += a[j];
                    else break;
                res = max(res, sum);
            }
        printf("%d\n", res);
    }
    return 0;
}
