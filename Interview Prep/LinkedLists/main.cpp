#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	int size;
public:
	LinkedList()
	{
		head=NULL;
		size=0;
	}
	friend ostream& operator <<(ostream& out,const LinkedList &other)
	{
		Node<T> *p = other.head;
		if (other.head == NULL) out<<endl<<"Empty";
		while(p != NULL)
		{
			out<<p->data<<' ';
			p = p->next;
		}
		return out;
	}
	Node<T>* getHead() { return head; };
	int getCount(){ return size; }
	bool isEmpty() { return size == 0; }
	void createN(T value)
	{
		Node<T> *t;
		t = new Node<T>;
		t->data = value;
		t->next = head;
		head = t;
		size++;
	}
	void deleteN(T value)
	{
		Node<T> *p=head,*q=NULL;
		if(isEmpty())
		{
			cout<<"Can't delete from an empty list!"<<endl;
			return;
		}
		if(head->data == value)
		{
			head = head->next;
			delete p;
		}
		else
		{
			while(p->data != value)
			{
				q = p;
				p=p->next;
			}
			q->next = p->next;
			delete p;
		}
		size--;
	}
	void deleteDupl()
	{
		Node<T>* curr = head;
		Node<T> *q,*p;
		while(curr != NULL)
		{
			q=NULL;
			p=curr;
			while(p != NULL)
			{
				q=p;
				p=p->next;
				if(p == NULL)
					break;
				if(p->data == curr->data)
				{
					q->next = p->next;
					delete p;
					p = q;
				}
			}
			curr=curr->next;
		}
	}
	T getKToLast(int k)
	{	
		int pos = size - k;
		Node<T> *t = head;
		
		if(k == 0)
		{
			while(t->next != NULL)
				t = t->next;
		}
		else
		{
			for(int i=0;i<pos;i++)
				t = t->next;
		}	
		return t->data;	
	}
	void partition(int x)
	{
		Node<T> *end=head;
		while(end->next != NULL)
			end = end->next;
		
		Node<T> *q=NULL,*p=head;
		
		while(p != end)
		{
			q=p;
			p=p->next;
			if(p->data >= x)
			{
				q->next = p->next;
				p->next = end->next;
				end->next = p;
				p = q;
			}
		}
		
	}
	void deleteAll()
	{
		Node<T> *p;
		while(head != NULL)
		{
			p = head;
			head = head->next;
			delete p;
			size--;
		}
	}
	~LinkedList(){ deleteAll(); }
};



int main()
{
	LinkedList<int> ll;
	
	//Partition the linked list
	/*
	ll.createN(1);
	ll.createN(2);
	ll.createN(10);
	ll.createN(5);
	ll.createN(8);
	ll.createN(5);
	ll.createN(3);
	cout<<ll<<endl;
	ll.partition(5);
	cout<<ll;*/
	
	//Get kth element
	/*LinkedList<int> ll;
	ll.createN(11);
	ll.createN(9);
	ll.createN(7);
	ll.createN(5);
	ll.createN(3);
	cout<<ll;
	cout<<ll.getKToLast(5);*/
	
	//Delete Duplicates
	/*ll.createN(6);
	ll.createN(8);
	ll.createN(5);
	ll.createN(5);
	ll.createN(6);
	ll.createN(6);
	ll.createN(6);
	ll.createN(6);
	ll.createN(6);
	ll.createN(6);
	ll.createN(11);
	cout<<ll<<endl;
	ll.deleteDupl();
	cout<<ll;*/
	
	//Testing out create and delete
	/*LinkedList<int> ll;
	cout<<"Initially, the size is "<<ll.getCount()<<endl;
	ll.deleteN(5);
	ll.createN(11);
	ll.createN(8);
	ll.createN(5);
	cout<<ll;
	cout<<endl<<"After adding these elements, the size is "<<ll.getCount();
	cout<<endl;
	ll.deleteN(8);
	cout<<ll;
	cout<<endl<<"After deletion, the size is "<<ll.getCount();
	ll.deleteAll();
	cout<<endl<<"After deleting everything, the size is "<<ll.getCount();
	cout<<ll;*/
	return 0;
}
