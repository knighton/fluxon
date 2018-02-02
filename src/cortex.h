#pragma once

#include <vector>

#include "neuron.h"

using std::vector;

class Cortex {
  public:
    void Init(size_t num_neurons);

    void Tick();

  private:
    vector<Neuron> neurons_;
};
