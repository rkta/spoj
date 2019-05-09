// quicksort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

int partition(int *array, int begin, int end) {
    int pivot = begin;

    for (int i = begin + 1; i < end + 1; ++i) {
        if (array[i] <= array[begin]) {
            ++pivot;
            int tmp = array[i];
            array[i] = array[pivot];
            array[pivot] = tmp;
        }
    }
    int tmp = array[pivot];
    array[pivot] = array[begin];
    array[begin] = tmp;
    return pivot;
}

void quicksort(int *array, int begin, int end) {
    if ( begin >= end) {
        return;
    }

    int pivot = partition(array, begin, end);

    quicksort(array, begin, pivot -1);
    quicksort(array, pivot + 1, end);
}

double stamp () {
    struct timeval t;
    gettimeofday(&t, 0);
    int64_t millitime = t.tv_sec * INT64_C(1000) + t.tv_usec / 1000;
    return millitime;
}

int main() {
    int n;
    int *array;

    scanf("%d", &n);
    double afterN = stamp();    // debug
    printf("n: %d\n", n);

    array = malloc(n * sizeof(*array));
    double afterMalloc = stamp();   // debug
    printf("afterMalloc:\t%d\n", afterMalloc);
    printf("size: %d \n", (n * sizeof(*array)));
    printf("\n");

    for (int i=0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    double afterArray = stamp();    // debug
    printf("afterArray:\t%d\n", afterArray);

    int begin = 0;
    int end = n - 1;
    quicksort(array, begin, end);
    double afterSort = stamp(); // debug
    printf("afterSort:\t%d\n", afterSort);

    for (int i = 0; i <= end; ++i) {
        printf("%d\n", array[i]);
    }
    double afterPrint = stamp();    // debug

    printf("n:\t\t%d\n", n);
    printf("afterN:\t\t%d\n", afterN);
    printf("afterMalloc:\t%d\n", afterMalloc);
    printf("afterArray:\t%d\n", afterArray);
    printf("afterSort:\t%d\n", afterSort);
    printf("afterPrint:\t%d\n", afterPrint);
    return 0;
}
