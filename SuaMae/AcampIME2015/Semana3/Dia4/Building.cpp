#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010, MAXD = 110, MAXL = MAXN*MAXN;

int n, m, ind[MAXD][MAXD], degi, degl, pai[MAXN], h[MAXN], res;

char M[MAXD][MAXD];

struct liga{
	int a, b, c;
} lis[MAXL];

bool cmp(liga i,liga j){
	return i.c<j.c;
}

int raiz(int v){
	if(pai[v]==v) return v;
	return pai[v] = raiz(pai[v]);
}

void join(int i,int j){
	if(h[i]<h[j])
		pai[i]=j;
	else if(h[i]>h[j])
		pai[j]=i;
	else{
		pai[j]=i;
		h[i]++;
	}
}


int main (){
	scanf("%d%d",  &n, &m);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	degl=0;
	degi=1;
	liga sup, inf;
	sup.a=sup.b=inf.a=inf.b=-1;
	
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a][b]=='#'){
				ind[a][b]=degi++;
			}
		}
	}
			
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a-1][b]=='#'){
				if(sup.b!=-1){
					lis[degl].a = ind[sup.a][sup.b];
					lis[degl].b = ind[a-1][b];
					lis[degl++].c = b-sup.b;
				}
				sup.a=a;
				sup.b=b;
			}
			if(M[a+1][b]=='#'){
				if(inf.b!=-1){
					lis[degl].a = ind[inf.a][inf.b];
					lis[degl].b = ind[a+1][b];
					lis[degl++].c = b-inf.b;
				}
				inf.a=a;
				inf.b=b;
			}
			if(M[a][b]=='#'){
				if(sup.b!=-1){
					lis[degl].a = ind[sup.a][sup.b];
					lis[degl].b = ind[a-1][b];
					lis[degl++].c = b-sup.b;
				}
				sup.a=a;
				sup.b=b;
				if(inf.b!=-1){
					lis[degl].a = ind[inf.a][inf.b];
					lis[degl].b = ind[a+1][b];
					lis[degl++].c = b-inf.b;
				}
				inf.a=a;
				inf.b=b;
			}
		}
	}
	
	liga dir, esq;
	dir.a=dir.b=esq.a=esq.b=-1;
	for(int b=1;b<=n;b++){
		for(int a=1;a<=m;a++){
			if(M[a][b-1]=='#'){
				if(esq.a!=-1){
					lis[degl].a = ind[esq.a][esq.b];
					lis[degl].b = ind[a][b-1];
					lis[degl++].c = a-esq.a;
				}
				esq.a=a;
				esq.b=b;
			}
			if(M[a][b+1]=='#'){
				if(dir.a!=-1){
					lis[degl].a = ind[dir.a][dir.b];
					lis[degl].b = ind[a][b+1];
					lis[degl++].c = a-dir.a;
				}
				dir.a=a;
				dir.b=b;
			}
			if(M[a][b]=='#'){
				if(esq.a!=-1){
					lis[degl].a = ind[esq.a][esq.b];
					lis[degl].b = ind[a][b-1];
					lis[degl++].c = a-esq.a;
				}
				esq.a=a;
				esq.b=b;
				if(dir.a!=-1){
					lis[degl].a = ind[dir.a][dir.b];
					lis[degl].b = ind[a][b+1];
					lis[degl++].c = a-dir.a;
				}
				dir.a=a;
				dir.b=b;
			}
		}
	}
	for(int a=0;a<degl;a++){
		printf("%d %d %d\n", lis[a].a, lis[a].b, lis[a].c);
	}
	//kruskal
	sort(&lis[0],&lis[degl],cmp);
	for(int a=0;a<degl;a++){
		int i = lis[a].a, j = lis[a].b, c = lis[a].c;
		if(raiz(i)!=raiz(j)){
			join(i,j);
			res+=c;
		}
	}
	printf("%d\n", res);
	
	return 0;
}


/*
1 3 2
1 0 4
0 0 2
2 1 -4
2 4 -4
0 0 2
0 0 2
3 2 2
3 5 2
0 0 -4
0 0 -4
4 3 2
0 0 2
4 0 4
1 0 2
1 0 2
4 1 -2
4 3 -1
0 4 2
0 0 -1
0 0 0
*/
