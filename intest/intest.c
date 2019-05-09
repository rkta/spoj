#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int k;
    int count = 0;
    int *array;

    scanf("%d %d", &n, &k);

    array = malloc(n * sizeof(*array));

    for (int i=0; i < n; ++i) {
        scanf("%d", &array[i]);
        if (array[i] % k == 0) {
            count++;
        }
    }
    printf("%d\n", count);
}
