#include <iostream>
using namespace std;

bool check(int mid, int arr[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < mid; i++) {
        sum += arr[i];
    }
    if (sum >= k) return true;

    for (int i = mid; i < n; i++) {
        sum += arr[i] - arr[i - mid];
        if (sum >= k) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, arr, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
