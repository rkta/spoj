#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

// Input lines are:
// x1, y1, r1, x2, y2, r2
// with x,y being the center of the circle
// Sample data
// "103 104 5 100 100 10"
// "103 104 10 100 100 10"
// Distance: 5 and 5

double point_distance(double x1, double y1, double x2, double y2)
{
    return sqrt( pow((x2-x1), 2) + pow((y2-y1), 2));
}

bool is_inside(double d, double r1, double r2)
{
    return r1 > r2 ? d < r1 : d < r2;
}

bool is_overlapping(double d, double r1, double r2)
{
    return (r1 + r2) > d;
}

int main()
{
    std::cout << "103 104 5 100 100 10" << std::endl << "103 104 10 100 100 10" << std::endl << std::endl;
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

    std::cout << std::endl;

    for (int i=0; i < 6 * n; i=i+6) {
        double d = point_distance(array[i],
                array[i+1],
                array[i+3],
                array[i+4]
                );
        std::cout << d << " ";
        if (is_inside(d, array[i+2], array[i+5])){
            printf("%c\n", 'I');
        } else if ( is_overlapping(d, array[i+2], array[i+5])){
            printf("%c\n", 'E');
        } else {
            printf("%c\n", 'O');
        }
    }
}
