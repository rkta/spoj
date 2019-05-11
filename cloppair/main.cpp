#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <algorithm>

// Input lines are:
// x1, y1

struct point{
    int x;
    int y;
    size_t ini_idx;
};

struct data{
    struct point* array;
    size_t n;
};

void read_stdin(struct data* d){
    auto fp = stdin;
    fscanf(fp, "%lu", &d->n);

    d->array = (struct point*)malloc(d->n * sizeof(*d->array));

    for (size_t i=0; i < d->n; ++i) {
        int x;
        int y;
        fscanf(fp, "%d %d", &x, &y);
        d->array[i] = { .x = x, .y = y, .ini_idx = i };
    }
}

double point_distance(const struct point& p1, const struct point& p2)
{
    return sqrt(pow((p2.x-p1.x), 2) + pow((p2.y-p1.y), 2));
}

bool cmp_x (const struct point &a, const struct point &b)
{
    return a.x < b.x;
}

int main()
{
    struct data da;
    read_stdin(&da);

    std::vector <struct point> points(da.array, da.array+da.n);

    std::sort(points.begin(), points.end(), cmp_x);

    double min_dist = std::numeric_limits<double>::max();

    for (size_t i=1; i < points.size(); ++i) {
        double d = point_distance(points[0], points[i]);
        if ( d < min_dist ) { min_dist = d; }
        std::cout << std::setw(3) << std::right << points[i].x << " " << std::setw(3) << std::right << points[i].y << " " << d << "\n";
    }
    std::cout << "mid_dist: " << min_dist << "\n";
    free(da.array);
}
