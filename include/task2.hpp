// Copyright 2019 Enyarina
#pragma once

#include "Stack.hpp"

template <typename T>
class S_Stack : public Stack<T>
{
public:
    template <typename ... Args>
    void push_emplace(Args&& ... value) {
        auto node = Stack<T>::head;
        Stack<T>::head = new typename
                Stack<T>::Node{std::forward<Args>(value ...), node};
    }
    
    T pop() {
        if (Stack<T>::head) {
            auto node = Stack<T>::head->data;
            Stack<T>::head = Stack<T>::head->next;
            return node;
        } else {
            throw std::exception();
        }
    }
};

