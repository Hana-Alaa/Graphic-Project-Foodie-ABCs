#include <graphics.h>
#include <conio.h>  
#include <stdio.h>
#include <dos.h>
// #include <stdlib.h>
#include <mouse_r.h>
#include <bitmap.h>
#include <ctype.h>   // for toupper and tolower

void displayMainScreen();
void draw3DText(char text[], int x, int y, int depth, int color, int fontSize);
void displayBar();
void displayImageAndWord(char imagePath[], char word[], int xImage, int yImage, int xText , int yText);
void displayInfo();

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // initialize mouse
    initmouse();
    showmouse();
    int x1, y1, b;
    
    displayMainScreen();

    getch();
    closegraph();
    return 0;
}

// Function for the Main Screen
void displayMainScreen() {
    int x1, y1, b;

    // Draw the entire screen in light cyan
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, getmaxx(), getmaxy());

    // Draw the start and about and exit button 
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    bar(245, 200, 395, 240);
    bar(245, 260, 395, 300);
    bar(245, 320, 395, 360);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(280, 215, "START");
    outtextxy(280, 275, "About");
    outtextxy(288, 335, "EXIT");

    outtextxy(20, 450, "Supervised by Dr: Tamer Medhat");

    // Draw the 3D text    
    draw3DText("Foodie ABCs", 55, 100, 5, 6, LIGHTCYAN);
}

// Function to draw 3D text
void draw3DText(char text[], int x, int y, int depth, int fontSize, int defaultColor) {
    int b, x1, y1;

    while (1) {
        // To change color
        for (int i = 0; i < depth; i++) {
            int color = defaultColor + i;  
            setcolor(color);
            settextstyle(DEFAULT_FONT, HORIZ_DIR, fontSize);
            outtextxy(x + i, y + i, text);
            delay(200);  // delay to control the speed of color change
        }

        // Check for mouse input
        getmouse(&b, &x1, &y1);

        // click in start button
        if (b == 1 && x1 > 245 && x1 < 395 && y1 > 200 && y1 < 240) {
            // Wait for the mouse button to be released
            while (b == 1) {
                getmouse(&b, &x1, &y1);
            }
            displayBar();
        }
        // click in about button
        else if (b == 1 && x1 > 245 && x1 < 395 && y1 > 260 && y1 < 300) {
            // Wait for the mouse button to be released
            while (b == 1) {
                getmouse(&b, &x1, &y1);
            }
            cleardevice();
            displayInfo();
        }
        // click in exit button
        else if (b == 1 && x1 > 245 && x1 < 395 && y1 > 320 && y1 < 360) {
            // Wait for the mouse button to be released
            while (b == 1) {
                getmouse(&b, &x1, &y1);
            }
            cleardevice();
            closegraph(); 
            exit(0);       // Exit the program
        }
    }
}

