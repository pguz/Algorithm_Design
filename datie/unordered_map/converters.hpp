#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "../queue/queue_inserter.hpp"

using namespace std;

namespace cppie {
namespace datie {
namespace unordered_mapie {
    
template<typename T, typename U>
void keys_into_queue(const unordered_map<T, U>& um, queue<T>& q) {
    transform(
        um.cbegin(),
        um.cend(),
        datie::queuie::make_queue_inserter(q),
        [](const typename unordered_map<T, U>::value_type &pair ){
	      return pair.first;});
}

template<typename T, typename U>
void keys_into_set(const unordered_map<T, U>& um, unordered_set<T>& us) {
    transform(
        um.cbegin(),
        um.cend(),
        inserter(us, us.end()),
        [](const typename unordered_map<T, U>::value_type &pair){
	      return pair.first;});
}

template<typename T, typename U, typename W, typename Lambda>
void into_vector(const unordered_map<T, U>& um, Lambda& func, vector<W>& v) {
    transform(
        um.cbegin(),
        um.cend(),
        back_inserter(v),
        func);
}

}}}
