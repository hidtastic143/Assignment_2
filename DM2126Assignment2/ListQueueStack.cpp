#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Muhammad Nurhidayat Bin Suderman
 *  \date      10 / Feb / 2016
 *  \note      150576E
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList()
{
	head = 0;
}

LinkedList::~LinkedList()
{

}

void LinkedList::push_front(int data)
{
	if (head == nullptr)
	{
		Node* newNode = new Node(data);
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		Node* newNode = new Node(data);
		Node* curr = head;
		newNode->next = curr;
		head = newNode;
	}
}

void LinkedList::push_back(int data)
{
	if (head == nullptr)
	{
		Node* newNode = new Node(data);
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		Node* newNode = new Node(data);
		Node* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		newNode->next = nullptr;
	}
}

int LinkedList::pop_front()
{
	if (head == nullptr)
		return 0;
	else
	{
		int temp = 0;
		Node* curr = head;
		head = curr->next;
		temp = curr->data;
		delete curr;
		return temp;
	}
}

int LinkedList::pop_back()
{
	if (head == nullptr)
		return 0;
	else if (head->next == nullptr)
		return pop_front();
	else
	{
		int temp = 0;
		Node* curr = head->next;
		Node* prev = head;
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}
		temp = curr->data;
		delete curr;
		prev->next = nullptr;
		return temp;
	}
}

void LinkedList::insert_at(int pos, int data)
{
	if (head == nullptr || pos <= 0)
		push_front(data);
	else if (pos >= (int)size())
		push_back(data);
	else
	{
		int temp = 1;
		Node* newNode = new Node(data);
		Node* curr = head->next;
		Node* prev = head;
		while (temp < pos)
		{
			prev = curr;
			curr = curr->next;
			temp++;
		}
		newNode->next = curr;
		prev->next = newNode;
	}
}

int LinkedList::pop_at(int pos)
{
	int temp = 0;
	if (head == nullptr || pos >= (int)size())
		return temp;
	else if (pos <= 0)
		return pop_front();
	else
	{
		temp++;
		Node* curr = head->next;
		Node* prev = head;
		while (temp < pos)
		{
			prev = curr;
			curr = curr->next;
			temp++;
		}
		temp = curr->data;
		prev->next = curr->next;
		delete curr;
		return temp;
	}
}

size_t LinkedList::size()
{
	if (head == nullptr)
		return 0;
	else
	{
		size_t size = 1;
		Node* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
			size++;
		}
		return size;
	}
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
	front = 0;
	back = 0;
}

Queue::~Queue()
{

}

void Queue::enqueue(int data)
{
	Node* newNode = new Node(data);
	if (front == 0)
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		Node* curr = front;
		Node* newNode = new Node(data);
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		back = newNode;
		newNode->next = nullptr;
	}
}

int Queue::dequeue()
{
	if (front == 0)
	{
		back = 0;
		return 0;
	}
	else if (front->next == 0)
	{
		int temp = 0;
		Node* curr = front;
		temp = curr->data;
		front = 0;
		back = 0;
		delete curr;
		return temp;
	}
	else
	{
		int temp = 0;
		Node* curr = front;
		temp = front->data;
		front = front->next;
		delete curr;
		return temp;
	}
}

size_t Queue::size()
{
	if (front == 0)
		return 0;
	else
	{
		size_t size = 1;
		Node* curr = front;
		while (curr != back)
		{
			curr = curr->next;
			size++;
		}
		return size;
	}
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
	top = 0;
}

Stack::~Stack()
{

}

void Stack::push(int data)
{
	if (top == 0)
	{
		Node* newNode = new Node(data);
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		Node* newNode = new Node(data);
		newNode->next = top;
		top = newNode;
	}
}

int Stack::pop()
{
	if (top == 0)
		return 0;
	else
	{
		int temp = 0;
		Node* curr = top;
		top = top->next;
		temp = curr->data;
		delete curr;
		return temp;
	}
}

size_t Stack::size()
{
	if (top == 0)
		return 0;
	else
	{
		size_t size = 1;
		Node* curr = top;
		while (curr->next != 0)
		{
			curr = curr->next;
			size++;
		}
		return size;
	}
}
