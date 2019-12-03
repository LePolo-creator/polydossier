#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arbre_bin.h"

// Type abstrait de données

arbre creer_arbre_vide (void)
{
  return NULL ;
}

arbre creer_arbre(Elt e, arbre fg, arbre fd)
{
  noeud * nouveau;
  nouveau = (noeud *)malloc(sizeof(noeud));
  nouveau->elt = e;
  nouveau->fils_gauche = fg;
  nouveau->fils_droit = fd;
  return nouveau;
}

arbre fils_gauche(arbre a)
{
  assert(!est_arbre_vide(a));
  return a->fils_gauche;
}

arbre fils_droit(arbre a)
{
  assert(!est_arbre_vide(a));
  return a->fils_droit;
}

Elt racine(arbre a)
{
  assert(!est_arbre_vide(a));
  return a->elt;
}

int est_arbre_vide(arbre a)
{
  return (a == NULL) ;
}

// Fonctions outils

arbre creer_feuille(Elt e)
{
  return creer_arbre(e, creer_arbre_vide(), creer_arbre_vide()) ;
}

int est_feuille(arbre a)
{
  if (est_arbre_vide(a))
    return 0 ;
  return (est_arbre_vide(a->fils_gauche) && est_arbre_vide(a->fils_droit)) ;
}

void print_arbre_aux(arbre a)
{
  if (est_arbre_vide(a))
    printf(".") ;
  else
  {
    printf("%d (", a->elt) ;
    print_arbre_aux(a->fils_gauche) ;
    printf(") (");
    print_arbre_aux(a->fils_droit) ;
    printf(")") ;
  }
}

void print_arbre(arbre a) // Notation préfixe
{
  print_arbre_aux(a) ;
  printf("\n") ;
}

void free_noeud(arbre a)
{
  free(a) ;
}

void free_arbre(arbre a)
{
  if (!est_arbre_vide(a)){
    free_arbre(fils_gauche(a));
    free_arbre(fils_droit(a));
    free_noeud(a);
  }
}