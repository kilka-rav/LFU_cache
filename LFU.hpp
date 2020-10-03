#ifndef _LFU_HPP_
#define _LFU_HPP_
#include <iostream>
#include <unordered_map>
#include <map>
#include <iterator>

using Rule_t = std::multimap<int, double>;
using Hash_t = std::unordered_map<int, Rule_t::iterator>;

template <typename T>
class Cashe {
    size_t size_;
    Hash_t hash;
    Rule_t rule;
    public:
        Cashe(size_t size) : size_(size) {}
    private:
        bool full() const {
            return (rule.size() == size_);
        }   
    
    auto search_min() const {
        return rule.begin();
    }   
    /*void print() {
        Rule_t::iterator It = rule.begin();
        while (It != rule.end()) {
            std::cout << "(" << It->first << ", " << It->second <<") ";
            It++;
        }
        std::cout<<std::endl;
    }
    */    //неудобно выводить при больших размерах
    public:
        bool lookup(const T element) {
            auto hit = hash.find(element); 
            if ( hit == hash.end() ) {  
                if ( full() ) { 
                    auto del = search_min();
                    hash.erase(del->second);
                    rule.erase(del);
                }   
                Rule_t::iterator It = rule.insert(std::pair<int, T>(1, element));
                hash[element] = It;
                //print();
                return false;
            }
            Rule_t::iterator It = hit->second;
            int new_count = It->first + 1;
            rule.erase(hit->second);
            It = rule.insert(std::pair<int, T>(new_count, element));
            hash[element] = It;
            //print();
            return true;
        }   
};
#endif
