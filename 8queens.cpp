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
int md[2 * 8], ad[2 * 8];
int row[8], col[8];
int main() {
    IO;
    int n = 8;
    string s[8];
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
        md[i - j + n - 1] = 0;
        ad[i + j] = 0;
        row[i] = 0;
        col[j] = 0;
    }
    int queen = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
        if (s[i][j] == '*') {
            queen++;
            md[i - j + n - 1]++;
            ad[i + j]++;
            row[i]++;
            col[j]++;
        }
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
        if (row[i] > 1 || col[j] > 1 || md[i - j + n - 1] > 1 || ad[i + j] > 1) {
            cout << "invalid";
            return 0;
        }
    if (queen == 8) cout << "valid";
    else cout << "invalid";
    return 0;
}