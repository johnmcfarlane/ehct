#include "s.h"

void bar() {
    S s;
    s();
}

int main() {
    for (auto i = 10000000000L; i; -- i) {
        bar();
    }
}
