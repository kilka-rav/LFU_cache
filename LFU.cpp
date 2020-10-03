#include <cassert>
#include <fstream>
#include "LFU.hpp"


int main() {
    int hits = 0;
    int n;
    size_t m;
    std::cin >> m;
    assert(std::cin.good());
    std::cin >> n;
    assert(std::cin.good());
    Cashe<double> c = {m};
    double q;
    for(int i = 0; i < n; i++) {
        std::cin >> q;
        assert(std::cin.good());
        if ( c.lookup(q) )
            hits += 1;
    }
    std::cout << "Hits: " << hits << std::endl;
    return 0;
}


