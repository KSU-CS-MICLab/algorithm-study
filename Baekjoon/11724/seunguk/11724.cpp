#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001]; // graph
bool check[1001];    // visit check


void bfs(int node);

int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v); a[v].push_back(u);
    }

    int components = 0;
    for (int i=1; i<=n; i++) {
        if (check[i] == false) {
            bfs(i);
            components += 1;
        }
    }

    printf("%d\n",components);

    return 0;
}

void bfs(int start) {
    queue<int> q;
//    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i=0; i<a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
