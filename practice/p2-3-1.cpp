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

int N, W;
vector<PII> naps;

// i = 現在の番号, j = 現在の重さ
int solve(int i, int j) {
    int res;
    if (i == N) {
        res = 0;
    } else if (j < naps[i].w) {
        res = solve(i + 1, j);
    } else {
        // 詰める場合と詰めない場合の価値の最大値をとる
        res = max(solve(i + 1, j), solve(i + 1, j - naps[i].w) + naps[i].v);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> W;
    rep (i, N) {
        PII nap;
        cin >> nap.w >> nap.v;
        naps.pb(nap);
    }
    cout << solve(0, W) << endl;
    return 0;
}
