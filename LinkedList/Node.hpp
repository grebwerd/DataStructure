#ifndef __NODE__HPP
#define __NODE__HPP

template <typename T>
class Node 
{
    public:
        Node();
        Node( T val );
        ~Node();
        
        void add();
        void remove();
        void insert();

    private:
        Node* nextNode;
        T m_val;
};
#endif
