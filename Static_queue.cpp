//Implementazione di coda statica

#include<iostream>
using namespace std;

#define MAX_SIZE 1000

template<typename T>
class Static_queue{

		T*array;
		int size = 0; //Dimensione iniziale
		int maxSize = MAX_SIZE;

		//Indici di testa e coda
		int head = -1;
		int tail = -1;

	public:

		Static_queue(int maxSize = MAX_SIZE) : maxSize(maxSize){  //like a void constructor
			array = new T[maxSize];

		}

		//Static_queue() : maxSize(MAX_SIZE){}

		//Ragionare in termini di un array circolare 
		void enqueue(T val){  //Inserisci
			
			if(size == maxSize)
			{
				cerr << "\nFull queue" << endl;
				return;
			}

			if(head == -1)
				head = 0;
			
			tail = (++tail % maxSize);
			array[tail] = val;
			size++;
			return;
		}

		T dequeue(){  //Estrai

			if(size == 0)
			{
				cerr << "\nEmpty queue" << endl;
				return 0;
			}

			T tmp = array[head];
			head = (++head % maxSize);  //Prima incremento e poi faccio il modulo con la lunghezza della coda
			size--;
			return tmp;
		}

		friend ostream& operator<< (ostream& os, Static_queue<T>& sq){

			if(sq.size == 0)
			{
				os << "\nEmpty queue" << endl;
				return os;
			}

			os << "\nSize= " << sq.size << endl;
			os << "MaxSize= " << sq.maxSize << endl;

			for(int i=sq.head, count=0; count < sq.size; count++)
			{
				os << "Array[" << i << "] = " << sq.array[i] << endl;
				i = (i+1) % sq.maxSize;
			}
			
			os << endl;
			return os;
		}
};

int main(){

	Static_queue<int> sq(10);

	sq.enqueue(1);
	sq.enqueue(2);
	sq.enqueue(3);
	sq.enqueue(4);
	sq.enqueue(5);

	cout << sq ;

	sq.dequeue();
	sq.dequeue();
	sq.dequeue();

	cout << sq ;

	sq.enqueue(6);

	cout << sq ;

}