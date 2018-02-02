#include "neuron.h"

#include <cassert>
#include <cmath>
#include <cstdlib>

using std::make_pair;

namespace {

inline float Rand() {
    return (float)rand() / RAND_MAX;
}

}  // namespace

float Neuron::MakeInitialValue() {
    float ret = Rand();
    return ret * ret;
}

float Neuron::MakeReliability() {
    float ret = Rand();
    return sqrt(ret);
}

void Neuron::MakeInitialOutputs(size_t num_neurons,
                                vector<pair<uint32_t, float>>* outputs) {
    outputs->clear();
    assert(num_neurons);

    // First, select what fraction of the population of neurons to connect to
    // (ie, a "balanced" collection of low and high amounts of fanout).
    float coverage = Rand();
    coverage *= 0.2;
    coverage += 0.025;

    // Then randomly sample that fraction of the neurons (self-linking is
    // considered okay).  Weight the connections with a steep backoff so that
    // some pairs of neurons can be tight.
    float sum_of_weights = 0;
    for (uint32_t i = 0; i < num_neurons; ++i) {
        if (Rand() < coverage) {
            float weight = pow(Rand(), 3);
            outputs->emplace_back(make_pair(i, weight));
            sum_of_weights += weight;
        }
    }

    // The weights need to add up to 1.
    for (auto& it : *outputs) {
        auto& weight = it.second;
        weight /= sum_of_weights;
    }
}

void Neuron::InitValues(
        float value, float reliability,
        const vector<pair<uint32_t, float>>& out) {
    out_.clear();
    assert(0 <= value);
    assert(0 <= reliability);
    assert(reliability <= 1);
    for (auto& it : out) {
        auto& frac = it.second;
        assert(0 < frac);
        assert(frac <= 1);
    }
    value_ = value;
    reliability_ = reliability;
    out_.reserve(out.size());
    for (auto& it : out) {
        out_.emplace_back(it);
    }
}

void Neuron::InitDefaults(size_t num_neurons) {
    float value = MakeInitialValue();
    float reliability = MakeReliability();
    vector<pair<uint32_t, float>> out;
    MakeInitialOutputs(num_neurons, &out);
    InitValues(value, reliability, out);
}
