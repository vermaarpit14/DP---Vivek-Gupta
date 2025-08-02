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

bool check(int row, int col, int n, vector<string> &board)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i -= 1;
        j -= 1;
    }
    i = row, j = col;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
            return false;
        i -= 1;
        j += 1;
    }
    return true;
}

int countPossible(int row, int n, vector<string> &board)
{
    if (row == n)
        return 1;
    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == '.' && check(row, i, n, board))
        {
            board[row][i] = 'Q';
            ways += countPossible(row + 1, n, board);
            board[row][i] = '.';
        }
    }
    return ways;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // code here
    int n = 8;
    vector<string> board(n);
    rep(i, 0, n) cin >> board[i];
    cout << countPossible(0, n, board) << "\n";
}