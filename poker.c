/*
 * menuu.c
 * 
 * This game has been make to show a statistics simulation of a geometric 
 * distribution on picking a card that you have chosen from a deck of 52 
 * playing card .
 * 
 * Copyright 2012 tina <tina@tina-HEL81C>
 * This is the main menu of the program when it start so it contains 
 * START GAME
 * HELP
 * OPTIONS 
 * STATISTICS OF GAME 
 * 
 */
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <math.h>
void loadHelp() ;
void nextHelp() ;
void loadExit() ;
void playGame() ;
void loadWin(int ni , int futi) ;
void loadStatistics() ;
void loadOptions() ;
void loadGame(int num ) ;
double calculateProbability(int d) ;
void mainMenu() ;
int main(int argc, char **argv){  
	//loadWin(7 , 5 ) ; 
	mainMenu();
	return 0;
}
void loadExit(){
	SDL_Quit() ;
	exit(0) ;
	}
double calculateProbability(int d) {
	return pow((51. / 52.) ,(d-1)) * (1. / 52.) ;
}
void loadWin(int milcah , int makaza) {
/*
 * The probability follows a Geo(p) 
 * where 	p = 1/52
 * 			q = 51/52
 * hence p(enters)  =  q ^ enters - 1 * p 
 * */
//	double probabilityPassing  = calculateProbability(milcah) ;
	char probb[200] ; 
	char probbnot[200] ; 
	sprintf(probb , "Probability of a success after %d trials was : %f" ,milcah , calculateProbability(milcah)) ;
	sprintf(probbnot , " was : %f" , (1. - calculateProbability(milcah)) ) ;
/*
 * *******************************************************************
 * End of the Geo() Fomulation 
 * ****************************************************
 * */
	
	SDL_Surface *screen ;
	SDL_Surface *text ;
	SDL_Color color2 = {0 , 0 , 255 } ;
	SDL_Color color = {0 , 0 , 0 } ;
	SDL_Color color1 = {255 , 255 , 255 } ;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr , "This is an error : %s " , SDL_GetError() ) ;
		SDL_Quit() ;
		exit(1) ;
		}	
	screen = SDL_SetVideoMode(1250 , 790 , 16 , SDL_FULLSCREEN) ;
//creating the color fot the windows 
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(screen->format , 255,0,0) ;
	white  = SDL_MapRGB(screen->format , 255,255,255) ;
	brown  = SDL_MapRGB(screen->format , 120,0,0) ;
	green  = SDL_MapRGB(screen->format , 0,255,0) ;
	blue  = SDL_MapRGB(screen->format , 0,0,255) ;		
	SDL_FillRect(screen , NULL ,brown) ;
	SDL_Flip(screen) ;
	TTF_Init() ;
	TTF_Font *font ;
	char textWinEnter[20] ; 
	char textWinCard[20] ; 
	sprintf(textWinEnter , "%d" , milcah) ;
	sprintf(textWinCard  , "%d" , makaza) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 100 ) ;
	text  = TTF_RenderText_Blended(font , "You won " , color2) ;
	SDL_Rect textposn ; 
	textposn.x = 100 ; 
	textposn.y = 20 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 40 ) ;
	text  = TTF_RenderText_Blended(font , "The probability of getting it correct when you failed to get it ", color) ;
	textposn.x = 80 ; 
	textposn.y = 300 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , probbnot , color) ;
	textposn.x = 380 ; 
	textposn.y = 350 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , probb , color) ;
	textposn.x = 80 ; 
	textposn.y = 400 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 80 ) ;
	text  = TTF_RenderText_Blended(font , "Press f2 to play again" , color1) ;	
	textposn.x = 100 ; 
	textposn.y = 500 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	SDL_Flip(screen) ;
	while (1){
		SDL_Event event ;
		SDL_WaitEvent(&event) ;
		
		if (event.type == SDL_QUIT){
			break ;
			}
		else if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE){
				mainMenu() ; 
			}
			else if (event.key.keysym.sym == SDLK_SPACE){
				break ; 
			}
			else if (event.key.keysym.sym == SDLK_F2){
				playGame() ;
				}
			
			}		
		}
	}
