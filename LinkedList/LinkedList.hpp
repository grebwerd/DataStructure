#ifndef __LINKEDLIST__HPP__
#define __LINKEDLIST__HPP__

#include "Node.hpp"
template <class T>
class LinkedList 
{
    public:
        LinkedList() : head ( NULL ){}

        void insert( T val )
        {
            Node<T>* tempNode;
            if( NULL == head )
            {
                head = new Node<T>();
                head->nextNode = new Node<T>( val );
                return;
            }
            tempNode = new Node<T>();
            tempNode->nextNode = head->nextNode;
            while( true )
            {
                if( !tempNode->nextNode->nextNode )
                {
                    tempNode->nextNode->nextNode
                    = new Node<T>( val );
                    return;
                }
                tempNode->nextNode = tempNode->nextNode->nextNode;
            }
        }

        void display() 
        {
            Node<T>* tempNode;
            if( NULL == head )
            {
                std::cout<<"head ptr is null"<<std::endl;
                return;
            }
            tempNode = new Node<T>();
            tempNode->nextNode = head->nextNode;
            std::cout<<"LinkedList: ";
            while( tempNode->nextNode )
            {
                std::cout<<tempNode->nextNode->getVal()<<" ";
                tempNode->nextNode = tempNode->nextNode->nextNode;
            }
            std::cout<<std::endl;
        }

    private:
        Node<T>* head;
};


#endif
