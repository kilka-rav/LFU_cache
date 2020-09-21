#include <cassert>
#include <list>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <map>
#include "LFU.hpp"

int main() {
    std::ifstream F;
    int num;
    std::cout<<"Choose test: 1-test, 2 - random, 3 - LFU_bad\n";
    std::cin>>num;
    assert(std::cin.good());

    if ( num == 1 ) {
    F.open("test.txt");
    }
    else if ( num == 2 ) {
        F.open("random.txt");
    }
    else if ( num == 3 ) {
        F.open("LFU_bad.txt");
    }
    int hits = 0;
    int n;
    size_t m;
    F >> m;
    assert(std::cin.good());
    F >> n;
    assert(std::cin.good());
    cashe_t c{m};
    for(int i = 0; i < n; i++) {
        int q;
        F >> q;
        assert(std::cin.good());
        if ( c.lookup(q) )
            hits += 1;
    }
    std::cout << "Hits: " << hits << std::endl;
    F.close();
    return 0;
}


