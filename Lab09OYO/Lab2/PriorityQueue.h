#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;
template<class T>
class PQNode{
    public:
        T data;
        int priority;

        PQNode(T Data)
        {
            data = Data;
            priority = 1;
        }
        PQNode(T Data, int Priority)
        {
            data = Data;
            if(Priority < 1)
                Priority = 1;
            priority = Priority;
        }
};

template<class T>
class PriorityQueue
{
    private:
        vector<PQNode<T>> queue;
    public:

        PriorityQueue() //Default constructor
        {
            
        }
        PriorityQueue(const PriorityQueue<T> &obj) //Copy contructor
        {
            queue = obj.queue;
        }
        ~PriorityQueue()
        {
            queue.clear();
        }
        friend ostream &operator<<(ostream &obj, const PriorityQueue<T> &right)
        {
            obj << right.data << " --- " << right.priority << endl;
            return obj;
        }
        PriorityQueue &operator=(const PriorityQueue<T> &obj)
        {
            queue = obj.queue;
            return *this;
        }
        void enqueue(T Data, int priority = 1)
        {
            PQNode<T> node(Data, priority);
            queue.push_back(node);
        }
        T dequeue()
        {
            T value;
            if(isEmpty())
                return value;
            else
            {
            int top = queue.at(0).priority;
            for(int i = 0; i < size(); i++)
            {
                if(queue.at(i).priority > top)
                    top = queue.at(i).priority;
            }
            PriorityQueue<T> temp;
            while(!isEmpty() && top != 0)
            {
                for(int i = 0; i < size(); i++)
                {
                    if(queue.at(i).priority == top)
                        temp.queue.push_back(queue.at(i));
                }
                top--;
            }
            queue.swap(temp.queue);
            T newData = queue.front().data;
            queue.erase(queue.begin());
            return newData;
            }
        }
        void print()
        {
            for(int i = 0; i < queue.size(); i++)
            {
                cout << queue.at(i).data << " --- " << queue.at(i).priority << endl;
            }
        }
        bool isEmpty()
        {
            if(queue.size() == 0)
                return true;
            else
                return false;
        }
        void clear()
        {
            queue.clear();
        }
        int size()
        {
            return queue.size();
        }
};




#endif