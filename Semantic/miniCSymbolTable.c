#include "miniCSymbolTable.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

struct PosicionListaRep {
  Simbolo dato;
  struct PosicionListaRep *sig;
};

struct ListaRep {
  PosicionLista cabecera;
  PosicionLista ultimo;
  int n;
};

typedef struct PosicionListaRep *NodoPtr;

Lista creaLS() {
  Lista nueva = malloc(sizeof(struct ListaRep));
  nueva->cabecera = malloc(sizeof(struct PosicionListaRep));
  nueva->cabecera->sig = NULL;
  nueva->ultimo = nueva->cabecera;
  nueva->n = 0;
  return nueva;
}

void liberaLS(Lista lista) {
  while (lista->cabecera != NULL) {
    NodoPtr borrar = lista->cabecera;
    lista->cabecera = borrar->sig;
    free(borrar);
  }
  free(lista);
}

void insertaLS(Lista lista, PosicionLista p, Simbolo s) {
  NodoPtr nuevo = malloc(sizeof(struct PosicionListaRep));
  nuevo->dato = s;
  nuevo->sig = p->sig;
  p->sig = nuevo;
  if (lista->ultimo == p) {
    lista->ultimo = nuevo;
  }
  (lista->n)++;
}

void suprimeLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  NodoPtr borrar = p->sig;
  p->sig = borrar->sig;
  if (lista->ultimo == borrar) {
    lista->ultimo = p;
  }
  free(borrar);
  (lista->n)--;
}

Simbolo recuperaLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig->dato;
}

PosicionLista buscaLS(Lista lista, char *nombre) {
  NodoPtr aux = lista->cabecera;
  while (aux->sig != NULL && strcmp(aux->sig->dato.nombre,nombre) != 0) {
    aux = aux->sig;
  }
  return aux;
}

void asignaLS(Lista lista, PosicionLista p, Simbolo s) {
  assert(p != lista->ultimo);
  p->sig->dato = s;
}

int longitudLS(Lista lista) {
  return lista->n;
}

PosicionLista inicioLS(Lista lista) {
  return lista->cabecera;
}

PosicionLista finalLS(Lista lista) {
  return lista->ultimo;
}

PosicionLista siguienteLS(Lista lista, PosicionLista p) {
  assert(p != lista->ultimo);
  return p->sig;
}


//NUESTRO

int perteneceTS(Lista lista, char * simbolo){
  
  PosicionLista encontrado = buscaLS(lista, simbolo);
  
  return finalLS(lista) != encontrado;
  
}


int esConstante(Lista lista, char * simbolo){
  
  PosicionLista p = buscaLS(lista, simbolo);
  
  if ( p != finalLS(lista)){
    
    Simbolo recuperado = recuperaLS(lista, p);
    return CONSTANTE == recuperado.tipo;
    
  }else {
    return 0;
  }
}



void imprimirTablaS(Lista lista){
  
  printf("\t.data\n");
  printf("\n");
  // Impresion de cadenas en la cabecera
  PosicionLista auxP = inicioLS(lista);
  
  while (auxP != finalLS(lista)) {
    
    Simbolo auxS = recuperaLS(lista, auxP);
    
    if (CADENA == auxS.tipo) {
      printf("$str%d:\n", auxS.valor+1);
      printf("\t.asciiz %s\n", auxS.nombre);
    }
    
    auxP = siguienteLS(lista, auxP);
  }
  
  //Impresion de variables y constantes en la cabecera
  auxP = inicioLS(lista);
  
  while (auxP != finalLS(lista)) {
    
    Simbolo auxCV = recuperaLS(lista, auxP);
    
    if (CONSTANTE == auxCV.tipo | VARIABLE == auxCV.tipo) {
      printf("_%s:\n", auxCV.nombre);
      printf("\t.word 0\n");
    }
    
    auxP = siguienteLS(lista, auxP);
  }
  printf("\n");
}