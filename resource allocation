#include <stdio.h>
void greedyActivitySelection(int s[], int f[], int n) {
    int i, j;

    printf("Activities selected by Greedy approach :\n");

    i = 0;
    printf("A%d ", i + 1);

    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            printf("A%d ", j + 1);
            i = j;
        }
    }
    printf("\n");
}

void bruteForceActivitySelection(int s[], int f[], int n) {
    int i, j, count = 0;
    int selected[n];
    
    printf("Activities selected by Brute Force approach are:\n");
    
    for (i = 0; i < n; i++) {
        int flag = 1;
        for (j = 0; j < i; j++) {
            if (f[j] > s[i] && selected[j]) {
                flag = 0;
                break;
            }
        }
        selected[i] = flag;
        if (flag) {
            printf("A%d ", i + 1);
            count++;
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &finish[i]);
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by finish time:\n");
    printf("Activity\tStart\tFinish\n");
    for (i = 0; i < n; i++)
        printf("A%d\t\t%d\t%d\n", i + 1, start[i], finish[i]);

    printf("\n");
    greedyActivitySelection(start, finish, n);
    bruteForceActivitySelection(start, finish, n);

    return 0;
}
