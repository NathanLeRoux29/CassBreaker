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
int vitesse2X;
int vitesse2Y;

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

        //Vie Briques

int nbBrique;
int briqueTouche;

        //Vie jeu

int nbvie;
int tentative;
float diminutionBarre;

        //Gameover
    
int xrectGameOver;
int yrectGameOver;
int longGameOver;
int hautGameOver;

        //Victoire
    
int xrectVictoire;
int yrectVictoire;
int longVictoire;
int hautVictoire;
int PauseGame;

/*-----------------------------------------Initialisation du jeu-----------------------------------------*/


void init_game(){               //mettre votre code d'initialisation ici

//Initialisation de la Balle

ballx=WINDOW_WIDTH/2;           //Placement de la balle
bally=WINDOW_HEIGHT-100;
rayonBall=10;                   //Taille de la balle
vitesseX = 3;                   //Vitesse de la balle
vitesseY = -6;

//Initialisation trainé Balle

ball2x = ballx-3;
ball2y = bally +3;
rayonBall2 = rayonBall;
vitesse2X = 3;                   //Vitesse de la balle
vitesse2Y = -6;

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
        viebrique[i][j]=1;
    }     
 }

nbBrique=nbligne*nbcolonne;     //Vie Brique
briqueTouche=0;                 //Nb brique touché

//Vie jeu

nbvie=3;                        //Nb de vie possible pour le joueur
tentative=1;                    // Initialisation des tentative
diminutionBarre=1.5;            // Taille de la diminution de la barre a la perte de vie 

//Ecran GameOver

xrectGameOver=WINDOW_WIDTH/9;
yrectGameOver=WINDOW_HEIGHT/4;
longGameOver=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
hautGameOver=200;

//Ecran Victoire

xrectVictoire=WINDOW_WIDTH/9;
yrectVictoire=WINDOW_HEIGHT/3;
longVictoire=WINDOW_WIDTH-((WINDOW_WIDTH/9)*2);
hautVictoire=200;
PauseGame=1;                   //Si différent de 1 met le jeu en pause


}


/*-----------------------------------------BALLE-----------------------------------------*/


void rebondBall(){              //Rebond de la balle sur la fenetre 

    if (ballx >= WINDOW_WIDTH-rayonBall)        //Rebond largeur
        {vitesseX = vitesseX*(-1);}
    if (ballx <= rayonBall) 
        {vitesseX = vitesseX*(-1);}

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

void drawBall(){                //Dessin de la ball
    changeColor(255, 255, 255);
    drawCircle(ballx,bally,rayonBall);  //Dessin de la ball
    ballx=ballx+ vitesseX;      //Déplacement de la balle largeur
    bally=bally+ vitesseY;      //Déplacement de la balle hauteur
}

void drawBalltraine(){                //Dessin de la traine
    changeColor(100, 255, 100);
    drawCircle(ball2x,ball2y,rayonBall2);  //Dessin de la traine
    ball2x=ball2x+vitesseX;      //Déplacement de la balle largeur
    ball2y=ball2y+vitesseY;      //Déplacement de la balle hauteur
        if(vitesseX<0){
            vitesse2X=vitesse2X*(-1);
        }

        if(vitesseY<0){
            vitesse2Y=vitesse2Y*(-1);
        }

}

/*-----------------------------------------BARRE-----------------------------------------*/


void drawBarre(){               //Dessin de la barre

    if(tentative==1){
        changeColor(114, 246, 82);
    }
    else if(tentative==2){
        changeColor(246, 246, 82);
    }
    else if(tentative==3){
        changeColor(246, 82, 82);
    }
    drawRect(xBarre,yBarre,longBarre,hauteurBarre);

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
   
void drawBrick(){             //Dessin des briques
    changeColor(255, 255, 0);

    for(int i=0;i<nbcolonne;i++){               //Correspond aux colonnes de mes briques
        for (int j=0; j<nbligne;j++){           //Correspond aux lignes de mes briques
            if (viebrique[i][j]==1){
                xBrique=xEcart+(longBrique+espaceBrique)*i;
                yBrique=yEcart+(hauteurBrique+espaceBrique)*j;
                drawRect(xBrique,yBrique,longBrique,hauteurBrique);

                             //Rebond de la balle sur les Briques
                            
                    //bas
                
                if(((bally<=yBrique+hauteurBrique+rayonBall) && (bally>yBrique+hauteurBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY<0)){
                    vitesseY=vitesseY*(-1); 
                    viebrique[i][j]=0;
                    briqueTouche=briqueTouche+1;
                }

                    //haut

                else if(((bally>=yBrique-rayonBall) && (bally<yBrique)) &&
                    ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY>0)){
                    vitesseY=vitesseY*(-1);
                    viebrique[i][j]=0;
                    briqueTouche=briqueTouche+1;
                }

                    //gauche

                if((ballx>=xBrique-rayonBall) && (ballx<xBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX>0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=0;
                    briqueTouche=briqueTouche+1;
                }
                    //droite

                else if((ballx<=xBrique+longBrique+rayonBall) && (ballx>xBrique+longBrique) &&
                    ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX<0)){
                    vitesseX=vitesseX*(-1);
                    viebrique[i][j]=0; 
                    briqueTouche=briqueTouche+1;
                }
                
            }
        }
    }
}

/*-----------------------------------------GameOver-----------------------------------------*/

void drawGameOver(){
    changeColor(243,32,55);
    drawRect(xrectGameOver,yrectGameOver,longGameOver,hautGameOver);
    //PauseGame=PauseGame-1;
    //printf("Nombre de briques touché%d ",briqueTouche)


}

/*-----------------------------------------Victoire-----------------------------------------*/

void drawVictoire(){
    changeColor(16,62,214);
    drawRect(xrectVictoire,yrectVictoire,longVictoire,hautVictoire);
    //PauseGame=PauseGame-1;
    //printf("Nombre de briques touché%d ",briqueTouche);
}


/*-----------------------------------------Jeu-----------------------------------------*/

void drawGame(){
    /* Ici je dessine mon jeu
     * exemple position x, y modifiés dans KeyPressed() et utilisés pour
     * pouvoir deplacer la figure à chaque boucle de gameLoop()
     */
    clear();

        if((tentative<=nbvie) && (PauseGame==1)){
            drawBrick();    
            drawBall();
            drawBalltraine();
            drawBarre();
            rebondBall();
            rebondBarre ();
        }

        if((tentative>nbvie) && (briqueTouche<nbBrique)){
            drawGameOver();
        }

        if(briqueTouche==nbBrique){
            drawVictoire();
            
        }
        if (PauseGame==1){
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