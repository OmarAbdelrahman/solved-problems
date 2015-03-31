#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n < 3) {
        cout << n << endl;
        return 0;
    }

    int result = 2;
    for (int i = 2, j; i < n; ++i) {
        for (j = i; j < n && a[j] == a[j - 1] + a[j - 2]; ++j);
        result = max(result, j - i + 2);
        i = j;
    }
    
    cout << result << endl;
    return 0;
}
