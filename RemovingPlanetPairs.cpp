/*Imagine you have a list of numbers that represent the masses of some planets in a solar system in kilograms. You also have a constant k.

In one step, you can choose two planets from the list whose masses add up to k and remove them from the list.

Find the maximum number of steps you can do on the list. (Note:- The planets are imaginary so the mass can be zero).*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        long k;
        cin >> n >> k;

        vector<long> masses(n);
        for (int i = 0; i < n; i++) {
            cin >> masses[i];
        }

        sort(masses.begin(), masses.end());

        int steps = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            long sum = masses[left] + masses[right];

            if (sum == k) {
                steps++;
                left++;
                right--;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }

        cout << steps << endl;
    }

    return 0;
}
