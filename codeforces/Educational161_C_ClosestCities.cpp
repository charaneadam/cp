#include <iostream>
#include <vector>
using namespace std;
 
void solve(){
  int n;
  cin >> n;
  vector<int> v(n), ltr(n), rtl(n);
  for (int i=0; i<n; i++) cin >> v[i];
 
  ltr[0]=0, ltr[1]=1;
  for(int i=1; i<n-1; i++){
    if(v[i]-v[i-1]>v[i+1]-v[i]) ltr[i+1] = 1;
    else ltr[i+1] = v[i+1] - v[i];
    ltr[i+1] += ltr[i];
  }
 
  rtl[n-1]=0, rtl[n-2]=1;
  for(int i=n-2; i>0; i--){
    if(v[i]-v[i-1]<v[i+1]-v[i]) rtl[i-1] = 1;
    else rtl[i-1] = v[i] - v[i-1];
    rtl[i-1] += rtl[i];
  }
 
  int m, p, q, ans;
  cin >> m;
  while(m--){
    cin >> p >> q;
    p--, q--;
    ans = p<q? ltr[q] - ltr[p] : rtl[q] - rtl[p];
    cout << ans << endl;
  }
}
 
int main(){
  int t;
  cin >> t;
  while(t--) solve();
}
