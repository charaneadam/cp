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

vector<vb> g;
vector<vll> dp;
int n,m;

vi extractIntegerWords(string str){
    stringstream ss(str);
    string temp;
    int found;
    vi integers;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found)
            integers.PB(found);
        temp = "";
    }
    return integers;
}

ll solve(int r, int c){
    if(r >= n || c >= m || !g[r][c]) return 0;
    if((r == n-1 && c == m-2) || (r == n-2 && c == m-1))
        return 1;
    return solve(r+1, c) + solve(r,c+1);
}

int main() {
    IOS;
    int tc;
    cin >> tc;
    string line;
    while(tc--){
        cin >> n >> m;
        g.assign(n, vb(m, true));
        for(int i=0; i<n; i++){
            getline(cin, line);
            vi ints = extractIntegerWords(line);
            if(ints.size() > 1) for(int j=1; j<(int)ints.size(); j++) g[i][ints[j]-1] = false;
        }
        cout << solve(0, 0);
        if(tc) cout << endl;
    }
    return 0;
}

/*
* Test cases:
*
 * TC#1:
 *  Input:
 *      {{1,1,1,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,0,0,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}}
 *  Output:
 *      166
 *
 * TC#2:
 *  Input:
 *      {}
 *  Output:
 *      0
*/