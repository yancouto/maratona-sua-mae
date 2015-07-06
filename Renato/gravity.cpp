#include <cstdio>
#define alpha(c) ((c)>='A' && (c)<='D')

struct point {
	int x=0, y=0;
};

int grid[10][10];
int mem[7][7][7][7][7][7][7][7];
int obst_n=0;
point obst[64];
point init[4];

/* p1 bloco! p2 obst */
inline bool collides(point p1, point p2) {
	return  (p2.x == p1.x || p2.x == p1.x+1) &&
			(p2.y == p1.y || p2.y == p1.y+1);
}

int sim(int dir) {
	if (dir == 0) {
		for (int i=0;i<
	}
}

int main() {
	int t, total;

	scanf("%d", &t);
	for (int k=0;k<t;++k) {
		memset(mem, -1, sizeof(mem));
	
		int freq[4] = {0, 0, 0, 0}
		for (int i=0;i<10;++i) 
			grid[i][0] = grid[i][9] = grid[0][i], grid[9][i] = 1;
		for (int i=1;i<=8;++i) {
			for (int j=1;j<=8;++j) {
				char c;
				scanf(" %c", &c);
				if (alpha(c)) {
					if (!freq[c-'A'])
						init[c-'A'] = {i, j};
					++freq[c-'A'];
					grid[i][j] = 0;
				} else if (c=='#') {
					grid[i][j] = 1;
				} else grid[i][j] = 0;
			}
		}	

		printf("Case %d: %d\n", k+1, total);
	}

	return 0;
}