void playGame(){
	//this.showTime() ;
	SDL_Event evnt ;
	SDL_Color colr ={0 ,0 ,0};
	SDL_Surface *screen ;
	SDL_Surface *txts ;
	SDL_Surface *backnext ;
	SDL_Surface *movements ;
	SDL_Surface *image ;
	SDL_Surface *active ;
	TTF_Init() ;
	TTF_Font *fontz ;
	TTF_Font *fonts ;
	SDL_Init(SDL_INIT_VIDEO) ;
	screen = SDL_SetVideoMode(670 , 677 , 16 , SDL_HWSURFACE) ;
	fontz = TTF_OpenFont("fonts/Blaklitn.ttf" , 50) ;
	fonts = TTF_OpenFont("fonts/Blaklitn.ttf" , 20) ;
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(screen->format , 255,0,0) ;
	white  = SDL_MapRGB(screen->format , 255,255,255) ;
	brown  = SDL_MapRGB(screen->format , 120,0,0) ;
	green  = SDL_MapRGB(screen->format , 0,255,0) ;
	blue  = SDL_MapRGB(screen->format , 0,0,255) ;	
	SDL_FillRect(screen , NULL ,brown) ;
//	SDL_Flip(screen) ;
//screen Help header 	
	txts = TTF_RenderText_Blended(fontz , "SELECT A CARD " ,colr) ;
	SDL_Rect txtsPosition ;
	txtsPosition.x = 150 ; 
	txtsPosition.y = 65 ;
	SDL_BlitSurface(txts, NULL , screen , &txtsPosition );
	SDL_Flip(screen) ;	
	image  = IMG_Load("cards/back.PNG") ;
	active  = IMG_Load("cards/active.PNG") ;
	SDL_Rect actposn ; 
	SDL_Rect imagePosition ;
	imagePosition.x = 200 ; 
	imagePosition.y = 250 ;
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
	image  = IMG_Load("cards/2l.PNG") ;
	imagePosition.x = 400 ; 
	imagePosition.y = 250 ;
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
	SDL_Flip(screen) ;
	
//.............................main & next.....................................

	backnext = SDL_CreateRGBSurface(SDL_HWSURFACE, 250 ,50,32,0,0,0,0) ;
	SDL_FillRect(backnext , NULL , white) ;
	SDL_Rect backnextPosition ;
//load on position at which the buttons will be at  
	backnextPosition.y = 600 ;
//exit to main menu button
	backnextPosition.x = 40 ; 
	SDL_BlitSurface(backnext, NULL , screen , &backnextPosition );
//next text of help button
	backnextPosition.x = 40 + 220 +120; 
	SDL_BlitSurface(backnext, NULL , screen , &backnextPosition );
	SDL_Flip(screen) ;
	int control = 0 ;
//this the mover surface 
	movements = SDL_CreateRGBSurface(SDL_HWSURFACE, 250 ,50,32,0,0,0,0) ;
	SDL_FillRect(movements , NULL , green) ;
	SDL_Rect movementsPosition ;
//load on position at which the buttons will be at  
	movementsPosition.y = 600 ;
	movementsPosition.x = 40 ; 
	SDL_BlitSurface(movements, NULL , screen , &movementsPosition );
	SDL_Flip(screen) ;
	int taken =0 ;
	int change = 0 ;
	int card  = 1 ;
	int activechange = 0 ;
	int changeCards = 0 ;
	char *cname = "" ;
	while (1) {
		SDL_WaitEvent(&evnt) ;
		if (evnt.type ==SDL_QUIT) {
			break ;
			}
		else if (evnt.type == SDL_KEYDOWN){
			if (evnt.key.keysym.sym == SDLK_ESCAPE){
				break ; 
				}
			else if (evnt.key.keysym.sym == SDLK_RIGHT ) {
					if (changeCards == 0){
						if (taken ==  0){
									movementsPosition.x  += 220 + 120;
									backnextPosition.x = 40  ; 
								if (movementsPosition.x > 40+ 220 +120) {
									movementsPosition.x = 220 +40 +120 ;
									}
									control = backnextPosition.x;
							}
						else {
							control = 200 ;
							}
					}
					else if (changeCards == 1){
						//printf("This is whre the cards are changed \n ") ;
								card ++ ;
								switch(card){
									case 1 :
										image  = IMG_Load("card/2d.PNG") ;
										break ;
									case 2 :
										 image  = IMG_Load("card/3l.PNG") ;
										break ;
									case 3 :
										 image  = IMG_Load("card/5d.PNG") ;
										break ;
									case 4 :
										 image  = IMG_Load("card/6l.PNG") ;
										break ;
									case 5 :
										 image  = IMG_Load("card/8d.PNG") ;
										break ;
									case 6 :
										 image  = IMG_Load("card/jd.PNG") ;
										break ;
									case 7 :
										 image  = IMG_Load("card/kl.PNG") ;
										break ;
									case 8 :
										 image  = IMG_Load("card/qs.PNG") ;
										break ;
									case 9 :
										 image  = IMG_Load("card/ks.PNG") ;
										break ;
									case 10 :
										 image  = IMG_Load("card/jh.PNG") ;
										break ;
									case 11 :
										 image  = IMG_Load("card/Ad.PNG") ;
										break ;
									case 12 :
										 image  = IMG_Load("card/9s.PNG") ;
										break ;
									case 13 :
										 image  = IMG_Load("card/8h.PNG") ;
										break ;
									case 14 :
										 image  = IMG_Load("card/6s.PNG") ;
										break ;
									case 15 :
										 image  = IMG_Load("card/5h.PNG") ;
										break ;
									case 16 :
										 image  = IMG_Load("card/3s.PNG") ;
										break ;
									case 17 :
										 image  = IMG_Load("card/2h.PNG") ;
										break ;
									case 18 :
										 image  = IMG_Load("card/2l.PNG") ;
										break ;
									case 19 :
										 image  = IMG_Load("card/4d.PNG") ;
										break ;
									case 20 :
										 image  = IMG_Load("card/5l.PNG") ;
										break ;
									case 21 :
										 image  = IMG_Load("card/7d.PNG") ;
										break ;
									case 22 :
										 image  = IMG_Load("card/8l.PNG") ;
										break ;
									case 23 :
										 image  = IMG_Load("card/10d.PNG") ;
										break ;
									case 24 :
										 image  = IMG_Load("card/Ah.PNG") ;
										break ;
									case 25 :
										 image  = IMG_Load("card/jl.PNG") ;
										break ;
									case 26 :
										 image  = IMG_Load("card/qd.PNG") ;
										break ;
									case 27 :
										 image  = IMG_Load("card/js.PNG") ;
										break ;
									case 28 :
										 image  = IMG_Load("card/Al.PNG") ;
										break ;
									case 29 :
										 image  = IMG_Load("card/10h.PNG") ;
										break ;
									case 30 :
										 image  = IMG_Load("card/8s.PNG") ;
										break ;
									case 31 :
										 image  = IMG_Load("card/7h.PNG") ;
										break ;
									case 32 :
										 image  = IMG_Load("card/5s.PNG") ;
										break ;
									case 33 :
										 image  = IMG_Load("card/2s.PNG") ;
										break ;
									case 34 :
										 image  = IMG_Load("card/4h.PNG") ;
										break ;
									case 35 :
										 image  = IMG_Load("card/3d.PNG") ;
										break ;
									case 36 :
										 image  = IMG_Load("card/4l.PNG") ;
										break ;
									case 37 :
										 image  = IMG_Load("card/6d.PNG") ;
										break ;
									case 38 :
										 image  = IMG_Load("card/7l.PNG") ;
										break ;
									case 39 :
										 image  = IMG_Load("card/9d.PNG") ;
										break ;
									case 40 :
										 image  = IMG_Load("card/10l.PNG") ;
										break ;
									case 41 :
										 image  = IMG_Load("card/As.PNG") ;
										break ;
									case 42 :
										 image  = IMG_Load("card/kd.PNG") ;
										break ;
									case 43 :
										 image  = IMG_Load("card/qh.PNG") ;
										break ;
									case 44 :
										 image  = IMG_Load("card/ql.PNG") ;
										break ;
									case 45 :
										 image  = IMG_Load("card/kh.PNG") ;
										break ;
									case 46 :
										 image  = IMG_Load("card/10s.PNG") ;
										break ;
									case 47 :
										 image  = IMG_Load("card/qh.PNG") ;
										break ;
									case 48 :
										 image  = IMG_Load("card/7s.PNG") ;
										break ;
									case 49 :
										 image  = IMG_Load("card/6h.PNG") ;
										break ;
									case 50 :
										 image  = IMG_Load("card/4s.PNG") ;
										break ;
									case 51 :
										 image  = IMG_Load("card/3h.PNG") ;
										break ;
									case 52 :
										 image  = IMG_Load("card/9l.PNG") ;
										break ;
									default :										 
										card = 52 ; 
										break ;
								}								
								imagePosition.x = 400 ; 
								imagePosition.y = 250 ;
								SDL_BlitSurface(image, NULL , screen , &imagePosition );
								SDL_Flip(screen) ;
								printf("%d" , card) ;
						}
				}
			else if (evnt.key.keysym.sym == SDLK_UP ) {
				if (activechange == 1 ) {
					active  = IMG_Load("cards/active.PNG") ;
					}
						taken = 1 ;
						actposn.x = 200 ;
						control = 200 ; 
						actposn.y = 250 ;
						changeCards = 1 ;
						if (movementsPosition.x == 380){
							SDL_FillRect(movements , NULL , white) ;
							backnextPosition.x = 380 ;
							backnextPosition.y = 600 ;
							change = 1 ;
							}
						if(movementsPosition.x == 40) {
							SDL_FillRect(movements , NULL , white) ;
							backnextPosition.x = 40 ;
							backnextPosition.y = 600 ;
							change = 1 ;
							}				
					}
			else if (evnt.key.keysym.sym == SDLK_DOWN ) {
						
						if (change == 1 ) {
						changeCards = 0 ;
						SDL_FillRect(movements , NULL , green) ;
						taken = 0 ;
						backnextPosition.y = 600 ;
						backnextPosition.x = 40 ; 
						movementsPosition.y = 600 ;
						movementsPosition.x = 40 ; 
						control = backnextPosition.x;
						image  = IMG_Load("cards/back.PNG") ; 
						active  = IMG_Load("cards/back.PNG") ; 
						imagePosition.x = 200 ; 
						imagePosition.y = 250 ;
						SDL_BlitSurface(image, NULL , screen , &imagePosition );
						SDL_Flip(screen) ;
						activechange = 1 ;	
						}
					}
			else if (evnt.key.keysym.sym == SDLK_LEFT ) {
						if (changeCards == 0){
							if (taken == 0){	
								backnextPosition.x = 40 + 220 +120 ; 				
								movementsPosition.x  -= 340 ;  
								if (movementsPosition.x < 40 ) {
									movementsPosition.x = 40 ;
								}
								control = backnextPosition.x;
							}
							else {
							control = 200 ;
							}
						}
						else if (changeCards == 1 ){
								//printf("This is whre the cards are changed \n ") ;
								//cname = "card/" , card , ".PNG" ;
								/*the algorithm 
								 * take a number from the list of where variable card is incresing and then try to change
								 * from there
								 *   
								 * */
								card -- ;
								switch(card){
									case 1 :
										image  = IMG_Load("card/2d.PNG") ;
										break ;
									case 2 :
										 image  = IMG_Load("card/3l.PNG") ;
										break ;
									case 3 :
										 image  = IMG_Load("card/5d.PNG") ;
										break ;
									case 4 :
										 image  = IMG_Load("card/6l.PNG") ;
										break ;
									case 5 :
										 image  = IMG_Load("card/8d.PNG") ;
										break ;
									case 6 :
										 image  = IMG_Load("card/jd.PNG") ;
										break ;
									case 7 :
										 image  = IMG_Load("card/kl.PNG") ;
										break ;
									case 8 :
										 image  = IMG_Load("card/qs.PNG") ;
										break ;
									case 9 :
										 image  = IMG_Load("card/ks.PNG") ;
										break ;
									case 10 :
										 image  = IMG_Load("card/jh.PNG") ;
										break ;
									case 11 :
										 image  = IMG_Load("card/Ad.PNG") ;
										break ;
									case 12 :
										 image  = IMG_Load("card/9s.PNG") ;
										break ;
									case 13 :
										 image  = IMG_Load("card/8h.PNG") ;
										break ;
									case 14 :
										 image  = IMG_Load("card/6s.PNG") ;
										break ;
									case 15 :
										 image  = IMG_Load("card/5h.PNG") ;
										break ;
									case 16 :
										 image  = IMG_Load("card/3s.PNG") ;
										break ;
									case 17 :
										 image  = IMG_Load("card/2h.PNG") ;
										break ;
									case 18 :
										 image  = IMG_Load("card/2l.PNG") ;
										break ;
									case 19 :
										 image  = IMG_Load("card/4d.PNG") ;
										break ;
									case 20 :
										 image  = IMG_Load("card/5l.PNG") ;
										break ;
									case 21 :
										 image  = IMG_Load("card/7d.PNG") ;
										break ;
									case 22 :
										 image  = IMG_Load("card/8l.PNG") ;
										break ;
									case 23 :
										 image  = IMG_Load("card/10d.PNG") ;
										break ;
									case 24 :
										 image  = IMG_Load("card/Ah.PNG") ;
										break ;
									case 25 :
										 image  = IMG_Load("card/jl.PNG") ;
										break ;
									case 26 :
										 image  = IMG_Load("card/qd.PNG") ;
										break ;
									case 27 :
										 image  = IMG_Load("card/js.PNG") ;
										break ;
									case 28 :
										 image  = IMG_Load("card/Al.PNG") ;
										break ;
									case 29 :
										 image  = IMG_Load("card/10h.PNG") ;
										break ;
									case 30 :
										 image  = IMG_Load("card/8s.PNG") ;
										break ;
									case 31 :
										 image  = IMG_Load("card/7h.PNG") ;
										break ;
									case 32 :
										 image  = IMG_Load("card/5s.PNG") ;
										break ;
									case 33 :
										 image  = IMG_Load("card/2s.PNG") ;
										break ;
									case 34 :
										 image  = IMG_Load("card/4h.PNG") ;
										break ;
									case 35 :
										 image  = IMG_Load("card/3d.PNG") ;
										break ;
									case 36 :
										 image  = IMG_Load("card/4l.PNG") ;
										break ;
									case 37 :
										 image  = IMG_Load("card/6d.PNG") ;
										break ;
									case 38 :
										 image  = IMG_Load("card/7l.PNG") ;
										break ;
									case 39 :
										 image  = IMG_Load("card/9d.PNG") ;
										break ;
									case 40 :
										 image  = IMG_Load("card/10l.PNG") ;
										break ;
									case 41 :
										 image  = IMG_Load("card/As.PNG") ;
										break ;
									case 42 :
										 image  = IMG_Load("card/kd.PNG") ;
										break ;
									case 43 :
										 image  = IMG_Load("card/qh.PNG") ;
										break ;
									case 44 :
										 image  = IMG_Load("card/ql.PNG") ;
										break ;
									case 45 :
										 image  = IMG_Load("card/kh.PNG") ;
										break ;
									case 46 :
										 image  = IMG_Load("card/10s.PNG") ;
										break ;
									case 47 :
										 image  = IMG_Load("card/qh.PNG") ;
										break ;
									case 48 :
										 image  = IMG_Load("card/7s.PNG") ;
										break ;
									case 49 :
										 image  = IMG_Load("card/6h.PNG") ;
										break ;
									case 50 :
										 image  = IMG_Load("card/4s.PNG") ;
										break ;
									case 51 :
										 image  = IMG_Load("card/3h.PNG") ;
										break ;
									case 52 :
										 image  = IMG_Load("card/9l.PNG") ;
										break ;
									default :										 
										card = 1 ; 
										break ;
								}								
								imagePosition.x = 400 ; 
								imagePosition.y = 250 ;
								SDL_BlitSurface(image, NULL , screen , &imagePosition );
								SDL_Flip(screen) ;
								printf("%d" , card) ;

							}
					
				}
			else if (evnt.key.keysym.sym == SDLK_F1){
				SDL_WM_ToggleFullScreen(screen);
				}
			else if (evnt.key.keysym.sym == SDLK_RETURN) {
						printf ("%d" , control) ;
						if (control == 380) {
							mainMenu() ;							
							}
						else if (control == 40 ) {
							loadGame(card) ;
							//printf("%d \n " , card ) ;
							}
						else if (control == 200){
							//printf("This is where the card is so we need to alternate this one \n ") ;
							changeCards = 1 ;
							} 
				}
			}		
						if (actposn.x > 0 &&actposn.y > 0  ){
							SDL_BlitSurface(active, NULL , screen , &actposn);
						}
						SDL_BlitSurface(backnext, NULL , screen , &backnextPosition );
						SDL_BlitSurface(movements, NULL , screen , &movementsPosition );
						SDL_BlitSurface(txts, NULL , screen , &txtsPosition );
						txts = TTF_RenderText_Blended(fontz , "MAIN" ,colr) ;
						txtsPosition.x = 50 +50 ; 
						txtsPosition.y =595 ;
						SDL_BlitSurface(txts, NULL , screen , &txtsPosition );
						txts = TTF_RenderText_Blended(fontz , "NEXT" ,colr) ;
						txtsPosition.x = 50 +220+180 ; 
						txtsPosition.y = 595 ;
						SDL_BlitSurface(txts, NULL , screen , &txtsPosition );
					SDL_Flip(screen) ;
		}
		SDL_Flip(screen) ;
	SDL_Quit() ;
	}
