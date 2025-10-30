#include<stdio.h>
#include<stdlib.h>
#include<float.h>

#define MAX 100

void optimalBST(float p[], float q[], int n){
float e[MAX][MAX], w[MAX][MAX], t; int
root[MAX][MAX];
int i, j, r, l;

for (i = 1; i <= n + 1; i++){
e[i][i - 1] = q[i - 1]; w[i][i
- 1] = q[i - 1];
}

for (l = 1; l <= n; l++){ for (i = 1; i
<= n - l + 1; i++){ j = i + l - 1;

e[i][j] = FLT_MAX; w[i][j] = w[i][j
- 1] + p[j - 1] + q[j]; for (r = i; r <=
j; r++){ t = e[i][r - 1] + e[r +
1][j] + w[i][j]; if (t < e[i][j]){
e[i][j] = t; root[i][j] = r;
}
}
}
}

printf("%.4f\n", e[1][n]);
}

int main(){ int n = 4; float p[] =
{0.1, 0.2, 0.4, 0.3}; float q[] = {0.05,
0.1, 0.05, 0.05, 0.1};

optimalBST(p, q, n);

return 0;
}
