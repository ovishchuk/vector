/**
 * @file Vector.hpp
 * @author Oleksandr Ishchuk (o.v.ishchuk@gmail.com)
 * @date 2022-07-14
 * @brief std::vector like container
 * @details my own attempt to implement vector container. It is a template
 * class. Data are stored in private dinamic array and member methods do several
 * actions around it (like appening or deletion of items).
 * @todo erase special item by index;
 * insert item before or after index;
 */

#ifndef OVI_VECTOR_HPP
#define OVI_VECTOR_HPP

namespace ovi
{

template<class T>
class Vector
{
public:
    Vector<T>();
    ~Vector<T>();
    T& operator[] (const unsigned index);
    const T& operator[] (const unsigned index) const;
    
    // insert item at the beginning
    void insertHead(T *node);
    template<typename Data> 
    void insertHead(Data data);
    
    // insert item at the end
    void insertTail(T *node);
    template<typename Data> 
    void insertTail(Data data);

    // erase last item
    void eraseTail();
    // clear all items from tail to head
    void eraseAll();

    // returns the size of array
    unsigned length();

private:
    // pointer to items array
    T **nodeArray;
    // the size of array
    unsigned nodeArraySize;
};

} // namespace ovi

#include "vector.inl"

#endif // OVI_VECTOR_HPP