#include <iostream>
#include <cstdio>

using namespace std;

int main() {

        int n, x, result = 0;
        scanf("%d",&n);
        while(n--) {
                scanf("%d", &x);
                result ^= x;
        }
        printf("%d\n", result);

        return 0;
}
