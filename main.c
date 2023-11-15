

#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 700
#define FPS 60
#define tabMax 18







/*/////////////////////////////////////////Variables\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*-----------------------------------------Element de jeux-----------------------------------------*/

        //Variables Balle

int ballx;
int bally;
int rayonBall;
int vitesseX;
int vitesseY;

        //Variables trainé Balle

int ball2x;
int ball2y;
int rayonBall2;
int ball3x;
int ball3y;
int rayonBall3;

        //Variables Barre

int xBarre;
int yBarre;
int longBarre;
int hauteurBarre;
int deplTouche;
int couleurBarre;

        //Variables Barre2

int xBarre2;
int yBarre2;
int longBarre2;
int hauteurBarre2;
int deplTouche2;

        //Variables Briques

int xBrique;
int yBrique;
int xEcart;
int yEcart;
int longBrique;
int hauteurBrique;
int espaceBrique;
int nbcolonne;
int nbligne;
int ytabmulti;
int xtabmulti;


/*-----------------------------------------Gameplay-----------------------------------------*/

        //Vie Briques

int viebrique[6][5];
int vieMulti[6][5];
int i;
int j;
int nbBrique;
int briqueTouche;
int nbBriqueMulti;
int briqueToucheMulti;

        //Gameplay

int nbvie;
int nbvieJ2;
int tentative;
int tentativeJ2;
float diminutionBarre;
int PauseGame;
int reinittab;
int timeinittab;
int accelPalier;
int movex;
int movey;

/*-----------------------------------------Menu-----------------------------------------*/

int start;
int histoire;
int arcade;
int solo;
int multi;
int coop;
int versus;


/*-----------------------------------------Affichage-----------------------------------------*/

        //Gameover
    
int xrectGameOver;
int yrectGameOver;
int longGameOver;
int hautGameOver;

int xDefaite;
int yAvaDefaite;

int xfin1;
int xfin2;
int xfin3;
int xfin4;
int xfin5;
int xfinj1;
int xfinj2;

        //Victoire
    
int xrectVictoire;
int yrectVictoire;
int longVictoire;
int hautVictoire;

int xVictoire;
int yAvavictoire;
int vitVictoire;
int avavitVictoire;

        //Accueil
    
int xrectLogo;
int yrectLogo;
int longLogo;
int hautLogo;

int yfond;
int xdebutjeu;
int ydebutjeu;

int menuXentre;
int menuXentre2;
int menuXsortie;
int menuXsortie2;
int menuXentre3;
int menuXentre4;
int menuY;
int menuY2;

        //Mission

int xkitty;
int ykitty;
int vitesseAssetX;
int vitesseAssetY;

        //Asset Jeux

int xAvavie;
int yAvavie;
int xAvavie2;
int yAvavie2;
int vitesseAvavieY;
int xAvavitesse;
int yAvavitesse;
int xAvavitesse2;
int yAvavitesse2;
int xAvavitesse3;
int yAvavitesse3;
int timervitesse1;
int timervitesse2;
int timervitesse3;
int timervitesse4;
int timervitesse5;






/*////////////////////////////////////////Initialisation des tableaux///////////////////////////////////////*/

void init_tab(){

        for(int i=0;i<nbcolonne;i++){   //Initialisation du tableau des vies
        for(int j=0;j<nbligne;j++){
            if ((j<2 && j>=0)){
                viebrique[i][j]=2;
            }
            else if ((j==2) && (i>=1) && (i<=4)){
                viebrique[i][j]=3;
            }
            else {
                viebrique[i][j]=1;
            }
        }     
    }   

    for(int i=0;i<nbcolonne;i++){   //Initialisation du tableau des vies
        for(int j=0;j<3;j++){
            if ((j<3 && j>=0) && i==1){
                vieMulti[i][j]=0;
            }
            else if ((j<3 && j>=0) && i==4){
                vieMulti[i][j]=0;
            }


            else if ((j==1) && (i>=2) &&(i<=3)){
                vieMulti[i][j]=3;
            }

            else if (j==1){
                vieMulti[i][j]=2;
            }

            else {
                vieMulti[i][j]=1;
            }
        }
    }     
      
}



/*////////////////////////////////////////Initialisation du jeu///////////////////////////////////////*/

