
//Haciendo arreglaciones

#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include "NodoA.hpp"			//aqui habia un nodo AAAAAAAAAAA
#define ERROR -1
using std::cout;
using std::endl;
using std::ostream;


template <class T>

class Lista {

	protected:				//esto era private
		int n;
		Nodo<T>* primero;
		 

	public:

		Lista();
		Lista(const Lista<T> &L1);
		virtual ~Lista();

		//Getters		
		T consultar(int pos) const;						//Funciona! //Manda una posicion y retorna un elemento
		int consultarE(T elem) const;		       		//Funciona! //Manda un elemento y retorna la posicion de donde esta
		int longitud(){	return (this->n);}				//Funciona! 
		bool esVacia() const {return (this->n==0);}		//Funciona!					

		//Setters
		void insertar(T elem, int pos);					//Funciona!
		void insertarF(T elem);							//Funciona sorpresivamente //Inserta al final 
		void eliminarP(int pos);						//Funciona!	//Elimina el elemento dado una posicion
		void eliminarE(T elem);							//Funciona! //Elimina el elemento en especifico
		void modificarE(T elem, int pos);				//Funciona! //Modifica el elemento especifico en una posicion especifica
		void vaciar();									//Funciona! 
	
		
		//Metodos
			
		void invertir();								//Funciona!

		//void invertir(int, int);
		bool esta(T);									//Funciona!
		Lista<T> subLista(int inicio, int fin);			//Funciona! devuelve una lista incluyendo el rango, ejem: 12345 - inicio(2), fin(5) - retorna 2345
		void burbuja(bool);								//Funciona! //Ordena de forma ascendente (true) y descendente (false)
		//void mezclarOrdenado(Lista<T> l1, Lista<T> l2);
		Lista<int> aparicion(T);					    //Funciona!//Devuelve una lista con la posicion de todas las apariciones del elemento T
		T mayor();										//Funciona!
		T menor();										//Funciona!
		void concatenar(Lista<T> L1);					//Funcionaaaaaaaaaaaaa

		void copiar(const Lista<T> &L1);				//Funciona!

		//Imprimir
		void imprimir() const;							//Funciona!			

};

template <class T>
Lista<T>::Lista() {
	this->primero = NULL;
	this->n = 0;
}

template <class T>
Lista<T>::Lista (const Lista<T> &L1) {
	
	this->copiar(L1);
}

template <class T>
Lista<T>::~Lista() {
	this->vaciar();
}

//--------------------------------------------------------------------------------------

//Getters

template <class T>
T Lista<T>::consultar(int pos) const{

	Nodo<T> *aux;
	aux = this->primero;
	int i;

	if( pos > 0 && pos < (this->n) + 1){

		if(pos == 1){

			return aux->obtElem();

		}else{

			for(i=2; i < pos+1; i++){

				aux = aux->obtProx();
			}

			return aux->obtElem();

		}
	}

	//cout << "\nError en consultar la posicion.\n" << endl;

	return ERROR;

}

template <class T>
int Lista<T>::consultarE(T elem) const{

	Nodo<T> *aux;
	aux = new Nodo<T>;
	aux = this->primero;
	int pos = 1;
	
	while (aux != NULL) {
				
		if (aux->obtElem() == elem) {
			return pos;
		}

		pos++;
		aux = aux->obtProx();
	}
}

//------------------------------------------------------------------------------------------------------
//Setters

template <class T>
void Lista<T>::insertar(T elem, int pos) {
	
	int i;
	Nodo<T> *act = this->primero, *sig, *nuevo;
	nuevo = new Nodo<T>;
	nuevo->modElem(elem);
	
	if(pos == 1) {
		
		nuevo->modProx(this->primero);
		this->primero = nuevo;
		this->n++;

	}else{

		if(pos > 1 && pos <= (this->n)+1) {
			
			for(i = 1; i < pos - 1 ; i++) {
				
				act = act->obtProx();
			}
			
			sig = act->obtProx();
			act->modProx(nuevo);
			nuevo->modProx(sig);
			this->n++;
		}
		else{
			cout << "\nError en insertar en la posicion\n" << endl;
		}
	}

}

