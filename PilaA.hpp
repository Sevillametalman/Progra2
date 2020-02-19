#ifndef PILA_H_
#define PILA_H_
#include <iostream>

using namespace std;
#include "NodoA.hpp"

template <class T>
class Pila{

	private: 

		Nodo<T> *top;
		int n;

	public: 


		Pila ();
		Pila (const Pila<T> &p1);
		~Pila ();
		void vaciar ();

		//Getters
		bool esVacia() const {return (this->n == 0);}
		int longitud() const {return (this-> n);}
		T tope() const;

		//Setters
		void apilar(T elem);
		void desapilar();
	
		//Metodos

		void invertir();
		T mayor() const;								//Funciona
		T menor() const;								//Funciona

		T eliminarMayor();
		T eliminarMayorP(T n);
		T eliminarMenor();
		T eliminarMenorP(T n);
		void ordenarP(bool band);						//Ordena sin elementos repetidos	
		void panquecas();								//Modo prueba
		bool postfija();								//Funciona
		void apilarDos(Pila<T> &p1);					//Funciona
		void voltear(int pos);							//Funciona


		void imprimir() const;
};


template <class T>
Pila<T>::Pila(){
	
	this->top = NULL;
	this->n = 0;
}

template <class T>
Pila<T>::Pila(const Pila<T> &p1){

	Pila<T> paux;
	Nodo<T> *naux, *nuevo;
	this->top = NULL;
	naux = p1.top;

	while(naux != NULL)
	{
		paux.apilar(naux->obtElem());
		naux = naux->obtAnt();
	}

	naux = paux.top;
	
	while(naux != NULL)
	{
		nuevo = new Nodo<T>;
		nuevo->modElem(naux->obtElem());
		nuevo->modAnt(this->top);
		this->top = nuevo;
		naux = naux->obtAnt();
	}
	this->tam = p1.longitud();
	paux.vaciar();
}

template <class T>
Pila<T>::~Pila(){	
	this->vaciar();
}

template <class T>
void Pila<T>::vaciar(){
	
	while (!this->esVacia()) {
		this->desapilar();
	}
	this->top = NULL;
	this->n = 0;
}

template <class T>
T Pila<T>::tope () const {	
	return (this->top->obtElem());
}


template <class T>
void Pila<T>::apilar (T elem) {
	
	Nodo<T> *nuevo;
	nuevo = new Nodo<T>;
	nuevo->modElem(elem);
	
	nuevo->modAnt(this->top);
	this->top = nuevo;
	this->n++;
	
}

template <class T>
void Pila<T>::desapilar() {
	
	Nodo<T> *aux;
	
	if(!this->esVacia())
	{
		aux = this->top;
		if(this->n != 1)
		{
			this->top = aux->obtAnt();
		}
		else
		{
			this->top = NULL;
		}
		delete aux;
		this->n--;
	}

}

//-------------------------------------------------------
//Metodos

template <class T>
void Pila<T>::invertir(){

	Pila<T> *invertida;
	invertida = new Pila<T>();
	Nodo<T> *aux;
	aux = this->top;
	
	while(aux->obtAnt() != NULL){

		invertida->apilar(aux->obtElem());
		aux = aux->obtAnt();

	}

	invertida->apilar(aux->obtElem());
	this->vaciar();
	*this = *invertida;

}

template<class T>
T Pila<T>::mayor() const {

	Nodo<T> *aux = this->top;
	T mayor = aux->obtElem();
	
	while(aux!=NULL){

		if(aux->obtElem() > mayor){

			 mayor = aux->obtElem();

		}

		aux = aux->obtAnt();

	}

	return mayor;
	
}

template<class T>
T Pila<T>::menor() const {

	Nodo<T> *aux = this->top;
	T menor = aux->obtElem();
	
	while(aux!=NULL){

		if(aux->obtElem() < menor){

			 menor = aux->obtElem();

		}

		aux = aux->obtAnt();

	}

	return menor;
	
}

template <class T>
T Pila<T>::eliminarMayor()
{
  T aux;

  if(this->n > 0)
  {
    aux = this->tope();
    return this->eliminarMayorP(aux);
  }

}

