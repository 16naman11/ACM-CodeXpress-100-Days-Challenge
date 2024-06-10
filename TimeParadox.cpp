/*In a mysterious realm where time paradoxes abound, you find yourself facing a unique challenge involving a sequence of integers from 1 to n. The time-traveling algorithm you possess has the power to manipulate the array in a peculiar manner:

You start by traversing the array from left to right, removing the first number and then every other number that follows, creating an alternate timeline. Following this, you reverse the process by traversing the array from right to left, removing the rightmost number and every other number in the reverse timeline. This pattern repeats, jumping between timelines, until only a single number remains.

Your task is to determine the last number that persists through the time paradox. Given an integer n, adhere to the rules of the algorithm, and output the final integer that defies the paradoxical forces.*/

#include <iostream>

int last_number(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * (n / 2 + 1 - last_number(n / 2));
    }
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        std::cin >> n;
        int result = last_number(n);
        std::cout << result << std::endl;
    }

    return 0;
}
