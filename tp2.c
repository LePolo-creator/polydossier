#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dichotomie(float f(float), float a, float b,int nb_cs, int nmax, float *aa, float * bb){
    
    float c,temp;
    int n, resul ;

    if (f(a)*f(b) <= 0){

        temp = pow(10,-nb_cs) ;//Calcul 1 fois
        n = 0 ;
        while (fabs(a-b)>= temp* (fabs(a)+0.1) && n <= nmax){
            c = (a+b)/2 ;
            if (f(a)*f(c) <= 0)
                b = c ;
            else
                a = c ;
            n = n + 1 ;
        }

        *aa = a ;
        *bb = b ;

        if (n > nmax)
            resul =  -1 ;
        else
            resul =  n ;
    }
    else
        resul = -2 ;

    return resul ;
}

int bairstow(float coeef[],int degre,float epsilon_deno, int nmax, int nb_cs, float sol_relles[], float sol_complexe[]){
    
}

int newton(float f(float),float fprime(float), float x0,float delta, float epislon_deno, int nb_cs, int nmax, float *x1){
    int n, resul ;
    float xk,xk1, temp ;
    
    n = 0 ;
    temp = pow(10,-nb_cs) ;
    xk = x0 ;
    xk1 = x0 + 2 * temp * (fabs(x0) + 0.1 ) ;
    while (n <= nmax && (fabs(xk-xk1) > temp * (fabs(xk1)+0.1))){
        xk1 = xk ;
        if ( fabs(fprime(xk)) > epislon_deno ){
            xk = xk1 - f(xk1)/fprime(xk1) ; 
        }
        else
            xk = xk1 + delta ; 
        n = n + 1 ;  
    }
    *x1 = xk ;
    if (n > nmax)
        resul = -1 ;
    else
        resul = n ;
    return resul;
}

float f(float x){
    return 2*x*x*x-7*x*x+8*x;
}

float fprime(float x){
    return 6*x*x-14*x+8 ;
}

int main(){
    int resultat, nb_inter ;
    float a, b, resul_a,resul_b ,pas ;

    /*
    //EXO 1 
    printf("Nombre de sous intervalle = ") ;
    scanf("%d",&nb_inter) ;
    a = 0 ;
    b = 4 ;
    pas = (b-a) / nb_inter ;
   
    for (int i = 1; i <= nb_inter; i = i + 1 ){
        if ( i == nb_inter)
            resultat = dichotomie(f,a + (i-1)*pas,b,3,100,&resul_a,&resul_b) ;
        else
            resultat = dichotomie(f,a + (i-1)*pas,a + i * pas,3,100,&resul_a,&resul_b) ;
        if (resultat == -1)
            printf("Pas de racine \n") ;
        else if (resultat == -2)
            printf("Pas de racine dans [%14.7e,%14.7e] \n",a + (i-1)*pas, a + i*pas) ;
        else
            printf("Racine [%14.7e,%14.7e] N = %d\n",resul_a,resul_b,resultat) ;
    }
    */
    //EXO 3
    /*
    resultat = newton(f,fprime,1,10e-2,10e-6,6,10e2,&resul_a) ;
    if (resultat == -1)
        printf("Pas de racine réelles\n") ;
    else
        printf("Racine = %14.7e, n = %d\n",resul_a,resultat) ;
    

    return 0;
    */
}