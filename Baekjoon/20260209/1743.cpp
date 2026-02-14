#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101];
bool visited[101][101];
int mvx[4] = {0, 1, 0, -1};
int mvy[4] = {1, 0, -1, 0};

int bfs(int n, int m)
{
    queue<pair<int, int>> Q;
    int biggest = 0;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == 1 && visited[i][j] == false)
            {
                count = 0;
                Q.push(make_pair(i, j));
                visited[i][j] = true;
                while(!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    count++;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + mvx[dir];
                        int ny = cur.second + mvy[dir];
                        
                        if (nx < 1 || nx > n || ny < 1 || ny > m)
                            continue;
                        if (board[nx][ny] == 0 || visited[nx][ny])
                            continue;
                        Q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
                biggest = max(count, biggest);
            }
        }
    }
    return biggest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, r, c, ans;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        board[r][c] = 1;
    }

    ans = bfs(n, m);
    cout << ans << '\n';
    return 0;
}