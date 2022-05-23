#include<iostream>
using namespace std;

template<typename T>
class Static_stack{
	
		T* array;
		int top = -1; //Indice della cima
		int size = 0; //Dimensione iniziale della pila
		int maxSize = -1; //Dimensione massima raggiungibile dallo stack
	
	public:
		
		Static_stack(int maxSize) : maxSize(maxSize){
			
			array = new T[maxSize];
		}
		
		bool isEmpty(){
			
			return top == -1;
		}
		
		T get_top(){
			
			if(isEmpty())
				return -1;
			
			return array[top];
		}
		
		void push(T val){
			
			if(top == maxSize-1)
			{
				cerr << "\nFull stack. Push function not avaible" << endl;
				return;
			}
			size++;
			array[++top] = val; //Prima aggiorno l'indice e poi inserisco val
		}
		
		T pop(){
			
			if(isEmpty())
				return -1;
			size--;
			return array[top--]; //Prima restituisco e poi decremento
		}
		
		friend ostream& operator<< (ostream& os, Static_stack& s){
			
			if(s.isEmpty())
			{
				os << "Empty Stack!" << endl;
				return os;
			}
			
			os << "\nSize= " << s.size << endl;
			os << "\nMaxSize= " << s.maxSize << endl;
			os << "\nStatic_stack:" << endl;
			os << "Top->\t" << s.get_top() << endl ;

			for(int i=s.top; i>=0; i--)
				os << "\t" << s.array[i] << endl;
			
			os << endl;
			return os;
		}
};

int main(){
	
	Static_stack<int> st(5);
	
	st.push(67);
	st.push(34);
	st.push(93);
	st.push(42);
	st.push(56);
	st.push(81);
	
	cout << st << endl;
	
}