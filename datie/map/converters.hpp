#pragma once

#include <map>
#include <vector>

using namespace std;

namespace cppie {
namespace datie {
namespace mapie {
    
template<typename T, typename U, typename W, typename Lambda>
void into_vector(const map<T, U>& um, Lambda& func, vector<W>& v) {
    transform(
        um.cbegin(),
        um.cend(),
        back_inserter(v),
        func);
}

}}}
