#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 100010;

int n, m, q, degi, ind[MAXN], low[MAXN];

vector <int> adj[MAXN], arv[MAXN];

void go(int v, int pai){
	ind[v]=low[v]=degi++;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt==pai) continue;
		if(ind[nxt]==0){
			go(nxt,v);
			low[v]=min(low[v],low[nxt]);
		}
		else{
			low[v]=min(low[v],ind[nxt]);
		}
	}
}

int main (){
	degi=1;
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	go(1,0);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int A, B, tip;
		scanf("%d%d%d", &tip, &A, &B);
		if(tip==1){
			int g1, g2; 
			scanf("%d%d", &g1, &g2);
			
			
		}
	}
	
}
