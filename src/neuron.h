#pragma once

#include <cstdint>
#include <utility>
#include <vector>

using std::pair;
using std::vector;

class Neuron {
  public:
    // Generate an initial activation value with the desired properties.
    //
    // Start with most neurons almost "empty", with a smattering of
    // likely-to-spike high values to try to achieve a normal-looking activation
    // pattern at cold start.
    static float MakeInitialValue();

    // Generate a valid 'reliability' value with the desired properties.
    //
    // Sample a uniform distribution from 0 to 1, then heavily bend it toward
    // the high end.
    static float MakeReliability();

    // Select an initial distribution of neighboring neurons to connect to.
    static void MakeInitialOutputs(size_t num_neurons,
                                   vector<pair<uint32_t, float>>* out);

    // Accessors.
    float value() const { return value_; }
    float reliability() const { return reliability_; }
    const vector<pair<uint32_t, float>>& out() const { return out_; }

    // Set up a neuron with the given initial values.
    void InitValues(float value, float reliability,
                    const vector<pair<uint32_t, float>>& out);

    // Set up a neuron choosing its own reasonable initial values.
    void InitDefaults(size_t num_neurons);

    // Gather up our values to track high-level statistics.
    void CollectStatistics(vector<float>* values,
                           vector<float>* reliabilities) const;

  private:
    // Its activation (non-negative).  Zeroed after spiking.
    float value_;

    // From 0 (spikes are pure noise) to 1 (spike at 1.0 with no noise).
    float reliability_;

    // List of (neuron index, fraction of activation to send from 0 to 1).
    vector<pair<uint32_t, float>> out_;
};
