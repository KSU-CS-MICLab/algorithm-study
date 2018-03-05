#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int x, int y, int cnt);

int a[25][25];
int g[25][25];
int ans[25*25];
int n;
int dx[] = {0, 0, 1, -1}; // dx, dy로 상,하,좌,우 움직 일 수 있다
int dy[] = {1, -1, 0, 0};

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]);
        }

    }

    int cnt = 0; // 단지 번호
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && g[i][j] == 0) {
                bfs(i, j, ++cnt);
            }
        }
    }

    printf("%d\n",cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[g[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }

    return 0;
}

// 너비 우선 탐색
void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y)); // 현재 좌표(위치)를 큐에 담는다.
    g[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) { // 상,하,좌,우 움직인다.
            int nx = x+dx[k];
            int ny = y+dy[k];

            // if 조건문 보기 편하게 yoda condition을 사용한거임.
            // yoda condition은 null 체크할때도 쓸 수도 있음.
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (a[nx][ny] == 1 && g[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    g[nx][ny] = cnt;
                }
            }
        }
    }
}

