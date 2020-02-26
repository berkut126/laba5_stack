// Copyright 2018 Your Name <your_email>
#include <gtest/gtest.h>
#include <Stack.hpp>
#include <task1.hpp>
#include <task2.hpp>

struct Hello{
    int c = 0;
    char d = ' ';
    Hello(int a, char b){
        c = a;
        d = b;
    }
    explicit Hello(int a){
        c = a;
    }
    explicit Hello(char b){
        d = b;
    }
};

TEST(Stack, push_test_1)
{
    Stack<int> my_stack{};
    for (size_t index = 1; index <= 10; ++index) {
        my_stack.push(index);
    }
    EXPECT_EQ(my_stack.Head(), 10);
    EXPECT_EQ(std::is_move_constructible<Stack<std::string>>::value, true);
EXPECT_EQ(std::is_move_assignable<Stack<std::string>>::value, true);
}

TEST(Stack, push_test_2)
{
    Stack<int> my_stack{};
    my_stack.push(1);
    my_stack.push(5);
    my_stack.push(10);
    EXPECT_EQ(my_stack.Head(), 10);
    Stack<char> my_stack2{};
    my_stack2.push('1');
    my_stack2.push('5');
    my_stack2.push('8');
    EXPECT_EQ(my_stack2.Head(), '8');
}

TEST(Stack, push_test_3)
{
    Stack<char> my_stack{};
    my_stack.push('1');
    EXPECT_EQ(my_stack.Head(), '1');
    my_stack.push('5');
    EXPECT_EQ(my_stack.Head(), '5');
    my_stack.push('8');
    EXPECT_EQ(my_stack.Head(), '8');
    Stack<int> my_stack2{};
    my_stack2.push(1);
    EXPECT_EQ(my_stack2.Head(), 1);
    my_stack2.push(5);
    EXPECT_EQ(my_stack2.Head(), 5);
    my_stack2.push(8);
    EXPECT_EQ(my_stack2.Head(), 8);
}

TEST(Stack, pop_test_1)
{
    F_Stack<int> my_stack{};
    my_stack.push(1);
    my_stack.push(5);
    my_stack.pop();
    EXPECT_EQ(my_stack.Head(), 1);
    F_Stack<char> my_stack2{};
    my_stack2.push('1');
    my_stack2.push('5');
    my_stack2.pop();
    EXPECT_EQ(my_stack2.Head(), '1');
}

TEST(Stack, push_emplace)
{
    S_Stack<Hello> my_stack{};
    my_stack.push_emplace(1, 'a');
    EXPECT_EQ((my_stack.pop()).c, 1);
    my_stack.push_emplace(2, 'b');
    EXPECT_EQ((my_stack.pop()).d, 'b');
}

TEST(Stack, pop_test)
{
    S_Stack<int> my_stack{};
    my_stack.push(1);
    my_stack.push(5);
    my_stack.pop();
    EXPECT_EQ(my_stack.Head(), 1);
    S_Stack<char> my_stack2{};
    my_stack2.push('1');
    my_stack2.push('5');
    my_stack2.pop();
    EXPECT_EQ(my_stack2.Head(), '1');
}
