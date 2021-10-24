#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G)
{
    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    dist[0] = 0; //始点０からの距離
    que.push(0);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (int x : G[v])
        {
            if (dist[x] != -1)
                continue;
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main()
{
    //頂点数 N　辺の数 M
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        //無向グラフ
        G[b].push_back(a);
    }

    //始点０は固定
    vector<int> dist = BFS(G);

    for (int v = 0; v < N; ++v)
        cout << v << ":" << dist[v] << endl;
}
