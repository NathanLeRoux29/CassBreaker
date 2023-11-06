#include <stdio.h>
#include <stdlib.h>

int main () {

int nbLigne=3;
int nbColonne=5;

int i;
int j;

    for (i=0 ; i<nbcolonne*nbligne ; i++){
        printf("%d",i);
        for (j=i; j<nbligne; j=i+5){
            xBrique=xEcart+(longBrique+espaceBrique)*i;
            yBrique=yEcart+(hauteurBrique+espaceBrique)*j;
            rebondBrique();
            drawRect(xBrique,yBrique,longBrique,hauteurBrique);     
        }
        printf("%d",i);
    }

}

