#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define swap(a, b) ({\
	int t;\
	t = a;\
	a = b;\
	b = t;\
})

void get_next(int *next, char *pattern) {
	int i = 1, j = -1;
	next[0] = -1;
	for (i = 1; pattern[i]; i++) {
		while (j != -1 && pattern[i] != pattern[j + 1]) j = next[j];
		if (pattern[i] == pattern[j + 1]) ++j;
		next[i] = j;
	}
	return ;
}

int kmp(char *buffer, char *pattern) {
	int *next = (int *)malloc(sizeof(int) * strlen(pattern));
	get_next(next, pattern);
	int j = -1;
	for (int i = 0; buffer[i]; i++) {
		while (j != -1 && buffer[i] != pattern[j + 1]) j = next[j];
		if (buffer[i] == pattern[j + 1]) ++j;
		if (j == strlen(pattern) - 1) return 1;
	}
	return 0;
}

void select_sort(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			} else {
				break;
			}
		}
	}
	return ;
}

void quick_sort(int *arr, int left, int right) {
	if (left >= right) return ;
	int base = arr[left], l = left, r = right;
	while (l < r) {
		while (l < r && base <= arr[r]) --r;
		arr[l] = arr[r];
		while (l < r && base >= arr[r]) ++l;
		arr[r] = arr[l];
	}
	arr[l] = base;
	quick_sort(arr, left, l - 1);
	quick_sort(arr, l + 1, right);
	return ;
}

void merge_sort(int *arr, int left, int right) {
	if (left >= right) return ;
	int mid = (left + right) >> 1;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	int temp[right - left + 1], cnt = 0;
	int x = left, y = mid + 1;
	while (x <= mid || y <= right) {
		if (x <= mid && (y > right || arr[x] < arr[y])) {
			temp[cnt] = arr[x];
			++x;
		} else {
			temp[cnt] = arr[y];
			++y;
		}
		++cnt;
	}
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i - left];
	}
	return ;
}

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return ;
}

int main() {
	int arr[7] = {0, 2, 1, 6, 4, 3, 9};
	//select_sort(arr, 7);
	//quick_sort(arr, 0, 6);
	//merge_sort(arr, 0, 6);
	//print(arr, 7);
	char buffer[100], pattern[100];
	scanf("%s%s", buffer, pattern);
	printf("%d\n", kmp(buffer, pattern));
	return 0;
}
