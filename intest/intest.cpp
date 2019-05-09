#include <stdio.h>
#include <stdlib.h>

extern "C" int intest() {
    int n;
    int k;
    int count = 0;
    int *array;

    scanf("%d %d", &n, &k);

    array = (int*)malloc(n * sizeof(*array));

    for (int i=0; i < n; ++i) {
        scanf("%d", &array[i]);
        if (array[i] % k == 0) {
            count++;
        }
    }
    printf("%d\n", count);

    //fp = stdin;
    //fscanf(fp, "%d\n%d\n", &NumberOfCities, &NumberOfOldRoads);
    //for (int i = 0; i < NumberOfOldRoads; i++)
    //{
    //    int cityA, cityB, length;
    //    fscanf(fp, "%d %d %d\n", &cityA, &cityB, &length);
    //    Roads[i] = Road(cityA, cityB, length);
    //}

}

int main(){
    intest();
}