// Function to display bars with letters
void displayBar(){
    cleardevice();
    // Some initialize for bar
    int x = 30, y = 10;                   // initial x and y for first bar
    int barWidth = 80, barHeight = 76;    // size for each bar 
    int b, x1, y1;

    // Draw 26 bars of letters
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        // set different color for each bar
        setfillstyle(SOLID_FILL, letter - 'A' + 1);   // SOLID_FILL --> pattren of fill , letter-'A'+1 --> color
        bar(x, y, x + barWidth, y + barHeight);

        // Draw Capital letters in bar
        if (letter == 'O') {
            setcolor(BLACK);
        }
        else {
            setcolor(WHITE);
        }
        char capitalLetter[2] = { letter, '\0'};
        settextstyle(DEFAULT_FONT, 0, 3);               // (fontStyle, fontDirection, fontSize)
        outtextxy(x + 18, y + 30, capitalLetter);

        // Draw Small letters in bar
        char smallLetter[2] = { tolower(letter), '\0' };  // Convert to lowercase letter using tolower()
        outtextxy(x + 43, y + 30, smallLetter);

        x += barWidth + 20;    // Increase x for the next bar
        // To go to the next row
	if (x + barWidth >= getmaxx()) {
	    x = 30;       // put initial x again (reset x)
	    y += barHeight + 20;
	}
    }
    // Add a back button
    setfillstyle(SOLID_FILL, WHITE);   
    bar(510, 410, 610, 450);
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(530, 423, "Back");
 for(;;){
       getmouse(&b, &x1, &y1);
       settextstyle(0, 0, 1);
       if (b == 1 && x1 > 30 && x1 < 110 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\apple.bmp" , "APPLE", 170, 50, 240, 350);
       }
       if (b == 1 && x1 > 130 && x1 < 210 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\banana.bmp" , "BANANA", 190, 50, 240, 410);
       }
       if (b == 1 && x1 > 230 && x1 < 310 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\carrot.bmp" , "CARROT", 170, 50, 240, 370);
       }
       if (b == 1 && x1 > 330 && x1 < 410 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\date.bmp" , "Date", 170, 80, 260, 320);
       }
       if (b == 1 && x1 > 430 && x1 < 510 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\eggplant.bmp" , "EGGPLANT", 200, 30, 230, 380);
       }
       if (b == 1 && x1 > 530 && x1 < 610 && y1 > 10 && y1 < 86){
	  displayImageAndWord("images\\fig.bmp" , "FIG", 190, 120, 280, 350);
       }

       if (b == 1 && x1 > 30 && x1 < 110 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\grape.bmp" , "GRAPE", 185, 80, 250, 360);
       }
       if (b == 1 && x1 > 130 && x1 < 210 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\ham.bmp" , "Hamburger", 190, 80, 220, 330);
       }
       if (b == 1 && x1 > 230 && x1 < 310 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\iccream.bmp" , "Ice Cream", 190, 10, 220, 430);
       }
       if (b == 1 && x1 > 330 && x1 < 410 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\jelly.bmp" , "Jelly", 190, 100, 250, 360);
       }
       if (b == 1 && x1 > 430 && x1 < 510 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\ketchub.bmp" , "Ketchub", 190, 5, 240, 440);
       }
       if (b == 1 && x1 > 530 && x1 < 610 && y1 > 106 && y1 < 182){
	  displayImageAndWord("images\\lemon.bmp" , "Lemon", 170, 80, 255, 340);
       }

       if (b == 1 && x1 > 30 && x1 < 110 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\mango3.bmp" , "Mango", 190, 30, 260, 370);
       }
       if (b == 1 && x1 > 130 && x1 < 210 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\nut.bmp" , "Nuts", 170, 130, 265, 320);
       }
       if (b == 1 && x1 > 230 && x1 < 310 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\orange.bmp" , "Orange", 180, 80, 250, 345);
       }
       if (b == 1 && x1 > 330 && x1 < 410 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\pear.bmp" , "Pear", 175, 20, 265, 400);
       }
       if (b == 1 && x1 > 430 && x1 < 510 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\quinc.bmp" , "Quince", 175, 30, 240, 385);
       }
       if (b == 1 && x1 > 530 && x1 < 610 && y1 > 202 && y1 < 278){
	  displayImageAndWord("images\\rase.bmp" , "Raspberry", 200, 160, 215, 320);
       }

       if (b == 1 && x1 > 30 && x1 < 110 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\straw.bmp" , "Strawberry", 190, 50, 200, 385);
       }
       if (b == 1 && x1 > 130 && x1 < 210 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\tomato.bmp" , "Tomato", 180, 80, 240, 380);
       }
       if (b == 1 && x1 > 230 && x1 < 310 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\ugli.bmp" , "Ugli Fruit", 180, 100, 200, 380);
       }
       if (b == 1 && x1 > 330 && x1 < 410 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\vege.bmp" , "Vegetables", 190, 100, 205, 380);
       }
       if (b == 1 && x1 > 430 && x1 < 510 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\water.bmp" , "Watermelon", 180, 100, 200, 380);
       }
      if (b == 1 && x1 > 530 && x1 < 610 && y1 > 298 && y1 < 374){
	  displayImageAndWord("images\\ximenia.bmp" , "Ximenia", 180, 140, 240, 330);
       }

      if (b == 1 && x1 > 30 && x1 < 110 && y1 > 394 && y1 < 470){
	  displayImageAndWord("images\\yellow.bmp" , "Yellow Watermelon", 150, 100, 120, 370);
       }
      if (b == 1 && x1 > 130 && x1 < 210 && y1 > 394 && y1 < 470){
	  displayImageAndWord("images\\z.bmp" , "Zucchini", 180, 30, 220, 375);
       }
      if (b == 1 && x1 > 510 && x1 < 610 && y1 > 410 && y1 < 450){
	  cleardevice();
	  displayMainScreen();
       }
    }
}

void displayImageAndWord(char imagePath[], char word[], int xImage, int yImage, int xText , int yText  ) {
  cleardevice(); 

  setfillstyle(SOLID_FILL, WHITE);
  bar(0, 0, getmaxx(), getmaxy());

  // Display the image
  displaybitmap(xImage, yImage, imagePath);

  // Display the Word
  setcolor(0);
  settextstyle(0, 0, 3);
  outtextxy(xText, yText, word);

  // Add a back button
  setfillstyle(SOLID_FILL, WHITE);
  rectangle(20, 20, 120, 60);
  floodfill(70, 40, WHITE);
  setcolor(BLACK);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
  outtextxy(40, 34, "Back");

  // Wait for a mouse click
  int x1, y1, b;

  for(;;){
       getmouse(&b, &x1, &y1);
       if (b == 1 && x1 > 20 && x1 < 120 && y1 > 20 && y1 < 60) {
	   // Wait for the mouse button to be released
	   while (b == 1) {
		getmouse(&b, &x1, &y1);
	   }
	   break; // Break the loop when the back button is clicked
	}
  }

cleardevice();
displayBar(); // Redraw the bar screen
}

void displayInfo() {
    cleardevice();
    int b, x1, y1;

    // Draw the entire screen in light cyan
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, getmaxx(), getmaxy());

    // Draw the header title
    setcolor(LIGHTMAGENTA);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(200, 80, "POWER TEAM");

    // Draw team members
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(250, 150, "Hana Alaa");
    outtextxy(230, 180, "Rahma Othman");
    outtextxy(235, 210, "Sara Khaled");
    outtextxy(235, 240, "Salma Sameh");
    outtextxy(240, 270, "Ahmed Alaa");
    outtextxy(235, 300, "Mohamed Gad");

    // Draw the Back button
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
    bar(250, 350, 395, 390);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(292, 365, "Back");

    for(;;){
	getmouse(&b, &x1, &y1);
	if (b == 1 && x1 > 250 && x1 < 395 && y1 > 350 && y1 < 390){
	cleardevice();
	displayMainScreen();
       }
    }
}