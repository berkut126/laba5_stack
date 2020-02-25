// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include <Stack.hpp>
#include <task1.hpp>
#include <task2.hpp>

TEST(Stack, push_test_1)
{
    Stack<int> my_stack{};
    for (size_t index = 1; index <= 10; ++index) {
        my_stack.push(index);
    }
    EXPECT_EQ(my_stack.Head(), 10);
}

TEST(Stack, push_test_2)
{
    Stack<int> my_stack{};

    my_stack.push(1);
    my_stack.push(5);
    my_stack.push(10);

    EXPECT_EQ(my_stack.Head(), 10);
}

TEST(Stack, push_test_3)
{
    Stack<int> my_stack{};

    my_stack.push(1);
    EXPECT_EQ(my_stack.Head(), 1);
    my_stack.push(5);
    EXPECT_EQ(my_stack.Head(), 5);
    my_stack.push(10);
    EXPECT_EQ(my_stack.Head(), 10);
}

TEST(Stack, pop_test_1)
{
    F_Stack<int> my_stack{};

    my_stack.push(1);
    my_stack.push(5);
    my_stack.pop();

    EXPECT_EQ(my_stack.Head(), 1);
}

TEST(Stack, push_emplace)
{
    S_Stack<int> my_stack{};

    my_stack.push_emplace(1);
    EXPECT_EQ(my_stack.Head(), 1);
    my_stack.push_emplace(5);
    EXPECT_EQ(my_stack.Head(), 5);
    my_stack.push_emplace(10);
    EXPECT_EQ(my_stack.Head(), 10);
}

TEST(Stack, pop_test)
{
    S_Stack<int> my_stack{};

    my_stack.push(1);
    my_stack.push(5);
    my_stack.pop();

    EXPECT_EQ(my_stack.Head(), 1);
}