template <class T>
void Lista<T>::eliminarP(int pos){
	
	Nodo<T> *act = this->primero, *aux;
	int i;
	
	if (pos == 1) {

		aux = act;
		this->primero = aux->obtProx();
		delete aux;
		this->n--;

	}

	else if(pos> 0 && pos <= this->n) {

		for(i = 1; i < pos - 1; i++) {
			act = act->obtProx();
		}

		aux = act->obtProx();
		act->modProx(aux->obtProx());
		delete aux;
		this->n--;

	}
	else{

		cout << "\nError en elminar la posicion" <<endl;

	}
}

template <class T>
void Lista<T>::eliminarE(T elem){

	Nodo<T> *act = this->primero, *aux;
	int i;
	
	if (this->consultar(1) == elem) {

		this->primero = act->obtProx();
		delete act;
		this->n--;

	}else {

		for (aux = act->obtProx(); aux != NULL; aux = aux->obtProx()) {
		
			if (aux->obtElem() == elem) {
				act->modProx(aux->obtProx());
				delete aux;
				this->n--;
			}

			act = aux;
		}
	}

}

template <class T>
void Lista<T>::modificarE(T elem, int pos){

	Nodo<T> *act;
	act = this->primero;

	int i;

	for(i=1; i<pos ;i++) {

		act = act->obtProx();

	}
		act->modElem(elem);
}


template <class T>
void Lista<T>::vaciar() {
	
	Nodo<T> *act;
	
	while(this->n > 0) 
	{
		act = this->primero;
		this->primero = act->obtProx();
		delete act;
		this->n--;
	}
}


//------------------------------------------------------------------------------------------------------------
//Metodos

template <class T>
void Lista<T>::invertir(){

	Nodo<T> *act = this->primero;
	Nodo<T> *prev = NULL;
	Nodo<T> *next;

	while(act != NULL){

		next = act->obtProx();
		act->modProx(prev);
		prev = act;
		act = next;

	}

	this->primero = prev;
	
}

template <class T>
void Lista<T>::copiar(const Lista<T> &L1) {
	
	Nodo<T> *act, *nuevo, *aux;
	
	if (!L1.esVacia()) {
		
		aux = L1.primero;
		nuevo = new Nodo<T>;
		nuevo->modElem(aux->obtElem());
		act = nuevo;
		this->primero = act;
		
		for (aux = aux->obtProx(); aux; aux = aux->obtProx()) {
			nuevo = new Nodo<T>;
			nuevo->modElem(aux->obtElem());
			act->modProx(nuevo);
			act = act->obtProx();
		}
		
		this->n = L1.n;
		
	}
	
}

template <class T>
void Lista<T>::burbuja(bool ascendente){

	Nodo<T> *ant, *sig;
	ant = new Nodo<T>;
	sig = new Nodo<T>;
	T aux;
	ant = this->primero;

	if(ascendente){

		while (ant != NULL) {
			
			sig = ant->obtProx();
			while (sig != NULL) {
				
				if (ant->obtElem() > sig->obtElem()) {
					aux = ant->obtElem();
					ant->modElem(sig->obtElem());
					sig->modElem(aux);
				}
				sig = sig->obtProx();
				
			}
			ant = ant->obtProx();
			
		}
	}else{

		while (ant != NULL) {
				
				sig = ant->obtProx();
				while (sig != NULL) {
					
					if (ant->obtElem() < sig->obtElem()) {
						aux = ant->obtElem();
						ant->modElem(sig->obtElem());
						sig->modElem(aux);
					}
					sig = sig->obtProx();
					
				}
				ant = ant->obtProx();
				
			}

	}

}	

template <class T>
bool Lista<T>::esta(T elem){

	Nodo<T>* aux;
	bool band;

	aux = this->primero;
	band = false;

	while( aux != NULL && !band){

		if(aux->obtElem() == elem){
			return(true);
		}

		aux = aux->obtProx();
	}
}

template <class T>
T Lista<T>::mayor(){

	Nodo<T>* aux;
	int i=1;
	T max;

	aux = this->primero;
	max = aux->obtElem();

	for(i=1; i < this->n; i++){

		if(aux->obtElem() > max){

			max = aux->obtElem();
		}
		aux = aux->obtProx();

	}
	
	return (max);
}

