#include <cstdio>

using namespace std;

int heap[125010];
int n;

int max(int a, int b) {
	if(a > b) return a;
	return b;
}

void swap(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}

void update_heap(int no) {
	if(no == 1) return ;
	int pai = no / 2;
	if(heap[pai] < heap[no]) {
		swap(heap[pai], heap[no]);
		update_heap(pai);
	}
}

void set_heap(int no) {
	int l = 2 * no, r = 2 * no + 1;
	if(l > n) return ;
	if(r > n) heap[r] = -1;
	if(heap[l] > heap[r] && heap[no] < heap[l]) {
		swap(heap[l], heap[no]);
		set_heap(l);
	}
	else if(heap[no] < heap[r]) {
		swap(heap[r], heap[no]);
		set_heap(r);	
	}
}

int main() {
	int N, a, i; scanf("%d", &N);
	n = N / 2 + 1;
	for(i = 1; i <= n; i++) { scanf("%d", &heap[i]); update_heap(i); } 
	//for(i = 1; i <= n; i++) printf("%d ", heap[i]); putchar('\n');
	for(; i <= N; i++) {
		scanf("%d", &a);
		if(a < heap[1]) {
			heap[1] = a;
			set_heap(1);
		}
	}	
	if(N % 2) printf("%.1f\n", (double)heap[1]);
	else printf("%.1f\n", ((double)heap[1] + max(heap[2], heap[3])) / 2.0);
	return 0;
}
