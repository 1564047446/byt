#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/



int main() {
    int row, cow;
    scanf("%d%d", &row, &cow);
    int target[row][cow];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cow; j++) {
            scanf("%d", &target[i][j]);
        }
    }
    int maxn = 0, row_ans, cow_ans;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cow; j++) {
            int cnt = 0;
            int temp_i = i, temp_j = j;
            while (temp_i--) {
                if (target[temp_i][j] == 1) {
                    ++cnt;
                } else {
                    break;
                }
            }
            temp_i = i;
            while (temp_i++ < row) {
                if (target[temp_i][j] == 1) {
                    ++cnt;
                } else {
                    break;
                }
            }
            while (temp_j--) {
                if (target[i][temp_j] == 1) {
                    ++cnt;
                } else {
                    break;
                }
            }
            temp_j = j;
            while (temp_j++ < cow) {
                if (target[i][temp_j] == 1) {
                    ++cnt;
                } else {
                    break;
                }
            }
            if (maxn < cnt) {
                maxn = cnt, row_ans = i, cow_ans = j;
            }
        }
    }
    printf("%d %d\n", row_ans + 1, cow_ans + 1);
}