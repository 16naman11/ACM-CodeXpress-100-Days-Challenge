/*Lira is now very keen on compiler development. :)

She knows that one of the most important components of a compiler, is its parser.

A parser is, in simple terms, a software component that processes text, and checks it's semantic correctness, or, if you prefer, if the text is properly built.

As an example, in declaring and initializing an integer, in C/C++, you can't do something like:

int = x ;4

as the semantics of such statement is incorrect, as we all know that the datatype must precede an identifier and only afterwards should come the equal sign and the initialization value, so, the corrected statement should be:

int x = 4;

Today, Lira is concerned with an abstract instruction which is composed of the characters "<" and ">" , which she will use on the design of her language, L++ :D.

She is using it as an abstraction for generating XML code Tags in an easier fashion and she understood that, for an expression to be valid, a "<" symbol must always have a corresponding ">" character somewhere (not necessary immediately) after it. Moreover, each ">" symbol should correspond to exactly one "<" symbol.

So, for instance, the instructions:

<<>>

<><>

<>

are all valid. While:

<<

>

are not.

Given some expressions which represent some instructions to be analyzed by Lira's compiler, you should tell the length of the longest prefix of each of these expressions that is valid, or 0 if there's no such a prefix.*/

#include <iostream>
#include <stack>
#include <string>

int longestValidPrefix(const std::string& expression) {
    std::stack<char> stack;
    int maxLength = 0;
    int currentLength = 0;

    for (char c : expression) {
        if (c == '<') {
            stack.push(c);
        } else if (c == '>') {
            if (!stack.empty()) {
                stack.pop();
                currentLength += 2; // Each pair contributes 2 to the length
                if (stack.empty()) {
                    maxLength = std::max(maxLength, currentLength);
                }
            } else {
                break; // Invalid prefix encountered
            }
        }
    }

    return maxLength;
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::string expression;
        std::cin >> expression;

        int result = longestValidPrefix(expression);
        std::cout << result << std::endl;
    }

    return 0;
}