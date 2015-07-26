#pragma once

#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

namespace cppie {
namespace algie {

template <typename T, typename U>
int stable_matching(
        const unordered_map<T, vector<U> > &M,
        const unordered_map<U, vector<T> > &W,
        vector< pair<T, U> > &res);
}}
#include "stable_matching.tpp"
