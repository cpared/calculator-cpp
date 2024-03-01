
#include "Stack.h"

Stack::Stack() {
    top_ = -1;
}

void Stack::Push(int value) {
    if (IsFull()) {
        return;
    }
    stack_[++top_] = value;
}

int Stack::Pop() {
    if (IsEmpty()) {
        return -1;
    }
    return stack_[top_--];
}

int Stack::Top() {
    return stack_[top_];
}


bool Stack::IsEmpty() {
    return top_ == -1;
}

bool Stack::IsFull() {
    return top_ == 9;
}
