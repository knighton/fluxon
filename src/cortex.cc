#include "cortex.h"

#include <cassert>

#include "util.h"

void Cortex::Init(size_t num_neurons) {
    neurons_.clear();
    assert(num_neurons);
    neurons_.resize(num_neurons);
    for (auto& neuron : neurons_) {
        neuron.InitDefaults(num_neurons);
    }
}

void Cortex::Dump() const {
    vector<float> values;
    vector<float> reliabilities;
    for (auto& neuron : neurons_) {
        neuron.CollectStatistics(&values, &reliabilities);
    }
    Look("value", values);
    Look("reliability", reliabilities);
}

void Cortex::Tick() {
    // TODO
}
