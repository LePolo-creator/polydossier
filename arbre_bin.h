#ifndef __ARBRE_BINAIRE__
#define __ARBRE_BINAIRE__


typedef char Elt;

struct znoeud {

  Elt elt ;
  unsigned int frequence ;
  struct znoeud *fils_gauche ;
  struct znoeud * fils_droit ;
};
typedef struct znoeud noeud ;
typedef struct znoeud * arbre ;

// Type abstrait de données

arbre creer_arbre_vide (void) ;
arbre creer_arbre(Elt e, arbre fg, arbre fd) ;
arbre fils_gauche(arbre a) ;
arbre fils_droit(arbre a) ;
Elt racine(arbre a) ;

int est_arbre_vide(arbre a) ;

// Fonctions outils

arbre creer_feuille(Elt e) ;
int est_feuille(arbre a) ;

void print_arbre(arbre a) ;
void free_noeud(arbre a) ;
void free_arbre(arbre a) ;


#endif