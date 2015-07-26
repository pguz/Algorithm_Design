#include <random>

#include <vector>
#include <iostream>

#include "algie/stable_matching.tpp"
#include "utils/TimeElapsedGuard.hpp"

using namespace std;

const vector< pair<int, int> > config = { {100, 80}, {200, 40}, {400, 20}, {800, 10}, {1600, 5} };

void random_unordered_map(int N_size, unordered_map<int, vector<int> >& um) {
    int l_bound = 1;
    int u_bound = N_size;
    int num_probes = N_size;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(l_bound, u_bound);
    
    for (int i = 1; i <= num_probes; ++i) {

        vector<int> v;
        unordered_set<int> s;
        
        for (int j = 1; j <= num_probes; ++j) {
            int generated = dis(gen);
            if(s.find(generated) != s.end()) {
                --j;
                continue;
            }
            s.insert(generated);
            v.push_back(generated);
        }
        um.insert(make_pair(i, v));
    }
}

long long stress_test(int N_size) {
    unordered_map<int, vector<int> > M;
    unordered_map<int, vector<int> > W;
    vector< pair<int, int> > res;
    
    random_unordered_map(N_size, M);
    random_unordered_map(N_size, W);
    
    long long microseconds = 0;
    
    {
        TimeElapsedGuard time_guard = TimeElapsedGuard(microseconds);
        cppie::algie::stable_matching<int, int>(M, W, res);    
    }
    
    return microseconds;
}

int main(int argc, char **argv) {
    for(auto& e: config) {
        const auto& N_size = e.first;
        const auto& repeated = e.second;
        
        cout << N_size << " time: " << flush;
        
        long long microseconds = 0;
        
        for(int i = 0; i < repeated; ++i)
            microseconds += stress_test(N_size);
        cout << microseconds / (double) repeated << endl;
    }
    return 0;
}
