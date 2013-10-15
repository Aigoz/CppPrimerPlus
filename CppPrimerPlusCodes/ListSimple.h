#ifndef __LISTSIMPLE_H__
#define __LISTSIMPLE_H__

// User Definition Item Data Type
// typedef double itemType;
// Use template is better!!

// List Item will be used by List Class
template <typename T>
struct listItem {
    T nodeItem;
    listItem * nextItem;
};

template <typename T>
class ListSimple
{
private:
    listItem<T> * lastItem;
    listItem<T> * firstItem;
    int listCount;
    bool _removeItem(listItem<T> * theListItem);

public:
    ListSimple();
    ListSimple(const T & theItem);
    ~ListSimple();

    bool isEmpty() const;
//    bool isFull() const;
    int getListCount() const;

    bool addItem(const T & nItem);
    bool addItemAtIndex(const T & nItem, int theIndex);
    bool removeItem();
    bool removeItem(const T & nItem);
    bool removeItemAtIndex(const T & nItem, int theIndex);
    void emptyList();

    void visit(void (*pf)(T & theItem)) const;
};


/************************************************************************/
/*                  Template Method Implementation                      */
/************************************************************************/
template <typename T>
ListSimple<T>::ListSimple()
{
    lastItem = firstItem = nullptr;
    listCount = 0;
}

template <typename T>
ListSimple<T>::ListSimple(const T & theItem)
{
    listItem<T> * currentListItem_ptr = new listItem<T>;
    currentListItem_ptr->nextItem = nullptr;
    currentListItem_ptr->nodeItem = theItem;

    listCount = 1;
    firstItem = currentListItem_ptr;
    lastItem = currentListItem_ptr;
}

template <typename T>
ListSimple<T>::~ListSimple()
{
    emptyList();
    lastItem = firstItem = nullptr;
}

template <typename T>
bool ListSimple<T>::isEmpty() const
{
    if (nullptr == firstItem)
        return true;
    else
        return false;
}

template <typename T>
int ListSimple<T>::getListCount() const
{
    return listCount;
}

template <typename T>
bool ListSimple<T>::addItem(const T & nItem)
{
    listItem<T> * currentListItem_ptr = new listItem<T>;
    if (currentListItem_ptr)
    {
        currentListItem_ptr->nextItem = nullptr;
        currentListItem_ptr->nodeItem = nItem;
    }
    else
        return false;

    lastItem->nextItem = currentListItem_ptr;
    lastItem = currentListItem_ptr;
    ++listCount;

    return true;
}

template <typename T>
bool ListSimple<T>::addItemAtIndex(const T & nItem, int theIndex)
{
    if (theIndex < 0)
        return false;
    else if (theIndex > listCount)
        theIndex = listCount;
    listItem<T> * currentListItem_ptr = new listItem<T>;
    if (currentListItem_ptr)
    {
        currentListItem_ptr->nextItem = nullptr;
        currentListItem_ptr->nodeItem = nItem;
    }
    else
        return false;

    if (0 == theIndex)
    {
        currentListItem_ptr->nextItem = firstItem;
        firstItem = currentListItem_ptr;
        ++listCount;

        return true;
    }

    listItem<T> * targetItem_ptr = firstItem;
    for (int i = 1; i < theIndex; i++)
        targetItem_ptr = targetItem_ptr->nextItem;
    currentListItem_ptr->nextItem = targetItem_ptr->nextItem;
    targetItem_ptr->nextItem = currentListItem_ptr;
    
    if (lastItem == targetItem_ptr)
        lastItem = currentListItem_ptr;
    ++listCount;

    return true;
}

template <typename T>
bool ListSimple<T>::removeItem()
{
    if (isEmpty())
        return false;
    
    listItem<T> * tempListItem_ptr = firstItem->nextItem;
    delete firstItem;
    firstItem = tempListItem_ptr;
    --listCount;
    return true;
}

template <typename T>
bool ListSimple<T>::removeItem(const T & nItem)
{
    listItem<T> * tempListItem_ptr = firstItem;
    listItem<T> * preTargetListItem_ptr = tempListItem_ptr;

    if (nullptr == tempListItem_ptr)
        return false;

    while (tempListItem_ptr->nextItem != nullptr)
    {
        if (nItem == tempListItem_ptr->nodeItem)
        {
            //  First Item
            if (tempListItem_ptr == firstItem)
            {
                tempListItem_ptr = tempListItem_ptr->nextItem;
                removeItem();   // listCount-- here
                preTargetListItem_ptr = tempListItem_ptr;
            }
            else    // Middle Item
            {
                tempListItem_ptr = tempListItem_ptr->nextItem;
                delete (listItem<T> *)(preTargetListItem_ptr->nextItem);
                --listCount;
                preTargetListItem_ptr->nextItem = tempListItem_ptr;
            }
            
        }
        else
        {
            preTargetListItem_ptr = tempListItem_ptr;
            tempListItem_ptr = tempListItem_ptr->nextItem;
        }
    }
    // Last Item
    if (nItem == tempListItem_ptr->nodeItem)
    {
        preTargetListItem_ptr->nextItem = nullptr;
        delete tempListItem_ptr;
        --listCount;
        lastItem = preTargetListItem_ptr;
    }

    return true;
}

template <typename T>
bool ListSimple<T>::removeItemAtIndex(const T & nItem, int theIndex)
{

}

template <typename T>
void ListSimple<T>::emptyList()
{
    while(firstItem != nullptr)
    {
        removeItem();
    }
    lastItem = nullptr;
}

template <typename T>
void ListSimple<T>::visit(void (*pf)(T & theItem)) const
{
    listItem<T> * tempListItem_ptr = firstItem;
    std::cout << "Total: " << listCount << " Items." << std::endl;

    int i = 0;
    while (tempListItem_ptr != nullptr)
    {
        std::cout << i << ":    ";
        (* pf)(tempListItem_ptr->nodeItem);
        tempListItem_ptr = tempListItem_ptr->nextItem;
        ++i;
    }
}

/************************************************************************/
/*                          Private Method                             */
/************************************************************************/
template <typename T>
bool ListSimple<T>::_removeItem(listItem<T> * theListItem)
{
/*    if (isEmpty())
        return false;

    listItem<T> * tempListItem_ptr = nullptr;
    
    if (firstItem == theListItem)
    {
        tempListItem_ptr = firstItem;
        firstItem = firstItem->nextItem;
        delete tempListItem_ptr;
        listCount--;
        return true;
    }
    else
    {
        tempListItem_ptr
    }
    */
}

#endif/*__LISTSIMPLE_H__*/