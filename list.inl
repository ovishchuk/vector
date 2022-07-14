/**
 * @file list.inl
 * @author Olexandr Ishchuk (o.v.ishchuk@gmail.com)
 * @brief implements list.hpp
 * @date 2022-07-14
 * 
 */

#include <iostream>
#include <cassert>

//============================================================================//
// public methods

template<class T>
List<T>::List()
{
    // new List must be empty and of zero length
    nodeArraySize = 0;
    nodeArray = nullptr;
}

template<class T>
List<T>::~List()
{
    // clean up
    eraseAll();
}

// for access by index
template<class T>
T& List<T>::operator[] (const unsigned index)
{
    assert( index >= 0 && index < nodeArraySize && nodeArray != nullptr );

    return *nodeArray[index];
}

// for access by index ( for const objects)
template<class T>
const T& List<T>::operator[] (const unsigned index) const
{
    assert( index >= 0 && index < nodeArraySize && nodeArray != nullptr );

    return *nodeArray[index];
}

template<class T>
void List<T>::insertHead(T *node)
{
    // create new array with size grater by one item and increase size variable
    T **newArray = new T*[++nodeArraySize];
    
    // write new item into beginning
    newArray[0] = node;

    // copy the old array to the rest of the new one
    for (size_t i = 1; i < nodeArraySize; i++)
    {
        newArray[i] = nodeArray[i - 1];
    }

    // delete old array if it exists
    if ( nodeArray != nullptr ) delete[] nodeArray;

    // array pointer now points to the new array
    nodeArray = newArray;
}

template<class T>
template<typename Data>
void List<T>::insertHead(Data data)
{
    // create item with value if such constructor was defined
    T *newNode = new T(data);
    
    // add item into the array beginning
    insertHead(newNode);
}

template<class T>
void List<T>::insertTail(T *node)
{
    // create new array with size grater by one item and increase size variable
    T **newArray = new T*[++nodeArraySize];

    // copy the old array to the new one
    for (size_t i = 0; i < nodeArraySize; i++)
    {
        newArray[i] = nodeArray[i];
    }

    // write new item to the end of the new array
    newArray[nodeArraySize - 1] = node;

    // delete old array if it exists
    if ( nodeArray != nullptr ) delete[] nodeArray;

    nodeArray = newArray;    
}

template<class T>
template<typename Data>
void List<T>::insertTail(Data data)
{
    // create item with value if such constructor was defined
    T *newNode = new T(data);

    // add item to the end
    insertTail(newNode);
}

template<class T>
void List<T>::eraseTail()
{
    // nothing will be done if array not exists
    if ( nodeArray != nullptr )
    {
        // if only one element exist, array will be deleted and pointer
        // to it erased
        if ( nodeArraySize == 1 )
        {
            delete nodeArray[0];
            delete[] nodeArray;
            nodeArray = nullptr;
        }
        else
        {
            // create new array with size lesser by one item and decrease size variable
            T **newArray = new T*[--nodeArraySize];

            // copy old array to the new one without last item
            for ( size_t i = 0; i < nodeArraySize; i++ )
            {
                newArray[i] = nodeArray[i];
            }

            // delete last item in old array
            delete nodeArray[nodeArraySize];
            
            // delete old array
            delete[] nodeArray;

            // array pointer points to the new array
            nodeArray = newArray;
        }
    }
}

template<class T>
void List<T>::eraseAll()
{
    // arase array from tail to head
    while ( nodeArray != nullptr )
    {
        // erase last item
        // emty array will be deleted and array pointer set to nullptr
        eraseTail();
    }
}

template<class T> unsigned
List<T>::length()
{
    // size of array
    return nodeArraySize;
}

//============================================================================//
// private methods
