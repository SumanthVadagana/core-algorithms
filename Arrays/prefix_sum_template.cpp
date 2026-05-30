#include <iostream>
#include <vector>

using namespace std;

// Modular function to build the prefix array
vector<long long> buildPrefixSum(const vector<long long>& arr) {
    int n = arr.size();
    vector<long long> pref(n);
    
    if (n > 0) {
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    return pref;
}

// Modular function to execute the O(1) query
long long rangeQuery(const vector<long long>& pref, int L, int R) {
    if (L == 0) return pref[R];
    return pref[R] - pref[L - 1];
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> pref = buildPrefixSum(arr);

    int q;
    if (!(cin >> q)) return 0;

    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << rangeQuery(pref, L, R) << "\n";
    }

    return 0;
}