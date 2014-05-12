#include "MyStack.h"

namespace myStl
{
    template<typename T, size_t size>
    MyStack<T, size>::MyStack()
            : m_queueSize(0)
    { }

    template<typename T, size_t size>
    void MyStack<T, size>::push(const T& elem)
    {
        if(m_queueSize != size)
        {
            m_queue[m_queueSize] = elem;
            ++m_queueSize;
        }
        else
        {
            throw std::range_error("Unable to push element, size exceeded");
        }
    }

    template<typename T, size_t size>
    void MyStack<T, size>::push(T &&elem)
    {
        if(m_queueSize != size)
        {
            m_queue[m_queueSize] = std::move(elem);
            ++m_queueSize;
        }
        else
        {
            throw std::range_error("Unable to push element, size exceeded");
        }
    }

    template<typename T, size_t size>
    T MyStack<T, size>::pop()
    {
        if(m_queueSize >= 1)
        {
            --m_queueSize;
            return m_queue[m_queueSize];
        }
        else
        {
            throw std::range_error("Unable to pop element, empty stack");
        }
    }

    template<typename T, size_t size>
    T& MyStack<T, size>::operator[] (size_t n)
    {
        if(n < size)
            return m_queue[n];
        else
            throw std::out_of_range("Index is out of range");
    }


    template<typename T, size_t size>
    void MyStack<T, size>::setSize(size_t s)
    {
        m_queueSize = s;
    }

//template<typename T, size_t size>
//std::ostream& operator<< ( std::ostream& os, const T& a)
//{
//	for (int i=0; i<size; i++) {os<<a.m_queue[i]<<' ';}
//	return os;
//}
}