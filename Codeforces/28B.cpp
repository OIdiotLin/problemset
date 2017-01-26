#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Graph{
private:
	vector<int> *_edge;
	int _vertexCount;
	int _edgeCount;
	bool **_isConnected;

public:
	Graph(int vertexCount) {
		_vertexCount = vertexCount;
		_edge = new vector<int>[_vertexCount + 1];
		_isConnected = new bool*[_vertexCount + 1];
		for (int i = 0;i <= _vertexCount;i++)
			_isConnected[i] = new bool[_vertexCount];
		memset(_isConnected, 0, sizeof(_isConnected));
		_edgeCount = 0;
	}

	~Graph() {
		delete[] _edge;
		for (int i = 0;i <= _vertexCount;i++)
			delete[] _isConnected[i];
		delete[] _isConnected;
	}

	bool isConnected(int originVertex, int currentVertex, int destinationVertex) {	// dfs
		_isConnected[originVertex][currentVertex] = true;
		if (destinationVertex == currentVertex)
			return true;
		int degrees = _edge[currentVertex].size();
		for (vector<int>::iterator nextVertex = _edge[currentVertex].begin();
			nextVertex != _edge[currentVertex].end(); nextVertex++) {
			if (!_isConnected[originVertex][*nextVertex])
				if (isConnected(originVertex, *nextVertex, destinationVertex))
					return true;
		}
		return false;
	}

	void addEdge(int startVertex, int endVertex) {
		_edgeCount++;
		_edge[startVertex].push_back(endVertex);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int size;
	cin >> size;
	Graph graph = Graph(size);
	int *arr = new int[size + 1];
	
	for (int i = 1;i <= size;i++)
		cin >> arr[i];

	for (int dist, i = 1;i <= size;i++) {
		cin >> dist;
		if (i - dist >= 1) {
			graph.addEdge(i, i - dist);
			graph.addEdge(i - dist, i);
		}
		if (i + dist <= size) {
			graph.addEdge(i, i + dist);
			graph.addEdge(i + dist, i);
		}
	}

	bool isUnconnected = false;
	for (int i = 1;i <= size;i++) {
		if (!graph.isConnected(i, i, arr[i])) {
			isUnconnected = true;
			break;
		}
	}
	cout << (isUnconnected ? "NO" : "YES") << endl;
	return 0;
}