template <class T>
T Lista<T>::menor(){

	Nodo<T>* aux;
	T min;

	aux = this->primero;
	min = aux->obtElem();

	for(int i=1; i < this->n; i++){

		if(aux->obtElem() < min){

			min = aux->obtElem();

		}

		aux = aux->obtProx();

	}	
		return (min);
	
}


template <class T>				
Lista<int> Lista<T>::aparicion(T e){

	Nodo<T> *act = this->primero;
	Lista<T> L;
	int pos = 1;

	for(int i=1; i <= this->n; i++) {

		if(act->obtElem() == e){

			L.insertar(pos, 1);
		}
		pos++;
		act = act->obtProx();
	}

	L.invertir();

return(L);
}

/*
template <class T>		
void Lista<T>::mezclarOrdenado(){



	Lista<T> L3;
	L1.burbuja(true);
	L2.burbuja(true);
	
	T aux1, aux2;


	while(!this->esVacia() && !L2.esVacia()){


		aux1 = this->consultar(1);
		aux2 = L2.consultar(1);

		if(aux1 < aux2){

			L3.insertar(aux1, 1);
			this->eliminarP(1);

			}else if( aux1 > aux2){

				L3.insertar(aux2, 1);
				this->eliminarP(1);

					}else{

						L3.insertar(aux1, 1);
						this->eliminarP(1);
						L2.eliminarP(1);

					}
	}

	//Comprobar si sobra

	if(!this->esVacia()){

		for (int i = 1; i < this->longitud(); i++)
		{
			aux1 = this->consultar(1);
			L3.insertar(aux1, 1);
			this->eliminarP(1);
		}

	}

	if(!L2.esVacia()){

		for (int i = 1; i < L2.longitud(); i++)
		{
			aux1 = L2.consultar(1);
			L3.insertar(aux1, 1);
			L2.eliminarP(1);
		}

	}

	
	L2.~Lista();
	
	return ();

}
*/

template<class T>
Lista<T> Lista<T>::subLista(int inicio, int fin){

	Lista<T> result;
	Nodo<T> *p1, *p2, *nuevo;
	

	if(inicio >= 0 && inicio <= fin && fin < this->n) //Asumiendo que las posiciones son correctas
	{
		p1 = this->primero;

		for(int i=1; i < inicio ; i++) 
		{
			p1 = p1->obtProx();
		}

		nuevo = new Nodo<T>;					
		result.primero = nuevo;					
		p2 = nuevo;										
		nuevo->modElem(p1->obtElem());	

		p1 = p1->obtProx();

		result.n = 1; 


		for(int i = inicio; i < fin ; i++) 
		{
			nuevo = new Nodo<T>;
			nuevo->modElem(p1->obtElem());
			p2->modProx(nuevo);
			p2 = nuevo;
			p1 = p1->obtProx();

			result.n++; 
		}

		p2->modProx(NULL); 

	}
	
	return result;

}

template <class T>
void Lista<T>::insertarF(T elem){

	Nodo<T> *nuevo = new Nodo<T>;
	nuevo -> modElem(elem);

	if(this->n == 0){

		this->primero = nuevo;

	}else{

		Nodo<T> *auxTemp = this ->primero;

		while(auxTemp->obtProx() != NULL){

			auxTemp = auxTemp -> obtProx();
		}

		auxTemp -> modProx(nuevo);

	}

	this -> n++;

}

template <class T>
void Lista<T>::concatenar(Lista<T> L1){


	int l1 = 0;
	l1 = L1.longitud();


	while( l1 != 0){
	
		this->insertarF(L1.consultar(1));
		L1.eliminarP(1);
		l1--;

	}


}

//-----------------------------------------------------------------------------------------------------
//Imprimir


template <class T>
void Lista<T>::imprimir () const {
	
	
	Nodo<T> *act = this->primero;
	
	for(int i=1; i <= this->n; i++) {
		
		cout << act->obtElem()<< " -> ";
		act = act->obtProx();
	}

	cout<<" NULL ";
	cout<<"\n";
}


#endif
