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
    int i,j;

    for (i = 0; i < taille; i++)
    {
        carac element_vide ;
        element_vide.caractere=NULL ;
        element_vide.freq=0 ;

        tab[i]=element_vide ;

    }
    char test[] = "je m'apè!le&éhe^$";

    wchar_t buffer ;
    

    int iterateur=0; 
    while(test[iterateur] != '\0') { 
        //-------------------------------
        buffer = test[iterateur] ;
        j=0 ;

                while (tab[j].caractere != NULL)
                {
                    if (tab[j].caractere==buffer)
                    {
                        tab[j].freq += 1 ;
                        break ;
                    }
                    j++ ;
                }

                if ((tab[j].caractere == NULL)&&(tab[j].freq == 0))
                {
                    tab[j].caractere = buffer ;
                    tab[j].freq = 1 ;
                }
        //-----------------------------------
        iterateur++; 
        }
    

                
    for ( i = 0; i < taille; i++)
    {

        printf(" %c , %d || " , tab[i].caractere , tab[i].freq) ;
    }

    
    

}


