/*Reena and Meena are playing an interesting game. They start from specific coordinates and take turns giving each other directions. Reena starts at point (x, y), and they follow a series of directions given by instructions through a string s, the instructions are as follows : -

There are following symbols in the String
N - North direction
S - South direction
E - East direction
W - West direction
The integers followed by the above symbols in the string signify the distance to be covered in the direction mentioned through the symbols (N,S,E,W).
Your task is to calculate the Euclidean distance from the origin (0,0) to their final position after following the directions.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int x, y;
        std::cin >> x >> y;

        std::string s;
        std::cin >> s;

        int len = s.length();

        for (int i = 0; i < len; i++) {
            int distance;

            // Check if the next characters form a valid integer
            if (std::isdigit(s[i + 1]) || (s[i + 1] == '-' && std::isdigit(s[i + 2]))) {
                std::sscanf(s.c_str() + i + 1, "%d", &distance);

                if (s[i] == 'N') {
                    y += distance;
                } else if (s[i] == 'S') {
                    y -= distance;
                } else if (s[i] == 'E') {
                    x += distance;
                } else if (s[i] == 'W') {
                    x -= distance;
                }

                // Skip the digits in the string
                while (std::isdigit(s[i + 1]) || s[i + 1] == '-') {
                    i++;
                }
            }
        }

        int final = x * x + y * y;
        double res = std::sqrt(final);
        std::cout << std::fixed << std::setprecision(2) << res << std::endl;
    }

    return 0;
}
