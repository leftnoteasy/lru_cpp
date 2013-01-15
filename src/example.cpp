#include "lru_cache.h"

#include <vector>
#include <iostream>

using namespace lrucache;
using namespace std;

int main() {
    const int ARRAY_SIZE = 12;
    int data[] = {1, 2, 3, 5, 4, 3, 2, 1, 4, 1, 3, 5};
    LruCache<int, int> cache(3);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int num = data[i];
        int* v = cache.get(num);
        if (NULL == v) {
            cout << "miss:" << num << endl;
            if (cache.size() < cache.maxSize()) {
                cache.add(num, num);
                cout << "add:" << num << endl;
            }
        } else {
            if (*v != num) {
                cout << "error:" << *v << " " << num << endl;
                return -1;
            }
            cout << "hit:" << num << endl;
        }
    }
}