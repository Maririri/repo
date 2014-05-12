#include <iostream>
#include <exception>      // std::exception
#include <stdexcept>

namespace myStl
{
    template <typename T, size_t size>
    class MyStack
    {
    public:
        MyStack();

        void push(T &&);
        void push(const T&);

        T pop();

        int empty() {return m_queueSize == 0;}

        void setSize(size_t);

        T& operator[] (size_t n);

    private:

        T m_queue[size];
        size_t m_queueSize;
    };
}