void loadHelp(){
	SDL_Event evnt ;
	SDL_Color colr ={0 ,0 ,0};
	SDL_Surface *scren ;
	SDL_Surface *txts ;
	SDL_Surface *backnext ;
	SDL_Surface *movements ;
	SDL_Surface *helptextcontainer ;
	TTF_Init() ;
	TTF_Font *fontz ;
	TTF_Font *fonts ;
	SDL_Init(SDL_INIT_VIDEO) ;
	scren = SDL_SetVideoMode(670 , 677 , 16 , SDL_HWSURFACE) ;
	fontz = TTF_OpenFont("fonts/Blaklitn.ttf" , 50) ;
	fonts = TTF_OpenFont("fonts/Blaklitn.ttf" , 20) ;
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(scren->format , 255,0,0) ;
	white  = SDL_MapRGB(scren->format , 255,255,255) ;
	brown  = SDL_MapRGB(scren->format , 120,0,0) ;
	green  = SDL_MapRGB(scren->format , 0,255,0) ;
	blue  = SDL_MapRGB(scren->format , 0,0,255) ;	
	SDL_FillRect(scren , NULL ,brown) ;
//	SDL_Flip(scren) ;
//screen Help header 	
	txts = TTF_RenderText_Blended(fontz , "Poker Game Help " ,colr) ;
	SDL_Rect txtsPosition ;
	txtsPosition.x = 150 ; 
	txtsPosition.y = 10 ;
	SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
	SDL_Flip(scren) ;
	helptextcontainer = SDL_CreateRGBSurface(SDL_HWSURFACE, 450 ,500,32,0,0,0,0) ;
	SDL_FillRect(helptextcontainer , NULL , white) ;
	SDL_Rect helptextcontainerPosition ;
//load on position one this the contaner for the help text 
	helptextcontainerPosition.x = 100 ; 
	helptextcontainerPosition.y = 80 ;
	SDL_BlitSurface(helptextcontainer, NULL , scren , &helptextcontainerPosition );
	backnext = SDL_CreateRGBSurface(SDL_HWSURFACE, 150 ,50,32,0,0,0,0) ;
	SDL_FillRect(backnext , NULL , white) ;
	SDL_Rect backnextPosition ;
//load on position at which the buttons will be at  
	backnextPosition.y = 600 ;
//exit to main menu button
	backnextPosition.x = 40 ; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
//next text of help button
	backnextPosition.x = 40 + 220 ; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
//back text button
	backnextPosition.x = 40 + 220 +220; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
	SDL_Flip(scren) ;
	int helpcontrol = 0 ;
//this the mover surface 
	movements = SDL_CreateRGBSurface(SDL_HWSURFACE, 150 ,50,32,0,0,0,0) ;
	SDL_FillRect(movements , NULL , green) ;
	SDL_Rect movementsPosition ;
//load on position at which the buttons will be at  
	movementsPosition.y = 600 ;
	movementsPosition.x = 40 ; 
	SDL_BlitSurface(movements, NULL , scren , &movementsPosition );
	SDL_Flip(scren) ;
	while (1) {
		SDL_WaitEvent(&evnt) ;
		if (evnt.type ==SDL_QUIT) {
			loadExit() ;
			break ;
			}
		else if (evnt.type == SDL_KEYDOWN){
			if (evnt.key.keysym.sym == SDLK_ESCAPE){
				helpcontrol = 40 ;
				break ; 
				}
			else if (evnt.key.keysym.sym == SDLK_RIGHT ) {
				//helpcontrol  = 2 ;					
					movementsPosition.x  += 220 ;
					backnextPosition.x = 40  ; 
				if (movementsPosition.x > 40+ 220) {
					movementsPosition.x = 220 +40 ;
					}
				}
			else if (evnt.key.keysym.sym == SDLK_LEFT ) {
					backnextPosition.x = 40 + 220 ; 				
					movementsPosition.x  -= 220 ; 
				if (movementsPosition.x < 40 ) {
					movementsPosition.x = 40 ;
					}
				}
			else if (evnt.key.keysym.sym == SDLK_F1){
				SDL_WM_ToggleFullScreen(scren);
				}
			else if (evnt.key.keysym.sym == SDLK_RETURN) {
				helpcontrol = movementsPosition.x ;
				break ;
				}
			}		

						SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
						SDL_BlitSurface(movements, NULL , scren , &movementsPosition );
						/* ............................................................................................*/					
					txts = TTF_RenderText_Blended(fonts , "How to play the Game " ,colr) ;
					txtsPosition.x = 125 ; 
					txtsPosition.y = 80 ;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "Use keyboard arrows to move up down left and" ,colr) ;
					txtsPosition.y = 80 +20 ;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "right. If you have reached an option that you" ,colr) ;
					txtsPosition.y = 80 +20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "want you hit return .When selecting a card on" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "the load game menu you use arrows to navigate" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "and then when the selected card is your choice" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "then you go to next to play the game. When the" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "main game is loaded then you need to selected" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 +20 ;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "a card by hitting the return key. If the card" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "that you have chose is correct then you win" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "screen will appear and then you press F2 to" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "play again or ESCAPE to return to the main" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "menu . The statictics will be shown on the" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "win page. If you give up on searching which" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "card is equal to the one  you have choosed" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "you  just just hit the space button to choose" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "another card or escape to  return to the" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "main menu" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					txts = TTF_RenderText_Blended(fonts , "Just as simple as that enjoy :)" ,colr) ;
					txtsPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
						//~ txts = TTF_RenderText_Blended(fonts , "The page one of the help text of the game" ,colr) ;
						//~ txtsPosition.x = 125 ; 
						//~ txtsPosition.y = 80 ;
						//~ SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
						txts = TTF_RenderText_Blended(fontz , "MAIN" ,colr) ;
						txtsPosition.x = 50 ; 
						txtsPosition.y =595 ;
						SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
						txts = TTF_RenderText_Blended(fontz , "NEXT" ,colr) ;
						txtsPosition.x = 50 +220 ; 
						txtsPosition.y = 595 ;
						SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
						txts = TTF_RenderText_Blended(fontz , "BACK" ,colr) ;
						txtsPosition.x = 50 + 220 + 220; 
						txtsPosition.y = 595 ;
						SDL_BlitSurface(txts, NULL , scren , &txtsPosition );
					SDL_Flip(scren) ;
		}
		SDL_Flip(scren) ;
		if (helpcontrol == 40) {
				mainMenu() ;
			}
		else if (helpcontrol == 260 ) {
				nextHelp() ;
			}
		else {
				mainMenu() ;
			} 
	SDL_Quit() ;
	}
