#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<heapapi.h>


using namespace std;
int UNVISITED = 0;
int VISITED = 1;
class Graph {
private:
	void operator = (const Graph&) {}
	Graph(const Graph&){}
public:
	Graph() {}
	virtual void Init(int n) = 0;
	virtual int n() = 0;
	virtual int e() = 0;
	virtual int first(int v) = 0;
	virtual int next(int v, int w) = 0;
	virtual void setEdge(int v1, int v2, int wght) = 0;
	virtual void delEdge(int v1, int v2) = 0;
	virtual bool isEdfe(int i, int j) = 0;
	virtual int weight(int v1, int v2) = 0;
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;
};
class Graphm : public Graph {
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
public:
	Graphm(int numVert) {
		Init(numVert);
	}
	~Graphm() {
		delete[] mark;
		for (int i = 0; i < numVertex; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void Init(int n) {
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		for (int i = 0; i < numVertex; i++)
			mark[i] = UNVISITED;
		matrix = (int **) new int*[numVertex];
		for (int i = 0; i < numVertex; i++)
			matrix[i] = new int[numVertex];
		for (int i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				matrix[i][j] = 0;
	}
	int n() { return numVertex; }
	int e() { return numEdge; }
	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
	}
	int next(int v, int w) {
		for (int i = w; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
	}
	void setEdge(int v1, int v2, int wgt) {
		if (matrix[v1][v2] == 0)
			numEdge++;
		matrix[v1][v2] = wgt;
	}
	void delEdge(int v1, int v2) {
		if (matrix[v1][v2])
			numEdge--;
		matrix[v1][v2] = 0;
	}
	bool isEdge(int v1, int v2) {
		return matrix[v1][v2]!= 0;
	}
	int weight(int v1, int v2) {
		return matrix[v1][v2];
	}
	int getMark(int v) {
		return mark[v];
	}
	void setMark(int v, int val) {
		mark[v] = val;
	}

};
void DFS(Graph*G, int v) {
	G->setMark(v, VISITED);
	for (int w = G->first(v); w < G->n(); w = G->next(v, w))
		if (G->getMark(w) == UNVISITED)
			DFS(G, w);

}
void BFS(Graph*G, int start, queue<int>  q) {
	int v, w;
	q.push(start);
	G->setMark(start, UNVISITED);
	while (q.size) {
		v = q.front();
		q.pop();
		for(w = G->first(v); w < G->n(); w = G->next(v,w))
			if (G->getMark(w) == UNVISITED)
			{
				G->setMark(w, VISITED);
				q.push(w);
			}

	}
}
int minVertex(Graph*G, int*D) {
	int i, v = -1;
	for (int i = 0;i < G->n(); i++)
		if (G->getMark(i) == UNVISITED) {
			v = i;
			break;
		}
	for (i++; i < G->n(); i++) {
		if (G->getMark(i) == UNVISITED && D[i] < D[v])
			v = i;
	}
}

void Dijkstra(Graph*G, int* D, int s){
	int i, v, w;
	for (int i = 0; i < G->n(); i++) {
		v = minVertex(G, D);
		for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
			if (D[w] > D[v] + G->weight(v, w))
				D[w] = D[v] + G->weight(v, w);
		}
	}
}
class DijkElem {
public:
	int vertex, distance;
	DijkElem() {
		vertex = -1;
		distance = -1;
	}
	DijkElem(int v, int d) {
		vertex = v;
		distance = d;
	}
};
template <typename L, typename G>
void Dijkastra2(Graph*G, int* D, int s) {
	int i, v, w;
	DijkElem temp;
	DijkElem E[G->e()];
	temp.distance = 0;
	temp.vertex = s;
	E[0] = temp;
	heap<DijkElem, DDComp> H(E, 1, G->e());
	for (i = 0; i < G->n(); i++) {
		do {
			if (H.size() == 0) return;
			temp = H.removefirst();
			v = temp.vertex;
		} while (G->getMark(v) == VISITED);
		G->setMark(v, VISITED);
		if (D[v] == INFINITY) return;
		for(w = G->first(v); w < G->n(); w = G->next(v,w))
			if (D[w] > D[v] + G->weight(v, w) {
				D[w] = D[v] + G->weight(v, w);
				temp.distance = D[w];
				temp.vertex = w;
				H.insert(temp);
			}
	}
}

void Prim(Graph*G, int* D, int s) {
	int i, v, w;
	int V[G->n()];
	DijkElem temp;
	DijkElem E[G->e()];
	temp.distance = 0; temp.vertex = s;
	E[0] = s;
	heap<DijkElem, DDcomp> H(E, 1, G->e());
	for (int i = 0; i < G_>n(); i++) {
		do {
			if (H.size()) return;
			temp = H.removefirst();
			v = temp.vertex;
		} while (G->getMark(v) == VISITED);
		G->setMark(v, VISITED);
		if (v != s)
			AddEdgetoMST(V[v], v);
		if (D[v] == INFINITY) return;
		for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
			if (D[w] > G->weight(v, w)) {
				D[w] = G->weight(v, w);
				V[w] = v;
				temp.distance = D[w];
				temp.vertex = w;
				H.insert(temp);
			}
		}
	}


}
	
