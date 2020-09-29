#include <cassert>
#include <fstream>
#include "LFU.hpp"


int main() {
    std::ifstream F;
    int num;
    std::cout<<"Choose test: 1-test, 2 - random, 3 - LFU_bad 4 - check_template\n";
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
    else if ( num == 4 ) {
        F.open("check_template.txt");
    }
    int hits = 0;
    int n;
    size_t m;
    F >> m;
    assert(std::cin.good());
    F >> n;
    assert(std::cin.good());
    Cashe<double> c = {m};
    double q;
    for(int i = 0; i < n; i++) {
        F >> q;
        assert(std::cin.good());
        if ( c.lookup(q) )
            hits += 1;
    }
    std::cout << "Hits: " << hits << std::endl;
    F.close();
    return 0;
}