void nextHelp() {	
	SDL_Event evnt ;
	SDL_Color colo = {0 , 0 , 0 } ;
	SDL_Surface *scren ;
	SDL_Surface *textin ;
	SDL_Surface *backnext ;
	SDL_Surface *movements ;
	SDL_Surface *helptextcontainer ;
	TTF_Init() ;
	SDL_Init(SDL_INIT_VIDEO) ;
	TTF_Font *font  ;
	TTF_Font *fonts  ;
	scren = SDL_SetVideoMode(670 , 677 , 16 , SDL_HWSURFACE) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 50) ;
	fonts  = TTF_OpenFont("fonts/Blaklitn.ttf" , 20) ;
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(scren->format , 255,0,0) ;
	white  = SDL_MapRGB(scren->format , 255,255,255) ;
	brown  = SDL_MapRGB(scren->format , 120,0,0) ;
	green  = SDL_MapRGB(scren->format , 0,255,0) ;
	blue  = SDL_MapRGB(scren->format , 0,0,255) ;	
	SDL_FillRect(scren , NULL ,brown) ;
	
	textin = TTF_RenderText_Blended(font , "Poker Game Help " ,colo) ;
	SDL_Rect textinPosition ;
	textinPosition.x = 150 ; 
	textinPosition.y = 10 ;
	SDL_BlitSurface(textin  , NULL  , scren , &textinPosition) ;
	SDL_Flip(scren) ;
	
	helptextcontainer = SDL_CreateRGBSurface(SDL_HWSURFACE, 450 ,500,32,0,0,0,0) ;
	SDL_FillRect(helptextcontainer , NULL , white) ;
	SDL_Rect helptextcontainerPosition ;
	//load on position one this the contaner for the help text 
	helptextcontainerPosition.x = 100 ; 
	helptextcontainerPosition.y = 80 ; //125
	SDL_BlitSurface(helptextcontainer, NULL , scren , &helptextcontainerPosition );
	backnext = SDL_CreateRGBSurface(SDL_HWSURFACE, 150 ,50,32,0,0,0,0) ;
	SDL_FillRect(backnext , NULL , white) ;
	SDL_Rect backnextPosition ;
//load on position at which the buttons will be at  
	backnextPosition.y = 600 ;
//exit to main menu button
	backnextPosition.x = 40 ; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
//next text of help button
	backnextPosition.x = 40 + 220 ; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
//back text button
	backnextPosition.x = 40 + 220 +220; 
	SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
	SDL_Flip(scren) ;
	int helpcontrol = 0 ;
//this the mover surface 
	movements = SDL_CreateRGBSurface(SDL_HWSURFACE, 150 ,50,32,0,0,0,0) ;
	SDL_FillRect(movements , NULL , green) ;
	SDL_Rect movementsPosition ;
//load on position at which the buttons will be at  
	movementsPosition.y = 600 ;
	movementsPosition.x = 40 ; 
	SDL_BlitSurface(movements, NULL , scren , &movementsPosition );
	SDL_Flip(scren) ;
	while (1) {
		SDL_WaitEvent(&evnt) ;
		if (evnt.type ==SDL_QUIT) {
			loadExit() ;
			break ;
			}
		else if (evnt.type == SDL_KEYDOWN){
			if (evnt.key.keysym.sym == SDLK_ESCAPE){
				//helpcontrol = 40 ;
				break ; 
				}
			else if (evnt.key.keysym.sym == SDLK_RIGHT ) {
					movementsPosition.x  += 220 + 220;
					backnextPosition.x =  movementsPosition.x - 440 ; 
				if (movementsPosition.x > 40 + 220 + 220) {
					movementsPosition.x = 220 + 220 +40 ;
					}
				}
			else if (evnt.key.keysym.sym == SDLK_LEFT ) {
					movementsPosition.x  -= 440  ; 
					backnextPosition.x = movementsPosition.x + 440; 				
				if (movementsPosition.x < 40 ) {
					movementsPosition.x = 40 ;
					}
				}
			else if (evnt.key.keysym.sym == SDLK_F1){
				SDL_WM_ToggleFullScreen(scren);
				}
			else if (evnt.key.keysym.sym == SDLK_RETURN) {
				printf("%d \n" ,movementsPosition.x) ;
				helpcontrol = movementsPosition.x ;
				break ;
				}
			}
					SDL_BlitSurface(backnext, NULL , scren , &backnextPosition );
					SDL_BlitSurface(movements, NULL , scren , &movementsPosition );
/* ............................................................................................*/					
					textin = TTF_RenderText_Blended(fonts , "The poker Game" ,colo) ;
					textinPosition.x = 125 ; 
					textinPosition.y = 80 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "Its a game for guesing if the card that you " ,colo) ;
					textinPosition.y = 80 +20 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "have selected is the correct one from a deck of" ,colo) ;
					textinPosition.y = 80 +20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "52 cards it can be customised for one to choose" ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "from a 20 , 10 or 5 cards on the options settings." ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "The game is an example of a statistical simulation " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "project at Nust . It simulates the probabilities " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "of winning from a deck of cards , it gives these " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 +20 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "conditional probabilities summarised on the " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "statistics link on the main menu. The probabilities" ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "are of independent events becaues the selection of" ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "one card does not affect the picking of the another." ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "The languaged used for the project is C programing." ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "Note that some GUI libraries where used also ." ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "SDL library for GUI and its own extra packages like" ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "SDL_ttf for text , and SDL_image for images .The " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "code for the game is under the terms of the " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "GNU General Public License as published by the " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(fonts , "Free Software Foundation " ,colo) ;
					textinPosition.y = 80 +20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20+ 20 + 20 + 20 + 20 + 20 + 20 + 20 + 20 +20;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