template <class T>
T Pila<T>::eliminarMayorP(T n)
{
  T aux;

  if(this->esVacia())
  {
    return n;
  }
  else
  {
    aux = this->tope();
    this->desapilar();
    if(aux > n)
    {
      n = aux;
    }
    n = this->eliminarMayorP(n);
    if(aux != n)
    {
      this->apilar(aux);
    }

    return n;
  }
}

template <class T>
T Pila<T>::eliminarMenor()
{

 T aux;
  if(this->n > 0)
  {
    aux = this->tope();
    return this->eliminarMenorP(aux);
  }
}

template <class T>
T Pila<T>::eliminarMenorP(T n)
{
   T aux;

  if(this->esVacia())
  {
    return n;
  }
  else
  {
    aux = this->tope();
    this->desapilar();
    if(aux < n)
    {
      n = aux;
    }
    n = this->eliminarMenorP(n);

    if(aux != n)
    {
      this->apilar(aux);
    }

    return n;
  }
}


template <class T>
void Pila<T>::ordenarP(bool band){

  T aux;

  if(band){

	  if(!this->esVacia()) {

	    aux = this->eliminarMenor();
	    this->ordenarP(band);
	    this->apilar(aux);
	  }  	

  }else{

	if(!this->esVacia()) {

	    aux = this->eliminarMayor();
	    this->ordenarP(band);
	    this->apilar(aux);
 	 }

  }

}


template <class T>
bool  Pila<T>::postfija(){		//Recursivo queda mas bonito

	Pila<char> pAux;

	while(this->esVacia()){

		if(this->tope() == ')' || this->tope() == '}' ||this->tope() == ']' ){



			pAux.apilar(this->tope());

		}else if(this->tope() == '(' && pAux.tope() == ')'){

			this->desapilar();
			pAux.desapilar();

				}else if(this->tope() == '{' && pAux.tope() == '}'){

						
					this->desapilar();
					pAux.desapilar();
						
						
					} else if(this->tope() == '[' && pAux.tope() == ']'){
				
						this->desapilar();
						pAux.desapilar();	
					}						
	}
		
		this->desapilar();
	

	return (pAux.esVacia());
}

template <class T>				//Funciona pero muere
void Pila<T>::apilarDos(Pila<T> &p1){

	T aux;

	while(!p1.esVacia()){

		aux = p1.tope();
		p1.desapilar();

		this->apilar(aux);

	}
	
	p1.~Pila();
}

template <class T>	
void Pila<T>::voltear(int pos){

	Pila<T> paux;

	for(int i = 1; i <= pos; i++){

		paux.apilar(this->tope());
		this->desapilar();		
	}

	paux.invertir();

	for(int i = 1; i <= pos; i++){

		this->apilar(paux.tope());
		paux.desapilar();		
	}

}

template <class T>
void Pila<T>::panquecas(){
	int iter = this->tam;
	Nodo<T> *aux, *mayor;
	Pila<T> paux;

	while(iter > 0)
	{
		aux = this->top;
		mayor = aux;
		for(int i=1;i<=iter;i++)
		{
			if(aux->obtElem() > mayor->obtElem()) mayor = aux;
			aux = aux->obtAnt();
		}
		while(this->top != mayor)
		{
			paux.apilar(this->top->obtElem());
			this->desapilar();
		}
		paux.apilar(this->top->obtElem());
		this->desapilar();
		paux.invertir();
		while(!paux.esVacia())
		{
			this->apilar(paux.tope());
			paux.desapilar();
		}
		for(int i=1;i<=iter;i++)
		{
			paux.apilar(this->tope());
			this->desapilar();
		}
		paux.invertir();
		while(!paux.esVacia())
		{
			this->apilar(paux.tope());
			paux.desapilar();
		}
		iter--;
	}
	
}

template <class T>
void Pila<T>::imprimir () const {
	
	Nodo<T> *aux;
	aux = this->top;
	for (int i = 1; i < this->n+ 1; i++) {
		
		cout<<aux->obtElem()<< "\t";
		aux = aux->obtAnt();
	}

	cout << endl;
	
}

#endif
