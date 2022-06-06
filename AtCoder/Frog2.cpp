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

// https://atcoder.jp/contests/dp/tasks/dp_b
int main() {
    IOS;
    int n,k;
    ll tmp;
    cin >> n >> k;
    vector<ll> h(n), sol(n, -1);
    sol[n-1] = 0;
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=n-2; i>=0; i--)
        for(int j=i; j<n && j < i+k+1; j++){
            tmp = abs(h[i] - h[j]) + sol[j];
            if(sol[i] == -1 || sol[i] > tmp){
                sol[i] = tmp;
            }
        }
    cout << sol[0];
    return 0;
}
