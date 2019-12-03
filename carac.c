#include "arbre_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#define taille 50 

typedef struct 
    {
        wchar_t caractere ;
        int freq ;

    } carac ;

int main(){
    

    //on initialise le tableau 
    carac tab[taille] ;
    int i;

    for (i = 0; i < taille; i++)
    {
        carac element_vide ;
        element_vide.caractere=NULL ;
        element_vide.freq=0 ;

        tab[i]=element_vide ;

    }
    // char test[] = "Je m'apè!le&éhe^$";

    char buffer ;
    buffer = L'é' ;
    printf("%lc" , buffer) ;
    

    int j=0 ;

    while (tab[j].caractere != NULL)
    {
        if (tab[j].caractere==buffer)
        {
            tab[j].freq += 1 ;
            break ;
        }
        j++ ;
    }

    if ((tab[j].caractere == NULL)&&(tab[j].caractere == 0))
    {
        tab[j].caractere = buffer ;
        tab[j].freq = 1 ;
    }
    
    
    
    

    for ( i = 0; i < taille; i++)
    {
        printf("%lc , %d \n" , tab[i].caractere , tab[i].freq) ;
    }

}



