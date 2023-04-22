// AUTOR: Rubén Díaz Marrero
// FECHA: 17/04/2023
// EMAIL: alu0101552613@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
      // poner código
    }
  }
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  int aux_1 = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << aux_1 << std::endl;
  int aux_2{0};
  if (!(c == 'l' || c == 'c' || c== 'r')) {
    aux_2 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << aux_2 <<  std::endl;
  }
  switch (c) {
    case '+':
      aux_2 += aux_1;
      break;
    case '-':
      aux_2 -= aux_1;
      break;
    case '*':
      aux_2 = aux_1 * aux_2;
      break;
    case '/':
      aux_2 = aux_2 / aux_1;
      break;
    case '^':
      aux_2 = pow(aux_2, aux_1);
      break;
    case 'r':
      aux_2 = sqrt(aux_1);
      break;
    case 'l':
      aux_2 = log2(aux_1);
      break;
    case 'c':
      aux_2 = aux_1 * aux_1;
      break;
  }

  stack_.push(aux_2);
  std::cout << "   Metemos en la pila el resultado: " << std::endl;
}

 
#endif  // RPNT_H_
