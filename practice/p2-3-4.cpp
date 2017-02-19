#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))
#define xyrange(x, minX, maxX, y, minY, maxY) (range(x, minX, maxX) && range(y, minY, maxY))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const int INF = INT_MAX / 2;

#define w first
#define v second

const int MAX_N = 100;
const int MAX_W = 10000;
int dp[MAX_N + 1][MAX_W + 1];

int N, W;
vector<PII> naps;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> W;
    rep (i, N) {
        PII nap;
        cin >> nap.w >> nap.v;
        naps.pb(nap);
    }
    rep (i, N) {
        rep (j, W + 1) {
            for (int k = 0;k * naps[i].w <= j;k++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - naps[i].w * k] + naps[i].v * k);
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}
