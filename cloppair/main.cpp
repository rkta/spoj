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

double dist_all(std::vector<point>::iterator begin,
        std::vector<point>::iterator end,
        bool skip = true)
{
    double min_dist = std::numeric_limits<double>::max();
    for (auto it = begin; it != end; ++it){
        std::cout << it->x << " " << it->y << "\n";
        for (auto jt = it + 1; jt != end; ++jt){
            if (skip) {
                if ( (jt->x - it->x) > min_dist) {break;}
            }
            double d = point_distance(*it, *jt);
            if ( d < min_dist ) { min_dist = d; }
            std::cout << std::setw(3) << std::right << jt->x << " " << std::setw(3) << std::right << jt->y << " " << d << "\n";
        }
        std::cout << "min_dist: " << min_dist << "\n";
        std::cout << std::endl;
    }
    return min_dist;
}

int main()
{
    struct data da;
    read_stdin(&da);

    std::vector <struct point> points(da.array, da.array+da.n);

    std::sort(points.begin(), points.end(), cmp_x);

    for (size_t i=0; i < points.size(); ++i){
        std::cout << std::setw(3) << std::right << points[i].x << " " << std::setw(3) << std::right << points[i].y << "\n";
    }
    std::cout << std::endl;

    double min_dist = dist_all(points.begin(), points.end(), false);
    double min_dist_break = dist_all(points.begin(), points.end());

    std::cout << "min_dist_break: " << min_dist_break << "\n";
    std::cout << "min_dist: " << min_dist << "\n";

    free(da.array);
}
