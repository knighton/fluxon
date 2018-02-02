#pragma once

#include <vector>

#include "neuron.h"

using std::vector;

class Cortex {
  public:
    void Init(size_t num_neurons);

    void Dump() const;

    void Tick();

  private:
    vector<Neuron> neurons_;
};
