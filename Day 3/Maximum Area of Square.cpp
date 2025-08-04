/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        rep(i, 0, n){
            rep(j, 0, m)
            cin>>a[i][j];
        }
        int L = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        rep(i, 1, n+1){
            rep(j, 1, m+1){
                if(a[i-1][j-1] == 1){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                    L = max(L, dp[i][j]);
                }
            }
        }
        cout<<L*L<<"\n";
    }
    return 0;
}