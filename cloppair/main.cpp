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

struct result{
    double min_dist;
    size_t lo_idx;
    size_t up_idx;
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

bool cmp_x (const struct point& a, const struct point& b)
{
    return a.x < b.x;
}

bool cmp_y (const struct point& a, const struct point& b)
{
    return a.y < b.y;
}

template <int point::*M>
struct result dist_all(std::vector<point>::iterator begin,
        std::vector<point>::iterator end,
        bool skip = true)
{
    struct result res;
    res.min_dist = std::numeric_limits<double>::max();
    for (auto it = begin; it != end; ++it){
        //std::cout << it->x << " " << it->y << "\n";
        for (auto jt = it + 1; jt != end; ++jt){
            if (skip) {
                if ( (*jt.*M - *it.*M) > res.min_dist) {break;}
            }
            double d = point_distance(*it, *jt);
            if ( d < res.min_dist ) {
                res.min_dist = d;
                res.lo_idx = it->ini_idx;
                res.up_idx = jt->ini_idx;
            }
            //std::cout << std::setw(3) << std::right << jt->x << " " << std::setw(3) << std::right << jt->y << " " << d << "\n";
        }
        //std::cout << "min_dist: " << res.min_dist << "\n";
        //std::cout << std::endl;
    }
    return res;
}

int main()
{
    struct data da;
    read_stdin(&da);

    std::vector <struct point> points(da.array, da.array+da.n);

    std::sort(points.begin(), points.end(), cmp_x);

    //std::cout << "input data sorted:\n";
    //std::cout << std::setw(3) << std::right << "x" << std::setw(3) << std::right << "y" << std::setw(3) << std::right << "i" << "\n";
    //for (size_t i=0; i < points.size(); ++i){
    //    std::cout << std::setw(3) << std::right << points[i].x << " " << std::setw(3) << std::right << points[i].y << " " << std::setw(3) << std::right << points[i].ini_idx << "\n";
    //}
    //std::cout << std::endl;

    //struct result min_dist = dist_all<&point::x>(points.begin(), points.end(), false);
    //struct result min_dist_break = dist_all<&point::x>(points.begin(), points.end());

    auto median = points.begin() + points.size()/2;
    //std::cout << "L--------------------------------------------------------------------------------\n";
    //struct result min_distL = dist_all<&point::x>(points.begin(), median, false);
    struct result min_distL = dist_all<&point::x>(points.begin(), median);
    //std::cout << "R--------------------------------------------------------------------------------\n";
    //struct result min_distR = dist_all<&point::x>(median, points.end(), false);
    struct result min_distR = dist_all<&point::x>(median, points.end());

    //double min_distT = std::min(min_distL.min_dist, min_distR.min_dist);
    double min_distT = std::min(min_distL.min_dist, min_distR.min_dist);

    std::vector<struct point> s;
    for (auto& p : points){
        if (std::abs(p.x - median->x) < min_distT){
            s.push_back(p);
        }
    }
    std::sort(s.begin(), s.end(), cmp_y);
    struct result min_distS = dist_all<&point::x>(s.begin(), s.end(), false);

    //std::cout << "array s:\n";
    //for (auto& p : s){
    //    std::cout << std::setw(3) << std::right << p.x << " " << std::setw(3) << std::right << p.y << "\n";
    //}

    //std::cout << "min_dist_break: " << min_dist_break.min_dist << " idx: " << min_dist_break.lo_idx << " " << min_dist_break.up_idx << "\n";
    //std::cout << "min_dist: " << min_dist.min_dist << " idx: " << min_dist.lo_idx << " " << min_dist.up_idx << "\n";
    std::cout << "min_dist L: " << min_distL.min_dist << " idx: " << min_distL.lo_idx << " " << min_distL.up_idx << "\n";
    std::cout << "min_dist R: " << min_distR.min_dist << " idx: " << min_distR.lo_idx << " " << min_distR.up_idx << "\n";
    std::cout << "min_dist S: " << min_distS.min_dist << " idx: " << min_distS.lo_idx << " " << min_distS.up_idx << "\n";

    //cout << fixed << setprecision(6);
    free(da.array);
}
