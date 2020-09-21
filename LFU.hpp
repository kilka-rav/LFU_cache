struct cashe_t {
    size_t size_;
    std::unordered_map<int, std::multimap<int, int>::iterator> hash;
    std::multimap<int, int> rule;
    cashe_t(size_t size) : size_(size) {}

    bool full() {
        return (rule.size() == size_);
    }   
    
    auto search_min() {
        return rule.begin();
    }   
    void print() {
        std::multimap<int, int>::iterator It = rule.begin();
        while (It != rule.end()) {
            std::cout << "(" << It->first << ", " << It->second <<") ";
            It++;
        }
        std::cout<<std::endl;
    }
    bool lookup(int element) {
        auto hit = hash.find(element); 
        if ( hit == hash.end() ) {  // если элемент не найден
            if ( full() ) { //check size in rule
                auto del = search_min();
                hash.erase(del->second);
                rule.erase(del);
            }
            std::multimap<int, int>::iterator It = rule.insert(std::pair<int, int>(1, element));
            hash[element] = It;
            print();
            return false;
        }
        std::multimap<int, int>::iterator It = hit->second;
        int new_count = It->first + 1;
        rule.erase(hit->second);
        It = rule.insert(std::pair<int, int>(new_count, element));
        hash[element] = It;
        print();
        return true;
    }   
};

    