/* ............................................................................................*/
					textin = TTF_RenderText_Blended(font , "MAIN" ,colo) ;
					textinPosition.x = 50 ; 
					textinPosition.y =595 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(font , "NEXT" ,colo) ;
					textinPosition.x = 50 +220 ; 
					textinPosition.y = 595 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					textin = TTF_RenderText_Blended(font , "BACK" ,colo) ;
					textinPosition.x = 50 + 220 + 220; 
					textinPosition.y = 595 ;
					SDL_BlitSurface(textin, NULL , scren , &textinPosition );
					SDL_Flip(scren) ;
		}
		SDL_Flip(scren) ;
		if (helpcontrol == 40) {
				mainMenu() ;
			}
		else if (helpcontrol == 480 ) {
				loadHelp() ;
			}
		else {
				mainMenu() ;
			} 
	SDL_Quit() ;
	}
void loadOptions(){
	SDL_Surface *screen ;
	SDL_Surface *text ;
	SDL_Color color = {255 , 0 , 0 } ;
	SDL_Color color2 = {0 , 0 , 255 } ;
	SDL_Color color1 = {255 , 255 , 255 } ;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr , "This is an error : %s " , SDL_GetError() ) ;
		SDL_Quit() ;
		exit(1) ;
		}	
	screen = SDL_SetVideoMode(670 , 677 , 16 , SDL_HWSURFACE) ;
//creating the color fot the windows 
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(screen->format , 255,0,0) ;
	white  = SDL_MapRGB(screen->format , 255,255,255) ;
	brown  = SDL_MapRGB(screen->format , 120,0,0) ;
	green  = SDL_MapRGB(screen->format , 0,255,0) ;
	blue  = SDL_MapRGB(screen->format , 0,0,255) ;		
	SDL_FillRect(screen , NULL ,brown) ;
	SDL_Flip(screen) ;
	TTF_Init() ;
	TTF_Font *font ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 60 ) ;
	text  = TTF_RenderText_Blended(font , "Poker Game Option" , color1) ;
	SDL_Rect textposn ; 
	textposn.x = 100 ; 
	textposn.y = 100 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 30 ) ;
	text  = TTF_RenderText_Blended(font , "The Options for the poker game are Disabled. " , color) ;	
	textposn.x = 50 ; 
	textposn.y = 200 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "you can just play the game with 52 card only " , color) ;	
	textposn.x = 50 ; 
	textposn.y = 250 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "Press ESC to go back to the main menu " , color2) ;	
	textposn.x = 50 ; 
	textposn.y = 300 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	SDL_Flip(screen) ;
	while (1){
		SDL_Event event ;
		SDL_WaitEvent(&event) ;
		if (event.type == SDL_QUIT){
			break ;
			}
		else if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE){
				mainMenu() ; 
			}
			else if (event.key.keysym.sym == SDLK_F2){
				playGame() ;
				}
			
			}		
		}
	}
void loadStatistics(){
	SDL_Surface *screen ;
	SDL_Surface *text ;
	SDL_Color color = {255 , 0 , 0 } ;
	SDL_Color color2 = {0 , 0 , 255 } ;
	SDL_Color color1 = {255 , 255 , 255 } ;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr , "This is an error : %s " , SDL_GetError() ) ;
		SDL_Quit() ;
		exit(1) ;
		}	
	screen = SDL_SetVideoMode(670 , 677 , 16 , SDL_HWSURFACE) ;
//creating the color fot the windows 
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(screen->format , 255,0,0) ;
	white  = SDL_MapRGB(screen->format , 255,255,255) ;
	brown  = SDL_MapRGB(screen->format , 120,0,0) ;
	green  = SDL_MapRGB(screen->format , 0,255,0) ;
	blue  = SDL_MapRGB(screen->format , 0,0,255) ;		
	SDL_FillRect(screen , NULL ,brown) ;
	SDL_Flip(screen) ;
	TTF_Init() ;
	TTF_Font *font ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 60 ) ;
	text  = TTF_RenderText_Blended(font , "Poker Game Option" , color1) ;
	SDL_Rect textposn ; 
	textposn.x = 100 ; 
	textposn.y = 100 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 30 ) ;
	text  = TTF_RenderText_Blended(font , "Sorry there is a Saving of statistics error " , color) ;	
	textposn.x = 50 ; 
	textposn.y = 200 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "because you are not connected to our servers. " , color) ;	
	textposn.x = 50 ; 
	textposn.y = 250 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "You can just play the game it will show you the" , color) ;	
	textposn.x = 50 ; 
	textposn.y = 300 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "geometric distribution of getting the " , color) ;	
	textposn.x = 50 ; 
	textposn.y = 350 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "correct card after playing." , color) ;	
	textposn.x = 50 ; 
	textposn.y = 400 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	text  = TTF_RenderText_Blended(font , "Press ESC to go back to the main menu " , color2) ;	
	textposn.x = 50 ; 
	textposn.y = 450 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	SDL_Flip(screen) ;
	while (1){
		SDL_Event event ;
		SDL_WaitEvent(&event) ;
		if (event.type == SDL_QUIT){
			break ;
			}
		else if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE){
				mainMenu() ; 
			}
			else if (event.key.keysym.sym == SDLK_F2){
				playGame() ;
				}
			
			}		
		}
	}
void loadGame(int elizabeth){
    //int kadhi = 100 ; //2l ;
    int card = 0 ;
	int z =0;
	int win = 0 ; 
	SDL_Surface *screen ;
	SDL_Surface *text ;
	SDL_Color color = {0 , 0 , 0 } ;
	//load screen surface
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr , "This is an error : %s " , SDL_GetError() ) ;
		SDL_Quit() ;
		exit(1) ;
		}	
	screen = SDL_SetVideoMode(1250 , 790 , 16 , SDL_FULLSCREEN) ;
//creating the color fot the windows 
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(screen->format , 255,0,0) ;
	white  = SDL_MapRGB(screen->format , 255,255,255) ;
	brown  = SDL_MapRGB(screen->format , 120,0,0) ;
	green  = SDL_MapRGB(screen->format , 0,255,0) ;
	blue  = SDL_MapRGB(screen->format , 0,0,255) ;	
//end color
//end loading screen
//put color to the window brown
	SDL_FillRect(screen , NULL ,brown) ;
	SDL_Flip(screen) ;
//end the color settings on windows
//creating the other one  suraface image
	TTF_Init() ;
	TTF_Font *font ;
	font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 60 ) ;
	text  = TTF_RenderText_Blended(font , "Game 1 " , color) ;
	SDL_Rect textposn ; 
	textposn.x = 80 ; 
	textposn.y = 650 ; 
	SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
	SDL_Flip(screen) ;
	SDL_Surface *image ;
	SDL_Surface *active ;
	SDL_Surface *selected ;
	image  = IMG_Load("cards/back.PNG") ;
	active  = IMG_Load("cards/active.PNG") ;
	selected  = IMG_Load("cards/active.PNG") ;
	SDL_Rect actposn ; 
	SDL_Rect slctposn ; 
	SDL_Rect imagePosition ;

//.....................................................................
//image 1:1
	imagePosition.x = 30 ; 
	imagePosition.y = 50 ;
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of surface
//load another image 1:2
	imagePosition.x = 30 + 100  ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//load another image 1:3
	imagePosition.x = 30 + 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 +100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 2:1
//......................................................................
	imagePosition.x = 30 ; 
	imagePosition.y = 190 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//load another image 2:2
	imagePosition.x = 30 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//load another image 1:3
	imagePosition.x = 30 + 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 +100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//creating the selection div surface
//end of surface

//......................................................................

//load another image 3:1 selected cards 
	imagePosition.x =  30  ; 
	imagePosition.y = 230 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the third row first one 	
//load another image 2:2
	imagePosition.x = 30 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//load another image 1:3
	imagePosition.x = 30 + 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 +100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load				
//end of the second load

//......................................................................

