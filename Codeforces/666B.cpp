#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF (0x3f3f3f3f)
using namespace std;

class Graph {
private:
	vector<int> *_edge;
	int _vertexCount;
	int _edgeCount;
	int **_dist;
	bool *_visited;

	void bfs(int originVertex) {
		static queue<int> q;
		while (!q.empty())
			q.pop();
		memset(_visited, false, sizeof(_visited));
		_visited[originVertex] = true;
		q.push(originVertex);
		while (!q.empty()) {
			int currentVertex = q.front();
			q.pop();
			_visited[currentVertex] = false;
			for (vector<int>::iterator nextVertex = _edge[currentVertex].begin();
				nextVertex != _edge[currentVertex].end(); nextVertex++) {
				if (_dist[originVertex][*nextVertex] > _dist[originVertex][currentVertex] + 1) {
					_dist[originVertex][*nextVertex] = _dist[originVertex][currentVertex] + 1;
					if (!_visited[*nextVertex]) {
						_visited[*nextVertex] = true;
						q.push(*nextVertex);
					}
				}
			}
		}
	}

public:
	Graph(int vertexCount) {
		_vertexCount = vertexCount;
		_edgeCount = 0;
		_edge = new vector<int>[_vertexCount + 1];
		_visited = new bool[_vertexCount + 1];
		memset(_visited, false, sizeof(_visited));
		_dist = new int*[_vertexCount + 1];
		for (int i = 0; i <= _vertexCount; i++)
			_dist[i] = new int[_vertexCount + 1];
		for (int i = 1; i <= _vertexCount; i++)
			for (int j = 1; j <= _vertexCount; j++)
				_dist[i][j] = (i == j ? 0 : INF);
	}

	~Graph() {
		delete[] _edge;
		for (int i = 0;i <= _vertexCount;i++)
			delete[] _dist[i];
		delete[] _dist;
	}

	void findShortestPaths() {
		for (int i = 1;i <= _vertexCount;i++)
			bfs(i);
	}

	void addEdge(int startVertex, int endVertex) {
		_edgeCount++;
		_edge[startVertex].push_back(endVertex);
	}

	int getDist(int i, int j) {
		return _dist[i][j];
	}
};

inline bool cmp(const pair<int, int> &a, const pair<int, int> &b);

int main() {
	ios::sync_with_stdio(false);
	//freopen("666B.in", "r", stdin);
	int vertexCount, edgeCount;
	vector<pair<int, int> > *from, *to;
	cin >> vertexCount >> edgeCount;
	Graph graph = Graph(vertexCount);
	from = new vector<pair<int, int> >[vertexCount + 1];
	to = new vector<pair<int, int> >[vertexCount + 1];
	for (int from, to, i = 0;i < edgeCount;i++) {
		cin >> from >> to;
		graph.addEdge(from, to);
	}

	graph.findShortestPaths();
#define nodeId first
#define dist second
	for(int i = 1; i <= vertexCount; i++)
		for (int j = 1; j <= vertexCount; j++)
			if (graph.getDist(i, j) != INF && i != j) {
				to[i].push_back(make_pair(j, graph.getDist(i, j)));
				from[j].push_back(make_pair(i, graph.getDist(i, j)));
			}
	for (int i = 1;i <= vertexCount;i++) {
		sort(to[i].begin(), to[i].end(), cmp);
		sort(from[i].begin(), from[i].end(), cmp);
	}

	int node1, node2, node3, node4, dis = 0;
	for(int n2 = 1; n2<=vertexCount; n2++)
		for (int n3 = 1;n3 <= vertexCount; n3++) {
			if (graph.getDist(n2, n3) != INF && n2 != n3) {
				for (vector<pair<int, int> >::iterator u = from[n2].begin();
					u - from[n2].begin() < 4 && u != from[n2].end(); u++) {
					if (n2 != u->nodeId && n3 != u->nodeId) {
						int n1 = u->nodeId;
						for (vector<pair<int, int> >::iterator v = to[n3].begin();
							v - to[n3].begin() < 4 && v != to[n3].end(); v++) {
							if (n1 != v->nodeId && n2 != v->nodeId && n3 != v->nodeId) {
								int n4 = v->nodeId;
								if (graph.getDist(n1, n2) + graph.getDist(n2, n3) + graph.getDist(n3, n4) > dis) {
									dis = graph.getDist(n1, n2) + graph.getDist(n2, n3) + graph.getDist(n3, n4);
									node1 = n1, node2 = n2, node3 = n3, node4 = n4;
								}
							}
						}
					}
				}
			}
		}
	cout << node1 << " " << node2 << " " << node3 << " " << node4 << endl;
	return 0;
}

inline bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.dist > b.dist;
}
