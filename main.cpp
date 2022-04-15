#include <cstdlib>
#include <cmath>

//Hello!

int modexp(int x, int y, int N)
{
    if (y == 0) return 1;
    int z = modexp(x, y / 2, N);
    if (y % 2 == 0)
        return (z*z) % N;
    else
        return (x*z*z) % N;
}

auto miller_rabin(int num1, int repeat = 50) {
    if (num1 == 2){
        return true;
    }

    if (num1 % 2 == 0){
        return false;
    }

    int r = 0;
    int s = num1 - 1;
    while (s % 2 == 0) {
        r += 1;
        s = s/2;
    }
    for (int i = 1; i < repeat + 1; i++) {
        int a;
        a = rand() % (num1 - 2) + 2;
        int x = modexp(a, s, num1);
        if (x == 1 or x == x == num1 - 1) {
            continue;
        }
        for (int count; count < r - 1; count++){
            int x = modexp(a, 2, num1);
            if (x == num1 - 1) {
                break;
            }
            else if (x == 1) {
                return false;
            }

        }
    }
    return true;
}


