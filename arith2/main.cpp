#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

struct data{
    char* array;
    int n;
    int fields = 1;
};

void read_stdin(struct data* d){
    auto fp = stdin;
    fscanf(fp, "%d", &d->n);

    d->array = (char*)malloc(d->fields * d->n * sizeof(*d->array));

    for (int i=0; i < d->fields * d->n; i=i+d->fields) {
        for (int j = 0; j < d->fields; ++j){
        fscanf(fp, "%c\n", &d->array[i+j]);
        }
    }
}

int main()
{
    struct data da;
    da.fields=1;
    read_stdin(&da);

    for (int i=0; i < da.fields * da.n; i=i+da.fields) {
        //
    }
}
