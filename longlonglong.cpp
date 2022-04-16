#include <cmath>
#include <cstdlib>

struct longinteger {

    static const long long RANK = std::pow(10, 9);
    static const long long SIZE = 10;
    long long array[SIZE];

    longinteger() {
        for (int i = 0; i < SIZE; i++) {
            array[i] = 0;
        }
    }

    longinteger(const longinteger &other) {
        for (int i = 0; i < SIZE; i++) {
            array[i] = other.array[i];
        }
    }

    longinteger(long long x) {
        for (int i = 0; i < SIZE; i++) {
            array[i] = 0;
        }

        int next = 0;
        while (x) {
            array[next++] = x % RANK;
            x /= RANK;
        }
    }

    longinteger &operator=(const longinteger &other) {
        for (int i = 0; i < SIZE; i++) {
            array[i] = other.array[i];
        }

        return *this;
    }

};

