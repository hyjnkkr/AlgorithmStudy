#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> sub;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		int cnt = 0;
		for(int j = 1; j < 5 && i + j < v.size(); j++) {
			if(v[i] + 5 > v[i + j]) cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << 4 - ans << '\n';

	return 0;
}