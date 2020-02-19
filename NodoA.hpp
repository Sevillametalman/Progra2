#ifndef NODO_H_
#define NODO_H_
#include<iostream>
#include<stdlib.h>

template <class T>

class Nodo{
	//atributos
	private:
		T info;
		Nodo<T> *prox, *ant;

	//metodos
	public:
		//Creadores y destructores
		Nodo();	
		Nodo(Nodo &copia);	
		Nodo(T elem);	
		Nodo(T elem, Nodo *p);	
		virtual ~Nodo();				
		
		//Getters y setters
		Nodo *obtProx();
		void modProx(Nodo *p);
		Nodo *obtAnt();
		void modAnt(Nodo *p);
		T obtElem();
		void modElem(T elem);

		//Metodo
		/*void outOfRange(){
			if(this == NULL){
				cout<<"System out of range, NULL reached."<<endl;
				exit(1);
			}
		}*/

				
	
};

template <class T>
Nodo<T>::Nodo(){

}

template <class T>
Nodo<T>::Nodo(Nodo &copia){

	this->prox = copia.obtProx();
	this->info =copia.obtElem();
}

template <class T>
Nodo<T>::Nodo(T elem){

	this->info = elem;
	this->prox = NULL;
}

template <class T>
Nodo<T>::Nodo(T elem, Nodo* p){

	this->info = elem;
	this->prox = p;
}

template <class T>
Nodo<T>::~Nodo(){
}


template <class T>
Nodo<T> *Nodo<T>::obtProx(){

	return this->prox;
}

template <class T>
void Nodo<T>::modProx(Nodo* p){

	this->prox = p;
}

template <class T>
Nodo<T> *Nodo<T>::obtAnt(){

	return this->ant;
}

template <class T>
void Nodo<T>::modAnt(Nodo* p){

	this->ant = p;
}

template <class T>
T Nodo<T>::obtElem(){

	return this->info;
}

template <class T>
void Nodo<T>::modElem(T elem){

	this->info = elem;
}

#endif

