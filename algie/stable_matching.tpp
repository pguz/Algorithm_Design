/* Consider a set M = [m_1, ..., m_n] and a set W = [w_1, ..., w_n].
 * Let M x W denote the set of all possible ordered pairs of form (m,w),
 * where m in M and w in W. A matching S is a set of ordered pairs of ordered
 * pairs, each from MxW, with the property that each member of M and each
 * member of W appears in at most one pair in S. A perfect matching S'
 * is a matching with the property that each member of M and each member
 * of W appears in exactly one pair in S'.
 *
 * Each m in M ranks all w in W. Each w in W analogously, ranks all m.
 * There are two pairs (m,w), and (m',w') in S with the property that
 * m prefers w' to w and w' prefers m to m'. In this case there's nothing
 * to stop m and w' from abandoning their current partners and heading off
 * together. We'll say that such a pair (m,w') is an instability with respect
 * to S.
 *
 * We define a matching S as stable if:
 * (i) it is perfect
 * (ii) there is no instability with respect to S.
 */

#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include "datie/unordered_map/converters.hpp"
#include "datie/map/converters.hpp"

using namespace std;
using namespace cppie;

namespace cppie {
namespace algie {

//Gale-Shapley algorithm
template<typename T, typename U>
int stable_matching(
        const unordered_map<T, vector<U> > &M,
        const unordered_map<U, vector<T> > &W,
        vector< pair<T, U> > &res){

    //Initially all m in M and w in W are free
    unordered_map<U, T> occupied;
    
    //queue for free m
    queue<T> M_free;
    datie::unordered_mapie::keys_into_queue(M, M_free);
    
    unordered_map< T, typename vector< U >::const_iterator > m_curr_w;
    transform(
        M.begin(), 
        M.end(), 
        inserter(m_curr_w, m_curr_w.end()), 
        [](const typename unordered_map<T, vector<U> >::value_type &pair){
	      return make_pair(pair.first, pair.second.cbegin());});

    //While there is m which is free
    while(!M_free.empty()) {
    
        //get m element and preferences
        const auto &m = M_free.front();
        const std::vector<U> &m_prefs = M.at(m);

        //Iterate through m preferences
        for(typename vector< U >::const_iterator w = m_curr_w.at(m); w != m_prefs.cend(); ++w) {
            m_curr_w[m] = w;
            //if w is free, then paired
            if(occupied.find(*w) == occupied.end()) {
                occupied[*w] = m;
                break;
            }
            
            //get m paired to w
            const T &m_curr_w = occupied[*w];
            
            //get w preferences
            const std::vector<T> &w_prefs = W.at(*w);
            
            //find which is better for w
            std::vector<T> ms_fighting {m, m_curr_w};
            const auto &it = find_first_of(
                w_prefs.begin(),
                w_prefs.end(),
                ms_fighting.begin(),
                ms_fighting.end());
                
            //m wins, update current infos
            if(*it == m) {
                M_free.push(m_curr_w);
                occupied[*w] = m;
                break;
            }
        }
        M_free.pop();
    }


    //convert into vector
    const auto &func_map_into_vector = 
        [](const typename unordered_map<T, U>::value_type &pair){
	      return make_pair(pair.second, pair.first);};
    
    datie::unordered_mapie::into_vector(
        occupied, 
        func_map_into_vector, 
        res);
    
    return 0;
}

}}
