#include <cstdio>
#include <cstring>

using namespace std;

char a[1025][2050];
void draw(int x, int y, int n){/*确定三角形上面的那个点*/
    if (n == 1){/*输出最小的三角形*/
        a[x][y] = a[x + 1][y - 1] = '/';
        a[x][y + 1] = a[x + 1][y + 2] = '\\';
        a[x+1][y] = a[x + 1][y + 1] = '_';
        return ;
    }
    int d = 1 << (n - 1);
    draw(x, y, n - 1);/*当前的三角形*/
    draw(x + d, y - d, n - 1);/*左下的三角形*/
    draw(x + d, y + d, n - 1);/*右下的三角形*/
}
int main(){
    int n;
    while (~scanf("%d", &n) && n){
        int h = (1 << n);
        int w = (1 << (n + 1));
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                a[i][j] = ' ';
        draw(1, 1 << n, n);
        int k = ( 1 << n) + 1;/*不能在行末输出多余的空格*/
        for (int i = 1; i <= h; i++, k++){
            for (int j = 1; j <= k; j++){
                putchar(a[i][j]);/*printf就超时。。*/
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
