#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, k;
vector<int> w, v;

bool C(double x) {
	vector<double> y;
	for (int i = 0;i < N;i++) {
		y.push_back(v[i] - x * w[i]);
	}
	sort(y.begin(), y.end());
	reverse(y.begin(), y.end());
	double sum = 0;
	for (int i = 0;i < k;i++) {
		sum += y[i];
	}
	return sum >= 0;
}

double solve() {
	double lb = 0, ub = INF;
	for (int i = 0;i < 100;i++) {
		double mid = (ub + lb) / 2;
		if (C(mid)) {
			lb = mid;
		} else {
			ub = mid;
		}
	}
	return ub;
}

int main(){
	cin >> N >> k;
	w.resize(N);
	v.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> w[i] >> v[i];
	}
	cout << solve() << endl;
	return 0;
}

