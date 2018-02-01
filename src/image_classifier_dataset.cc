#include "image_classifier_dataset.h"

#include <cassert>
#include <cstdio>
#include <fstream>

using std::ifstream;

void ImageClassifierDataset::Load(const string& filename) {
    x_train_.clear();
    y_train_.clear();
    x_val_.clear();
    y_val_.clear();

    size_t train_samples;
    size_t train_channels;
    size_t train_height;
    size_t train_width;
    size_t val_samples;
    size_t val_channels;
    size_t val_height;
    size_t val_width;

    ifstream in(filename);
    in >> train_samples >> train_channels >> train_height >> train_width;
    in >> val_samples >> val_channels >> val_height >> val_width;
    assert(train_channels == val_channels);
    assert(train_height == val_height);
    assert(train_width == val_width);
    size_t pixels_per_image = train_channels * train_height * train_width;

    printf("Loading %zu training + %zu validation images (%zux%zux%zu)...\n",
           train_samples, val_samples, train_channels, train_height,
           train_width);

    x_train_.reserve(train_samples);
    y_train_.reserve(train_samples);
    x_val_.reserve(val_samples);
    y_val_.reserve(val_samples);

    for (size_t i = 0; i < train_samples; ++i) {
        for (size_t j = 0; j < pixels_per_image; ++j) {
            uint8_t byte;
            in >> byte;
            x_train_.emplace_back(byte);
        }
        uint8_t byte;
        in >> byte;
        y_train_.emplace_back(byte);
    }

    for (size_t i = 0; i < val_samples; ++i) {
        for (size_t j = 0; j < pixels_per_image; ++j) {
            uint8_t byte;
            in >> byte;
            x_val_.emplace_back(byte);
        }
        uint8_t byte;
        in >> byte;
        y_val_.emplace_back(byte);
    }

    printf("...done.\n");
}
