#include <cassert>
#include <fstream>
#include "LFU.hpp"


int main() {
    int hits = 0;
    int n, m;
    std::cin >> m >> n;
    assert(std::cin.good());
    Cashe<int> c = {m};
    for(int i = 0; i < n; i++) {
        int q;
        std::cin >> q;
        assert(std::cin.good());
        if ( c.lookup(q) )
            hits += 1;
    }
    std::cout << "Hits: " << hits << std::endl;
    return 0;
}

