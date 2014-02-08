#ifndef __LINKEDLIST__HPP__
#define __LINKEDLIST__HPP__

#include "Node.hpp"
template <class T>
class LinkedList 
{
    public:
        LinkedList() : headNode ( NULL ){}

        void append( T val )
        {
            Node<T>* tempNode;
            if( NULL == headNode )
            {
                headNode = new Node<T>();
                headNode->nextNode = new Node<T>( val );
                return;
            }
            tempNode = new Node<T>();
            tempNode->nextNode = headNode->nextNode;
            while( true )
            {
                if( !tempNode->nextNode->nextNode )
                {
                    tempNode->nextNode->nextNode = new Node<T>( val );
                    return;
                }
                tempNode->nextNode = tempNode->nextNode->nextNode;
            }
        }

        void deleteNode( T val )
        {
            if( NULL == headNode || NULL == headNode->nextNode )
            {
                std::cout << "LinkedList is empty " << std::endl;
                return;
            }

            Node<T>* tempNode = new Node<T>();
            tempNode->nextNode = headNode->nextNode;

            while( tempNode->nextNode )
            {
                if( tempNode->nextNode->getVal() == val )
                {
                    if( NULL == tempNode->nextNode->nextNode )
                    {
                        tempNode->nextNode = NULL;
                        return;
                    }
                    if( headNode->nextNode->getVal() == val )
                    {
                        Node<T>* x = headNode->nextNode->nextNode;
                        delete headNode->nextNode;
                        headNode->nextNode = x;
                        return;
                    }
                    else
                    {
                        Node<T>* x = tempNode->nextNode->nextNode;
                        delete tempNode->nextNode;
                        tempNode->nextNode = x;
                        return;
                    }
                }
                tempNode = tempNode->nextNode;
            }
            std::cout << "The value " << val << " is not in the LinkedList " << std::endl;
        }

        void prepend( T val )
        {
            Node<T>* tempNode;
            if( NULL == headNode )
            {
                headNode = new Node<T>();
                headNode->nextNode = new Node<T>( val );
            }
            else 
            {
                Node<T>* newNode = new Node<T>( val );
                newNode->nextNode = headNode->nextNode;
                headNode->nextNode = newNode;
            }
        }

        void display() 
        {
            Node<T>* tempNode;
            if( NULL == headNode )
            {
                std::cout << "headNode ptr is null " << std::endl;
                return;
            }
            tempNode = new Node<T>();
            tempNode->nextNode = headNode->nextNode;
            std::cout << "LinkedList: ";
            while( tempNode->nextNode )
            {
                std::cout<<tempNode->nextNode->getVal()<<" ";
                tempNode->nextNode = tempNode->nextNode->nextNode;
            }
            std::cout<<std::endl;
        }

    private:
        Node<T>* headNode;
};


#endif
