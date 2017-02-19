#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
vector<int> x;

bool C(int d) {
	int cnt = 1, pos = x[0];
	for (int i = 1;i < N;i++) {
		if (x[i] - pos <= d) {
			cnt++;
			pos = x[i];
		}
	}
	return cnt >= M;
}

int solve() {
	sort(x.begin(), x.end());
	int lb = 0, ub = INF;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (C(mid)) {
			ub = mid;
		} else {
			lb = mid;
		}
	}
	return ub;
}

int main(){
	cin >> N >> M;
	x.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> x[i];
	}
	cout << solve() << endl;
	return 0;
}

