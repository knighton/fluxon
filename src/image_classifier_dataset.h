#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class ImageClassifierDataset {
  public:
    const vector<uint8_t>& x_train() const { return x_train_; }
    const vector<uint8_t>& y_train() const { return y_train_; }
    const vector<uint8_t>& x_val() const { return x_val_; }
    const vector<uint8_t>& y_val() const { return y_val_; }

    void Load(const string& filename);

  private:
    vector<uint8_t> x_train_;
    vector<uint8_t> y_train_;
    vector<uint8_t> x_val_;
    vector<uint8_t> y_val_;
};