void init_game(){               //mettre votre code d'initialisation ici

/*-----------------------------------------Element de jeux-----------------------------------------*/


    //Initialisation de la Balle

    ballx=WINDOW_WIDTH/2;           //Placement de la balle
    bally=WINDOW_HEIGHT-60;
    rayonBall=10;                   //Taille de la balle
    vitesseX = 3;                   //Vitesse de la balle
    vitesseY = -6;

    //Initialisation trainé Balle

    ball2x = ballx-3;
    ball2y = bally +3;
    rayonBall2 = rayonBall-1;
    ball3x = ball2x-3;
    ball3y = ball2y-3;
    rayonBall3 =rayonBall-2;

    //Initialisation de la Barre

    xBarre = 300;                   //Placement de la barre
    yBarre = WINDOW_HEIGHT-50;

    longBarre = 100;                //Forme de la Barre
    hauteurBarre = 15;
    deplTouche = 20;                //Déplacement de la Barre
    couleurBarre = 249;

    //Initialisation de la Barre2

    xBarre2 = 300;                   //Placement de la barre
    yBarre2 = 50;

    longBarre2 = 100;                //Forme de la Barre
    hauteurBarre2 = 15;
    deplTouche2 = 20;                //Déplacement de la Barre


    //Initialisation des Briques

    xBrique;                        //Placement des Briques
    yBrique;
    xEcart = 27;                    //(WINDOW_WIDTH-((longBrique*nbcolonne)+(espaceBrique*(nbcolonne-1))))/2
    yEcart = 30;
    espaceBrique = 5;

    longBrique = 70;                //Formes des Briques
    hauteurBrique = 50;

    ytabmulti=210;
    xtabmulti=0;


/*-----------------------------------------Gameplay-----------------------------------------*/

    //*************************Tableau Brique Histoire

    nbcolonne = 6 ;                 //Taille tableau
    nbligne = 5 ;



    nbBrique=(nbligne*nbcolonne)+(nbcolonne*2)+(2*4);     //Vie Brique
    briqueTouche=0;                                       //Nb brique touché


    nbBriqueMulti=((3*(nbcolonne-2))+(1*4)+(2));                       //Vie Brique Multi
    briqueToucheMulti=0;                                   //Nb brique touché Multi

    //GamePlay

    nbvie=3;                        //Nb de vie possible pour le joueur
    nbvieJ2=3;                        //Nb de vie possible pour le joueur
    tentative=1;                    // Initialisation des tentative
    tentativeJ2=1;                    // Initialisation des tentative
    diminutionBarre=1.5;            // Taille de la diminution de la barre a la perte de vie
    PauseGame=1;                    //Si différent de 1 met le jeu en pause
    reinittab=0;
    timeinittab=0;
    accelPalier=0;
    movex=0;
    movey=0;

/*-----------------------------------------Menu-----------------------------------------*/

    start=0;
    histoire=0;
    arcade=0;
    solo=0;
    multi=0;
    coop=0;
    versus=0;

/*-----------------------------------------Affichage-----------------------------------------*/


    //Ecran GameOver

    xrectGameOver=WINDOW_WIDTH/9;
    yrectGameOver=WINDOW_HEIGHT/4;
    longGameOver=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
    hautGameOver=200;

    xDefaite = -500;
    yAvaDefaite = 947;

    xfin1 = -500;
    xfin2 = -500;
    xfin3 = -500;
    xfin4 = -500;
    xfin5 = -500;
    xfinj1 = -500;
    xfinj2 = -500;

    //Ecran Victoire

    xrectVictoire=WINDOW_WIDTH/9;
    yrectVictoire=WINDOW_HEIGHT/3;
    longVictoire=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
    hautVictoire=200;

    xVictoire = -500;
    yAvavictoire = 947;
    vitVictoire = 25;
    avavitVictoire = 10;
                    
    //Asset accueil et menu
        
    xrectLogo=25;
    yrectLogo=-100;
    longLogo=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
    hautLogo=50;

    xdebutjeu=-355;
    ydebutjeu=600;

    menuXentre=-355;
    menuXentre2=-355;
    menuXsortie=-355;
    menuXsortie2=-355;
    menuXentre3=-355;
    menuXentre4=-355;
    menuY=520;
    menuY2=600;

            //Mission

    xkitty=510;
    ykitty=-290;
    vitesseAssetX=5;
    vitesseAssetY=5;

            //Asset Jeux

    xAvavie=50;
    yAvavie=-130;
    xAvavie2=50;
    yAvavie2=-130;
    vitesseAvavieY=10;
    xAvavitesse=50;
    yAvavitesse=-130;
    xAvavitesse2=50;
    yAvavitesse2=-130;
    xAvavitesse3=50;
    yAvavitesse3=-130;
    timervitesse1=0;
    timervitesse2=0;
    timervitesse3=0;
    timervitesse4=0;
    timervitesse5=0;



}








/*/////////////////////////////////////////Element de jeux\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*-----------------------------------------BALLE-----------------------------------------*/


void rebondBall(){              //Rebond de la balle sur la fenetre + Diminution de la barre 

    if (ballx >= WINDOW_WIDTH-rayonBall)        //Rebond largeur
        {vitesseX = vitesseX*(-1);
    }

    if (ballx <= rayonBall) 
        {vitesseX = vitesseX*(-1);
    }

    if (bally >= WINDOW_HEIGHT-rayonBall)       //Rebond bas fenetre
        {vitesseY = vitesseY*(-1);
        tentative=tentative+1;                  //Rajoute une tentative
        longBarre=longBarre-((longBarre-(longBarre/diminutionBarre))/2);  //Diminue la taille de la barre lorsque -1 vie joueur
        xBarre=xBarre+((longBarre-(longBarre/diminutionBarre))/2);
    }

    if (bally <= rayonBall) 
        {vitesseY = vitesseY*(-1);
        if (multi>=1){

            if ((coop>=1) && (versus==0)){
                longBarre=longBarre-((longBarre-(longBarre/diminutionBarre))/2);  //Diminue la taille de la barre lorsque -1 vie joueur
                xBarre=xBarre+((longBarre-(longBarre/diminutionBarre))/2);
                tentative=tentative+1; 
            }                 //Rajoute une tentative
            else if ((versus>=1) && (coop==0)){
                longBarre2=longBarre2-((longBarre2-(longBarre2/diminutionBarre))/2);  //Diminue la taille de la barre lorsque -1 vie joueur
                xBarre2=xBarre2+((longBarre2-(longBarre2/diminutionBarre))/2);
                tentativeJ2=tentativeJ2+1;  
            } 
        }
    }
}


void drawBall(){                //Dessin de la ball + Acceleration
    changeColor(64, 218, 249); 
    drawCircle(ballx,bally,rayonBall);  //Dessin de la ball
    ballx=ballx+ vitesseX;      //Déplacement de la balle largeur
    bally=bally+ vitesseY;      //Déplacement de la balle hauteur
}

