#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
	int v, i, j, e, s;
	printf("Enter the no. of vertices\n");
	scanf("%d", &v);
	int graph[v+1][v+1];
	for(i=0; i<=v; i++){
		for(j=0; j<=v; j++){
			graph[i][j] = 0;
		}
	}
	printf("Enter the no. of edges\n");
	scanf("%d", &e);
	printf("Enter the edge and weight\n");
	int t1, t2, w;
	int e1[e+1], e2[e+1];
	for(i=0; i<e; i++){
		scanf("%d %d %d", &t1, &t2, &w);
		graph[t1][t2] = w;
		e1[i+1] = t1;
		e2[i+1]  = t2;
	}
	printf("Enter the starting node\n");
	scanf("%d", &s);
	int dist[v+1], parent[v+1];
	for(i=0; i<=v; i++){
		dist[i] = INT_MAX;
		parent[i] = 0;
	}
	dist[s] = 0;
	for(i=1; i<=v-1; i++){
		for(j=1; j<=e; j++){
			if(dist[e1[j]] != INT_MAX && graph[e1[j]][e2[j]]+dist[e1[j]] < dist[e2[j]]){
				dist[e2[j]] = graph[e1[j]][e2[j]]+dist[e1[j]];
				parent[e2[j]] = e1[j];
			}
		}
	}
	for(i=1; i<=e; i++){
		if(dist[e2[i]] > dist[e1[i]]+graph[e1[i]][e2[i]])
			printf("Negative weight cycle\n");
	}
	for(i=1; i<=v; i++){
		printf("Distance - %d, Node -  %d\n", dist[i], parent[i]+1);
	}
		
}
