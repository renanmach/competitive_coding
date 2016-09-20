// https://www.hackerrank.com/challenges/cut-the-tree/
// Cut the tree
// 19 september

#include <stdio.h>
#include <stdlib.h>

// this one I used pure C with only in/out libraries because I am training
// to a admission test of a company next week

// node of the tree/graph
typedef struct nnode {
	int *next;
	int degree2; // node degree used to dynamically allocate memory for *next
	int degree;	// node degree
	int value;	// value of the node/vertex
	int subtree_val;	// value of the subtree removing the edge between the node and its parent
	char visited;	// the node was already visited
} node;

// answer
int min_value;	// min Tree_diff
int maxval;	// sum of all vertices values

// abs value
int absolute_sub(int x, int y) {
	if(x>=y) {
		return x-y;
	}
	
	else {
		return y-x;
	}
}

// depth first search of the graph
int dfs(node *g, int u) {
	int i,v,treediff;
	
	g[u].visited = 1;
	
	g[u].subtree_val = g[u].value;
	
	// loops through the adjancent nodes of u
	for(i=0;i < g[u].degree;i++) {
		v = g[u].next[i];
		 
		if(g[v].visited == 0) {
			g[u].subtree_val += dfs(g,v);
		}
	}
	
	// calculates the treediff
	treediff = absolute_sub(maxval, 2*g[u].subtree_val); 
	
	if(treediff<min_value) {
		min_value = treediff;
	}
	
	return g[u].subtree_val;
}


int main(void) {
	node *g;	// graph
	int *edges,*edges2;
	
	maxval=0;
	
	int n,i;
	
	scanf("%d", &n);
	
	// alocate memory for the graph
	g = (node *) malloc((n+1)*sizeof(node));
	
	// store one vertex of the edge
	edges = (int *) malloc((n-1)*sizeof(int));
	
	// store one vertex of the edge
	edges2 = (int *) malloc((n-1)*sizeof(int));
	
	// read the vertices values
	for(i=1;i<=n;i++) {
		scanf("%d",&g[i].value);
		maxval+=g[i].value;
		
		g[i].visited = 0;
		g[i].degree = 0;	// number of edges
		g[i].degree2=0;
		g[i].subtree_val=0;	// value of the sub tree
	}
	
	int u,v;
	
	// read n-1 lines (the edges)
	// first it stores in the edges vectors and then allocate space for the *next
	// vectors of the nodes. This was done to dynamically allocate memory.
	// statically approach was giving seg fault 
	for(i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		g[u].degree2++;
		g[v].degree2++;
		
		edges[i]= v;
		edges2[i]= u;
	}	
	
	for(i=1;i<=n;i++) {
		g[i].next = (int *) malloc(g[i].degree2*sizeof(int));
	}
	
	for(int i = 0 ; i < n-1;i++) {
		g[edges[i]].next[g[edges[i]].degree++] = edges2[i];
		g[edges2[i]].next[g[edges2[i]].degree++]= edges[i];
		
	}
	
	min_value=maxval+1;
	
	// run dfs, calculating the subtree values of the nodes and the answer
	dfs(g,1);
	
	printf("%d\n",min_value);
	
	
	// free space
	for(i=1;i<=n;i++){
		free(g[i].next);
	}
	
	free(edges);
	free(edges2);
	free(g);
	
	return 0;
}