void drawAccelaration(){
//Accéleration de la balle 
        if ((briqueTouche==15) && (vitesseX>0)){
            vitesseX=4;
        }

        else if ((briqueTouche==15) && (vitesseX<0)){
            vitesseX=-4;
        }


        if ((briqueTouche==15) && (vitesseY>0)){
            vitesseY=7;
        }

        else if ((briqueTouche==15) && (vitesseY<0)){
            vitesseY=-7;
        }

//Accéleration de la balle 2

        if ((briqueTouche==25) && (vitesseX>0)){
            vitesseX=5;
        }

        else if ((briqueTouche==25) && (vitesseX<0)){
            vitesseX=-5;
        }


        if ((briqueTouche==25) && (vitesseY>0)){
            vitesseY=8;
        }

        else if ((briqueTouche==25) && (vitesseY<0)){
            vitesseY=-8;
        }
//Accéleration de la balle 3

        if ((briqueTouche==40) && (vitesseX>0)){
            vitesseX=6;
        }

        else if ((briqueTouche==40) && (vitesseX<0)){
            vitesseX=-6;
        }


        if ((briqueTouche==40) && (vitesseY>0)){
            vitesseY=9;
        }

        else if ((briqueTouche==40) && (vitesseY<0)){
            vitesseY=-9;
        }

}

void drawAccelarationMulti(){
//Accéleration de la balle 
        if ((accelPalier==1) && (vitesseX>0)){
            vitesseX=4;
        }

        else if ((accelPalier==1) && (vitesseX<0)){
            vitesseX=-4;
        }


        if ((accelPalier==1) && (vitesseY>0)){
            vitesseY=7;
        }

        else if ((accelPalier==1) && (vitesseY<0)){
            vitesseY=-7;
        }

//Accéleration de la balle 2

        if ((accelPalier==2) && (vitesseX>0)){
            vitesseX=5;
        }

        else if ((accelPalier==2) && (vitesseX<0)){
            vitesseX=-5;
        }


        if ((accelPalier==2) && (vitesseY>0)){
            vitesseY=8;
        }

        else if ((accelPalier==2) && (vitesseY<0)){
            vitesseY=-8;
        }
//Accéleration de la balle 3

        if ((accelPalier==3) && (vitesseX>0)){
            vitesseX=6;
        }

        else if ((accelPalier==3) && (vitesseX<0)){
            vitesseX=-6;
        }


        if ((accelPalier==3) && (vitesseY>0)){
            vitesseY=9;
        }

        else if ((accelPalier==3) && (vitesseY<0)){
            vitesseY=-9;
        }
//Accéleration de la balle 4

        if ((accelPalier==4) && (vitesseX>0)){
            vitesseX=7;
        }

        else if ((accelPalier==4) && (vitesseX<0)){
            vitesseX=-7;
        }


        if ((accelPalier==4) && (vitesseY>0)){
            vitesseY=10;
        }

        else if ((accelPalier==4) && (vitesseY<0)){
            vitesseY=-10;
        }
}

void drawBalltraine(){                //Dessin de la traine
    changeColor(133, 231, 251);
    drawCircle(ball2x,ball2y,rayonBall2);  //Dessin de la traine
    ball2x=ballx*1.001;      //Déplacement de la balle largeur
    ball2y=bally*1.001;      //Déplacement de la balle hauteur
}
void drawBalltraine2(){ 
    changeColor(185, 240, 251);
    drawCircle(ball3x,ball3y,rayonBall3);  //Dessin de la traine
    ball3x=ball2x*1.001;      //Déplacement de la balle largeur
    ball3y=ball2y*1.001;      //Déplacement de la balle hauteur
}

/*-----------------------------------------BARRE-----------------------------------------*/


void drawBarre(){                   //Dessin de la barre et changement de couleur

    if(tentative==1){
        changeColor(114, 246, 82);
        drawRect(xBarre,yBarre,longBarre,hauteurBarre);

    }
    else if(tentative==2){
        changeColor(246, 246, 82);
        drawRect(xBarre,yBarre,longBarre,hauteurBarre);

    }
    else if(tentative==3){
        changeColor(246, 82, 82);
        drawRect(xBarre,yBarre,longBarre,hauteurBarre);
    }


}
void drawBarre2(){                  //Dessin de la barre Coop et changement de couleur

    if(tentative==1){
        changeColor(114, 246, 82);
        drawRect(xBarre2,yBarre2,longBarre,hauteurBarre);

    }
    else if(tentative==2){
        changeColor(246, 246, 82);
        drawRect(xBarre2,yBarre2,longBarre,hauteurBarre);

    }
    else if(tentative==3){
        changeColor(246, 82, 82);
        drawRect(xBarre2,yBarre2,longBarre,hauteurBarre);
    }


}
void drawBarreVersus(){              //Dessin de la barre Versus et changement de couleur

    if(tentativeJ2==1){
        changeColor(114, 246, 82);
        drawRect(xBarre2,yBarre2,longBarre2,hauteurBarre2);

    }
    else if(tentativeJ2==2){
        changeColor(246, 246, 82);
        drawRect(xBarre2,yBarre2,longBarre2,hauteurBarre2);

    }
    else if(tentativeJ2==3){
        changeColor(246, 82, 82);
        drawRect(xBarre2,yBarre2,longBarre2,hauteurBarre2);
    }


}

