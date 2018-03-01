#include <iostream>
#include <vector>

using namespace std;

vector<int> a[20001];
int color[20001];

bool isBinaryGraph_DFS(int node, int color);

int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        int n,m;
        scanf("%d %d", &n, &m);

        for (int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }

        for (int i=0; i<m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }

        bool isTrue = true;
        for (int i=1; i<=n; i++) {
            if (color[i] == 0) {
                if (isBinaryGraph_DFS(i, 1) == false) {
                    isTrue = false;
                }
            }
        }
        printf("%s\n",isTrue ? "YES" : "NO");
    }
    return 0;
}

bool isBinaryGraph_DFS(int node, int c) {
    color[node] = c;

    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            if (isBinaryGraph_DFS(next, 3-c) == false) {
                return false;
            }
        } else if (color[next] == color[node]) {
            return false;
        }
    }

    return true;
}

