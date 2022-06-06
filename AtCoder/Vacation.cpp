#include <bits/stdc++.h>

using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define what_is(x) cerr << #x << " is " << x << endl
#define MOD 1000000007
#define F first
#define S second
#define U unsigned
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define CLR(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define REP(x, y) for(int x=0; x<SZ(y); x++)
#define FOR(x, y, z) for(int x=y; x<z; x++)
#define ALL(t) t.begin(), t.end()
#define ll long long
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<U int> vui;
typedef vector<ll> vll;
typedef vector<U ll> vull;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vi> vvi;

// https://atcoder.jp/contests/dp/tasks/dp_c
int main() {
    IOS;
    int n;
    cin >> n;
    ll a[n][3], ans[n][3];
    for(int i=0; i<n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for(int i=0; i<3; i++) ans[n-1][i] = a[n-1][i];
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<3; j++)
            ans[i][j] = a[i][j] + max(ans[i+1][(j+1)%3], ans[i+1][(j+2)%3]);

    cout << max(ans[0][0], max(ans[0][1], ans[0][2]));
    return 0;
}
