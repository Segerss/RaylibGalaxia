#include <chrono>

#include "Millis.h"

auto start_time = std::chrono::high_resolution_clock::now();

unsigned long long millis() {
    unsigned long long millis = 0;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    millis = (unsigned long long)elapsed_time.count();
    return millis;
}
