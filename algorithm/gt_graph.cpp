#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <queue>

#define GT_INF ((unsigned)-1 >> 1)

static const int max_vertex = 20;
static int graph[max_vertex][max_vertex] = {{GT_INF}};
static int dis[max_vertex] = {-1};

static int graph_vertex;
static int graph_edge;

static bool visited[max_vertex][max_vertex] = {{false}};

void gt_readgraph(const std::string& graph_src){
    for (auto& x: graph){
        for (auto& y: x){
            y = GT_INF;
        }
    }

    std::ifstream fs(graph_src);
    int u, v, w;

    fs >> graph_vertex >> graph_edge;
    while (fs >> u >> v >> w){
        graph[u][v] = graph[v][u] = w;
    }
}

bool bfs (int start, int terminal){
    memset(dis, -1, sizeof(dis));
    std::queue<int> Q;
    Q.push(start);

    while (!Q.empty()){
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < graph_vertex; ++ i){
            continue;
        }
    }
	return true;
}
