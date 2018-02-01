#include <cstdio>

#include "image_classifier_dataset.h"

int main() {
    ImageClassifierDataset mnist;
    mnist.Load("../spike/mnist.txt");
    printf("OK.\n");
}
