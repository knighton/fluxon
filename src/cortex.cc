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
    vector<float> activations;
    vector<float> reliabilities;
    for (auto& neuron : neurons_) {
        neuron.CollectStatistics(&activations, &reliabilities);
    }
    Look("activation", activations);
    Look("reliability", reliabilities);
}

void Cortex::Step() {
    vector<float> activations;
    activations.resize(neurons_.size());
    for (size_t i = 0; i < neurons_.size(); ++i) {
        auto& neuron = neurons_[i];
        neuron.Step(i, &activations);
    }
    for (size_t i = 0; i < activations.size(); ++i) {
        neurons_[i].SetActivation(activations[i]);
    }
}
