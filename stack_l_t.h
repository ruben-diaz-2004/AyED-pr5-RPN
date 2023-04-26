// AUTOR: Rubén Díaz Marrero
// FECHA: 17/04/2023
// EMAIL: alu0101552613@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  T modificacion();
  dll_t<T> l_;
};

template<class T> T stack_l_t<T>::modificacion() {
  dll_node_t<T>* aux = l_.get_head();
  T dato = 0;
  while (aux != NULL) {
    if (aux->get_data() % 2 == 0) dato += aux->get_data();
    aux = aux->get_next();
  }
  return dato;
}
// operaciones
/**
 * Añade un elemento a la pila
 * @param dato. Dato tipo T que contiene el nodo a almacenar
*/
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

// Extrae de la pila el último elemento que se introdujo
template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
  // std::cout << "Suma de pares: " << modificacion() << std::endl;
}

// Devuelve el dato del nodo que está en la cima de la pila
template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

// Comprueba si una pila está vacía
template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
