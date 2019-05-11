#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

// Input lines are:
// x1, y1, r1, x2, y2, r2
// with x,y being the center of the circle
// Sample data
// "103 104 5 100 100 10"   -> E
// "103 104 10 100 100 10"  -> O
// Distance: 5 and 5

double point_distance(double x1, double y1, double x2, double y2)
{
    return sqrt( pow((x2-x1), 2) + pow((y2-y1), 2));
}

char answer(double d, double r1, double r2)
{
    double r_max;
    double r_min;
    if (r1 > r2){
        r_max = r1;
        r_min = r2;
    } else {
        r_max = r2;
        r_min = r1;
    }
    bool inside = d < r_max;
    if (!inside) return 'O';

    bool contains = (d + r_min < r_max);
    if (contains) return 'I';

    bool tangent = (d + r_min == r_max);
    if (tangent) return 'E';

    return 'O';
}

int main()
{
    int n;
    int *array;
    auto fp = stdin;

    fscanf(fp, "%d", &n);

    array = (int*)malloc(6 * n * sizeof(*array));

    for (int i=0; i < 6 * n; i=i+6) {
        fscanf(fp, "%d %d %d %d %d %d", &array[i],
                &array[i+1],
                &array[i+2],
                &array[i+3],
                &array[i+4],
                &array[i+5]
              );
    }

    for (int i=0; i < 6 * n; i=i+6) {
        double d = point_distance(array[i],
                array[i+1],
                array[i+3],
                array[i+4]
                );
        std::cout << answer(d, array[i+2], array[i+5]) << "\n";
    }
}
