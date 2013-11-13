//For Chapter12 exercise 4
#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned long Item;

class Stack
{
public:
    Stack(int n = 10);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator = (const Stack & st);

protected:

private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
};

#endif/*__STACK_H__*/