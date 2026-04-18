// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int MAXsize>
class TStack {
 private:
    T data[MAXsize];
    int top;
 public:
    TStack() : top(0) {}
    void push_back(const T& value) {
        data[top] = value;
        top++;
    }
    void pop_back() {
        top--;
    }
    T get_el(int i) {
        return data[i];
    }
};

#endif  // INCLUDE_TSTACK_H_
