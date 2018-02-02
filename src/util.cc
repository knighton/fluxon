#include "util.h"

#include <cassert>
#include <cmath>
#include <cstdio>

void Look(const string& title, const vector<float>& ff) {
    assert(ff.size());

    float min = ff[0];
    float max = ff[0];
    float sum = 0;
    for (auto& f : ff) {
        if (f < min) {
            min = f;
        }
        if (max < f) {
            max = f;
        }
        sum += f;
    }
    float mean = sum / ff.size();
    float std = 0;
    for (auto& f : ff) {
        std += (f - mean) * (f - mean);
    }
    std = sqrt(std / ff.size());

    printf("    %s:\n", title.c_str());
    printf("        count: %zu\n", ff.size());
    printf("        range: min %.6f max %.6f\n", min, max);
    printf("        chart: mean %.6f std %.6f\n", mean, std);
}
