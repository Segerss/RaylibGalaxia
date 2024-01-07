#include <ctime>
#include <time.h>

#include "Millis.h"

unsigned long long millis() {
    unsigned long long millis = (clock() / 100);

    return millis;
}
