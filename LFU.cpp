#include <cassert>
#include <list>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <fstream>
struct node {
    int elem;
    int count;
};

struct cashe_t {
    size_t size_;
    std::list<node> rule;
    using ListIt = std::list<node>::iterator;
    std::unordered_map<int, ListIt> hash;
    
    cashe_t(size_t size) : size_(size) {}

    bool full() {
        return (rule.size() == size_);
    }
                
    auto search_min() {
        ListIt it = rule.end();
        ListIt min_it = it;
        int min_count = it->count;
        while(it != rule.begin()) {
            if ( min_count >= it->count ) {
                min_it = it;
                min_count = it->count;
            }
            it--;
        }
        return min_it;
    }

    bool lookup(int element) {
        auto hit = hash.find(element); 
        if ( hit == hash.end() ) {  // если элемент не найден
            if ( full() ) { //check size in rule
                ListIt del = search_min();
                hash.erase(del->elem);
                hash.erase(del->count);
                rule.pop_back();
                        
            }
            node add = {element, 1};
            rule.push_front(add);
            hash[element] = rule.end();
            return false;
        }
        hit->second->count++;
        return true;
    }
};

                
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
        F.open("LFU.bad.txt");
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