//load another image 3:1 card selected 
	imagePosition.x =  30  ; 
	imagePosition.y = 220 + 250 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the third row first element
 //load another image 2:2
	imagePosition.x = 30 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load
//load another image 1:3
	imagePosition.x = 30 + 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 +100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100 + 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load 
//load another image 1:4
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the second load				

//......................................................................

//start of the fourth row first element 
	imagePosition.x =  30 +100+100+100+100 ; 
	imagePosition.y = 220 + 250 + 140 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//the four remaining cards 
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100 ; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the surface 
//the four remaining cards 
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100 +100; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the surface 
//the four remaining cards 
	imagePosition.x = 30 + 100 + 100+ 100+ 100 + 100 +100+100; 
	SDL_BlitSurface(image, NULL , screen , &imagePosition );
//end of the surface 
	SDL_Flip(screen);
	int testingvar	;
	
//......................................................................
	//~ slctposn.x = 0 ; 
	//~ slctposn.y = 0 ;
	//~ SDL_BlitSurface(selected, NULL , screen , &slctposn);
//......................................................................
//end of the second load
	actposn.x = 30 ; 
	actposn.y = 50 ;
	if (actposn.y == 220 + 250 + 140 ){
			actposn.x = 30 +100+100+100+100 ;		
		}
/* the x coodinates 
 * 1 - > 50 
 * 2 - > 190 					50 + 140 
 * 3 - > 230 + 100				190 + 140
 * 4 - > 220 + 250				330 + 140
 * 5 - > 220 + 250 + 140		470 + 140
 * */
 
 /* the y coodinates
  * 1 - >	30 																		= 30
  * 2 - >	30 + 100  																= 130
  * 3 - >	30 + 100 + 100															= 230
  * 4 - >	30 + 100 + 100 + 100													= 330
  * 5 - >	30 + 100 + 100 + 100 + 100												= 430
  * 6 - >	30 + 100 + 100 + 100 + 100 + 100										= 530
  * 7 - >	30 + 100 + 100 + 100 + 100 + 100 + 100									= 630
  * 8 - >	30 + 100 + 100 + 100 + 100 + 100 + 100 + 100							= 730
  * 9 - >	30 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100						= 830
  * 10 - >	30 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100				= 930
  * 11 - >	30 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100			= 1030
  * 12 - >	30 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100 + 100	= 1130
  * 
  * */
  if (z == 0 ){
				font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 35 ) ;
				text  = TTF_RenderText_Blended(font , "Press enter to select a card " , color) ;
				textposn.x = 850 ; 
				textposn.y = 650 ; 
				SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
				SDL_Flip(screen) ;
			}
	SDL_BlitSurface(active, NULL , screen , &actposn);
	int cardnumber = 0 ;
	int countenter  = 0 ; 
