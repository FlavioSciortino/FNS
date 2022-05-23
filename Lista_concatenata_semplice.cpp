#include<iostream>

using namespace std;

struct nodo{
	
	int info;
	nodo* next; //puntatore a nodo
	
};

nodo* il = nullptr;  //inizio lista punta a NULL perchè inizialmente non vi sono elementi nella lista

void in_testa (nodo* &il, nodo* nuovo){
	nuovo->next = il;
	il = nuovo;
}

void in_coda (nodo* &il, nodo* nuovo){
	
	nodo* ultimo = nullptr;
	
	if(il == nullptr) //se la lista è vuota
		in_testa(il, nuovo);
	else
	{
		//cerco l'ultimo nodo
		ultimo = il;
		
		while(ultimo->next != nullptr)
			ultimo = ultimo->next;
		
		//Lo aggancio all'ultimo nodo
		ultimo->next = nuovo;
	}
	
}

void stampa_lista (nodo* il){
	
	//Non necessito di un nuovo puntatore a nodo perchè non essendo un passaggio
	//by reference non si corre il rischio di modificare la locazione di memoria
	//puntata da il
	
	if(il == nullptr)
		
		cout<<"\nLista vuota!"<<endl;
	
	else
		cout << "\nLista : " << endl;
	
		while(il != nullptr)
		{
			cout << il->info << " ";
			il = il->next;
		}
	
	cout << endl;
	
}

void distruggi_lista (nodo* &il){
	
	nodo* tmp = il;
	
	while(il != nullptr)
	{
		tmp = il->next;
		delete il;
		il = tmp;
	}
	
}

int main(){
	
	nodo* nuovo = nullptr;
	nuovo = new nodo; //aggancio al puntatore una nuova struct
	
	nuovo->info = 1000;
	nuovo->next = il; //faccio puntare il nuovo nodo all'inizio della vecchia lista
	
	//Adesso posso spostare il facendolo puntare al nuovo primo nodo
	il = nuovo;
	cout<< "Test: " << il->info << " - " << nuovo->info << endl;
	
	//Inserimento in testa senza funzione
	
	/*for(int i=0; i<10; i++)
	{
		nuovo = new nodo;
		nuovo->info = i;
		
		nuovo->next = il; 
		il = nuovo;
	}*/
	
	for(int i=0; i<10; i++)
	{
		nuovo = new nodo;
		nuovo->info = i;
		in_testa(il, nuovo);
	}
	
	//Stampa della lista senza funzione
	
	/*
	nodo* tmp = il;
	
	cout << "Lista :\n " << endl;
	while(tmp != nullptr)
	{
		cout << tmp -> info <<" ";  //Stampo la parte informativa
		tmp = tmp -> next;  //punto alla struct successiva
	}
	*/
	
	stampa_lista(il);
	
	distruggi_lista(il);
	
	stampa_lista(il);
	
	//Inserimento in coda senza funzione
	
	/*
	nodo* ultimo = nullptr;
	
	for(int i=0; i<10; i++)
	{
		nuovo = new nodo;
		nuovo->info = i;
		nuovo->next = nullptr;
		
		//Caso di lista vuota
		if(il == nullptr)
		{
			//nuovo->next = nullptr;
			//il = nuovo;
			
			in_testa(il, nuovo);
			
		}else{
			
			//Cerco l'ultimo nodo
			
			ultimo = il;
			
			while(ultimo->next != nullptr)
				ultimo = ultimo->next;
			
			//Lo aggancio all'ultimo nodo
			ultimo->next = nuovo;
			
		}
		
	}*/
	
	for(int i=0; i<10; i++)
	{
		nuovo = new nodo;
		nuovo -> info = i;
		nuovo -> next = nullptr;
		
		in_coda(il, nuovo);
	}
	
	stampa_lista(il);
}