
//Faltan añadir metodos


#ifndef COLA_H_
#define COLA_H_
#include <iostream>

#include "ListaA.hpp"

template <class T>
class  Cola : protected Lista<T> {

	private: 

		Nodo<T> *ult;

	public:

		 Cola();
		 bool esVacia();
		 void encolar(T elem);									//Funciona por ahora
		 void desencolar();										//Funciona por ahora
		 T frente() { return Lista<T>::consultar(1); }
		 int largo() { return Lista<T>::longitud(); }			//Funciona por ahora

		 //Metodos
		 T datoElem(int pos);										//Manda una posicion de la cola y devuelve la informacion de ahi
		 int posDato(T elem);										//Manda a buscar un dato y retorna la posicion 
		 void colaStarWars(int n, int m);							//Ruleta rusa donde n es el numero de personas y m es el contador para suicidarse 

		 void imprimir() { Lista<T>::imprimir();}					//Funciona a veces (._.)
};

template <class T>
Cola<T>::Cola(){

 	this->ult = NULL;
}

template <class T>
bool Cola<T>::esVacia(){

	return Lista<T>::esVacia();
}


template <class T>
void Cola<T>::encolar(T elem){

 	
  	Nodo<T> *aux;

	  if (this->n == 0)
	  {

	    Lista<T>::insertar(elem, 1);		//REVISAR
	    this->ult = this->primero;

	  }
	  else {

	    aux = new Nodo<T>;
	    aux->modElem(elem);
	    aux->modProx(NULL);

	    (this->ult)->modProx(aux);

	    this->ult = aux;
	    this->n += 1;

	  }

 }


template <class T>
void Cola<T>::desencolar()
{

  Lista<T>::eliminarP(1);
  if (this->n == 0)
  {
    this->ult = NULL;
  }
}

//-------------------------------------------------------------------------

template <class T>
void Cola<T>::colaStarWars(int n, int m){

	Cola<T> c1;
	T aux;
	int i = 1;

	for(int i = 1; i <= n; i++){

		c1.encolar(i);

	}
	//n es prisionero

	while(n > 1 && !c1.esVacia()){

		cout << "Numero de Prisioneros: ";
		c1.imprimir();
		cout << endl;

		aux = c1.frente();
		c1.desencolar();

		if(i != m){

			c1.encolar(aux);
			i++;

		}else{

			cout << "El prisionero " << aux << " muere" << endl;
			n--;
			i = 1;

		}

	}

	cout << "El prisionero tridor es: " << c1.frente() << endl;
	cout << "Fin del programa" << endl;



}


template <class T>
int Cola<T>::posDato(T elem){

	bool band = true;
	T aux;
	int cont=0;

	aux = Lista<T>::consultar(1);

	while(aux != elem){
	
		aux = Lista<T>::consultar(1);	
		Lista<T>::eliminarP(1);		
		this->encolar(aux);
		cont++;
		
	}

return cont;
	
}

template <class T>
T Cola<T>::datoElem(int pos){

	T aux;

	for(int i = 1; i < pos; i++){
	
		Lista<T>::eliminarP(1);
	
	}

	aux = Lista<T>::consultar(1);

	return aux;
}







#endif
