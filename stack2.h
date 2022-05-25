#include <stdio.h>

#define N 100
#define Tvalue int
struct El_St {
    Tvalue V;
    El_St * next;
};

struct Stack {
    El_St * first;
    int size;
};

void Init(Stack & S) {
    S.first = 0;
    S.size = 0;
}

int Empty(Stack S) {
    return S.first == 0;
}

void Push(Stack & S, Tvalue V) {
    El_St * t = new El_St;
    t -> next = S.first;
    S.first = t;
    S.first -> V = V;
    S.size++;
}

Tvalue Pop(Stack & S) {
    if (Empty(S)) {
        printf("STACK IS EMPTY");
    }
    else {
        Tvalue V = S.first -> V;
        S.first = S.first -> next;
        S.size--;
        return V;
    }
}

Tvalue Top(Stack S) {
    if (Empty(S)) {
        return -1;
    }
    else return S.first -> V;
}

int Size(Stack S) {
    return S.size;
}

void Display(Stack S) {
    if (Empty(S)) { printf("\nStack is empty\n");fflush(stdout); }
    else {
        printf("Numbers of stack elements:\n[ ");
        El_St * t = S.first;
        while (t) {
            printf("%d ", t -> V);
            t = t -> next;
        }
        printf("]\n");fflush(stdout);
    }
}
void Cat(Stack & S1, Stack & S2) {
    Tvalue V;
    if (!Empty(S2)) {
        V = Pop(S2);
        Cat(S1, S2);
        Push(S1, V);
    }
}

void Append(Stack & S1, Stack & S2) {
    Tvalue V;
    if (Empty(S1)) Cat(S1, S2);
    else {
        V = Pop(S1);
        Append(S1, S2);
        Push(S1, V);
    }
}
bool stack1 = false;