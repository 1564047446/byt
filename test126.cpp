#include <stdio.h>
#include <stdlib.h>

typedef struct u {
	int *father, *size;
} u;

void init(u *s, int n) {
	s->father = (int *)malloc(sizeof(int) * n);
	s->size = (int *)malloc(sizeof(int) * n);
	for (int i = 1; i <= n; i++) {
		s->father[i] = i;
		s->size[i] = 1;
	}
	return ;
}

int find(u *s, int index) {
	if (s->father[index] == 0) return 0;
	if (s->father[index] == index) return index;
	int father = find(s, s->father[index]);
	s->father[index] = father;
	return father;
}

int merge(u *s, int index1, int index2) {
	int a = find(s, index1);
	int b = find(s, index2);
	if (a == b) return 0;
	if (s->size[a] > s->size[b]) {
		s->father[b] = a;
		s->size[a] += s->size[b];
	} else {
		s->father[a] = b;
		s->size[b] += s->size[a];
	}
	return 1;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	u *s = (u *)malloc(sizeof(u));
	init(ss, n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", a, b);
		merge(u, a, b);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int k = find(s, i);
		if (k) {
			++ans;
			s->father[k] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
 }