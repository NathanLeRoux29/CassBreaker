#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 600
#define FPS 60
#define tabMax 6


/* Variable */


int ballx;
int bally;
int rayonBall;
int vitesseX;
int vitesseY;

int xBarre;
int yBarre;
;
int longBarre;
int hauteurBarre;
int deplTouche;


int xBrique;
int yBrique;
int xEcart;
int yEcart;
int longBrique;
int hauteurBrique;
int espaceBrique;
int nbcolonne;
int nbligne;
int nbbrique;
int tab [13];
int j;


/*Initialisation du jeu*/

void init_game(){
    //mettre votre code d'initialisation ici

ballx=WINDOW_WIDTH/2;
bally=WINDOW_HEIGHT-100;
rayonBall=10;
vitesseX = 3;
vitesseY = -5;

xBarre = 300;
yBarre = WINDOW_HEIGHT-50;

longBarre = 100;
hauteurBarre = 10;
deplTouche = 20;


xBrique;
yBrique;
xEcart = 27;
yEcart = 20;
longBrique = 70;
hauteurBrique = 50;
espaceBrique = 5;
nbcolonne = 6 ;
nbligne = 4 ;
nbbrique = nbligne*nbcolonne;


}


/*BALLE*/

void rebondBall(){
    if (ballx >= WINDOW_WIDTH-rayonBall){
    vitesseX = vitesseX*(-1);}
    if (ballx <= rayonBall) 
    {vitesseX = vitesseX*(-1);}

    if (bally >= WINDOW_HEIGHT-rayonBall)
    {vitesseY = vitesseY*(-1);}
void drawBall(){
    drawCircle(ballx,bally,rayonBall);
    ballx=ballx+ vitesseX;
    bally=bally+ vitesseY;
}

/*BARRE*/

void drawBarre(){
    drawRect(xBarre,yBarre,longBarre,hauteu
}

/*BARRE*/

void drawBarre(){
    drawRect(xBarre,yBarre,longBarre,hauteurBarre);
}

void rebondBarre (){
   
    if(((ballx >= xBarre) && (ballx <= xBarre+longBarre)) && (bally >= yBarre))
    {vitesseY= vitesseY*(-1);}

}

/*Brique*/

void rebondBrique (){
    
        //bas
        if(((bally<=yBrique+hauteurBrique+rayonBall) && (bally>yBrique+hauteurBrique)) &&
        ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY<0)){
            vitesseY=vitesseY*(-1); 
            (tab[j]=0);
        }

        //haut
        else if(((bally>=yBrique-rayonBall) && (bally<yBrique)) &&
        ((ballx<=xBrique+longBrique) && (ballx>=xBrique)) && (vitesseY>0)){
            vitesseY=vitesseY*(-1);
        }

        //gauche
        if((ballx>=xBrique-rayonBall) && (ballx<xBrique) &&
        ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX>0)){
            vitesseX=vitesseX*(-1);
        }

        //droite
        else if((ballx<=xBrique+longBrique+rayonBall) && (ballx>xBrique+longBrique) &&
        ((bally>=yBrique) && (bally<=yBrique+hauteurBrique)) && (vitesseX<0)){    
            vitesseX=vitesseX*(-1);
        }
   }
   


void drawBrick(){

int tableau;

        for(int i=0;i<nbcolonne;i++){      /*Correspond aux colonnes de mes briques*/
            for ( j=0; j<nbligne;j++){   /*Correspond aux lignes de mes briques*/
                xBrique=xEcart+(longBrique+espaceBrique)*i;
                yBrique=yEcart+(hauteurBrique+espaceBrique)*j;
                drawRect(xBrique,yBrique,longBrique,hauteurBrique);
                }
            rebondBrique();
        }
}


/*Jeu*/

void drawGame(){
    /* Ici je dessine mon jeu
     * exemple position x, y modifiés dans KeyPressed() et utilisés pour
     * pouvoir deplacer la figure à chaque boucle de gameLoop()
     */
    clear();
    drawBall();
    drawBarre();
    drawBrick();
    rebondBall();
    rebondBarre ();
    actualize();
    usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde
}
void KeyPressed(SDL_Keycode touche){
    /** @brief event.key.keysym.sym renvoi la touche appuyé
     *
     */
    switch (touche) {
        // Voir doc SDL_Keycode pour plus de touches https://wiki.libsdl.org/SDL_Keycode
        // ici exemple ou appuyer sur les touches Q | D modifie x (position du carré dans drawGame())
        case SDLK_q:
            //touche q appuyé
            printf("Q\n");
                if (xBarre >= 0){
                    xBarre=xBarre-deplTouche;
;}
                else;
            break;
        case SDLK_d:
            //touche d appuyé
            printf("D\n");
            if (xBarre <= WINDOW_WIDTH-longBarre){
                    xBarre=xBarre+deplTouche;}
                else;
            break;
        case SDLK_ESCAPE:
            freeAndTerminate();
            break;
        default:
            break;
    }
}
void joyButtonPressed(){
}

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