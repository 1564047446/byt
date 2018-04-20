#include <stdio.h>

#define  MAX 405
float get_ans(float *f, int n) 
{
    int j = 0;
    float sum = 0, factor = 1.0 / (float)n;
    for(j = 1; j <= n; j++) {
        if((j - 1) > (n - j)) {
            if(f[j - 1] >= 0.0) {
                sum = sum + f[j - 1] + 1;             
            } else {
                sum = sum + get_ans(f, j - 1) + 1 ;           
           }
        
        }
        else {
            if(f[n-j] >= 0.0) {
                 sum = sum + f[n - j] + 1; 
            } else {
                sum = sum + get_ans(f, n - j) + 1 ;     
            }
        }
        
    }
    f[n] = factor * sum ;
    return f[n];
}
int main()
{
    int t, n, j;
    scanf("%d",&t); 
    float f[MAX];
    while (t--) {
        scanf("%d",&n);        
        for (j = 0; j <= n; j++) {
            f[j] = -1.0;
        }
        f[0] = 0.0;
        f[1] = 1.0;
        printf("%.5f\n", get_ans(f, n));     
    }
    return 0;
}