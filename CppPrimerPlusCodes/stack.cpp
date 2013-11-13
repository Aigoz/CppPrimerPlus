#include "stack.h"

Stack::Stack(int n /* = 10 */)
{
    if (MAX >= n)
        size = n;
    else
        size = MAX;
    top = 0;
    pitems = new Item [size];
}

Stack::Stack(const Stack & st)
{
    size = st.size;
    top = st.top;
    pitems = new Item [size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    if (0 == top)
        return true;
    return false;
}

bool Stack::isfull() const
{
    if (size == top)
        return true;
    return false;
}

bool Stack::push(const Item & item)
{
    if (isfull())
        return false;

    pitems[top++] = item;
    return true;
}

bool Stack::pop(Item & item)
{
    if (isempty())
        return false;

    item = pitems[--top];
    return true;
}

Stack & Stack::operator=(const Stack & st)
{
    if (&st == this)
        return *this;
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item [size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];
}