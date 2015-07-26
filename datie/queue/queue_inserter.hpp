#pragma once

#include <queue>

using namespace std;

namespace cppie {
namespace datie {
namespace queuie {

template< typename T, typename U >
class queue_inserter : public std::iterator<std::output_iterator_tag, T>{
    queue<T, U> &qu;
public:
    queue_inserter(queue<T,U> &q) : qu(q) { }
    queue_inserter<T,U> operator ++ (int) { return *this; }
    queue_inserter<T,U> operator ++ () { return *this; }
    queue_inserter<T,U> operator * () { return *this; }
    void operator = (const T &val) { qu.push(val); }
};

template< typename T, typename U >
queue_inserter<T,U> make_queue_inserter(queue<T,U> &q) {
    return queue_inserter<T,U>(q);
}

}}}
