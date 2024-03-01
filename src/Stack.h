#ifndef SRC_STACK_H_
#define SRC_STACK_H_

class Stack {
 public:
    Stack();
    void Push(int value);
    int Pop();
    int Top();
    bool IsEmpty();
    bool IsFull();
 private:
    int top_;
    int stack_[10];
};

#endif  // SRC_STACK_H_