//pause the screen	
	while(1){
		int mark ; 
		SDL_Event event  ; 
		SDL_WaitEvent(&event) ;
		if (event.type == SDL_QUIT){
			break ;
			}
		else if (event.type == SDL_KEYDOWN){
			if(event.key.keysym.sym == SDLK_SPACE){
					break ;
					//playGame() ;
				}
			else if (event.key.keysym.sym == SDLK_ESCAPE){
					break ;
					//mainMenu() ;
				}
			else if(event.key.keysym.sym == SDLK_RIGHT){
					if (actposn.y == 50 ){
						if (actposn.x < 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ){
							actposn.x += 100 ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x - 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100  ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x - 100 ;
							}
					}
					else if (actposn.y == 190 ){
						if (actposn.x < 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ){
							actposn.x += 100 ;
							imagePosition.y = 190 ;
							imagePosition.x = actposn.x - 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100  ;
							imagePosition.y = 190 ;
							imagePosition.x = actposn.x - 100 ;
							}
					}
					else if (actposn.y == 230 + 100  ){
						if (actposn.x < 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ){
							actposn.x += 100 ;
							imagePosition.y = 230 + 100  ;
							imagePosition.x = actposn.x - 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100  ;
							imagePosition.y = 230 + 100  ;
							imagePosition.x = actposn.x - 100 ;
							}
					}
					else if (actposn.y == 220 + 250 ){
						if (actposn.x < 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100 ){
							actposn.x += 100 ;
							imagePosition.y = 220 + 250 ;
							imagePosition.x = actposn.x - 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100+ 100+ 100 + 100  ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x - 100 ;
							}
					}
					else if (actposn.y == 220 + 250 + 140 ){
						if (actposn.x < 30 + 100 + 100+ 100+ 100 + 100 +100+100 ){
							actposn.x += 100 ;
							imagePosition.y = 220 + 250 + 140 ;
							imagePosition.x = actposn.x - 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100+ 100+ 100 + 100 +100+100 ;
							imagePosition.y = 220 + 250 + 140 ;
							imagePosition.x = actposn.x - 100 ;
							}
					}
				} 
			else if(event.key.keysym.sym == SDLK_LEFT){
					if (actposn.y == 50 ){
						if (actposn.x > 30 ){
							actposn.x -= 100 ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x + 100 ;
						} 
						else {
							actposn.x = 30   ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x + 100 ;
							}
					}
					else if (actposn.y == 190 ){
						if (actposn.x > 30 ){
							actposn.x -= 100 ;
							imagePosition.y = 190 ;
							imagePosition.x = actposn.x + 100 ;
						} 
						else {
							actposn.x = 30  ;
							imagePosition.y = 190 ;
							imagePosition.x = actposn.x + 100 ;
							}
					}
					else if (actposn.y == 230 + 100  ){
						if (actposn.x > 30 ){
							actposn.x -= 100 ;
							imagePosition.y = 230 + 100  ;
							imagePosition.x = actposn.x + 100 ;
						} 
						else {
							actposn.x = 30   ;
							imagePosition.y = 230 + 100  ;
							imagePosition.x = actposn.x + 100 ;
							}
					}
					else if (actposn.y == 220 + 250 ){
						if (actposn.x > 30){
							actposn.x -= 100 ;
							imagePosition.y = 220 + 250 ;
							imagePosition.x = actposn.x + 100 ;
						} 
						else {
							actposn.x = 30 ;
							imagePosition.y = 50 ;
							imagePosition.x = actposn.x + 100 ;
							}
					}
					else if (actposn.y == 220 + 250 + 140 ){
						if (actposn.x > 30 +100+100+100+100 ){
							actposn.x -= 100 ;
							imagePosition.y = 220 + 250 + 140 ;
							imagePosition.x = actposn.x + 100 ;
						} 
						else {
							actposn.x = 30 + 100 + 100 + 100 + 100  ;
							imagePosition.y = 220 + 250 + 140 ;
							imagePosition.x = actposn.x + 100 ;
							}
					}
				} 
			else if(event.key.keysym.sym == SDLK_DOWN){
							switch(actposn.x){
//......................................................................1
								case 30 :
									if (actposn.y < 470){
										imagePosition.x = 30 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 30 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................2
								case 130 :
									if (actposn.y < 470){
										imagePosition.x = 130 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 130 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................3
								case 230 :
									if (actposn.y < 470){
										imagePosition.x = 230 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 230 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................4
								case 330 :
									if (actposn.y < 470 ){
										imagePosition.x = 330 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 330 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................5
								case 430 :
									if (actposn.y < 470+140){
										imagePosition.x = 430 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 430 ;
										actposn.y = 470 + 140 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................6
								case 530 :
									if (actposn.y < 470 +140){
										imagePosition.x = 530 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 530 ;
										actposn.y = 470 +140;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................7
								case 630 :
									if (actposn.y < 470 + 140 ){
										imagePosition.x = 630 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 630 ;
										actposn.y = 470 + 140 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................8
								case 730 :
									if (actposn.y < 470 + 140){
										imagePosition.x = 730 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 730 ;
										actposn.y = 470 + 140 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................9
								case 830 :
									if (actposn.y < 470){
										imagePosition.x = 830 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 830 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................10
								case 930 :
									if (actposn.y < 470){
										imagePosition.x = 930 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 930 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................11
								case 1030 :
									if (actposn.y < 470){
										imagePosition.x = 1030 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 1030 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//......................................................................12
								case 1130 :
									if (actposn.y < 470){
										imagePosition.x = 1130 ;
										actposn.y += 140 ;
										imagePosition.y = actposn.y - 140 ;										
									}
									else {
										imagePosition.x = 1130 ;
										actposn.y = 470 ;
										imagePosition.y = actposn.y - 140 ;
										}
									break ; 
//.....................................................................error
								default :
									printf("error occured ") ;
								}
				} 
			else if(event.key.keysym.sym == SDLK_UP){
							switch(actposn.x){
//......................................................................1
								case 30 :
									if (actposn.y > 50){
										imagePosition.x = 30 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 30 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................2
								case 130 :
									if (actposn.y > 50){
										imagePosition.x = 130 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 130 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................3
								case 230 :
									if (actposn.y > 50){
										imagePosition.x = 230 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 230 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................4
								case 330 :
									if (actposn.y > 50 ){
										imagePosition.x = 330 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 330 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................5
								case 430 :
									if (actposn.y > 50){
										imagePosition.x = 430 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 430 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................6
								case 530 :
									if (actposn.y > 50){
										imagePosition.x = 530 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 530 ;
										actposn.y = 50;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................7
								case 630 :
									if (actposn.y > 50 ){
										imagePosition.x = 630 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 630 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................8
								case 730 :
									if (actposn.y > 50){
										imagePosition.x = 730 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 730 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................9
								case 830 :
									if (actposn.y > 50){
										imagePosition.x = 830 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 830 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................10
								case 930 :
									if (actposn.y > 50){
										imagePosition.x = 930 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 930 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................11
								case 1030 :
									if (actposn.y > 50){
										imagePosition.x = 1030 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 1030 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//......................................................................12
								case 1130 :
									if (actposn.y > 50){
										imagePosition.x = 1130 ;
										actposn.y -= 140 ;
										imagePosition.y = actposn.y + 140 ;										
									}
									else {
										imagePosition.x = 1130 ;
										actposn.y = 50 ;
										imagePosition.y = actposn.y + 140 ;
										}
									break ; 
//.....................................................................error
								default :
									printf("error occured ") ;
								}
				} 
				else if (event.key.keysym.sym == SDLK_RETURN) {
								z = 1 ; 
								countenter ++ ;					    
//						printf(" \n x is  %d and y is %d  \n " , actposn.x , actposn.y ) ;
						if (actposn.y == 50 ){
							switch(actposn.x){
//..............................card....1.................................1

							case 30:
								selected  = IMG_Load("cards/jl.PNG") ;	//101 2h							 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card = 25;
								break ; 
//..............................card....2................................2
							case 130:
								selected  = IMG_Load("cards/4s.PNG") ;	//100 2l							 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 50 ;
								break ; 
//..............................card....3....................................3
							case 230:
								selected  = IMG_Load("cards/Ah.PNG") ; //102 2d								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 24;
								break ; 
//...............................card...4....................................4
							case 330:
								selected  = IMG_Load("cards/10d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card = 23;
								break ; 
//.................................card...5................................5
							case 430:
								selected  = IMG_Load("cards/2h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 17;
								break ; 
//..................................card...6.................................6
							case 530:
								selected  = IMG_Load("cards/2l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 18;
								break ; 
//..................................card...6.............................7
							case 630:
								selected  = IMG_Load("cards/10h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card = 29;
								break ; 
//..................................card....8..............................8
							case 730:
								selected  = IMG_Load("cards/8l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card = 22;
								break ; 
//....................................card.....9...........................9
							case 830:
								selected  = IMG_Load("cards/7d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 21;
								break ; 
//...................................card....10.............................10
							case 930:
								selected  = IMG_Load("cards/5l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 20;
								break ; 
//...................................card...11................................11
							case 1030:
								selected  = IMG_Load("cards/4d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 19;
								break ; 
//...................................card...12...........................12
							case 1130:
								selected  = IMG_Load("cards/3h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 51;
								break ; 
//....................................end................................
							default :
								break ; 
							}
							}
						else if (actposn.y == 190){
					switch(actposn.x){
//................................card..13....................................1
							case 30:
								selected  = IMG_Load("cards/qd.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 26;
								break ; 
//.................................card...14..................................2
							case 130:
								selected  = IMG_Load("cards/js.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 27;
								break ; 
//.................................card....15..............................3
							case 230:
								selected  = IMG_Load("cards/Al.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 28;
								break ; 
//..................................card....16...........................4
							case 330:
								selected  = IMG_Load("cards/8s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 30;
								break ; 
//..................................card....17................................5
							case 430:
								selected  = IMG_Load("cards/7h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 31;
								break ; 
//.................................card....18..............................6
							case 530:
								selected  = IMG_Load("cards/5s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 32;
								break ; 
//..................................card....19............................7
							case 630:
								selected  = IMG_Load("cards/2s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 33;
								break ; 
//..................................card...20..............................8
							case 730:
								selected  = IMG_Load("cards/4h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 34;
								break ; 
//...................................card...21...........................9
							case 830:
								selected  = IMG_Load("cards/5h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 16;
								break ; 
//...................................card..22.............................10
							case 930:
								selected  = IMG_Load("cards/6s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 14;
								break ; 
//..................................card....23............................11
							case 1030:
								selected  = IMG_Load("cards/8h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 13;
								break ; 
//..................................card.....24...........................12
							case 1130:
								selected  = IMG_Load("cards/9s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 12;
								break ; 
//....................................end................................
							default :
								break ; 
							}
							}
						else if (actposn.y == 330){
					switch(actposn.x){
//..................................card...25................................1
							case 30:
								selected  = IMG_Load("cards/Ad.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 11;
								break ; 
//..................................card....26............................2
							case 130:
								selected  = IMG_Load("cards/jh.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 10;
								break ; 
//......................................card...27.............................3
							case 230:
								selected  = IMG_Load("cards/ks.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 9;
								break ; 
//.................................card.....28........................4
							case 330:
								selected  = IMG_Load("cards/2d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 1;
								break ; 
//..................................card....29................................5
							case 430:
								selected  = IMG_Load("cards/3l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 2;
								break ; 
//..................................card....30................................6
							case 530:
								selected  = IMG_Load("cards/5d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 3;
								break ; 
//....................................card.....31..........................7
							case 630:
								selected  = IMG_Load("cards/6l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 4;
								break ; 
//....................................card......32........................8
							case 730:
								selected  = IMG_Load("cards/8d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 5;
								break ; 
//......................................card....33......................9
							case 830:
								selected  = IMG_Load("cards/jd.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 6;
								break ; 
//.....................................card.....34.......................10
							case 930:
								selected  = IMG_Load("cards/kl.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 7;
								break ; 
//.....................................card.....35.......................11
							case 1030:
								selected  = IMG_Load("cards/qs.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 8;
								break ; 
//......................................card.....36........................12
							case 1130:
								selected  = IMG_Load("cards/9l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 52;
								break ; 
//....................................end................................
							default :
								break ; 
							}
							}
						else if (actposn.y == 470){
							//printf("\n the position %d \n" , actposn.x) ;
						switch(actposn.x){
//.................................card...37..................................1
							case 30:
								selected  = IMG_Load("cards/3s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 16;
								break ; 
//...................................card....38.............................2
							case 130:
								selected  = IMG_Load("cards/3d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 35;
								break ; 
//....................................card...39............................3
							case 230:
								selected  = IMG_Load("cards/4l.PNG") ;
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 36;
								break ; 
//....................................card.....40.........................4
							case 330:
								selected  = IMG_Load("cards/6d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 37;
								break ; 
//....................................card.....41.........................5
							case 430:
								selected  = IMG_Load("cards/7l.PNG") ;
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 38;
								break ; 
//....................................card.......42.......................6
							case 530:
								selected  = IMG_Load("cards/9d.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 39;
								break ; 
//.....................................card.....43.........................7
							case 630:
								selected  = IMG_Load("cards/10l.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 40;
								break ; 
//.....................................card....44......................8
							case 730:
								selected  = IMG_Load("cards/As.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 41;
								break ; 
//....................................card...45..........................9
							case 830:
								selected  = IMG_Load("cards/kd.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 42;
								break ; 
//....................................card.....46.........................10
							case 930:
								selected  = IMG_Load("cards/ql.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 43;								
								break ; 
//....................................card....47...........................11
							case 1030:
								selected  = IMG_Load("cards/10s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 46 ;
								break ; 
//...................................card......48........................12
							case 1130:
								selected  = IMG_Load("cards/kh.PNG") ;
								//hk								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 45 ;
								break ; 
//....................................end................................
							default :
								break ; 
							}
							}
						else if (actposn.y == 610){
						switch(actposn.x){
//....................................card....49............................5
							case 430:
								selected  = IMG_Load("cards/ql.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 44;
								break ; 
//......................................card....50....................6
							case 530:
								selected  = IMG_Load("cards/qh.PNG") ; 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 47;
								break ; 
//...................................card.....51..............................7
							case 630:
								selected  = IMG_Load("cards/7s.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 48 ;
								break ; 
//....................................card......52............................8
							case 730:
								selected  = IMG_Load("cards/6h.PNG") ;								 
								slctposn.x = actposn.x ;
								slctposn.y = actposn.y ;
								card  = 49 ;
								break ; 
//....................................end................................
							default :
								break ; 
							}
							}
					}
			}
		SDL_BlitSurface(image, NULL , screen , &imagePosition );
		SDL_BlitSurface(active, NULL , screen , &actposn);
		if (card == elizabeth){
			win = 1 ; 
			}
		else {
			win = 0 ;
			}
		if (slctposn.x != 0 && z == 1 ){
				if (win == 1 ){
				font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 35 ) ;
				text  = TTF_RenderText_Blended(font , "Matched You won!!! " , color) ;
				textposn.x = 0 ; 
				textposn.y = 0 ; 
				SDL_BlitSurface(text , NULL , screen  ,&textposn) ;			
				loadWin(countenter , elizabeth) ;
				break ;
				}
				else if (win == 0){
				font  = TTF_OpenFont("fonts/Blaklitn.ttf" , 35 ) ;
				text  = TTF_RenderText_Blended(font , "Not matched " , color) ;
				textposn.x = 930 ; 
				textposn.y = 685 ; 
				SDL_BlitSurface(text , NULL , screen  ,&textposn) ;
				}
				SDL_BlitSurface(selected, NULL , screen , &slctposn);
			}
		SDL_Flip(screen) ;
		
	}
	
	if (testingvar == 1 ) {
				exit(0) ;
			}
	else {
				exit(0) ;
				}
	SDL_FreeSurface(image) ;
	SDL_FreeSurface(screen) ;
	atexit(SDL_Quit) ;
	}
void mainMenu(){
	TTF_Init() ;
	SDL_Surface *Menuu ;
	SDL_Surface *one  ; 
	SDL_Surface *text  ;
	TTF_Font *font ; 
	SDL_Color fontWhite = {0,0 ,0} ;
	font = TTF_OpenFont("fonts/Blaklitn.ttf" , 50) ;
	SDL_Init(SDL_INIT_VIDEO) ;
	Menuu  = SDL_SetVideoMode(677 , 700 , 16 , SDL_HWSURFACE) ;
	Uint32 brown , red , green , blue ,white ;
	red  = SDL_MapRGB(Menuu->format , 255,0,0) ;
	white  = SDL_MapRGB(Menuu->format , 255,255,255) ;
	brown  = SDL_MapRGB(Menuu->format , 120,0,0) ;
	green  = SDL_MapRGB(Menuu->format , 0,255,0) ;
	blue  = SDL_MapRGB(Menuu->format , 0,0,255) ;	
	SDL_FillRect(Menuu , NULL ,brown) ;
	SDL_Flip(Menuu) ;
								//header text 	
	text = TTF_RenderText_Blended(font , "Welcome to Poker Game " ,fontWhite) ;
	SDL_Rect textPosition ;
	textPosition.x = 80 ; 
	textPosition.y = 50 ;
	SDL_BlitSurface(text, NULL , Menuu , &textPosition );
	one = SDL_CreateRGBSurface(SDL_HWSURFACE, 400 ,80,32,0,0,0,0) ;
	SDL_FillRect(one , NULL , white) ;
	SDL_Rect onePosition ;
								//load on position one START GAME
	onePosition.x = 125 ; 
	onePosition.y = 200 ;
	SDL_BlitSurface(one, NULL , Menuu , &onePosition );
								//load on positoin two OPTIONS 
	onePosition.y = 200 + 100 ;
	SDL_BlitSurface(one, NULL , Menuu , &onePosition );
								//load on position three STATISTICS OF GAME 
	onePosition.y = 200 + 200 ;
	SDL_BlitSurface(one, NULL , Menuu , &onePosition );
								//load on posiition four  HELP
	onePosition.y = 200 + 300 ;
	SDL_BlitSurface(one, NULL , Menuu , &onePosition );
								//load on posiition four  Exit
	onePosition.y = 200 + 400 ;
	SDL_BlitSurface(one, NULL , Menuu , &onePosition );
								//second movement surface 	
	SDL_Surface *two  ;
	two  = SDL_CreateRGBSurface(SDL_HWSURFACE, 400 ,80,32,0,0,0,0) ;
	SDL_FillRect(two , NULL , green) ;
	SDL_Rect twoPosition ;
	twoPosition.x = 125 ;
	twoPosition.y = 200 ;
	SDL_BlitSurface(two, NULL , Menuu , &twoPosition );
	SDL_Flip(Menuu) ;
								//End of surface
	int control = 0 ;
	while(1){
		SDL_Event event ;
		SDL_WaitEvent(&event) ; 
		if (event.type == SDL_QUIT) {
			break ;
			}
		else if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE ){
				 break ;
				}
			else if (event.key.keysym.sym == SDLK_DOWN){
					twoPosition.y += 100 ;
					onePosition.y = twoPosition.y - 100 ;
					if (twoPosition.y > 600 ){
						twoPosition.y = 600 ;
						}
					if (onePosition.y <200) {
						onePosition.y = 200 ;
						}	
			}
			else if (event.key.keysym.sym == SDLK_UP){				
					twoPosition.y -= 100 ;
					onePosition.y = 100 + twoPosition.y ;
					if (twoPosition.y < 200 ){
						twoPosition.y = 200 ;
						}
					if (onePosition.y > 600 ){
						onePosition.y = 600 ;
						}
				}
			else if (event.key.keysym.sym == SDLK_RETURN){
								//200 loadGame control ==1 
								//300 loadOptions control ==2
								//400 loadStatistics control ==3
								//500 loadHelp control ==4
								//600 loadHelp control ==5
					if (twoPosition.y == 200){
						control  = 1 ;
						break ; 
						}
					else if (twoPosition.y == 300){
						control  = 2 ;
						break ; 
						}
					else if (twoPosition.y == 400){
						control  = 3 ;
						break ; 
						}
					else if (twoPosition.y == 500){
						control  = 4 ;
						break ; 
						}
					else if (twoPosition.y == 600){
						control  = 5 ;
						break ; 
						}
					else{
						break ; 
						}
				}
			}
			SDL_Delay(60) ;
			SDL_BlitSurface(one, NULL , Menuu , &onePosition );
			SDL_BlitSurface(two, NULL , Menuu , &twoPosition );
//Loading the text on the screen 
			text = TTF_RenderText_Blended(font , "LOAD GAME" ,fontWhite) ;
			textPosition.x = 150 ; 
			textPosition.y = 210 ;
			SDL_BlitSurface(text, NULL , Menuu , &textPosition );
			text = TTF_RenderText_Blended(font , "STATISTICS" ,fontWhite) ;
			textPosition.x = 150 ; 
			textPosition.y = 310 ;
			SDL_BlitSurface(text, NULL , Menuu , &textPosition );
			text = TTF_RenderText_Blended(font , "OPTIONS" ,fontWhite) ;
			textPosition.x = 150 ; 
			textPosition.y = 410 ;
			SDL_BlitSurface(text, NULL , Menuu , &textPosition );
			text = TTF_RenderText_Blended(font , "HELP" ,fontWhite) ;
			textPosition.x = 150 ; 
			textPosition.y = 510 ;
			SDL_BlitSurface(text, NULL , Menuu , &textPosition );
			text = TTF_RenderText_Blended(font , "EXIT" ,fontWhite) ;
			textPosition.x = 150 ; 
			textPosition.y = 610 ;
			SDL_BlitSurface(text, NULL , Menuu , &textPosition );
			SDL_Flip(Menuu) ;
		}
		switch(control){
			case 0 : 
				loadHelp() ;
				break ;
			case 1 :
				playGame() ;
				break ;
			case 2 :
				loadStatistics() ;
				break ;
			case 3 : 
				loadOptions() ;
				break ;
			case 4:
				loadHelp() ;
				break ;
			case 5:
				loadExit() ;
				break ;
			default :
				loadHelp() ;
				break ;
			
			}		
		SDL_FreeSurface(one) ;
		SDL_Quit() ;	
	}
