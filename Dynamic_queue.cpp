#include<iostream>
#include "Double_linked_list.cpp"
using namespace std;

template<typename T>
class Queue : protected DLList<T>{

	protected:

		int size;

	public:

		Queue() : DLList<T>(){}

		bool isEmpty(){
			return (size == 0);
		}

		void enqueue(T val){  //Inserisci in coda
			DLList<T> :: insertTail(val);
			size++;
		}

		DLNode<T>* dequeue(){

			if(isEmpty())
			{
				cerr << "Empty Queue" << endl;
				return nullptr;
			}

			DLNode<T>* ptr = DLList<T>::head;
			DLList<T> :: removeHead();
			size--;
			return ptr;
		}

		friend ostream& operator<< (ostream& os, Queue<T>& q){

			os << "\nSize=" << q.size << endl;
			
			if(q.isEmpty())
			{
				os << "Empty Queue" << endl;
				return os;
			}

			DLNode<T>* ptr  = q.head;
			os << "\nQueue starting at: " << *ptr << endl;
			os << "\nQueue:" << endl;
			while(ptr)
			{
				os << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
			os << "\nEnd Queue" << endl;
			
			return os;
		}

};

int main(){

	Queue<int> coda;

	coda.enqueue(1);
	coda.enqueue(2);
	coda.enqueue(3);
	coda.enqueue(4);
	coda.enqueue(5);

	cout << coda << endl;

	coda.dequeue();

	cout << coda << endl;
}