void rebondBarre (){            //Rebond de la barre
    
                    //haut

                if(((bally>=yBarre-rayonBall) && (bally<yBarre)) &&
                    ((ballx<=xBarre+longBarre) && (ballx>=xBarre)) && (vitesseY>0)){
                    vitesseY=vitesseY*(-1);
                }

                    //gauche

                if((ballx>=xBarre-rayonBall) && (ballx<xBarre) &&
                    ((bally>=yBarre) && (bally<=yBarre+hauteurBarre)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    
                }
                    //droite

                else if((ballx<=xBarre+longBarre+rayonBall) && (ballx>xBarre+longBarre) &&
                    ((bally>=yBarre) && (bally<=yBarre+hauteurBarre)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                }

}
void rebondBarre2(){            //Rebond de la barre
    
                    //bas

                if(((bally<=yBarre2+hauteurBarre2+rayonBall) && (bally>yBarre2)) &&
                    ((ballx<=xBarre2+longBarre2) && (ballx>=xBarre2)) && (vitesseY<0)){
                    vitesseY=vitesseY*(-1);
                }

                    //gauche

                if((ballx>=xBarre2-rayonBall) && (ballx<xBarre2) &&
                    ((bally>=yBarre2) && (bally<=yBarre2+hauteurBarre2)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    
                }
                    //droite

                else if((ballx<=xBarre2+longBarre2+rayonBall) && (ballx>xBarre2+longBarre2) &&
                    ((bally>=yBarre2) && (bally<=yBarre2+hauteurBarre2)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                }

}

/*-----------------------------------------Brique-----------------------------------------*/
   
void drawBrick(){              //Dessin des briques, Rebond des briques, Vie et Brique touché


    for(i=0;i<nbcolonne;i++){               //Correspond aux colonnes de mes briques
        for (j=0; j<nbligne;j++){           //Correspond aux lignes de mes briques
            if (viebrique[i][j]>=1){
                if(viebrique[i][j]<2){
                    changeColor(64, 218, 249);
                }

                else if (viebrique[i][j]==2){
                    changeColor(167, 19, 255);
                }

                else if (viebrique[i][j]==3){
                    changeColor(246, 101, 250);
                }
                xBrique=xEcart+(longBrique+espaceBrique)*i;
                yBrique=yEcart+(hauteurBrique+espaceBrique)*j;
                drawRect(xBrique,yBrique,longBrique,hauteurBrique);


                             //Rebond de la balle sur les Briques
                            
                    //bas
                
                if(((bally<=yBrique+hauteurBrique+rayonBall) && (bally>yBrique+hauteurBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY<0)){
                    vitesseY=vitesseY*(-1); 
                    viebrique[i][j]=viebrique[i][j]-1;
                    briqueTouche=briqueTouche+1;
                }

                    //haut

                else if(((bally>=yBrique-rayonBall) && (bally<yBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY>0)){
                    vitesseY=vitesseY*(-1);
                    viebrique[i][j]=viebrique[i][j]-1;
                    briqueTouche=briqueTouche+1;
                }

                    //gauche

                if((ballx>=xBrique-rayonBall) && (ballx<xBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=viebrique[i][j]-1;
                    briqueTouche=briqueTouche+1;
                }

                    //droite

                else if((ballx<=xBrique+longBrique+rayonBall) && (ballx>xBrique+longBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=viebrique[i][j]-1; 
                    briqueTouche=briqueTouche+1;
                }
                
            }
        }
    }

}

void drawBrickMulti(){         //Dessin des briques, Rebond des briques, Vie et Brique touché


    for(i=0;i<nbcolonne;i++){               //Correspond aux colonnes de mes briques
        for (j=0; j<nbligne;j++){           //Correspond aux lignes de mes briques
            if (vieMulti[i][j]>=1){
                if(vieMulti[i][j]<2){
                    changeColor(64, 218, 249);
                }

                else if (vieMulti[i][j]==2){
                    changeColor(167, 19, 255);
                }

                else if (vieMulti[i][j]==3){
                    changeColor(246, 101, 250);
                }
                xBrique=(xEcart+xtabmulti)+(longBrique+espaceBrique)*i;
                yBrique=(yEcart+ytabmulti)+(hauteurBrique+espaceBrique)*j;
                drawRect(xBrique,yBrique,longBrique,hauteurBrique);


                             //Rebond de la balle sur les Briques
                            
                    //bas
                
                if(((bally<=yBrique+hauteurBrique+rayonBall) && (bally>yBrique+hauteurBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY<0)){
                    vitesseY=vitesseY*(-1); 
                    vieMulti[i][j]=vieMulti[i][j]-1;
                    briqueToucheMulti=briqueToucheMulti+1;
                }

                    //haut

                else if(((bally>=yBrique-rayonBall) && (bally<yBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY>0)){
                    vitesseY=vitesseY*(-1);
                    vieMulti[i][j]=vieMulti[i][j]-1;
                    briqueToucheMulti=briqueToucheMulti+1;
                }

                    //gauche

                if((ballx>=xBrique-rayonBall) && (ballx<xBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    vieMulti[i][j]=vieMulti[i][j]-1;
                    briqueToucheMulti=briqueToucheMulti+1;
                }

                    //droite

                else if((ballx<=xBrique+longBrique+rayonBall) && (ballx>xBrique+longBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                    vieMulti[i][j]=vieMulti[i][j]-1; 
                    briqueToucheMulti=briqueToucheMulti+1;
                }
                
            }
        }
    }

}

void reninitpalier(){          //Mode arcade reinitialise les briques et change de palier
        if((briqueToucheMulti>=nbBriqueMulti) && (tentative<=nbvie)){
            reinittab=1;
            timeinittab=timeinittab+1;
                if((reinittab==1) && (timeinittab>=20)){
                    init_tab();
                    reinittab=0;
                    timeinittab=0;            
                    briqueToucheMulti=0;
                    accelPalier=accelPalier+1;
                }
        }
}

void moveBricky(){             //Mouvement des briques en arcade solo
    if (ytabmulti<260 && movey==0){
        ytabmulti=ytabmulti+1;
    }
    else if (ytabmulti>=260){
        movey=1;
    }
    if (ytabmulti>0 && movey==1){
        ytabmulti=ytabmulti-1;
    }
    else if (ytabmulti<=0){
        movey=0;
    }

}

void moveBrickmultiy(){        //Mouvement des briques en arcade solo
    if (ytabmulti<320 && movey==0){
        ytabmulti=ytabmulti+1;
    }
    else if (ytabmulti>=320){
        movey=1;
    }
    if (ytabmulti>180 && movey==1){
        ytabmulti=ytabmulti-1;
    }
    else if (ytabmulti<=180){
        movey=0;
    }

}



/*/////////////////////////////////////////Menu et Asset\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*-----------------------------------------Ecran d'accueil-----------------------------------------*/

void drawAccueil(){
    sprite(0, 0,"Asset/fondaccueil.bmp");

    sprite(xrectLogo, yrectLogo,"Asset/logo.bmp");
    sprite(xdebutjeu, ydebutjeu,"Asset/start.bmp");

    if(yrectLogo<100){
        yrectLogo=yrectLogo-vitesseY;
        }

    if(xdebutjeu<75){
        xdebutjeu=xdebutjeu+avavitVictoire;
        }

}

/*-----------------------------------------Choix de mode de jeux-----------------------------------------*/

void drawMenu(){
    sprite(0, 0,"Asset/fondaccueil.bmp");
    sprite(xdebutjeu, ydebutjeu,"Asset/start.bmp");
    sprite(xrectLogo, yrectLogo,"Asset/logo.bmp");
    sprite(menuXentre, menuY,"Asset/mhistoire.bmp");
    sprite(menuXentre2, menuY2,"Asset/marcade.bmp");


    if (xdebutjeu>0){
        xdebutjeu=xdebutjeu=xdebutjeu+avavitVictoire;
    }

    if(menuXentre<50){
        menuXentre=menuXentre+avavitVictoire;
    }  

    if(menuXentre2<50){
        menuXentre2=menuXentre2+avavitVictoire;
    } 

}



/*+++++++++++++++++++++++++++++++++++++++Choix histoire+++++++++++++++++++++++++++++++++++++++++++*/


/*-----------------------------------------Ecran de mission-----------------------------------------*/

void drawMission(){
    sprite(0, 0,"Asset/fondmission.bmp");
    sprite(20, ykitty,"Asset/kitty2.bmp");
    sprite(xkitty, 180,"Asset/kitty.bmp");
    sprite(0, 0,"Asset/bordurefondmission.bmp");

        if(xkitty>270){
            xkitty=xkitty-vitesseAssetX;
        }
        if(ykitty<80){
            ykitty=ykitty+vitesseAssetY;
        }
}


/*-----------------------------------------GameOver-----------------------------------------*/

void drawGameOver(){
    sprite(xDefaite, 225,"Asset/defaite.bmp");       //225
    sprite(0, yAvaDefaite,"Asset/avadefaite.bmp");     //453
        if (xDefaite<0){
            xDefaite=xDefaite+vitVictoire;
        }

        if (yAvaDefaite>453){
            yAvaDefaite=yAvaDefaite-avavitVictoire;
        }
        
}

void drawFinarcade(){   

    sprite(xfin1, 200,"Asset/fin1.bmp");
    sprite(xfin2, 200,"Asset/fin2.bmp");
    sprite(xfin3, 200,"Asset/fin3.bmp");
    sprite(xfin4, 200,"Asset/fin4.bmp");
    sprite(xfin5, 200,"Asset/fin5.bmp");

    if ((accelPalier+1==1) && (xfin1<0)){
        xfin1=xfin1+avavitVictoire;
    }

    else if ((accelPalier+1==2) && (xfin2<0)){
        xfin2=xfin2+avavitVictoire;
    }

    else if ((accelPalier+1==3) && (xfin3<0)){
        xfin3=xfin3+avavitVictoire;
    }

    else if ((accelPalier+1==4) && (xfin4<0)){
        xfin4=xfin4+avavitVictoire;
    }

    else if ((accelPalier+1==5) && (xfin5<0)){
        xfin5=xfin5+avavitVictoire;
    }
}

void drawFinversus(){   

    sprite(xfin1, 200,"Asset/finj1.bmp");
    sprite(xfin2, 200,"Asset/finj2.bmp");

    if ((tentativeJ2>nbvie) && (xfin1<0)){
        xfin1=xfin1+avavitVictoire;
    }

    else if ((tentative>nbvie) && (xfin2<0)){
        xfin2=xfin2+avavitVictoire;
    }


}


/*-----------------------------------------Victoire-----------------------------------------*/

void drawVictoire(){
    sprite(xVictoire, 225,"Asset/victoire.bmp");       //225
    sprite(0, yAvavictoire,"Asset/avavictoire.bmp");     //453
        if (xVictoire<0){
            xVictoire=xVictoire+vitVictoire;
        }

        if (yAvavictoire>453){
            yAvavictoire=yAvavictoire-avavitVictoire;
        }

}

void drawEnding(){
    sprite(0, 0,"Asset/fin.bmp");
}


/*-----------------------------------------Background-----------------------------------------*/

void drawBackground(){
    sprite(0, 0,"Asset/fondjeux.bmp");

}

void drawAva(){                 // Apparition d'Ava dans le jeu

            sprite(xAvavie, yAvavie,"Asset/avavie.bmp");

                if(((yAvavie>=-130) && (yAvavie<=0)) && (tentative==2) && (timervitesse1<50)){
                    yAvavie=yAvavie+vitesseAvavieY;
                } 

                else if ((yAvavie>=0)){                         //Debut du timer
                    timervitesse1=timervitesse1+1;
                }

                if ((tentative>=2) && (yAvavie>=-130) && (timervitesse1>=100)){        
                    yAvavie=yAvavie-vitesseAvavieY;
                }

            sprite(xAvavie2, yAvavie2,"Asset/avavie2.bmp");

                if(((yAvavie2>=-130) && (yAvavie2<=0)) && (tentative==3) && (timervitesse5<50)){
                    yAvavie2=yAvavie2+vitesseAvavieY;
                } 

                else if ((yAvavie2>=0)){                         
                    timervitesse5=timervitesse5+1;
                }

                if ((tentative>=3) && (yAvavie2>=-130) && (timervitesse5>=100)){        
                    yAvavie2=yAvavie2-vitesseAvavieY;
                }

            sprite(xAvavitesse, yAvavitesse,"Asset/avavitesse1.bmp");

                if(((yAvavitesse>=-130) && (yAvavitesse<=0)) && ((vitesseX==4) || (vitesseX==-4)) && (timervitesse2<50)){
                    yAvavitesse=yAvavitesse+vitesseAvavieY;
                } 

                else if ((yAvavitesse>=0)){
                    timervitesse2=timervitesse2+1;
                }

                if ((yAvavitesse>=-130) && (timervitesse2>=100)){
                    yAvavitesse=yAvavitesse-vitesseAvavieY;
                }

            sprite(xAvavitesse2, yAvavitesse2,"Asset/avavitesse2.bmp");

                if(((yAvavitesse2>=-130) && (yAvavitesse2<=0)) && ((vitesseX==5) || (vitesseX==-5)) && (timervitesse3<50)){
                    yAvavitesse2=yAvavitesse2+vitesseAvavieY;
                } 

                else if ((yAvavitesse2>=0)){
                    timervitesse3=timervitesse3+1;
                }

                if ((yAvavitesse2>=-130) && (timervitesse3>=100)){
                    yAvavitesse2=yAvavitesse2-vitesseAvavieY;
                }

            sprite(xAvavitesse3, yAvavitesse3,"Asset/avavitesse3.bmp");

                if(((yAvavitesse3>=-130) && (yAvavitesse3<=0)) && ((vitesseX==6) || (vitesseX==-6)) && (timervitesse4<50)){
                    yAvavitesse3=yAvavitesse3+vitesseAvavieY;
                } 

                else if ((yAvavitesse3>=0)){
                    timervitesse4=timervitesse4+1;
                }

                if ((yAvavitesse3>=-130) && (timervitesse4>=100)){
                    yAvavitesse3=yAvavitesse3-vitesseAvavieY;
                }
}

void drawScore(){
    if (accelPalier+1==1){
        sprite(0, 75,"Asset/1.bmp");
    }

    else if (accelPalier+1==2){
        sprite(0, 75,"Asset/2.bmp");
    }

    else if (accelPalier+1==3){
        sprite(0, 75,"Asset/3.bmp");
    }

    else if (accelPalier+1==4){
        sprite(0, 75,"Asset/4.bmp");
    }

    else if (accelPalier+1==5){
        sprite(0, 75,"Asset/5.bmp");
    }
}


/*+++++++++++++++++++++++++++++++++++++++Choix arcade+++++++++++++++++++++++++++++++++++++++++++*/

void drawMenuarcade(){
    sprite(0, 0,"Asset/menuarcade.bmp");

    sprite(xrectLogo, yrectLogo,"Asset/logo.bmp");
    sprite(menuXentre, menuY,"Asset/mhistoire.bmp");
    sprite(menuXentre2, menuY2,"Asset/marcade.bmp");
    sprite(menuXsortie, menuY,"Asset/msolo.bmp");
    sprite(menuXsortie2, menuY2,"Asset/mmulti.bmp");

    if(yrectLogo>-200){
        yrectLogo=yrectLogo+vitesseY;
        }

    if(menuXentre<500){
        menuXentre=menuXentre+avavitVictoire;
    }  

    if(menuXentre2<500){
        menuXentre2=menuXentre2+avavitVictoire;
    } 

    if(menuXsortie<50){
        menuXsortie=menuXsortie+avavitVictoire;
    }  

    if(menuXsortie2<50){
        menuXsortie2=menuXsortie2+avavitVictoire;
    } 
}

void drawMenumulti(){


    sprite(0, 0,"Asset/menuarcade.bmp");
    sprite(menuXentre3, menuY,"Asset/mcoop.bmp");
    sprite(menuXentre4, menuY2,"Asset/mversus.bmp");
    sprite(menuXsortie, menuY,"Asset/msolo.bmp");
    sprite(menuXsortie2, menuY2,"Asset/mmulti.bmp");

 
    if(menuXentre3<50){
        menuXentre3=menuXentre3+avavitVictoire;
    }  

    if(menuXentre4<50){
        menuXentre4=menuXentre4+avavitVictoire;
    } 

    if(menuXsortie<500){
        menuXsortie=menuXsortie+avavitVictoire;
    }  

    if(menuXsortie2<500){
        menuXsortie2=menuXsortie2+avavitVictoire;
    } 
}

void drawExplisolo(){
            drawBackground();
            drawScore();
            drawBrickMulti();  
            drawBarre();
            sprite(0, 450,"Asset/explisolo.bmp");
}

void drawExpliCoop(){
            drawBackground();
            drawScore();
            drawBrickMulti();  
            drawBarre();
            drawBarre2();
        sprite(0, 450,"Asset/explicoop.bmp");
}

void drawExpliVersus(){
            drawBackground();
            drawScore();
            drawBrickMulti();  
            drawBarre();
            drawBarre2();
    sprite(0, 450,"Asset/expliversus.bmp");
}




/*/////////////////////////////////////////Mode de Jeu\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/




void drawHistoire(){
            
        if(histoire==1){                           //Mission
            drawMission();
        }

        if((PauseGame==1) && (histoire>=2)){       //Jeux
            drawBackground();
            drawBrick();  
            drawAva();
            drawBalltraine2();
            drawBalltraine();
            drawBall();
            drawAccelaration();
            drawBarre();
            rebondBall();
            rebondBarre ();
        }

        if((briqueTouche==nbBrique) && (tentative<=nbvie)){    //Victoire
            vitesseX=0;
            vitesseY=0;
            drawVictoire();
        }

        if((tentative>nbvie) && (briqueTouche<nbBrique) && (histoire>=2)){      //Defaite
            vitesseX=0;
            vitesseY=0;
            drawGameOver();
            printf("%d\n",briqueTouche);
        }

        if((briqueTouche>=nbBrique) && (tentative<=nbvie) && (histoire>=3)){
            drawEnding();
        }
}

void drawSolo(){
            
        if((PauseGame==1)){       //Jeux

            drawBackground();
            drawScore();
            moveBricky();
            drawBrickMulti();  
            drawBalltraine2();
            drawBalltraine();
            drawBall();
            drawAccelarationMulti();
            drawBarre();
            rebondBall();
            rebondBarre ();
            reninitpalier();
        }

        if((tentative>nbvie)){     //Defaite
            vitesseX=0;
            vitesseY=0;
            drawFinarcade();
            printf("Vous avez atteint le palier%d\n",accelPalier+1);
        }

        if((tentative>nbvie) && (solo>=3)){
            drawEnding();
        }
}

void drawCoop(){
            
        if((PauseGame==1) && (multi>=1)){       //Jeux
            drawBackground();
            drawScore();
            moveBrickmultiy();
            drawBrickMulti();  
            drawBalltraine2();
            drawBalltraine();
            drawBall();
            drawAccelarationMulti();
            drawBarre();
            drawBarre2();
            rebondBall();
            rebondBarre ();
            rebondBarre2 ();
            reninitpalier();
        }

        if((tentative>nbvie)){     //Defaite
            vitesseX=0;
            vitesseY=0;
            drawFinarcade();
            printf("Vous avez atteint le palier%d\n",accelPalier+1);
        }

        if((tentative>nbvie) && (coop>=3)){
            drawEnding();
        }

}

void drawVersus(){
            
        if((PauseGame==1) && (multi>=1)){       //Jeux
            drawBackground();
            drawScore();
            moveBrickmultiy();
            drawBrickMulti();  
            drawBalltraine2();
            drawBalltraine();
            drawBall();
            drawAccelarationMulti();
            drawBarre();
            drawBarreVersus();
            rebondBall();
            rebondBarre ();
            rebondBarre2 ();
            reninitpalier();
        }

        if((tentative>nbvie)){     //Defaite
            vitesseX=0;
            vitesseY=0;
            drawFinversus();
            printf("Vous avez atteint le palier%d\n",accelPalier+1);
        }

        else if((tentativeJ2>nbvieJ2)){     //Defaite
            vitesseX=0;
            vitesseY=0;
            drawFinversus();
            printf("Vous avez atteint le palier%d\n",accelPalier+1);
        }

        if(((tentative>nbvie)||(tentativeJ2>nbvieJ2)) && (versus>=3)){
            drawEnding();
        }

}




/*/////////////////////////////////////////Jeu\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

void drawGame(){

    clear();
        if((start==0) && (histoire==0) && (arcade==0)){                                 //Ecran d'accueil
            drawAccueil();
        }

        else if((start==1) && (histoire==0) && (arcade==0)){                            //Ecran de menu
            drawMenu();
        }
        
        else if((start==1) && (histoire>=1) && (arcade==0) && (multi==0) && (solo==0) && (versus==0) && (coop==0)){                            //Histoire
            drawHistoire();
        }
        
        else if((start==1) && (histoire==0) && (arcade>=1) && (multi==0) && (solo==0)){ //Choix arcade
            drawMenuarcade();
        }

        else if ((start==1) &&(histoire==0) && (arcade==1) && (multi==0) && (solo==1)){ //Explication solo
            drawExplisolo();
        }

        else if ((start==1) &&(histoire==0) && (arcade==1) && (multi==0) && (solo==2)){ //lance le jeu solo
           drawSolo();
        }

        else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (versus==0) && (coop==0)){ //Choix multi
            drawMenumulti();
        }

        else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (versus==1) && (coop==0)){ //Explication versus
            drawExpliVersus();
        }

        else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (versus>=2) && (coop==0)){ //Explication versus
            drawVersus();
        }

        else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (coop==1) && (versus==0)){ //Explication versus
            drawExpliCoop();
        }

        else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (coop>=2) && (versus==0)){ //Explication versus
            drawCoop();
        }

        if (PauseGame==1){                                                              // Si jeu != en pause
            actualize();
        }

    usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde
}

/*-----------------------------------------Pressage de touche-----------------------------------------*/

void KeyPressed(SDL_Keycode touche){
    /** @brief event.key.keysym.sym renvoi la touche appuyé
     *
     */
    switch (touche) {
        // Voir doc SDL_Keycode pour plus de touches https://wiki.libsdl.org/SDL_Keycode
        // ici exemple ou appuyer sur les touches Q | D modifie x (position du carré dans drawGame())

//Deplacement Barre 1

        case SDLK_q:                    //touche q appuyé //Deplacement Barre sur la gauche
            printf("Q\n");
                if ((xBarre > 0) && (PauseGame==1)){                       
                    xBarre=xBarre-deplTouche;
                }
                else if (xBarre <= 0){
                    xBarre=0;
                }
                else;
            break;


        case SDLK_d:                   //touche d appuyé //Deplacement Barre sur la droite
            printf("D\n");
            if ((xBarre < WINDOW_WIDTH-longBarre) && (PauseGame==1)){      
                    xBarre=xBarre+deplTouche;
            }
            else if((xBarre >= WINDOW_WIDTH-longBarre) && (PauseGame==1)){
                xBarre >= WINDOW_WIDTH-longBarre;
            }
                else;
            break;

//Deplacement Barre 2

        case SDLK_LEFT:                    //touche b appuyé //Deplacement Barre sur la gauche
            printf("B\n");
                if ((xBarre2 > 0) && (PauseGame==1)){                       
                    xBarre2=xBarre2-deplTouche;}
            else if (xBarre2 <= 0){
                    xBarre2=0;
                }
                else;
            break;


        case SDLK_RIGHT:                   //touche dn appuyé //Deplacement Barre sur la droite
            printf("N\n");
            if ((xBarre2 < WINDOW_WIDTH-longBarre2) && (PauseGame==1)){      
                xBarre2=xBarre2+deplTouche;
            }
            else if((xBarre2 >= WINDOW_WIDTH-longBarre2) && (PauseGame==1)){
                xBarre2 >= WINDOW_WIDTH-longBarre2;
            }
                else;
            break;

//Autre

        case SDLK_ESCAPE:             //touche ESC appuyé //Ferme la fenetre arrete le jeu
            freeAndTerminate();
            break;


        case SDLK_v:                  //touche v appuyé //Restart du jeu
            printf("V\n");
            init_game();
            init_tab();
            break;


        case SDLK_p:                  //touche p appuyé //Met pause au jeu
            printf("p\n");
            PauseGame=PauseGame*(-1);
            break;

//Deplacement Menu

        case SDLK_SPACE:               //touche Espace appuyé //Lance le jeu
            if ((start==0) && (histoire==0) && (arcade==0) && (multi==0) && (solo==0) && (coop==0) && (versus==0)){
                printf("space\n");
                start=start+1;
                printf("start %d\n",start);
                
                }
            else if (histoire>=1 && (arcade==0) && (multi==0) && (solo==0) && (coop==0) && (versus==0)){
                printf("space\n");
                histoire=histoire+1;
                printf("histoire %d\n",histoire);
            }

            else if ((arcade==0) && (histoire==0) && (multi==0) && (solo==0) && (coop==0) && (versus==0)){
                printf("space\n");
                arcade=arcade+1;
                printf("arcade %d\n",arcade);
            }

            else if ((histoire==0) && (arcade==1) && (multi==0) && (solo>=1) && (versus==0) && (coop==0)){
                printf("space\n");
                solo=solo+1;
                printf("solo %d\n",solo);
            }

            else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (coop>=1)){
                printf("space\n");
                coop=coop+1;
                printf("coop %d\n",coop);
            }

            else if ((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (versus>=1)){
                printf("space\n");
                versus=versus+1;
                printf("versus %d\n",versus);
            }

            break;

        case SDLK_a:               //touche Espace appuyé //Lance le jeu
            if ((histoire==0) && (start==1) && (arcade==0) ){
                printf("A\n");
                histoire=histoire+1;
                printf("histoire %d\n",histoire);
            }
            else if ((histoire==0) && (arcade==1) && (multi==0) && (solo==0)){
                printf("E\n");
                solo=solo+1;
                printf("solo %d\n",solo);
            }
            else if((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (coop==0)){
                printf("E\n");
                coop=coop+1;
                printf("coop %d\n",coop);
            }
            break;

        case SDLK_e:               //touche Espace appuyé //Lance le jeu
            if (arcade==0){
                printf("E\n");
                arcade=arcade+1;
                printf("arcade %d\n",arcade);
            }
            else if ((arcade==1) && (multi==0)){
                printf("E\n");
                multi=multi+1;
                printf("multi %d\n",multi);
            }
            else if ((start==1) && (histoire==0) && (arcade==1) && (multi==1) && (solo==0) && (versus==0)){
                printf("E\n");
                versus=versus+1;
                printf("versus %d\n",versus);
            }

            break;

        case SDLK_x:                   //touche x start -1
            printf("x\n");
            start=start-1;
            break;


        default:
            break;
    }
}


void joyButtonPressed(){
}

/*-----------------------------------------GameLoop-----------------------------------------*/

void gameLoop() {
    int programLaunched = 1;
    while (programLaunched == 1) {
        // Boucle pour garder le programme ouvert
        // lorsque programLaunched est different de 1
        // on sort de la boucle, donc de la fonction
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // boucle pour la gestion d'évenement
            switch (event.type) {
                /** event.type renvoi le type d'evenement qui se passe
                 * (si on appuie sur une touche, clique de souris...)
                 * en fonction du type d'évènement on à alors
                 * différentes information accessibles
                 * voir doc pour plus d'event https://wiki.libsdl.org/SDL_EventType
                 */
                case SDL_QUIT:
                    // quand on clique sur fermer la fénêtre en haut à droite
                    programLaunched = 0;
                    break;

                case SDL_MOUSEBUTTONUP:
                    /* clique de la souris
                     * event.motion.y | event.motion.x pour les positions de la souris
                     */
                    printf("position de la souris x : %d , y : %d\n", (event.motion.x), event.motion.y);
                    break;

                case SDL_KEYDOWN:
                    KeyPressed(event.key.keysym.sym);
                    break;
                case SDL_JOYBUTTONDOWN:
                    break;
                default:
                    break;
            }
        }
        /* coder ici pour que le code s'execute après chaque évenement
         * exemple dessiner un carré avec position int x, int y qu'on peut
         * deplacer lorsqu'on appuie sur une touche
         */
        drawGame();
    }
}

int main(){
    /** @description 3 fonctions dans le main qui permettent de créer l'application et la maintenir ouverte :
     *  init(...) : initialiser la SDL/ fenêtre
     *  gameLoop() : boucle de jeu dans laquelle l'application reste ouverte
     *  freeAndTerminate() : quitte le programme proprement
     */
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    init_game();
    init_tab();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}