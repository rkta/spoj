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

struct data{
    int* array;
    int n;
    int fields;
};

void read_stdin(struct data* d){
    auto fp = stdin;
    fscanf(fp, "%d", &d->n);

    d->array = (int*)malloc(d->fields * d->n * sizeof(*d->array));

    for (int i=0; i < d->fields * d->n; i=i+d->fields) {
        for (int j = 0; j < d->fields; ++j){
        fscanf(fp, "%d", &d->array[i+j]);
        }
    }
}

int main()
{
    struct data da;
    da.fields=6;
    read_stdin(&da);

    for (int i=0; i < da.fields * da.n; i=i+da.fields) {
        double d = point_distance(da.array[i],
                da.array[i+1],
                da.array[i+3],
                da.array[i+4]
                );
        std::cout << answer(d, da.array[i+2], da.array[i+5]) << "\n";
    }
}
