#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdio.h>

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

Node* LinkedList::get(int index)
{
    Node* node2Return = this->head;
    for(int i = 0; i < index; i++)
    {
        node2Return = node2Return->getNextNode();
    }
    return node2Return;
}

void LinkedList::swap(int index1, int index2)
{
    int smaller = index1;
    int larger = index2;
    if(this->get(larger)->getPayload()->getDefense() < this->get(smaller)->getPayload()->getDefense())
    {
        smaller = index2;
        larger = index1;
    }
    Node* smallerNode = this->get(smaller);
    Node* largerNode = this->get(larger);
    printf("smaller: %d, larger: %d\n", smaller, larger);
    smallerNode->setNextNode(largerNode->getNextNode());
    largerNode->setPrevNode(smallerNode->getPrevNode());
    largerNode->setNextNode(smallerNode);
    smallerNode->getNextNode()->setPrevNode(smallerNode);
    smallerNode->setPrevNode(largerNode);
    if(smaller == 0)
    {
        this->head = largerNode;
    }

    if(larger == this->count-1)
    {
        this->tail = smallerNode;
    }
}

void LinkedList::insertionSortOnDefense()
{
    int theFollower;
    int current;
    for(int currStart = 1; currStart < this->count; currStart++)
    {
        current=currStart;
        theFollower = this->count;
        while(theFollower > 0 && this->get(theFollower)->getPayload()->getDefense() <
                this->get(current)->getPayload()->getDefense())
        {
            //I need to swap
            this->swap(theFollower, current);
            theFollower--;
        }
    }
}

void LinkedList::addEnd(Card* c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }
}