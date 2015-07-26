#include <random>
#include <iostream>
#include <unordered_set>

using namespace std;

void print_usage(int argc, char* argv[]) {
    cout << "./" << argv[0] << " lower_bound upper_bound num_probes" << endl;
}

int main(int argc, char* argv[]) {
    
    if(argc < 4) {
        print_usage(argc, argv);
        return -1;
    }
    
    int l_bound, u_bound, num_probes;
        
    try {
        l_bound = stoi(argv[1]);
        u_bound = stoi(argv[2]);
        num_probes = stoi(argv[3]);
    } catch(...) {
        print_usage(argc, argv);
        return -1;
    } 
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(l_bound, u_bound);
    
    for (int i = 0; i < num_probes; ++i) {
        cout << "{" << i << ", {";
        
        int generated = dis(gen);
        unordered_set<int> s {generated};
        cout << generated;
        
        for (int j = 0; j < num_probes - 1; ++j) {
            generated = dis(gen);
            if(s.find(generated) != s.end()) {
                --j;
                continue;
            }
            s.insert(generated);
            cout <<", " << generated;
        }
        cout << "}},\n";
    }
    cout << '\n';
    
    return 0;
}
