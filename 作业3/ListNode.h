#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode 
{
public:
    T data;
    ListNode* next;

    ListNode()
    {
        this->data=0;
        next=0;
    }

    ListNode(T data)
    {
        this->data =data;
        next=0;
    }
    
};



#endif // DEBUG