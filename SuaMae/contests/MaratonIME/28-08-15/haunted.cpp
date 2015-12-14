#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 60, INF = 100000000;

int n, m, g, p, M[MAXN][MAXN], dega, d[MAXN][MAXN], mrk[MAXN][MAXN];

int vi[4]={0,0,1,-1};
int vj[4]={1,-1,0,0};

struct port{
	int ii, jj, t;
} por[MAXN][MAXN];

struct arestas{
	int i, j, ii, jj, c;
} are[MAXN*MAXN*10];

inline void poeares(int i, int j, int ii, int jj, int c){
	are[dega].i=i;
	are[dega].j=j;
	are[dega].ii=ii;
	are[dega].jj=jj;
	are[dega].c=c;
	dega++;
}


bool valid(int i,int j){
	if(i>=0 && j>=0 && i<n && j<m && M[i][j]!=1)
		return true;
	return false;
}

bool pode(int i,int j){
	if(i>=0 && j>=0 && i<n && j<m && M[i][j]!=1 && mrk[i][j]==0)
		return true;
	return false;
}

void dfs(int i,int j){
	mrk[i][j]=1;
	if(M[i][j]==2){
		if(pode(por[i][j].ii,por[i][j].jj))
			dfs(por[i][j].ii,por[i][j].jj);
		return;
	}
	for(int a=0;a<4;a++){
		if(pode(i+vi[a],j+vj[a]))
			dfs(i+vi[a],j+vj[a]);
	}
}

int main (){
	while(scanf("%d%d", &n, &m) && m!=0 && n!=0){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				d[a][b]=INF;
				mrk[a][b]=0;
				M[a][b]=0;
			}
		}
		dega=0;
		scanf("%d", &g);
		for(int a=0;a<g;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			M[i][j]=1;
		}
		scanf("%d", &p);
		for(int a=0;a<p;a++){
			int i, j, ii, jj, t;
			scanf("%d%d%d%d%d", &i, &j, &ii, &jj, &t);
			M[i][j]=2;
			por[i][j].ii = ii;
			por[i][j].jj = jj;
			por[i][j].t = t;
		}
		dfs(0,0);
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(mrk[a][b]==0){
					M[a][b]=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==n-1 && j==m-1) continue;
				if(M[i][j]==2){
					if(valid(por[i][j].ii,por[i][j].jj))
						poeares(i,j,por[i][j].ii,por[i][j].jj,por[i][j].t);
					continue;
				}
				for(int a=0;a<4;a++){
					if(valid(i+vi[a],j+vj[a]))
						poeares(i,j,i+vi[a],j+vj[a],1);
				}
			}
		}
		d[0][0]=0;
		for(int ite=0;ite<n*m;ite++){ //num de vertice vezes
			for(int ar=0;ar<dega;ar++){
				int i = are[ar].i, j = are[ar].j, ii = are[ar].ii, jj = are[ar].jj, c = are[ar].c;
				if(d[ii][jj]>d[i][j]+c){
					d[ii][jj]=d[i][j]+c;
				}
			}
		}
		//jácabou belman
		int ver=0;
		for(int ar=0;ar<dega;ar++){
			int i = are[ar].i, j = are[ar].j, ii = are[ar].ii, jj = are[ar].jj, c = are[ar].c;
			if(i==n-1 && j==m-1) continue;
			if(d[ii][jj]>d[i][j]+c){
				ver=1;
				d[ii][jj]=d[i][j]+c;
			}
		}
		if(ver==1){
			printf("Never\n");
			continue;
		}
		else{
			if(mrk[n-1][m-1]==0)
				printf("Impossible\n");
			else
				printf("%d\n", d[n-1][m-1]);
		}
	}
	return 0;
}
	

