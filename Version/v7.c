#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 700
#define FPS 60
#define tabMax 18


/*-----------------------------------------Variables-----------------------------------------*/

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
int viebrique[6][5];
int i;
int j;

        //Vie Briques

int nbBrique;
int briqueTouche;

        //Gameplay

int nbvie;
int tentative;
float diminutionBarre;
int start=0;
int PauseGame;

        //Gameover
    
int xrectGameOver;
int yrectGameOver;
int longGameOver;
int hautGameOver;

        //Asset Defaite

int xDefaite;
int yAvaDefaite;

        //Victoire
    
int xrectVictoire;
int yrectVictoire;
int longVictoire;
int hautVictoire;

        //Asset Victoire

int xVictoire;
int yAvavictoire;
int vitVictoire;
int avavitVictoire;

        //Logo
    
int xrectLogo;
int yrectLogo;
int longLogo;
int hautLogo;

        //Accueil

int yfond;
int xdebutjeu;
int ydebutjeu;

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

/*-----------------------------------------Initialisation du jeu-----------------------------------------*/


void init_game(){               //mettre votre code d'initialisation ici

//Initialisation de la Balle

ballx=WINDOW_WIDTH/2;           //Placement de la balle
bally=WINDOW_HEIGHT-65;
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

//Initialisation des Briques

xBrique;                        //Placement des Briques
yBrique;
xEcart = 27;                    //(WINDOW_WIDTH-((longBrique*nbcolonne)+(espaceBrique*(nbcolonne-1))))/2
yEcart = 30;
espaceBrique = 5;

longBrique = 70;                //Formes des Briques
hauteurBrique = 50;

nbcolonne = 6 ;                 //Taille tableau
nbligne = 5 ;

for(int i=0;i<nbcolonne;i++){   //Initialisation du tableau des vies
    for(int j=0;j<nbligne;j++){
        if ((j<2 && j>=0)){
            viebrique[i][j]=2;
        }
        else if ((j==2) && (i>=2) && (i<=3)){
            viebrique[i][j]=3;
        }
        else {
            viebrique[i][j]=1;
        }
    }     
 }

nbBrique=(nbligne*nbcolonne)+(nbcolonne*2)+(2*2);     //Vie Brique
briqueTouche=0;                 //Nb brique touché

//GamePlay

nbvie=3;                        //Nb de vie possible pour le joueur
tentative=1;                    // Initialisation des tentative
diminutionBarre=1.5;            // Taille de la diminution de la barre a la perte de vie
PauseGame=1;                    //Si différent de 1 met le jeu en pause


//Ecran GameOver

xrectGameOver=WINDOW_WIDTH/9;
yrectGameOver=WINDOW_HEIGHT/4;
longGameOver=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
hautGameOver=200;

        //Asset Defaite

xDefaite = -500;
yAvaDefaite = 947;

//Ecran Victoire

xrectVictoire=WINDOW_WIDTH/9;
yrectVictoire=WINDOW_HEIGHT/3;
longVictoire=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
hautVictoire=200;

        //Asset Victoire

xVictoire = -500;
yAvavictoire = 947;
vitVictoire = 25;
avavitVictoire = 10;
                 
        //Logo
    
xrectLogo=25;
yrectLogo=-100;
longLogo=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
hautLogo=50;

xdebutjeu=-355;
ydebutjeu=620;

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


void rebondBall(){              //Rebond de la balle sur la fenetre 

    if (ballx >= WINDOW_WIDTH-rayonBall)        //Rebond largeur
        {vitesseX = vitesseX*(-1);
    }

    if (ballx <= rayonBall) 
        {vitesseX = vitesseX*(-1);
    }

    if (bally >= WINDOW_HEIGHT-rayonBall)       //Rebond hauteur
        {vitesseY = vitesseY*(-1);
        tentative=tentative+1;                  //Rajoute une tentative

        longBarre=longBarre-((longBarre-(longBarre/diminutionBarre))/2);  //Diminue la taille de la barre lorsque -1 vie joueur
        xBarre=xBarre+((longBarre-(longBarre/diminutionBarre))/2);
    }

    if (bally <= rayonBall) 
        {vitesseY = vitesseY*(-1);
    }

}

void drawBall(){                //Dessin de la ball + Accelaration
    changeColor(64, 218, 249); 
    drawCircle(ballx,bally,rayonBall);  //Dessin de la ball
    ballx=ballx+ vitesseX;      //Déplacement de la balle largeur
    bally=bally+ vitesseY;      //Déplacement de la balle hauteur


//Accélaration de la balle 
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

//Accélaration de la balle 2

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
//Accélaration de la balle 3

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


void drawBarre(){               //Dessin de la barre

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

/*-----------------------------------------Brique-----------------------------------------*/
   
void drawBrick(){             //Dessin des briques, Rebond des briques, Vie et Brique touché


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
                    printf("%d\n",briqueTouche);
                }

                    //haut

                else if(((bally>=yBrique-rayonBall) && (bally<yBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY>0)){
                    vitesseY=vitesseY*(-1);
                    viebrique[i][j]=viebrique[i][j]-1;
                    briqueTouche=briqueTouche+1;
                    printf("%d\n",briqueTouche);

                }

                    //gauche

                if((ballx>=xBrique-rayonBall) && (ballx<xBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=viebrique[i][j]-1;
                    briqueTouche=briqueTouche+1;
                    printf("%d\n",briqueTouche);                
                }

                    //droite

                else if((ballx<=xBrique+longBrique+rayonBall) && (ballx>xBrique+longBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=viebrique[i][j]-1; 
                    briqueTouche=briqueTouche+1;
                    printf("%d\n",briqueTouche);
                }
                
            }
        }
    }

}





/*/////////////////////////////////////////Ecran d'affichage et Asset\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*-----------------------------------------Logo-----------------------------------------*/

void drawLogo(){
    sprite(xrectLogo, yrectLogo,"Asset/logo.bmp");
    sprite(xdebutjeu, ydebutjeu,"Asset/start.bmp");

    if(yrectLogo<100){
        yrectLogo=yrectLogo-vitesseY;
        }

    if(xdebutjeu<75){
        xdebutjeu=xdebutjeu+avavitVictoire;
        }
}

/*-----------------------------------------Ecran d'accueil-----------------------------------------*/

void drawAccueil(){
    sprite(0, 0,"Asset/fondaccueil.bmp");

    drawLogo();

}

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


/*-----------------------------------------Background-----------------------------------------*/

void drawBackground(){
    sprite(0, 0,"Asset/fondjeux.bmp");

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






/*/////////////////////////////////////////Jeu\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

void drawGame(){

    clear();
        if(start<=0){                           //Ecran d'accueil
            drawAccueil();
        }
        
        if(start==1){                           //Mission
            drawMission();
        }

        if((PauseGame==1) && (start>=2)){       //Jeux
            drawBackground();
            drawBrick();  
            drawAva();
            drawBalltraine2();
            drawBalltraine();
            drawBall();
            drawBarre();
            rebondBall();
            rebondBarre ();
        }

        if((briqueTouche==nbBrique) && (tentative<=nbvie)){    //Victoire
            vitesseX=0;
            vitesseY=0;
            drawVictoire();

        }

        if((tentative>nbvie) && (briqueTouche<nbBrique) && (start>=2)){      //Defaite
            vitesseX=0;
            vitesseY=0;
            drawGameOver();
        }

        if((briqueTouche>=nbBrique) && (tentative<=nbvie) && (start>=3)){
            drawEnding();
        }
        
        if (PauseGame==1){                                          // Si jeu != en pause
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


        case SDLK_q:                    //touche q appuyé //Deplacement Barre sur la gauche
            printf("Q\n");
                if ((xBarre >= 0) && (PauseGame==1)){                       
                    xBarre=xBarre-deplTouche;}
                else;
            break;


        case SDLK_d:                   //touche d appuyé //Deplacement Barre sur la droite
            printf("D\n");
            if ((xBarre <= WINDOW_WIDTH-longBarre) && (PauseGame==1)){      
                    xBarre=xBarre+deplTouche;}
                else;
            break;


        case SDLK_ESCAPE:             //touche ESC appuyé //Ferme la fenetre arrete le jeu
            freeAndTerminate();
            break;


        case SDLK_v:                  //touche v appuyé //Restart du jeu
            printf("V\n");
            init_game();
            break;


        case SDLK_p:                  //touche p appuyé //Met pause au jeu
            printf("p\n");
            PauseGame=PauseGame*(-1);
            break;


        case SDLK_SPACE:               //touche Espace appuyé //Lance le jeu
            printf("space\n");
            start=start+1;
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
                    printf("position de la souris x : %d , y : %d\n", event.motion.x, event.motion.y);
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
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}