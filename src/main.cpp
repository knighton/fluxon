#include <cstdio>

#include "cortex.h"
#include "image_classifier_dataset.h"

int main() {
    ImageClassifierDataset mnist;
    mnist.Load("../spike/mnist.txt");

    Cortex cortex;
    cortex.Init(16536);
    cortex.Dump();

    printf("OK.\n");
}
