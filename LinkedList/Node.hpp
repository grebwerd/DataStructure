#ifndef __NODE__HPP
#define __NODE__HPP

template <class T> 
class Node 
{
    public:
        Node( T val ) : m_val ( val ) {}
    private:
        T m_val;
};
#endif 
