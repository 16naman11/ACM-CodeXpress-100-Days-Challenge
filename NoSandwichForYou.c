/*The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Print the number of students that are unable to eat.*/


#include <stdio.h>

int countStudentsUnableToEat(int students[], int sandwiches[], int n) {
    int count = 0;
    while (n > 0) {
        if (students[0] == sandwiches[0]) {
            for (int i = 0; i < n - 1; i++) {
                students[i] = students[i + 1]; 
                sandwiches[i] = sandwiches[i + 1]; 
            }
            n--; 
            count = 0; 
        } else {
            int temp_student = students[0];
            for (int i = 0; i < n - 1; i++) {
                students[i] = students[i + 1]; 
            }
            students[n - 1] = temp_student; 
            count++;
            if (count == n) 
                break;
        }
    }
    return n; 
}

int main() {
    int T;
    scanf("%d", &T); 
    while (T--) {
        int n;
        scanf("%d", &n); 
        
        int students[n], sandwiches[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &students[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &sandwiches[i]);

        int unable_to_eat = countStudentsUnableToEat(students, sandwiches, n);
        printf("%d\n", unable_to_eat);
    }
    return 0;
}