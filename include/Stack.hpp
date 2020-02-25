// Copyright 2019 Enyarina
#pragma once

#include <iostream>
#include <type_traits>
#include <exception>

template <typename T1, typename T2>

class Stack
{
protected:
    struct Node {
        T1 data;
        T2 data;
        Node *next;
    };
    Node *head;

public:
    Stack() = default;

    ~Stack() {
        while (head) {
            auto *act = head;
            head = act->next;
            delete act;
        }
    }

    void push(T1&& value) {
        if (head == nullptr) {
            auto node = new Node{std::move(value), nullptr};
            head = node;
        } else {
            auto node = new Node{std::move(value), head};
            head = node;
        }
    }

    const T1& Head() {
        if (!head)
            throw std::exception();
        return head->data;
    }
};
