	#include <stdio.h>
	#include <stdlib.h>
	#define inf 0x3f3f3f3f

	#define swap(a, b) { \
		__typeof(a) t = a; \
		a = b; \
		b = t; \
	}

	typedef struct Heap {
		int n, size;
		int *data, *id;
	} Heap;

	void init(Heap *p, int size) {
		p->id = (int *)malloc(sizeof(int) * (size + 1));
		p->data = (int *)malloc(sizeof(int) * (size + 1));
		p->n = 0;
		p->size = size + 1;
	}

	int push(Heap *p, int value, int id) {
		p->data[++p->n] = value;
		p->id[p->n] = id;
		int index = p->n;
		while (index > 1 && p->data[index] >= p->data[index >> 1]) {
			if (p->data[index] == p->data[index >> 1] && p->id[index] > p->id[index >> 1]) {
				index >>= 1;
				break;
			}
			swap(p->data[index], p->data[index >> 1]);
			swap(p->id[index], p->id[index >> 1]);	
			index >>= 1;
		}
	}

	int pop(Heap *p) {
		swap(p->data[1], p->data[p->n]);
		swap(p->id[1], p->id[p->n]);
		--p->n;
		int index = 1, maxn;
		while (index * 2 <= p->n) {
			int index1 = index * 2, index2 = index * 2 + 1;
			maxn = index;
			if (p->data[maxn] < p->data[index1]) {maxn = index1;}
			else if (p->data[maxn] == p->data[index1]) {
				if (p->id[maxn] > p->id[index1]) {
					maxn = index1;
				}
			}
			if (index2 <= p->n && p->data[maxn] < p->data[index2]) {maxn = index2;}
			else if (index2 <= p->n && p->data[maxn] == p->data[index2]) {
				if (p->id[maxn] > p->id[index2]) {
					maxn = index2;
				}
			}
			if (index == maxn) break;
			swap(p->data[index], p->data[maxn]);
			swap(p->id[index], p->id[maxn]);
			index = maxn;
		}
		return 1;
	}

	int get_front(Heap *p) {
		return p->data[1];
	}

	int get_front_id(Heap *p) {
		return p->id[1];
	}

	int main() {
		int t, num = 0;
		scanf("%d", &t);
		while (t--) {
				Heap *p[101];
		for (int i = 0; i <= 100; ++i) {
			p[i] = (Heap *)malloc(sizeof(Heap));
			init(p[i], 5000);
		}
			int n;
			scanf("%d", &n);
			printf("Case #%d:\n", ++num);
			for (int i = 0; i < n; ++i) {
				int f, s;
				scanf("%d%d", &f, &s);
				push(p[s], f, i + 1);
			}
			for (int i = 0; i < n; ++i) {
				int index, maxn = -1, id = inf;
				for (int j = 0; j < 101; ++j) {
					if (p[j]->n == 0) continue;
					if (get_front(p[j]) > maxn) {
						maxn = get_front(p[j]);
						index = j;
						id = get_front_id(p[j]);
					} else if (get_front(p[j]) == maxn) {
						if (get_front_id(p[j]) < id) {
							id = get_front_id(p[j]);
							index = j;
							maxn = get_front(p[j]);
						} else continue;
					}
				}
				printf("%d", get_front_id(p[index]));
				if (i != n - 1) printf(" ");
				else printf("\n");
				pop(p[index]);
				for (int j = 0; j < 101; ++j) {
					if (p[j]->n == 0) continue;
					p[j]->data[1] = p[j]->data[1] + j * (i + 1);
				}
			}
			for (int i = 1; i <= 100; ++i) free(p[i]->data), free(p[i]->id), free(p[i]);
		}
		return 0;
}