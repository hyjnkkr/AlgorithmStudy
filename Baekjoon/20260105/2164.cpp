#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    int i = 0;
    while(q.size() != 1) { 
        if (i % 2 == 0) { 
            q.pop();
        } else { 
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        i++;
    }
    cout << q.front() << '\n';
    
	return 0;
}