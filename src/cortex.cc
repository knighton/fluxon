#include "cortex.h"

#include <cassert>

void Cortex::Init(size_t num_neurons) {
    neurons_.clear();
    assert(num_neurons);
    neurons_.resize(num_neurons);
    for (auto& neuron : neurons_) {
        neuron.InitDefaults(num_neurons);
    }
}

void Cortex::Tick() {
    // TODO
}
