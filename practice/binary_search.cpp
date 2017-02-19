#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

int solve() {
	int lb = 0, ub = n;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (a[mid] >= k) {
			ub = mid;
		} else {
			lb = mid;
		}
	}
	return ub;
}

int main(){
	cin >> n >> k;
	a.resize(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cout << solve() << endl;
	return 0;
}

