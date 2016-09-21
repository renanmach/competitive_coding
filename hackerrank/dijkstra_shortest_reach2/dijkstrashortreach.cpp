// https://www.hackerrank.com/contests/master/challenges/dijkstrashortreach?h_r=internal-search
// Dijkstra: Shortest Reach 2
// 21 September 2016

#include <stdio.h>
#include <stdlib.h>

#define MAXN 3001

using namespace std;

long long INFINITY = 9000000000000000LL;

typedef struct edge {
	int v;
	int w;
} Edge;

typedef struct edge2 {
	int v;
	int u;
	int w;
} Edge2;

typedef struct node {
	int v;
	Edge *next;
	long long d;	
	int degree;
	int pos_in_heap;
} Node;


class Myqueue {
public:	
	Myqueue(Node g[], int n, int s) {
		heap = (Node**) malloc((n+1)*sizeof(Node*));
		size = 1;	// source
		
		for(int i = 1 ; i <=n; i++)
			insert(&g[i], s);
	}
	
	bool empty() {
		return size == 0 ? true : false;
	}
	
	Node *extract_min() {
		Node *r = heap[1];
		
		heap[1] = heap[size--];
		heap[1]->pos_in_heap = 1;
		
		int pos = 1;
		int c1, c2, minc;
		
		while(true) {
			c1 = 2*pos;
			c2 = (2*pos) + 1;
			
			if(c1 > size)
				break;
			
			// there is only one child
			if(c2 > size)
				minc = c1;
			
			// the node has both children
			// take the smallest child id
			else {
				minc = heap[c1]->d <= heap[c2]->d ? c1 : c2;
			}
			
			// if the value of the father is greater than the value of the smallest
			// child, swap
			if(heap[pos]->d > heap[minc]->d) {
				swap(pos,minc);
				pos = minc;
			}
			
			// the value of the father is smaller than its children's
			else
				break;
		}
		
		return r;
	}
	
	void decrease_distance(long long v, int d) {
		heap[v]->d = d;
		
		int curr = v;
		int father = v/2;
		
		while(father > 0 && heap[curr]->d < heap[father]->d) {
			swap(curr,father);
			curr = father;
			father = father/2;
		}
	}
	
	// the values u.d are either 0 or INFINITY 
	void insert(Node *u, int s) {
		if(u->v == s) {
			heap[1] = u;
			heap[1]->pos_in_heap = 1;
		}
		
		else {
			heap[++size] = u;
			heap[size]->pos_in_heap = size;
		}
	}
	
	void free_heap() {
		free(heap);
	}

private:
	Node **heap;
	int size;
	
	void swap(int a, int b) {
		Node *x = heap[a];
		heap[a] = heap[b];
		heap[b] = x;
		
		heap[a]->pos_in_heap = a;
		heap[b]->pos_in_heap = b;
	}
};

void dijkstra(Node g[], int n, int s) {
	g[s].d = 0;
	
	Myqueue q(g,n,s);
	
	while(!q.empty()) {
		Node *u = q.extract_min();
		
		for(int i = 0 ; i < u->degree; i++) {
			// (u,v)
			Edge e = u->next[i];
			
			// d[v] > d[u]+w(u,v)
			if(g[e.v].d > (g[u->v].d + e.w)) {
				g[e.v].d = g[u->v].d + e.w;			// new shorter distance
				q.decrease_distance(g[e.v].pos_in_heap, g[e.v].d);	// updates the queue
			}
		}
	}
	
	q.free_heap();
}

int main(void) {
	int t;
	
	scanf("%d",&t);
	
	while(t--) {
		int n,m,s;
		
		scanf("%d %d",&n, &m);
		
		Node g[n+1];
		
		Edge2 e[m];
		
		for(int i = 1 ; i <= n ; i++) {
			g[i].v = i;
			g[i].degree = 0;
			g[i].d = INFINITY;
		}
		
		// read edges
		for(int i = 0 ; i < m ; i++) {
			scanf("%d %d %d",&e[i].u,&e[i].v, &e[i].w);
			
			g[e[i].u].degree++;
			g[e[i].v].degree++;
		}
		
		// source
		scanf("%d", &s);
		
		// allocate space for the next arrays
		for(int i = 1 ; i <= n ; i++) {
			g[i].next = new Edge[g[i].degree];
				
			// we will increment this again later
			g[i].degree = 0;
		}
		
		// insert the edges to the graph
		for(int i = 0 ; i < m ; i++) {
			Edge ed;
			ed.v = e[i].v;
			ed.w = e[i].w;
			
			Edge ed2;
			ed2.v = e[i].u;
			ed2.w = e[i].w;
				
			g[e[i].u].next[g[e[i].u].degree++] = ed;
			g[e[i].v].next[g[e[i].v].degree++] = ed2;
		}
		
		dijkstra(g,n,s);				
		
		bool print_space = false;
		
		// print result
		for(int i = 1 ; i <=n ; i++) {
			if(i == s)
				continue;
				
			if(!print_space)
				print_space = true;
			else 
				printf(" ");
				
			if(g[i].d == INFINITY) {
				g[i].d = -1;
			}
				
			printf("%lld", g[i].d);
		}
		
		for(int i = 1 ; i <=n ; i++) {
			delete[] g[i].next;
		}
		
		printf("\n");
	}
	
	return 0;
}
