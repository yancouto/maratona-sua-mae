#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;
const int MAX = 300100;

int head, tail, fth[MAX];
map <string, int> mapa;
string u, s, fila[MAX];

struct P{
	int a, b, c;
	P () {}
	P(int x, int y, int z){ a = x; b = y; c = z; }
	void imp(){ printf("%c%d%c\n", a == 0 ? 'S' : 'B', b, c == 1 ? 'C' : 'W'); }
};

P fp[MAX];

int von[4][9] = {{11, 15, 16, 22, 25 ,26 ,31, 34, 35},
				{ 4,  7,  8, 20, 24, 25, 29, 33, 34},
				{ 4,  7,  8, 11, 15, 16, 29, 30, 31},
				{ 2,  3,  4, 11, 12, 13, 20, 21, 22}};

int  zu[4][9] = {{26, 25, 22, 34, 31, 35, 11, 16, 15},
				{29, 34, 33,  8,  7,  4, 25, 24, 20},
				{16, 11, 15, 31, 30, 29,  4,  8,  7},
				{20, 21, 22,  2,  3,  4, 11, 12, 13}};

void tres(int a, int b, int c, int d, int e, int f){
	string r = s;
	s[a] = r[d];
	s[b] = r[e];
	s[c] = r[f];
}

void move(int a, int b, int c){
	if(a == 0){ //s move
		if(b == 1) tres(18, 23, 36, 23, 36, 18);
		if(b == 2) tres( 5, 27, 32, 32,  5, 27);
		if(b == 3) tres( 9, 14, 28, 14, 28,  9);
		if(b == 4) tres( 1, 10, 19, 19,  1, 10);
	}
	else{
		move(0, b, c);
		
		string r = s;
		for(int i=0;i<9;i++) s[von[b][i]] = r[zu[b][i]];
	}
	
	if(c == 2) move(a, b, 1);
}

bool fim(){
	for(int i=1;i<=9;i++)   if(u[i] != u[1])  return false;
	for(int i=10;i<=18;i++) if(u[i] != u[10]) return false;
	for(int i=19;i<=27;i++) if(u[i] != u[19]) return false;
	for(int i=28;i<=36;i++) if(u[i] != u[28]) return false;
	return true;
}

int main(){
	char x;
	
	u = "$";
	for(int i=0;i<36;i++){
		scanf(" %c", &x); u += x;
	}
	
	mapa.clear();
	mapa[u] = 0;
	
	head = tail = 0;
	fila[tail++] = u;
	
	bool possible = false;
	int th;
	while(head < tail){
		if(tail > 5000) break;
		th = head; u = fila[head++];
		//printf("em %s mit %d %d\n", u.c_str(), head, tail);
		//if(u == "$222222222111111111333333333444444444") while(1);
		
		if(fim()){
			possible = true;
			break;	
		}
		
		for(int a=0;a<=1;a++){ // s ou b
		for(int b=1;b<=4;b++){ // vertice
		for(int c=1;c<=2;c++){ //C = 1 ; W = 2
			s = u;
			move(a, b, c);
			//printf("got s %s tem %d de %d %d %d\n", s.c_str(), mapa.count(s), a, b, c);
			if(mapa.count(s)) continue;
			
			mapa[s] = mapa[u] + 1;
			fp[tail] = P(a, b, c);
			fth[tail] = th;
			fila[tail] = s;
			tail++;
		}
		}
		}
	}
	
	if(!possible) printf("Impossible\n");
	else{
		vector <P> ans;
		ans.clear();
		while(th){
			ans.push_back(fp[th]);
			th = fth[th];
		}
		for(int i=ans.size()-1;i>=0;i--) ans[i].imp();
	}
	return 0;
}

