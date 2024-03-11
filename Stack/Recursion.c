/**
 * Author: Hossam Hassan
 * Description: applications on stacks
*/
#include <stdio.h>

/** Time Complexity: O(2 ^ n)*/
void hanoi(int N, char from, char to, char aux) {
    if(N) {
        hanoi(N - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", N, from, to);
        hanoi(N - 1, aux, to, from);
    }
    return;
}


/** Time Complexity: O(2 ^ n)*/
void hanoi2(int N, char from, char to, char aux) {
    int temp;
    while(N > 0) {
        hanoi2(N - 1, from, aux, to);
        printf("Move Disk %d from %c to %c\n", N, from, to);
        temp = from;
        from = aux;
        aux = temp;
        --N;
    }
    return;
}



int main() {
    hanoi(4, 'A', 'C', 'B');
    puts("\n");
    hanoi2(4, 'A', 'C', 'B');
}