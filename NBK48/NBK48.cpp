#include <stdio.h> 

#define MAX_NSIZE (100000) 

int main()
{
    int p[MAX_NSIZE], q[MAX_NSIZE];
    int N_values,Q_values, i;
    int Sum_p, Sum_q;
    if (scanf_s("%d", &N_values) != 1) {
        fprintf(stderr, "ERROR\n");
        return 1;
    }
    else if (N_values <= 0 || N_values >= MAX_NSIZE) {
        fprintf(stderr, "ERROR \n1 <= N <= %d\n", MAX_NSIZE);
        return 1;
    }

    if (scanf_s("%d", &Q_values) != 1) {
        fprintf(stderr, "ERROR\n");
        return 1;
    }
    else if (Q_values <= 0 || Q_values >= MAX_NSIZE) {
        fprintf(stderr, "ERROR \n1 <= Q <= %d\n", MAX_NSIZE);
        return 1;
    }

    for (i = 1; i <= N_values; i++) {
        if (scanf_s("%d", &p[i]) != 1) {
            fprintf(stderr, "ERROR \n");
            return 1;
        }
        else if (p[i] <= -10000 || p[i] >= 10000) {
            fprintf(stderr, "ERROR \n-10000 <= p%d <= 10000\n", i);
            return 1;
        }
    }

    for (i = 1; i <= Q_values; i++) {
        if (scanf_s("%d", &q[i]) != 1) {
            fprintf(stderr, "ERROR \n");
            return 1;
        }
        else if (q[i] <= 0 || q[i] >= 1000000000) {
            fprintf(stderr, "ERROR \n0 <= q%d <= 1000000000\n", i);
            return 1;
        }
    }

    for (i = 1; i <= Q_values; i++) {
        Sum_p = 0;
        for (int j = 1; j <= N_values; j++)
        {
            Sum_p += p[j];
            if (Sum_p >= q[i])
            {
                printf("\n%d", j);
                Sum_p -= p[j];
                j = N_values + 1;
            }
        }
    }

    return 0;
}
