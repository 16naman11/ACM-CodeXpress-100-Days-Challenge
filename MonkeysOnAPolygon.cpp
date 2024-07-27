/*There is a regular convex polygon with n vertices. The vertices are labeled from 0 to n - 1 in a clockwise direction, and each vertex has exactly one monkey. The following figure (click here) shows a convex polygon of 6 vertices.

Each monkey moves simultaneously to a neighboring vertex. A neighboring vertex for a vertex i can be:

the vertex (i + 1) % n in the clockwise direction, or the vertex (i - 1 + n) % n in the counter-clockwise direction. A collision happens if at least two monkeys reside on the same vertex after the movement or intersect on an edge.

Print the number of ways the monkeys can move so that at least one collision happens. Since the answer may be very large, print it modulo 10^9 + 7.

Note that each monkey can only move once.

*/

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        int base_soln = 6;

        for (int i = 4; i <= n; i++) {
            
            base_soln = (base_soln * 2 + 2) % MOD;
        }

        cout << base_soln << endl;
    }

    return 0;
}
