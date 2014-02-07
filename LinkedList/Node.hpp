#ifndef __NODE__HPP
#define __NODE__HPP

template <class T> 
class Node 
{
    public:
        Node(): nextNode( NULL ) {}
        Node( T val ) : m_val ( val ), nextNode( NULL ) {}
        const T getVal() 
        {
            return m_val;
        }

        Node<T>* nextNode;
    private:
        T m_val;

};
#endif 
