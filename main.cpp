#include<stdlib.h>
#include <time.h>
#include"stack2.h"
#include <stdio.h>
int maxcount = 0;
int FindMax(Stack &S1){
    Stack S2;
    Init(S2);
    //Tvalue max = Top(S1);
    Tvalue max = 0;
    int startSize = Size(S1);
    for (int i = 0; i < startSize; i++){
        if (Top(S1) != -1 && Top(S1) > max){
            max = Top(S1);
        }
        Push(S2, Pop(S1));
    }
    maxcount = 0; // количество максимальных элементов
    startSize = Size(S2);
    for (int i = 0; i < startSize; i++){
        if (Top(S2) != max){
            Push(S1, Pop(S2));
        }
        else{
            Pop(S2);
            maxcount++;
        }
    }
    return max;
}
void SelectionSort(Stack &S){
    Stack S2;
    Init(S2);
    while (!Empty(S)) {
        Tvalue thatMax = FindMax(S);
        for (int i = 0; i < maxcount; i++) { // если было несколько одинаковых макс. элементов, добавляем все
            Push(S2, thatMax);
        }
    }
    if (stack1) {
        while (!Empty(S2)) { // переворачиваем стек, чтобы было расположение элементов от минимального к максимальному
            for (int i = 0; i < Size(S2); i++) {
                Push(S, Pop(S2));
            }
        }
    }
    else{
        printf("\nOutput stack: ");
        Display(S2);
    }
}
int main() {
    srand(time(0));
    Stack S1;
    Init(S1);
    Tvalue v;
    for (int i = 0; i < 10; i++) {
        v = rand()%100;
        Push(S1, v);
    }
    printf("Input stack: ");
    Display(S1);
    FindMax(S1);
    SelectionSort(S1);
    if (stack1) {
        printf("\nOutput stack: ");
        Display(S1); }
    return 0;
}