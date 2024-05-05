#ifndef LAB_12_STACK_H
#define LAB_12_STACK_H

#include <iostream>
#include <memory>
#include <cassert>

class Stack{
private:
    struct Node{
        char data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head = nullptr;
    int N = 0;
public:
    Stack() = default;

    ~Stack(){
        while(head){
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }

    void push(char item){
        head = std::unique_ptr<Node>(new Node{item, std::move(head)});
        ++N;
    }

    char pop(){
        assert(N > 0);
        auto next = std::move(head->next);
        char item = head->data;
        head = std::move(next);
        --N;
        return item;
    }

    char top(){
        return head->data;
    }

    bool empty() const{
        return N == 0;
    }

    // TODO : implement print function

    void print() const{
        Node* temp = head.get();
        while(temp != nullptr){
            std::cout << temp->data << ' ';
            temp = temp->next.get();
        }
        std::cout << '\n';
    }
};

#endif //LAB_12_STACK_H
