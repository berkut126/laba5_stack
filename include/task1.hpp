
// Copyright 2019 Enyarina
#pragma once

#include "Stack.hpp"

template <class T>
class F_Stack : public Stack<T1>
{
public:
    void push(const T& value) {
        auto node = new typename Stack<T>::Node{value, Stack<T>::head};
        Stack<T>::head = node;
    }

    void pop() {
        if (Stack<T>::head)
            Stack<T>::head = Stack<T>::head->next;
        else
            throw std::exception();
    }
};
