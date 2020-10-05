#include <cassert>
#include <fstream>
#include "LFU.hpp"


int main() {
    int hits = 0;
    int n, m;
    int count = 0;
    std::cin >> m >> n;
    assert(std::cin.good());
    Cashe<int> c = {m};
    int q;
    while(std::cin >> q) {
        assert(std::cin.good());
        count++;
        if ( c.lookup(q) )
            hits += 1;
    }
    std::cout << "Hits: " << hits << std::endl;
    if ( count != n ) {
        std::cout << "Wrong file size\n";
    }
    return 0;
}

