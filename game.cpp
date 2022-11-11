/*  Abdul Nafay 
    20I-0492
    CS G
    PROJECT*/

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<ctime>
#include<cstdlib>
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
string name1,name2,name3,name4; 
bool selected=false;
bool redtrn=false;;
bool bluetrn = false;
bool greentrn = false;
bool yeltrn = false;
bool redhouse = false;
bool bluhouse = false;
bool grehouse = false;
bool yelhouse = false;
bool killred = false;          
bool killblu = false;
bool killgre = false;
bool killyel = false;
bool rand6 = false; 
int roll1=0;
int roll2=0;
int score1=0,score2=0,score3=0,score4=0;
int plyr1score=0,plyr2score=0,plyr3score=0,plyr4score=0;
bool winred =false;
bool winblu= false;
bool wingre = false;
bool winyel = false;
bool rearrange=false;
int save1=0;
int save2=0;

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void piece (int x , int y ,int col) //for pieces on board
{

DrawCircle(x,y,10,colors[BLACK]);
DrawCircle(x,y,8,colors[WHITE]);

if(col==1)
{
DrawCircle(x,y,6,colors[DARK_RED]);
}
else if(col==2)
{
DrawCircle(x,y,6,colors[AQUA_MARINE]);
}

else if(col==3)
{
DrawCircle(x,y,6,colors[DARK_GREEN]);

}
else if(col==4)
{
DrawCircle(x,y,6,colors[YELLOW]);

}


}
void dice (int num)// for displaying dice
{
if(num==1)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (400,300,4,colors[BLACK]);
	}
else if(num==2)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (387,309,4,colors[BLACK]);
	DrawCircle (410,290,4,colors[BLACK]);
	}
else if(num==3)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (387,309,4,colors[BLACK]);
	DrawCircle (400,297,4,colors[BLACK]);
	DrawCircle (410,286,4,colors[BLACK]);
	}
else if(num==4)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (387,309,4,colors[BLACK]);
	DrawCircle (410,309,4,colors[BLACK]);
	DrawCircle (410,290,4,colors[BLACK]);
	DrawCircle (387,290,4,colors[BLACK]);
	}
else if(num==5)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (387,309,4,colors[BLACK]);
	DrawCircle (410,309,4,colors[BLACK]);
	DrawCircle (410,290,4,colors[BLACK]);
	DrawCircle (387,290,4,colors[BLACK]);
	DrawCircle (400,300,4,colors[BLACK]);
	}
else if(num==6)
	{
	DrawSquare( 375 ,275 ,50 ,colors[WHITE]);
	DrawCircle (387,315,4,colors[BLACK]);
	DrawCircle (410,315,4,colors[BLACK]);
	DrawCircle (410,285,4,colors[BLACK]);
	DrawCircle (387,285,4,colors[BLACK]);
	DrawCircle (410,300,4,colors[BLACK]);
	DrawCircle (387,300,4,colors[BLACK]);
	
	}
	
}

int k =7; // initally 7 so won't show animation at start
void turn(int num)  // for displaying dice on every turn
{
if(k<6)
	{
	dice(k);

	}
else if(k>6)
dice(num);

}




void next_turn()		// for giving turn to next player
{
if(redtrn == true)
{
redtrn = false;
bluetrn = true;
}

else if (bluetrn == true)
{
bluetrn = false;
greentrn = true;

}

else if (greentrn == true)
{
greentrn = false;
yeltrn = true;

}
else if (yeltrn == true)
{
yeltrn = false;
redtrn = true;

}

}

void score_increment(int num) /////////// to increment score when needed
{
if(redtrn)
{
score1 = score1 + num;
}
else if (bluetrn)
{
score2 = score2 +num;
}
else if(greentrn)
{
score3 = score3 +num;
}
else if (yeltrn)
{
score4 = score4+num;
}

}


void dice_menu (int number,int x ,int y )// for displaying dice
{
if(number==1)
	{
	DrawSquare( x ,y ,50 ,colors[WHITE]); // x y 
	DrawCircle (x+25,y+25,4,colors[BLACK]);
	}
else if(number==2)
	{
	DrawSquare( x ,y ,50 ,colors[WHITE]); // x // y 
	DrawCircle (x+12,y+34,4,colors[BLACK]);
	DrawCircle (x+35,y+15,4,colors[BLACK]);
	}
else if(number==3)
	{
	DrawSquare( x ,y ,50 ,colors[WHITE]);  // x// y
	DrawCircle (x+12,y+34,4,colors[BLACK]);
	DrawCircle (x+25,y+22,4,colors[BLACK]);
	DrawCircle (x+35,y+11,4,colors[BLACK]);
	}
else if(number==4)
	{	//x //y
	DrawSquare( x ,y ,50 ,colors[WHITE]);
	DrawCircle (x+12,y+34,4,colors[BLACK]);
	DrawCircle (x+35,y+34,4,colors[BLACK]);
	DrawCircle (x+35,y+15,4,colors[BLACK]);
	DrawCircle (x+12,y+15,4,colors[BLACK]);
	}
else if(number==5)
	{
	DrawSquare( x ,y ,50 ,colors[WHITE]);
	DrawCircle (x+12,y+34,4,colors[BLACK]);
	DrawCircle (x+35,y+34,4,colors[BLACK]);
	DrawCircle (x+35,y+15,4,colors[BLACK]);
	DrawCircle (x+12,y+15,4,colors[BLACK]);
	DrawCircle (x+25,y+25,4,colors[BLACK]);
	}
else if(number==6)
	{
	DrawSquare( x ,y ,50 ,colors[WHITE]);
	DrawCircle (x+12,y+40,4,colors[BLACK]);
	DrawCircle (x+35,y+40,4,colors[BLACK]);
	DrawCircle (x+35,y+10,4,colors[BLACK]);
	DrawCircle (x+12,y+10,4,colors[BLACK]);
	DrawCircle (x+35,y+25,4,colors[BLACK]);
	DrawCircle (x+12,y+25,4,colors[BLACK]);
	
	}
	
}
//const int red_out[4][2] = { {219,118},{220,172},{274,171} , {273,117} };
//const int blu_out[4][2] = { {219,418},{220,472},{274,471} , {273,417} };
//const int gre_out[4][2] = { {519,418},{520,472},{574,471} , {573,417} };
//const int yel_out[4][2] = { {519,118},{520,172},{574,171} , {573,117} };

// row represent piece number column represent x,  y, on_board_status,  bool(eligibility)
int redplyr[4][4] = {{219 ,118,0,0},{ 220, 172,0,0},{274 ,171,0,0 },{273 ,117,0,0 }};
int bluplyr[4][4] = {{219,418,0,0},{220,472,0,0}, {274 , 471 ,0,0 } ,{273,417,0,0} };
int greplyr[4][4] = {{ 519 , 418,0,0},{ 520 , 472,0,0 }, {574 , 471,0,0} ,{573,417,0,0 } };
int yelplyr[4][4] = { {519 , 118 ,0,0} , { 520 , 172 ,0,0} , {574 , 171 ,0,0} , {573,117,0,0} };

//54 because 2 diagnols
const int pos[54][2] = { {366 ,66 } ,{ 366, 99} , {366 ,132 } , {366 ,165} ,{366 ,198 } ,  {366 ,231 } ,{366,264},{333 ,264 } , { 300,264 } ,  {267 ,264 } ,   {234 , 264} ,   { 201,264 } ,{ 168,264 } , { 168,297 } , { 168,330 } , { 201 , 330 } , { 234 , 330 }  ,{ 267 , 330 } , {300, 330 } ,{ 333 , 330 }  , { 366 , 365 }, { 366 , 398 } , { 366 , 431 } , { 366 , 464 } , { 366 , 497 }, { 366 , 530 }  , { 399 ,530} , { 432 , 530 }, { 432 , 497 }, { 432 , 464 }, { 432 , 431 }, { 432 , 398 }, { 432 , 365 },{432,332},{ 465 , 332  }, { 498 , 332  }, { 531 , 332  }, {  564, 332  }, { 597 , 332  }, { 630 , 332  },{ 630 , 299  }, { 630 , 266  }, { 597 , 266  }, { 564 , 266  }, { 531 , 266  }, { 498 , 266  }, { 465 , 266  }, { 432 , 233 },  { 432 , 200  },   { 432 , 167 },  { 432 ,  134 },  { 432 , 101  },  { 432 , 66 }, { 399 , 66 } };
int piece_no; // for piece that moves 
int num = 0; // doesnot show any dice during step 
int steps =0; // count steps moved by piece
int steps1=0;
const int red_house[6][2]={{399, 99},{399,132} ,{399,165},{399,198} ,{399,231},{399,251} };
const int blu_house[6][2]={{201,297} ,{234,297},{267,297} ,{300,297},{333,297},{353,297} };
const int gre_house[6][2]={{399 ,497} ,{399,464},{399,431} ,{399,398},{399,365},{399,345} };
const int yel_house[6][2]={{597 , 299} ,{564,299},{531,299} ,{498,299},{465,299},{445,299} };
int ind=0;
int ind1=0;
int ind2=0;
int ind3=0;


void sort_score(string new_score, string new_name) ///////////////////////////////////////////to enter winner score on leaderboard if greater
{
ifstream inputfile;
inputfile.open("highscores.txt");
string *score = nullptr;
string *name = nullptr;
score = new string[10];
name = new string[10];
for(int p =0 ; p<10 ;p++)
{
inputfile>>name[p];
inputfile>>score[p];

}
inputfile.close();

if(stoi(new_score)>stoi(score[9]))
{
score[9] = new_score;
name[9]  = new_name;
}
string temp;
string temp1;
 for(int i =0 ; i <10 ; i++)
 {
     for(int j=0 ; j<9 ; j++)
     {
         if(stoi(score[j])<stoi(score[j+1]) )
         {
             temp =score[j];
             temp1 = name[j];
             score[j] = score[j+1];
             name[j] = name[j+1] ;
             score[j+1] = temp;
             name[j+1] = temp1;
             
         }
     }
     
 }
ofstream outputfile;
outputfile.open("highscores.txt");
for(int o=0 ; o<10 ; o++)
{
outputfile << name[o] << "   " << score[o] <<endl; 

}




}


void win_check() //////////////////////////////////////////to check if any colour has won the game
{
if(redtrn) {
 if( ( (redplyr[0][0] == 399) && (redplyr[0][1] == 251) ) && ( (redplyr[1][0] == 399) && (redplyr[1][1] == 251) )&&( (redplyr[2][0] == 399) && (redplyr[2][1] == 251) )&&( (redplyr[3][0] == 399) && (redplyr[3][1] == 251) )) {
 
 if(!winred){
 score1=score1+15;
 }
  winred =true;
  
   } 

}

else if (bluetrn) {
if( ( (bluplyr[0][0] == 353) && (bluplyr[0][1] == 297) ) && ( (bluplyr[1][0] == 353) && (bluplyr[1][1] == 297) )&&( (bluplyr[2][0] == 353) && (bluplyr[2][1] == 297) )&&( (bluplyr[3][0] == 353) && (bluplyr[3][1] == 297) )) { 
 if(!winblu){
 score2=score2+15;
 }
winblu =true;

 } 

}

else if (greentrn) {
if( ( (greplyr[0][0] == 399) && (greplyr[0][1] == 345) ) && ( (greplyr[1][0] == 399) && (greplyr[1][1] == 345) )&&( (greplyr[2][0] == 399) && (greplyr[2][1] == 345) )&&( (greplyr[3][0] == 399) && (greplyr[3][1] == 345) )) { 
 if(!wingre){
 score3=score3+15;
 }
wingre =true; 

} 

}
else if (yeltrn) {
if( ( (yelplyr[0][0] == 445) && (yelplyr[0][1] == 299) ) && ( (yelplyr[1][0] == 445) && (yelplyr[1][1] == 299) )&&( (yelplyr[2][0] == 445) && (yelplyr[2][1] == 299) )&&( (yelplyr[3][0] == 445) && (yelplyr[3][1] == 299) )) { 
 if(!winyel){
 score4=score4+15;
 }

winyel =true;

 } 



}
}


void kill_piece(int x1,int y1) /////////////////// to check if another piece at that point and remove it
{
const int red_out[4][2] = { {219,118},{220,172},{274,171} , {273,117} };
const int blu_out[4][2] = { {219,418},{220,472},{274,471} , {273,417} };
const int gre_out[4][2] = { {519,418},{520,472},{574,471} , {573,417} };
const int yel_out[4][2] = { {519,118},{520,172},{574,171} , {573,117} };

if(x1 == 234 && y1 == 264) {return;}
if(x1 == 432 && y1 ==134 ) {return;}
if(x1 == 366 && y1 == 464) {return;}
if(x1 == 564 && y1 == 332) {return;}
if(x1 == 366 && y1 == 99)  {return;}
if(x1 == 201 && y1 == 330) {return;}
if(x1 == 432 && y1 == 497) {return;}
if(x1 == 597 && y1 == 266) {return;}


if(redtrn){
for(int i=0 ; i<4 ; i++){

if(bluplyr[i][0] == x1 && bluplyr[i][1] == y1 )
{
killred = true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (blu_out[s][0] != bluplyr[0][0] && blu_out[s][1] != bluplyr[0][1]) && (blu_out[s][0] != bluplyr[1][0] && blu_out[s][1] != bluplyr[1][1]) && (blu_out[s][0] != bluplyr[2][0] && blu_out[s][1] != bluplyr[2][1]) && (blu_out[s][0] != bluplyr[3][0] && blu_out[s][1] != bluplyr[3][1]))
{

bluplyr[i][0] = blu_out[s][0];
bluplyr[i][1] = blu_out[s][1];
bluplyr[i][3] = 0;
if(roll1==0){
yeltrn=true;
redtrn = false;
}
return;

}
}


}
if(greplyr[i][0] == x1 && greplyr[i][1] == y1)
{
killred = true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (gre_out[s][0] != greplyr[0][0] && gre_out[s][1] != greplyr[0][1]) && (gre_out[s][0] != greplyr[1][0] && gre_out[s][1] != greplyr[1][1]) && (gre_out[s][0] != greplyr[2][0] && gre_out[s][1] != greplyr[2][1]) && (gre_out[s][0] != greplyr[3][0] && gre_out[s][1] != greplyr[3][1]))
{

greplyr[i][0] = gre_out[s][0];
greplyr[i][1] = gre_out[s][1];
greplyr[i][3] = 0;
if(roll1==0){
yeltrn=true;
redtrn = false;
}
return;
}
}
}

if(yelplyr[i][0] == x1 && yelplyr[i][1] == y1)
{
killred = true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (yel_out[s][0] != yelplyr[0][0] && yel_out[s][1] != yelplyr[0][1]) && (yel_out[s][0] != yelplyr[1][0] && yel_out[s][1] != yelplyr[1][1]) && (yel_out[s][0] != yelplyr[2][0] && yel_out[s][1] != yelplyr[2][1]) && (yel_out[s][0] != yelplyr[3][0] && yel_out[s][1] != yelplyr[3][1]))
{

yelplyr[i][0] = yel_out[s][0];
yelplyr[i][1] = yel_out[s][1];
yelplyr[i][3] = 0;
if(roll1==0){
yeltrn=true;
redtrn = false;
}
return;
}
}
}

}
}

else if(bluetrn){

for(int i=0 ; i<4 ; i++){

if(redplyr[i][0] == x1 && redplyr[i][1] == y1)
{
killblu=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (red_out[s][0] != redplyr[0][0] && red_out[s][1] != redplyr[0][1]) && (red_out[s][0] != redplyr[1][0] && red_out[s][1] != redplyr[1][1]) && (red_out[s][0] != redplyr[2][0] && red_out[s][1] != redplyr[2][1]) && (red_out[s][0] != redplyr[3][0] && red_out[s][1] != redplyr[3][1]))
{

redplyr[i][0] = red_out[s][0];
redplyr[i][1] = red_out[s][1];
redplyr[i][3] = 0;
if(roll1==0) {
redtrn=true;
bluetrn = false;
}
return;
}
}
}
if(greplyr[i][0] == x1 && greplyr[i][1] == y1)
{
killblu=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (gre_out[s][0] != greplyr[0][0] && gre_out[s][1] != greplyr[0][1]) && (gre_out[s][0] != greplyr[1][0] && gre_out[s][1] != greplyr[1][1]) && (gre_out[s][0] != greplyr[2][0] && gre_out[s][1] != greplyr[2][1]) && (gre_out[s][0] != greplyr[3][0] && gre_out[s][1] != greplyr[3][1]))
{

greplyr[i][0] = gre_out[s][0];
greplyr[i][1] = gre_out[s][1];
greplyr[i][3] = 0;
if(roll1==0) {
redtrn=true;
bluetrn = false;
}
return;
}
}
}

if(yelplyr[i][0] == x1 && yelplyr[i][1] == y1)
{
killblu=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (yel_out[s][0] != yelplyr[0][0] && yel_out[s][1] != yelplyr[0][1]) && (yel_out[s][0] != yelplyr[1][0] && yel_out[s][1] != yelplyr[1][1]) && (yel_out[s][0] != yelplyr[2][0] && yel_out[s][1] != yelplyr[2][1]) && (yel_out[s][0] != yelplyr[3][0] && yel_out[s][1] != yelplyr[3][1]))
{

yelplyr[i][0] = yel_out[s][0];
yelplyr[i][1] = yel_out[s][1];
yelplyr[i][3] = 0;
if(roll1==0) {
redtrn=true;
bluetrn = false;
}
return;
}
}
}

}


}


else if(greentrn){

for(int i=0 ; i<4 ; i++){

if(redplyr[i][0] == x1 && redplyr[i][1] == y1)
{
killgre=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (red_out[s][0] != redplyr[0][0] && red_out[s][1] != redplyr[0][1]) && (red_out[s][0] != redplyr[1][0] && red_out[s][1] != redplyr[1][1]) && (red_out[s][0] != redplyr[2][0] && red_out[s][1] != redplyr[2][1]) && (red_out[s][0] != redplyr[3][0] && red_out[s][1] != redplyr[3][1]))
{

redplyr[i][0] = red_out[s][0];
redplyr[i][1] = red_out[s][1];
redplyr[i][3] = 0;
if(roll1==0) 
{
bluetrn=true;
greentrn = false;
}
return;
}
}
}
if(bluplyr[i][0] == x1 && bluplyr[i][1] == y1)
{
killgre=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (blu_out[s][0] != bluplyr[0][0] && blu_out[s][1] != bluplyr[0][1]) && (blu_out[s][0] != bluplyr[1][0] && blu_out[s][1] != bluplyr[1][1]) && (blu_out[s][0] != bluplyr[2][0] && blu_out[s][1] != bluplyr[2][1]) && (blu_out[s][0] != bluplyr[3][0] && blu_out[s][1] != bluplyr[3][1]))
{

bluplyr[i][0] = blu_out[s][0];
bluplyr[i][1] = blu_out[s][1];
bluplyr[i][3] = 0;
if(roll1==0) 
{
bluetrn=true;
greentrn = false;
}
return;
}
}
}

if(yelplyr[i][0] == x1 && yelplyr[i][1] == y1)
{
killgre=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (yel_out[s][0] != yelplyr[0][0] && yel_out[s][1] != yelplyr[0][1]) && (yel_out[s][0] != yelplyr[1][0] && yel_out[s][1] != yelplyr[1][1]) && (yel_out[s][0] != yelplyr[2][0] && yel_out[s][1] != yelplyr[2][1]) && (yel_out[s][0] != yelplyr[3][0] && yel_out[s][1] != yelplyr[3][1]))
{

yelplyr[i][0] = yel_out[s][0];
yelplyr[i][1] = yel_out[s][1];
yelplyr[i][3] = 0;
if(roll1==0) 
{
bluetrn=true;
greentrn = false;
}
return;
}
}
}

}


}



else if(yeltrn){

for(int i=0 ; i<4 ; i++){

if(redplyr[i][0] == x1 && redplyr[i][1] == y1)
{
killyel=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (red_out[s][0] != redplyr[0][0] && red_out[s][1] != redplyr[0][1]) && (red_out[s][0] != redplyr[1][0] && red_out[s][1] != redplyr[1][1]) && (red_out[s][0] != redplyr[2][0] && red_out[s][1] != redplyr[2][1]) && (red_out[s][0] != redplyr[3][0] && red_out[s][1] != redplyr[3][1]))
{

redplyr[i][0] = red_out[s][0];
redplyr[i][1] = red_out[s][1];
redplyr[i][3] = 0;
if(roll1==0)
{
greentrn=true;
yeltrn = false;
}
return;
}
}
}
if(bluplyr[i][0] == x1 && bluplyr[i][1] == y1)
{
killyel=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (blu_out[s][0] != bluplyr[0][0] && blu_out[s][1] != bluplyr[0][1]) && (blu_out[s][0] != bluplyr[1][0] && blu_out[s][1] != bluplyr[1][1]) && (blu_out[s][0] != bluplyr[2][0] && blu_out[s][1] != bluplyr[2][1]) && (blu_out[s][0] != bluplyr[3][0] && blu_out[s][1] != bluplyr[3][1]))
{

bluplyr[i][0] = blu_out[s][0];
bluplyr[i][1] = blu_out[s][1];
bluplyr[i][3] = 0;
if(roll1==0)
{
greentrn=true;
yeltrn = false;
}
return;
}
}
}

if(greplyr[i][0] == x1 && greplyr[i][1] == y1)
{
killyel=true;
score_increment(10);
for(int s =0; s <4 ; s++)
{
if( (gre_out[s][0] != greplyr[0][0] && gre_out[s][1] != greplyr[0][1]) && (gre_out[s][0] != greplyr[1][0] && gre_out[s][1] != greplyr[1][1]) && (gre_out[s][0] != greplyr[2][0] && gre_out[s][1] != greplyr[2][1]) && (gre_out[s][0] != greplyr[3][0] && gre_out[s][1] != greplyr[3][1]))
{

greplyr[i][0] = gre_out[s][0];
greplyr[i][1] = gre_out[s][1];
greplyr[i][3] = 0;
if(roll1==0)
{
greentrn=true;
yeltrn = false;
}
return;
}
}
}

}


}

}



void move_piece(int &x , int &y ,int &z)    /////////////////for movement on path and on home paths 
{

if (!steps){return;}

if(x == 399 && y== 66 && redtrn && killred)
{

redhouse = true;


}
if(x==168 && y == 297&& bluetrn && killblu)
{
bluhouse = true;
}

if(x==399 && y==530 && greentrn && killgre)
{
grehouse=true;
}

if(x==630 && y==299 && yeltrn && killyel)
{
yelhouse=true;
}



if (redhouse){
if ((ind ==1&& steps>5) ||    (ind ==2&& steps>4) || (ind ==3&& steps>3) || (ind ==4&& steps>2)|| (ind ==5&& steps>1) ){
if (roll2==0&&roll1==0){roll1=steps;


steps=0;
}
else{roll2=steps;


steps=0;
}
rand6=false;
redhouse=false;

for(int i=0 ; i<4 ; i++)
	{
		redplyr[i][2] =0;
		}
		selected=false;
	return;

}

if (red_house[ind][1]>y){
y++;
}
else{
steps--;
score_increment(1);
ind++;
if(x==399 && y==251)
{
score_increment(15);
}
if (steps==0){redhouse=false;

		next_turn();
		ind=0;
	if(roll1!=0)//Meaning if  there is a second turn of that player 
	{
	rand6=false;
	if(redtrn) {redtrn = false;
	yeltrn =true;}
	else if(bluetrn) {bluetrn = false;
	redtrn = true;}
	else if(greentrn) {greentrn = false;
	bluetrn = true;}
	else if(yeltrn) {yeltrn =false;
	greentrn = true;}
	}
	
	
	for(int i=0 ; i<4 ; i++)
	{	

		redplyr[i][2] =0;
		}
		selected=false;
	
	
	}
}

return;

}


if (bluhouse){
if ((ind1 ==1&& steps>5) ||    (ind1 ==2&& steps>4) || (ind1 ==3&& steps>3) || (ind1 ==4&& steps>2)|| (ind1 ==5&& steps>1) ){
if (roll2==0&&roll1==0){roll1=steps;


steps=0;
}
else{roll2=steps;


steps=0;
}
rand6=false;
bluhouse=false;

for(int i=0 ; i<4 ; i++)
	{
		bluplyr[i][2] =0;
		}
		selected=false;
	return;

}

if (blu_house[ind1][0]>x){
x++;
}
else{
steps--;
score_increment(1);
ind1++;
if(x==353 && y==297)
{
score_increment(15);
}
if (steps==0){bluhouse=false;
		next_turn();
		ind1=0;
	if(roll1!=0)//Meaning if  there is a second turn of that player 
	{
	rand6=false;
	if(redtrn) {redtrn = false;
	yeltrn =true;}
	else if(bluetrn) {bluetrn = false;
	redtrn = true;}
	else if(greentrn) {greentrn = false;
	bluetrn = true;}
	else if(yeltrn) {yeltrn =false;
	greentrn = true;}
	}
	
	for(int i=0 ; i<4 ; i++)
	{	

		bluplyr[i][2] =0;
		}
		selected=false;
	
	
	}
}

return;

}


if (grehouse){
if ((ind2 ==1&& steps>5) ||    (ind2 ==2&& steps>4) || (ind2 ==3&& steps>3) || (ind2 ==4&& steps>2)|| (ind2 ==5&& steps>1) ){
if (roll2==0&&roll1==0){roll1=steps;


steps=0;
}
else{roll2=steps;

steps=0;
}
rand6=false;
grehouse=false;

for(int i=0 ; i<4 ; i++)
	{
		greplyr[i][2] =0;
		}
		selected=false;
	return;

}
if (gre_house[ind2][1]<y){
y--;
}
else{
steps--;
score_increment(1);
ind2++;
if(x==399 && y==345)
{
score_increment(15);
}
if (steps==0){grehouse=false;
		next_turn();
		ind2=0;
	if(roll1!=0)//Meaning if  there is a second turn of that player 
	{
	rand6=false;
	if(redtrn) {redtrn = false;
	yeltrn =true;}
	else if(bluetrn) {bluetrn = false;
	redtrn = true;}
	else if(greentrn) {greentrn = false;
	bluetrn = true;}
	else if(yeltrn) {yeltrn =false;
	greentrn = true;}
	}
	
	for(int i=0 ; i<4 ; i++)
	{	

		greplyr[i][2] =0;
		}
		selected=false;
	
	}
}

return;

}


if (yelhouse){

if ((ind3 ==1&& steps>5) ||    (ind3 ==2&& steps>4) || (ind3 ==3&& steps>3) || (ind3 ==4&& steps>2)|| (ind3 ==5&& steps>1) ){
if (roll2==0&&roll1==0){roll1=steps;


steps=0;
}
else{roll2=steps;


steps=0;
}
rand6=false;
yelhouse=false;

for(int i=0 ; i<4 ; i++)
	{
		yelplyr[i][2] =0;
		}
		selected=false;
	return;

}
if (yel_house[ind3][0]<x){
x--;
}
else{
steps--;
score_increment(1);
ind3++;
if(x==445 && y==299)
{
score_increment(15);
}
if (steps==0){yelhouse=false;
		next_turn();
		ind3=0;
	if(roll1!=0)//Meaning if  there is a second turn of that player 
	{
	rand6=false;
	if(redtrn) {redtrn = false;
	yeltrn =true;}
	else if(bluetrn) {bluetrn = false;
	redtrn = true;}
	else if(greentrn) {greentrn = false;
	bluetrn = true;}
	else if(yeltrn) {yeltrn =false;
	greentrn = true;}
	}
	
	for(int i=0 ; i<4 ; i++)
	{	

		yelplyr[i][2] =0;
		}
		selected=false;
	
	
	}
}

return;

}






if(x!=pos[piece_no][0] )
	{
		if(pos[piece_no][0] > x)
		{
		x++;
		}
		else{
		
		x--;
		}
	}
	
else if(y!=pos[piece_no][1] )
	{
	
	//cout<<"PositionNum "<<piece_no <<"   x   "<<y<<endl;
	
	
		if(pos[piece_no][1] > y)
		{
		
		y++;
		}
		else
		y--;
	}
	
	if(pos[piece_no][0] == x && pos[piece_no][1] == y)
	{
	
	piece_no++;
	if((x== 366 && y==264) || ( x==432 && y == 332 )) //for 2 corner blocks
	{
	steps++;
	score_increment(-1);
	}
	
		steps--;
		score_increment(1);
	if(steps==0)
	{
	
	kill_piece(x,y);
	next_turn();
	
	for(int i=0 ; i<4 ; i++)
	{	

		redplyr[i][2]=0;
		bluplyr[i][2]=0;
		greplyr[i][2]=0;
		yelplyr[i][2]=0;
		}
		selected=false;
	if(roll1!=0)//Meaning if  there is a second turn of that player 
	{
	rand6=false;
	if(redtrn) {redtrn = false;
	yeltrn =true;}
	else if(bluetrn) {bluetrn = false;
	redtrn = true;}
	else if(greentrn) {greentrn = false;
	bluetrn = true;}
	else if(yeltrn) {yeltrn =false;
	greentrn = true;}
	}
	
	}
	
	
	}
		if (piece_no==54 ){
		
		piece_no=0;
	
		}
		
	

}

// display all pieces for player
void piece_player(int ar[4][4] ,int col)
{
for(int j=0 ; j<4 ; j++)
	{
	piece ( ar[j][0] , ar[j][1] , col);
	}
}

void piece_number(int ar[4][4]) //checking which piece to move
{

for(int j=0 ; j<4 ; j++)
	{
		if(ar[j][3]==0 || ar[j][2]==0  )	//if equal to 0 piece not eligible
		{
		continue;
		}
	move_piece(ar[j][0] , ar[j][1] , ar[j][2] );

	}
win_check();             ////////////////////////////to skip turn of the winner 
if(winred && redtrn)
{

redtrn =false;
bluetrn = true;
steps =0;
roll1=0;
roll2=0;
}
if(winblu && bluetrn)
{
bluetrn =false;
greentrn = true;
steps =0;
roll1=0;
roll2=0;
}
if (wingre && greentrn)
{
greentrn = false;
yeltrn = true;
steps=0;
roll1=0;
roll2=0;
}
if (winyel && yeltrn)
{
yeltrn = false;
redtrn = true;
steps=0;
roll1=0;
roll2=0;
}

}


void choice_movement( int ar[4][4] ,int Cordx , int Cordy) /////////////////// to see where user clicked and select that piece
{
if (selected){return;}

  
		 
				for(int i =0 ; i<54 ; i++)
			{	int rang1,rang2;
				rang1 = abs(pos[i][0] - Cordx);	
				rang2 = abs(pos[i][1] - Cordy);		
				if((rang1>=0 && rang1<=20) && (rang2>=0 && rang2<= 20))
				{
	
				piece_no = i+1; //getting value for piece
			
				


				for(int j =0 ; j<4 ; j++)
				{
				if((pos[piece_no-1][0] == ar[j][0]) && (pos[piece_no-1][1] == ar[j][1]) ) 
				{ selected=true;
				


cout<<"Cord_x"<<Cordx<<"   ,  "<<Cordy<<endl;
Cordx=ar[j][0];
Cordy=ar[j][1];
		if ( (Cordx==234&&Cordy==264)||  (Cordx==432&&Cordy==134)||(Cordx==366&&Cordy==464)||(Cordx==564&&Cordy==332)||(Cordx==366&&Cordy==99)||(Cordx==201&&Cordy==330)||(Cordx==432&&Cordy==497)||(Cordx==597&&Cordy==266)){ 
		
		
		cout<<"gggggggggggggggggggggggggggggggggggggggggggggggg"<<endl;
		
		if (!rand6){
				if (roll2){
				
	
				steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){
	
			steps=roll1;
				
				cout<<"Steps ->roll1="<<roll1<<endl;
			
				roll1=0;

			}				
				}
		
		
		}
		else{

				for (int k=0;k<4;k++){

				if((pos[piece_no-1][0] == ar[k][0]) && (pos[piece_no-1][1] == ar[k][1])&& k!=j ){
			save1=k;
			save2=j;
			
			selected=false;
			rearrange=true;
					} 
				
		
			}
}

				ar[j][2] = 1;
				if (!rand6){
				if (roll2){
				if (selected){
				steps=roll2;
						}
				else{
				if (roll2%2==0){
					steps=roll2/2;
			
						}
				else{
				return;	
					}
			
				}

	


				//steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){


				if (selected){
				steps=roll1;
						}
				else{
				if (roll1%2==0){
					steps=roll1/2;
			
						}
			
				}
				cout<<"Steps ->roll1="<<roll1<<endl;
			
				roll1=0;

			}				
				}
				
				
				
				
				




				break;
				}
			
				}
				
				
				}
			}
			
			
			ind=0;
			
			for( int a=0 ; a<5 ; a++)
			{
			int rang3 , rang4;
			rang3 = abs(red_house[a][0] -Cordx);
			rang4 = abs(red_house[a][1] -Cordy);
			if((rang3>=0 && rang3<=20) && (rang4>=0 && rang4<= 20))
			{
			ind = a+1;
			
				for(int s =0 ; s<5 ; s++)
				{
				
				if((red_house[ind-1][0] == ((ar[s][0]))) && (red_house[ind-1][1] == ar[s][1]) ) 
				{
				
				 ar[s][2] = 1;
				
				if (!rand6){
				if (roll2){
				steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){
				cout<<"Steps ->roll1="<<roll1<<endl;
				steps=roll1;
				roll1=0;

			}				
				}
				
				
				
				
				
				redhouse=true;
				selected=true;
				break;
				}
			
				}
				break;
			
			}
			
			} 
			
			ind1=0;
			for( int b=0 ; b<5 ; b++)
			{
			int rang5 , rang6;
			rang5 = abs(blu_house[b][0] -Cordx);
			rang6 = abs(blu_house[b][1] -Cordy);
			if((rang5>=0 && rang5<=20) && (rang6>=0 && rang6<= 20))
			{
			ind1 = b+1;
			cout << "INDEX : " << ind1 <<endl; 
				for(int s =0 ; s<4 ; s++)
				{
				
				
				if((blu_house[ind1-1][0] == ((ar[s][0]))) && (blu_house[ind1-1][1] == ar[s][1]) ) 
				{
				
				if (!rand6){
				if (roll2){
				steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){
				cout<<"Steps ->roll1="<<roll1<<endl;
				steps=roll1;
				roll1=0;

			}				
				}
				
				
				
				 ar[s][2] = 1;
				
				bluhouse=true;
				selected=true;
				break;
				}
			
				}
				break;
			
			}
			
			} 
			ind2=0;
			for( int c=0 ; c<5 ; c++)
			{
			int rang7 , rang8;
			rang7 = abs(gre_house[c][0] -Cordx);
			rang8 = abs(gre_house[c][1] -Cordy);
			if((rang7>=0 && rang7<=20) && (rang8>=0 && rang8<= 20))
			{
			ind2 = c+1;
			
				for(int s =0 ; s<4 ; s++)
				{
				
				
				if((gre_house[ind2-1][0] == ((ar[s][0]))) && (gre_house[ind2-1][1] == ar[s][1]) ) 
				{
				if (!rand6){
				if (roll2){
				steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){
				cout<<"Steps ->roll1="<<roll1<<endl;
				steps=roll1;
				roll1=0;

			}				
				}
				
				
				
				
				ar[s][2] = 1;
			
				
				cout<<"aaaa"<<s<<endl;
				grehouse=true;
				selected=true;
				break;
				}
			
				}
				break;
			
			}
			
			} 
			
			ind3=0;
			for( int d=0 ; d<5 ; d++)
			{
			int rang9 , rang10;
			rang9 = abs(yel_house[d][0] -Cordx);
			rang10 =abs(yel_house[d][1] -Cordy);
			if((rang9>=0 && rang9<=20) && (rang10>=0 && rang10<= 20))
			{
			ind3 = d+1;
			
				for(int s =0 ; s<4 ; s++)
				{
				
				
				if((yel_house[ind3-1][0] == ((ar[s][0]))) && (yel_house[ind3-1][1] == ar[s][1]) ) 
				{
				
				if (!rand6){
				if (roll2){
				steps=roll2;
				cout<<"Steps ->roll2="<<roll2<<endl;
				roll2=0;
			}
			else if (roll2==0&& roll1!=0){
				cout<<"Steps ->roll1="<<roll1<<endl;
				steps=roll1;
				roll1=0;

			}				
				}
				
				
				
				ar[s][2] = 1;
				
				yelhouse=true;
				selected=true;
				break;
				}
			
				}
				break;
			
			}
			
			} 
			

			
			
			
			
			
}
void out_piece (int ar[4][4] ,const int ar1[4][2],  int x_out , int y_out , int x_in ,int y_in  )  ////////////// to see which piece user picks form outside when get 6
{


				for(int i =0 ; i<4 ; i++)
			{	int rang_out1,rang_out2;
				rang_out1 = abs(ar1[i][0] -x_out);	
				rang_out2 = abs(ar1[i][1] -y_out);		
				if((rang_out1>=0 && rang_out1<=20) && (rang_out2>=0 && rang_out2<= 20))
				{
				
				for(int j =0 ; j<4 ; j++)
				{
				if((ar1[i][0] == ar[j][0]) && (ar1[i][1] == ar[j][1]) ) 
				{ 
				ar[j][3] = 1;
				ar[j][0] = x_in;
				ar[j][1] = y_in;
				roll2=0;
				selected=false;
				//next_turn();
				break;
				}
			
				
					
				
				}
			}
			}
	
	




}


int rand_colour1()   /////////////////////////to generate the first  2 random colors 
{
int col = GetRandInRange(1,3);

return col;

}


int rand_colour2()           ///////////////////to generate first 3 random colors 
{
int col1 =GetRandInRange(1,4);  
return col1;
}
int rand_colour3()          /////////////////////to generate  4 random colors
{
int col2;
col2 = GetRandInRange(1,5);

return col2;
}



void starting_plyr(int highest_roll)      //////////////select the player with highest roll before game
{
if(highest_roll == 1 )
{
redtrn = true;
}
else if(highest_roll == 2)
{
greentrn = true;

}

else if(highest_roll == 3)
{
bluetrn = true;
}
else if(highest_roll == 4)
{
yeltrn = true;
}


}

void name()
{
DrawRectangle(200,368,30,200,colors[BLACK]);
DrawRectangle(200,368,150,20,colors[BLACK]);
DrawRectangle(370,368,20,170,colors[BLACK]);
DrawRectangle(370,368,100,20,colors[BLACK]);
DrawRectangle(450,368,20,170,colors[BLACK]);
DrawRectangle(485,368,20,170,colors[BLACK]);
DrawLine(494,379,603,443,20,colors[BLACK]);
DrawLine(494,524,603,443,20,colors[BLACK]);
DrawCircle(677,442,70,colors[BLACK]);
DrawCircle(677,442,60,colors[RED]);
DrawCircle(677,442,45,colors[DARK_GREEN]);
DrawCircle(677,442,30,colors[OLIVE]);
DrawCircle(677,442,15,colors[BLUE]);



}


void background ()
{
int x=80,y=70;

for (int i=0;i<14;i++){
if (i%2==0){


for(int k=0;k<15;k++){



if (k%4==1){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[NAVAJO_WHITE]);

DrawRectangle(x-80,y-122,160,100+8,colors[NAVAJO_WHITE]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[NAVAJO_WHITE]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[GRAY]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[GRAY]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[GRAY]);
	}
else if (k%4==2){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[FIREBRICK]);
DrawRectangle(x-80,y-122,160,100+8,colors[FIREBRICK]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[FIREBRICK]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[CRIMSON]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[CRIMSON]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[CRIMSON]);

}
else if(k%4==3){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[DARK_GOLDEN_ROD]);
DrawRectangle(x-80,y-122,160,100+8,colors[DARK_GOLDEN_ROD]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[DARK_GOLDEN_ROD]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[YELLOW]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[YELLOW]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[YELLOW]);
		} 
else if(k%4==0){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[ROYAL_BLUE]);
DrawRectangle(x-80,y-122,160,100+8,colors[ROYAL_BLUE]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[ROYAL_BLUE]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[NAVY]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[NAVY]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[NAVY]);
		} 

x+=160;

}
if (i%2==0){

x=0;}
else{

x=80;
}
}


else{


for(int k=0;k<15;k++){


if (k%4==3){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[NAVAJO_WHITE]);

DrawRectangle(x-80,y-122,160,100+8,colors[NAVAJO_WHITE]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[NAVAJO_WHITE]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[GRAY]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[GRAY]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[GRAY]);
	}
else if (k%4==0){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[FIREBRICK]);
DrawRectangle(x-80,y-122,160,100+8,colors[FIREBRICK]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[FIREBRICK]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[CRIMSON]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[CRIMSON]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[CRIMSON]);

}
else if(k%4==1){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[DARK_GOLDEN_ROD]);
DrawRectangle(x-80,y-122,160,100+8,colors[DARK_GOLDEN_ROD]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[DARK_GOLDEN_ROD]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[YELLOW]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[YELLOW]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[YELLOW]);
		} 
else if(k%4==2){
DrawTriangle(x+80,y-15,x,y+20,x-80,y-15,colors[ROYAL_BLUE]);
DrawRectangle(x-80,y-122,160,100+8,colors[ROYAL_BLUE]);
DrawTriangle(x-80,y-122,x+80,y-122,x,y-158,colors[ROYAL_BLUE]);
DrawLine(x-80,y-16,x-3,y-46,2,colors[NAVY]);
DrawLine(x+80,y-16,x-3,y-46,2,colors[NAVY]);
DrawLine(x-3,y-158,x-3,y-46,2,colors[NAVY]);
		} 

x+=160;

}
if (i%2==0){

x=0;}
else{

x=80;
}

}
y+=143;
}



}


/*
 * Main Canvas drawing function.
 * */
//Board *b;164
bool menu = true;
bool menu1 = false;
bool menu2 = false;
bool menu2a = false;
bool roll_menu =true;
int plyr1 = 0;
int plyr2 =0;
int plyr3 =0;
int plyr4 =0;
bool menu2b = false;
bool menu2c = false;
bool generated1 =true;
bool generated2 = true;
bool generated3 = true;
bool generated4 =true;
int num_roll1;
int num_roll2; 
int num_roll3;
int num_roll4; 
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.176/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.352/*Blue Component*/, 0.79 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(generated1) {
	
	
	num_roll1 = GetRandInRange(1,7);
	generated1 = false;
	}
	if(generated2) {
	
	
	num_roll2 = GetRandInRange(1,7);
	generated2 = false;
	}
	if(generated3) {
	
	
	num_roll3 = GetRandInRange(1,7);
	generated3 = false;
	}
	if(generated4) {
	
	
	num_roll4 = GetRandInRange(1,7);
	generated4 = false;
	}
	
	
	
		// menu implementation
	if(menu) 
	{
	 
	DrawRectangle(0,0,800,600,colors[BLACK]);
	background();
	name();
	DrawRoundRect(325,275,130,60,colors[MIDNIGHT_BLUE]);
	DrawRoundRect(300,175,200,60,colors[MIDNIGHT_BLUE]);
	DrawString (350,300,"START",colors[OLIVE]);
	DrawString (325,200,"SCOREBOARD",colors[OLIVE]);
	DrawRoundRect(325,75,130,60,colors[MIDNIGHT_BLUE]);
	DrawString (360,100,"EXIT",colors[OLIVE]);
	if(menu1)
		{
		
		DrawRectangle(0,0,800,600,colors[BLACK]);
		background();
		DrawString (350,550,"LEADER BOARD ",colors[WHITE]);
		DrawRoundRect(10,545,130,40,colors[GRAY]);
		DrawString (20,560,"RETURN",colors[BLACK]);
		ifstream inputfile;
		inputfile.open("highscores.txt");
		string *score = nullptr;
		string *name = nullptr;
		score = new string[10];
		name = new string[10];
		for(int p =0 ; p<10 ;p++)
		{
		inputfile>>name[p];
		inputfile>>score[p];

		}
		inputfile.close();
		DrawRectangle(0,0,800,600,colors[BLACK]);
		background();
		DrawRoundRect(338,545,210,30,colors[GRAY]);
		DrawString (350,550,"LEADER BOARD ",colors[BLACK]);
		DrawRoundRect(10,545,130,40,colors[GRAY]);
		DrawString (20,560,"RETURN",colors[BLACK]);
		
		DrawRoundRect(17,35,500,500,colors[GRAY]);
		
		int temp_var = 482;
		
		DrawString (40,temp_var,"NAME",colors[BLACK]);	
		DrawString (350,temp_var,"SCORE",colors[BLACK]);	
		
		for(int l =0 ; l <10 ; l++)
		{
		DrawString (40,temp_var-50,name[l],colors[BLACK]);			
		DrawString(350,temp_var-50,score[l],colors[BLACK]);
		temp_var = temp_var-40;
		}
		}
	if(menu2)
		{
		DrawRectangle(0,0,800,600,colors[BLACK]);
		background();
		DrawString (320,550,"CHOOSE NUMBER OF PLAYERS : ",colors[WHITE]);
		DrawRoundRect(10,545,130,40,colors[GRAY]);
		DrawString (20,560,"RETURN",colors[BLACK]);
		
		
		DrawRoundRect(205,390,140,40,colors[GRAY]);
		DrawRoundRect(205,340,140,40,colors[GRAY]);
		DrawRoundRect(205,290,140,40,colors[GRAY]);
		DrawString (215,400,"2 PLAYERS",colors[BLACK]);
		DrawString (215,350,"3 PLAYERS",colors[BLACK]);
		DrawString (215,300,"4 PLAYERS",colors[BLACK]);
		
		}
	if(menu2a)
	{
	DrawRectangle(0,0,800,600,colors[BLACK]);
	background();
	DrawString (320,550,"CHOOSE COLOR FOR 2 PLAYERS : ",colors[WHITE]);
	DrawRoundRect(10,545,130,40,colors[GRAY]);
	DrawString (20,560,"RETURN",colors[BLACK]);
	DrawRoundRect(205,390,150,40,colors[GRAY]);
	DrawString (215,400,"PLAYER 1: ",colors[BLACK]);
	DrawSquare (400,400,30,colors[RED]);
	DrawSquare (460,400,30,colors[GREEN]);
	DrawRoundRect(205,340,150,40,colors[GRAY]);
	DrawString (215,350,"PLAYER 2: ",colors[BLACK]);
	DrawSquare (400,350,30,colors[RED]);
	DrawSquare (460,350,30,colors[GREEN]);
	
	DrawRoundRect(620,320,150,40,colors[GRAY]);
	DrawString (635,330," RANDOM ",colors[BLACK]);
	
	
	
	}
	
	if(menu2b)
	{
	DrawRectangle(0,0,800,600,colors[BLACK]);
	background();
	DrawString (320,550,"CHOOSE COLOR FOR 3 PLAYERS : ",colors[WHITE]);
	DrawRoundRect(10,545,130,40,colors[GRAY]);
	DrawString (20,560,"RETURN",colors[BLACK]);
	DrawRoundRect(205,390,150,40,colors[GRAY]);
	DrawString (215,400,"PLAYER 1: ",colors[BLACK]);
	DrawSquare (400,400,30,colors[RED]);
	DrawSquare (460,400,30,colors[GREEN]);
	DrawSquare (520,400,30,colors[BLUE]);
	DrawRoundRect(205,340,150,40,colors[GRAY]);
	DrawString (215,350,"PLAYER 2: ",colors[BLACK]);
	DrawSquare (400,350,30,colors[RED]);
	DrawSquare (460,350,30,colors[GREEN]);
	DrawSquare (520,350,30,colors[BLUE]);
	DrawRoundRect(205,280,150,40,colors[GRAY]);
	DrawString (215,300,"PLAYER 3: ",colors[BLACK]);
	DrawSquare (400,300,30,colors[RED]);
	DrawSquare (460,300,30,colors[GREEN]);
	DrawSquare (520,300,30,colors[BLUE]);
	DrawRoundRect(620,320,150,40,colors[GRAY]);
	DrawString (635,330," RANDOM ",colors[BLACK]);
	
	}
	if(menu2c)
	{
	DrawRectangle(0,0,800,600,colors[BLACK]);
	background();
	DrawString (320,550,"CHOOSE COLOR FOR 4 PLAYERS : ",colors[WHITE]);
	DrawRoundRect(10,545,130,40,colors[GRAY]);
	DrawString (20,560,"RETURN",colors[BLACK]);
	DrawRoundRect(205,390,150,40,colors[GRAY]);
	DrawString (215,400,"PLAYER 1: ",colors[BLACK]);
	DrawSquare (400,400,30,colors[RED]);
	DrawSquare (460,400,30,colors[GREEN]);
	DrawSquare (520,400,30,colors[BLUE]);
	DrawSquare (580,400,30,colors[OLIVE]);
	DrawRoundRect(205,340,150,40,colors[GRAY]);
	DrawString (215,350,"PLAYER 2: ",colors[BLACK]);
	DrawSquare (400,350,30,colors[RED]);
	DrawSquare (460,350,30,colors[GREEN]);
	DrawSquare (520,350,30,colors[BLUE]);
	DrawSquare (580,350,30,colors[OLIVE]);
	DrawRoundRect(205,280,150,40,colors[GRAY]);
	DrawString (215,300,"PLAYER 3: ",colors[BLACK]);
	DrawSquare (400,300,30,colors[RED]);
	DrawSquare (460,300,30,colors[GREEN]);
	DrawSquare (520,300,30,colors[BLUE]);
	DrawSquare (580,300,30,colors[OLIVE]);
	DrawRoundRect(205,230,150,40,colors[GRAY]);
	DrawString (215,250,"PLAYER 4: ",colors[BLACK]);
	DrawSquare (400,250,30,colors[RED]);
	DrawSquare (460,250,30,colors[GREEN]);
	DrawSquare (520,250,30,colors[BLUE]);
	DrawSquare (580,250,30,colors[OLIVE]);
	DrawRoundRect(620,320,150,40,colors[GRAY]);
	DrawString (635,330," RANDOM ",colors[BLACK]);
	
	
	
	
	}	
	}
	
	 else if(roll_menu)
		{
		if(plyr3 == 0)
		{
		num_roll3 =0;
		}
		if(plyr4 == 0)
		{
		num_roll4=0;
		}
		
		DrawRectangle(0,0,800,600,colors[BLACK]);
		background();
		DrawRoundRect(310,545,330,40,colors[GRAY]);
		DrawString (320,550,"SELECTING HIGHEST ROLL: ",colors[WHITE]);
		DrawRoundRect(205,390,150,40,colors[GRAY]);
		DrawString (215,400,"PLAYER 1: ",colors[BLACK]);
		DrawString(370,400,"ROLL: "+to_string(num_roll1),colors[BLACK]);
		dice_menu(num_roll1, 510,410);
		DrawRoundRect(205,340,150,40,colors[GRAY]);
		DrawString (215,350,"PLAYER 2: ",colors[BLACK]);
		DrawString(370,350,"ROLL: "+to_string(num_roll2),colors[BLACK]);
		dice_menu(num_roll2, 510,345);
		
		if(plyr3!=0)
		{
		DrawRoundRect(205,280,150,40,colors[GRAY]);
		DrawString (215,300,"PLAYER 3: ",colors[BLACK]);
		DrawString(370,300,"ROLL: "+to_string(num_roll3),colors[BLACK]);
		dice_menu(num_roll3, 510,280);
		}
		if(plyr4!=0)
		{
		DrawRoundRect(205,230,150,40,colors[GRAY]);
		DrawString (215,240,"PLAYER 4: ",colors[BLACK]);
		DrawString(370,240,"ROLL: "+to_string(num_roll4),colors[BLACK]);
		dice_menu(num_roll4, 510,220);
		}
		DrawRoundRect(205,115,150,40,colors[GRAY]);
		DrawString (215,130,"   START ",colors[BLACK]);
		if((num_roll1 >= num_roll2) &&(num_roll1 >= num_roll3) && (num_roll1>=num_roll4))
		{
		starting_plyr(plyr1);
		}
		else if ((num_roll2 >= num_roll1) &&(num_roll2 >= num_roll3) && (num_roll2>=num_roll4))
		{
		starting_plyr(plyr2);
		}
		else if ((num_roll3 >= num_roll1) &&(num_roll3 >= num_roll2) && (num_roll3>=num_roll4))
		{
		starting_plyr(plyr3);
		}
		else if ((num_roll4 >= num_roll1) &&(num_roll4 >= num_roll2) && (num_roll4>=num_roll3))
		{
		starting_plyr(plyr4);
		}
		
		
		}
	
	
	
	
	else {
	 	
	DrawString( 1, 380, "TURN" ,colors[DARK_GRAY]);
	if(redtrn)
	{
	DrawSquare(91,375,25,colors[RED]);
	}
	else if(bluetrn)
	{
	DrawSquare(91,375,25,colors[BLUE]);
	}
	else if (greentrn)
	{
	DrawSquare(91,375,25,colors[GREEN]);
	}
	else if(yeltrn)
	{
	DrawSquare(91,375,25,colors[OLIVE]);
	}
	
	
	//drawing board
	DrawSquare( 150 , 50 ,500,colors[WHITE]); 	
	DrawSquare( 150 , 50 ,200,colors[RED]);
	DrawSquare( 450 , 50 ,200,colors[OLIVE]);
	DrawSquare( 150 , 350 ,200,colors[BLUE]);
	DrawSquare( 450 , 350 ,200,colors[GREEN]);
	DrawRectangle(383,83,33,167,colors[RED]);
	DrawRectangle(183,283,167,33,colors[BLUE]);
	DrawRectangle(383,350,33,167,colors[GREEN]);
	DrawRectangle(450,283,167,33,colors[OLIVE]);
	DrawSquare(349,83,33,colors[RED]);
	DrawSquare(183,317,34,colors[BLUE]);
	DrawSquare(583,250,33,colors[OLIVE]);
	DrawSquare(417,483,34,colors[GREEN]);
	DrawRoundRect(175,75,150,150,colors[WHITE]);
	DrawRoundRect(475,75,150,150,colors[WHITE]);
	DrawRoundRect(175,375,150,150,colors[WHITE]);
	DrawRoundRect(475,375,150,150,colors[WHITE]);
	DrawRoundRect(200,100,40,40,colors[RED]);
	DrawRoundRect(200,155,40,40,colors[RED]);
	DrawRoundRect(255,100,40,40,colors[RED]);
	DrawRoundRect(255,155,40,40,colors[RED]);
	DrawRoundRect(500,100,40,40,colors[OLIVE]);
	DrawRoundRect(500,155,40,40,colors[OLIVE]);
	DrawRoundRect(555,100,40,40,colors[OLIVE]);
	DrawRoundRect(555,155,40,40,colors[OLIVE]);
	DrawRoundRect(500,400,40,40,colors[GREEN]);
	DrawRoundRect(500,455,40,40,colors[GREEN]);
	DrawRoundRect(555,400,40,40,colors[GREEN]);
	DrawRoundRect(555,455,40,40,colors[GREEN]);
	DrawRoundRect(200,400,40,40,colors[BLUE]);
	DrawRoundRect(200,455,40,40,colors[BLUE]);
	DrawRoundRect(255,400,40,40,colors[BLUE]);
	DrawRoundRect(255,455,40,40,colors[BLUE]);
	
	
	DrawSquare(417,117,34,colors[GRAY]);
	DrawSquare(217,249,34,colors[GRAY]);
	DrawSquare(349,449,34,colors[GRAY]);
	DrawSquare(550,317,34,colors[GRAY]);
	int temp = 18;
	for(int i =0 ; i<7 ; i++)
	{
	
	DrawLine(349,temp+33,450,temp+33,3,colors[BLACK]);
	temp= temp+33;
	}
	
	
	DrawLine(383,50,383,250,3,colors[BLACK]);
	DrawLine(416,50,416,250,3,colors[BLACK]);
	
	DrawLine (349,350,450,350,3,colors[BLACK]);
	temp = 350;
	for(int i=0 ; i<6 ; i++)
	{
	DrawLine (349,temp+33,450,temp+33,3,colors[BLACK]);
	temp = temp+33;
	}
	DrawLine(383,350,383,550,3,colors[BLACK]);
	DrawLine(416,350,416,550,3,colors[BLACK]);
	
	temp =150;
	for(int i =0 ; i<6 ; i++)
	{
	DrawLine(temp+33,249,temp+33,350,3,colors[BLACK]);
	temp=temp+33;
	}
	
	DrawLine(150,283,350,283,3,colors[BLACK]);
	DrawLine(150,316,350,316,3,colors[BLACK]);
	
	DrawLine(450,350,450,250,3,colors[BLACK]);
	temp = 450;
	for(int i =0 ; i<5 ; i++)
	{
	DrawLine(temp+33,350,temp+33,250,3,colors[BLACK]);
	temp =temp+33;
	}
	
	DrawLine(650,283,450,283,3,colors[BLACK]);
	DrawLine(650,316,450,316,3,colors[BLACK]);
	
	
	DrawTriangle( 350, 250 , 450, 250 , 400 , 300, colors[RED] );
	DrawTriangle( 349, 250 , 349, 350 , 400 , 300, colors[BLUE] );
	DrawTriangle( 350, 350 , 450, 350 , 400 , 300, colors[GREEN] );
	DrawTriangle( 450, 350 , 450, 250 , 400 , 300, colors[OLIVE] );
	
	
	
	
	
	// for printing pieces of pieces
	piece_player(redplyr,1);
	piece_player(bluplyr,2);
	piece_player(greplyr,3);
	piece_player(yelplyr,4);
	
	
	
	// displaying names
	if(plyr1 == 1 )
	{
	DrawString(153,24,name1,colors[DARK_GRAY]);
	}
	else if(plyr1 ==2)
	{
	DrawString(480,560,name1,colors[DARK_GRAY]);
	}	
	else if(plyr1 ==3)
	{
	DrawString(153,560,name1,colors[DARK_GRAY]);
	}
	else if(plyr1 ==4)
	{
	DrawString(480,24,name1,colors[DARK_GRAY]);
	}
	
	if(plyr2 == 1 )
	{
	DrawString(153,24,name2,colors[DARK_GRAY]);
	}
	else if(plyr2 ==2)
	{
	DrawString(480,560,name2,colors[DARK_GRAY]);
	}	
	else if(plyr2 ==3)
	{
	DrawString(153,560,name2,colors[DARK_GRAY]);
	}
	else if(plyr2 ==4)
	{
	DrawString(480,24,name2,colors[DARK_GRAY]);
	}
		if(plyr3 == 1 )
	{
	DrawString(153,24,name3,colors[DARK_GRAY]);
	}
	else if(plyr3 ==2)
	{
	DrawString(480,560,name3,colors[DARK_GRAY]);
	}	
	else if(plyr3 ==3)
	{
	DrawString(153,560,name3,colors[DARK_GRAY]);
	}
	else if(plyr3 ==4)
	{
	DrawString(480,24,name3,colors[DARK_GRAY]);
	}
		if(plyr4 == 1 )
	{
	DrawString(153,24,name4,colors[DARK_GRAY]);
	}
	else if(plyr4 ==2)
	{
	DrawString(480,560,name4,colors[DARK_GRAY]);
	}	
	else if(plyr4 ==3)
	{
	DrawString(153,560,name4,colors[DARK_GRAY]);
	}
	else if(plyr4 ==4)
	{
	DrawString(480,24,name4,colors[DARK_GRAY]);
	}
	
	
	
	if(plyr1==1)
	{
	plyr1score = score1;	
	}
	else if (plyr1==2)
	{
	plyr1score = score3;
	}
	else if(plyr1==3)
	{
	plyr1score = score2;
	}
	else if(plyr1 == 4)
	{
	plyr1score = score4;
	}
	
		if(plyr2==1)
	{
	plyr2score = score1;	
	}
	else if (plyr2==2)
	{
	plyr2score = score3;
	}
	else if(plyr2==3)
	{
	plyr2score = score2;
	}
	else if(plyr2 == 4)
	{
	plyr2score = score4;
	}
	
			if(plyr3==1)
	{
	plyr3score = score1;	
	}
	else if (plyr3==2)
	{
	plyr3score = score3;
	}
	else if(plyr3==3)
	{
	plyr3score = score2;
	}
	else if(plyr3 == 4)
	{
	plyr3score = score4;
	}
	
	
			if(plyr4==1)
	{
	plyr4score = score1;	
	}
	else if (plyr4==2)
	{
	plyr4score = score3;
	}
	else if(plyr4==3)
	{
	plyr4score = score2;
	}
	else if(plyr4 == 4)
	{
	plyr4score = score4;
	}
	
	
	
	
	
	
	//Displaying Score
	if(plyr1==1)
	
	{
	DrawString(239,24,"SCORE:"+to_string(plyr1score),colors[DARK_GRAY]);
	}
	else if (plyr1==3)
	{
	DrawString(239,560,"SCORE:"+to_string(plyr1score),colors[DARK_GRAY]);
	}
	else if (plyr1==2)
	{
	DrawString(565,560,"SCORE:"+to_string(plyr1score),colors[DARK_GRAY]);
	}
	else if (plyr1==4)
	{
	DrawString(565,24,"SCORE:"+to_string(plyr1score),colors[DARK_GRAY]);
	}
	
	if(plyr2==1)
	
	{
	DrawString(239,24,"SCORE:"+to_string(plyr2score),colors[DARK_GRAY]);
	}
	else if (plyr2==3)
	{
	DrawString(239,560,"SCORE:"+to_string(plyr2score),colors[DARK_GRAY]);
	}
	else if (plyr2==2)
	{
	DrawString(565,560,"SCORE:"+to_string(plyr2score),colors[DARK_GRAY]);
	}
	else if (plyr2==4)
	{
	DrawString(565,24,"SCORE:"+to_string(plyr2score),colors[DARK_GRAY]);
	}
	
		if(plyr3==1)
	
	{
	DrawString(239,24,"SCORE:"+to_string(plyr3score),colors[DARK_GRAY]);
	}
	else if (plyr3==3)
	{
	DrawString(239,560,"SCORE:"+to_string(plyr3score),colors[DARK_GRAY]);
	}
	else if (plyr3==2)
	{
	DrawString(565,560,"SCORE:"+to_string(plyr3score),colors[DARK_GRAY]);
	}
	else if (plyr3==4)
	{
	DrawString(565,24,"SCORE:"+to_string(plyr3score),colors[DARK_GRAY]);
	}
	
		if(plyr4==1)
	
	{
	DrawString(239,24,"SCORE:"+to_string(plyr4score),colors[DARK_GRAY]);
	}
	else if (plyr4==3)
	{
	DrawString(239,560,"SCORE:"+to_string(plyr4score),colors[DARK_GRAY]);
	}
	else if (plyr4==2)
	{
	DrawString(565,560,"SCORE:"+to_string(plyr4score),colors[DARK_GRAY]);
	}
	else if (plyr4==4)
	{
	DrawString(565,24,"SCORE:"+to_string(plyr4score),colors[DARK_GRAY]);
	}
	
	if(winred)
	{
	DrawString(200,199, "RED WON",colors[BLACK]);
	}	
	if(winblu)
	{
	DrawString(200,527, "BLUE WON",colors[BLACK]);
	}
	if(wingre)
	{
	DrawString(490,527, "GREEN WON",colors[BLACK]);
	}
	if(winyel)
	{
	DrawString(490,199, "YELLOW WON",colors[BLACK]);
	}
	

	// displaying the dice roll
	turn(num);
	
	}

	
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
glutPostRedisplay();
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			next_turn();
			steps=0;
			roll1=0;
			roll2=0;
			selected =false;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 
 

 
void PrintableKeys(unsigned char key, int x, int y) {

	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if(menu){return;}
	if (key == 32 ) //when space is pressed dice is rolled
			{
			
			
			 
		if(steps==0&& roll1==0)			
		{	
			
			num = GetRandInRange(1,7);
			
			if (num==6&& !rand6){
			rand6=true;
cout<<"Storing the LAst 6 "<<endl;
			roll2=6;
			roll1 =0;
			k=1;
			return ;
			}
			if (roll1==0){
			roll1=num;
			rand6=false;
			selected = false;
			}
			
					
			k=1; //reseting animation on every move
		}
	}
	
if(( (redplyr[0][0]==219 && redplyr[0][1] ==118) ) &&  ((redplyr[1][0]==220 && redplyr[1][1] ==172)) &&  ((redplyr[2][0]==274 && redplyr[2][1] ==171)) &&  ((redplyr[3][0]==273 && redplyr[3][1] ==117)) && (roll1!=6) && (roll2!=6) && redtrn)
{



 steps =0;
 roll1=0;
 roll2=0;
 selected = false;
next_turn();
 return;

}
	
if(( (bluplyr[0][0]==219 && bluplyr[0][1] ==418) ) &&  ((bluplyr[1][0]==220 && bluplyr[1][1] ==472)) &&  ((bluplyr[2][0]==274 && bluplyr[2][1] ==471)) &&  ((bluplyr[3][0]==273 && bluplyr[3][1] ==417)) && (roll1!=6) && (roll2!=6) && bluetrn)
{



 steps =0;
 roll1=0;
 roll2=0;
 selected = false;
next_turn();
 return;

}

if(( (greplyr[0][0]==519 && greplyr[0][1] ==418) ) &&  ((greplyr[1][0]==520 && greplyr[1][1] ==472)) &&  ((greplyr[2][0]==574 && greplyr[2][1] ==471)) &&  ((greplyr[3][0]==573 && greplyr[3][1] ==417)) && (roll1!=6) && (roll2!=6) && greentrn)
{



 steps =0;
 roll1=0;
 roll2=0;
 selected = false;
next_turn();
 return;

}

if(( (yelplyr[0][0]==519 && yelplyr[0][1] ==118) ) &&  ((yelplyr[1][0]==520 && yelplyr[1][1] ==172)) &&  ((yelplyr[2][0]==574 && yelplyr[2][1] ==171)) &&  ((yelplyr[3][0]==573 && yelplyr[3][1] ==117)) && (roll1!=6) && (roll2!=6) && yeltrn)
{



 steps =0;
 roll1=0;
 roll2=0;
 selected = false;
next_turn();
 return;

}
	
	

	
	glutPostRedisplay();
	
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 
void Timer(int m) {

	bool two_plyrs = false;
	bool game_end  = false;
	if(plyr3==0 && plyr4 ==0)
	{
	two_plyrs = true;
	
	}
		 if(two_plyrs)
	{
	if(winred) 
	{
	game_end =true;
	}
	if(wingre) 
	{
	game_end =true;
	}
	
	
	}
	
	if (plyr1 != 0 && plyr2!=0 && plyr3!=0 && plyr4 == 0)
	{
	if( (winred && winblu) || (winred && wingre) || (wingre && winblu) ) 
	{
	game_end =true;
	}
		
	
	
	if(plyr1!=0 && plyr2!=0 && plyr3!=0 && plyr4!= 0)
	{
	if( (winred && winblu && wingre) || (winred && winblu && winyel) || (winred && wingre && winyel) || (wingre && winblu && winyel) )
	{
	game_end = true;
	
	}
	}
	

	

	
	
	}
	if(game_end)
	{	
	sort_score(to_string(plyr1score),name1);
	sort_score(to_string(plyr2score),name2);
	sort_score(to_string(plyr3score),name3);
	sort_score(to_string(plyr4score),name4);
	exit(0);
	

	}

	//////////////////////////////////implementation for different number of players
	if(plyr3 ==0) 
	{
	if(bluetrn)
	{
	next_turn();
	}

	}
	if (plyr4 ==0)
	{
	if(yeltrn)
	{
	next_turn();
	}
	}
	
	


	k++;
	piece_number(redplyr);
	piece_number(bluplyr);
	piece_number(greplyr);
	piece_number(yelplyr);
	
	
if (rearrange&&steps==0){

if(bluetrn) {
redplyr[save1][0]=redplyr[save2][0];
redplyr[save1][1]=redplyr[save2][1];
}
else if (yeltrn)
{
greplyr[save1][0]=greplyr[save2][0];
greplyr[save1][1]=greplyr[save2][1];

}
else if (greentrn)
{
bluplyr[save1][0]=bluplyr[save2][0];
bluplyr[save1][1]=bluplyr[save2][1];

}
else if (redtrn)
{
yelplyr[save1][0]=yelplyr[save2][0];
yelplyr[save1][1]=yelplyr[save2][1];

}

	
	


	rearrange=false;	
	}
	
	
	
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS

	glutTimerFunc(4.0, Timer, 0);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
y=600-y;
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {
y=600-y;
const int red_out[4][2] = { {219,118},{220,172},{274,171} , {273,117} };
const int blu_out[4][2] = { {219,418},{220,472},{274,471} , {273,417} };
const int gre_out[4][2] = { {519,418},{520,472},{574,471} , {573,417} };
const int yel_out[4][2] = { {519,118},{520,172},{574,171} , {573,117} };
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
	if(roll_menu)
	{
	int roll_menu_rang1 = abs(272-x);
	int roll_menu_rang2 = abs(138-y);
	if((roll_menu_rang1 && roll_menu_rang1 <= 20) && (roll_menu_rang2 >=0 && roll_menu_rang2 <= 80))
	{
	roll_menu = false;
	}
	
	}
	
	if(menu) 
	{
	int rang1_menu;
	int rang2_menu;
	rang1_menu = abs(385 -x);
	rang2_menu = abs(300 -y);
	if((rang1_menu >= 0 && rang1_menu <= 20) && (rang2_menu >=0 && rang2_menu <= 40))
	{
	
	menu2 = true;	
	
	}
	int rang3_menu;
	int rang4_menu;
	rang3_menu = abs(402 -x);
	rang4_menu = abs(208 -y);
	if((rang3_menu >= 0 && rang3_menu <= 20) && (rang4_menu >=0 && rang4_menu <= 80))
	{
	menu1 = true;
	}
	int rang5_menu;
	int rang6_menu;
	rang5_menu = abs(68 -x);
	rang6_menu = abs(564 -y);
	if(menu1) {
	
	if((rang5_menu >= 0 && rang5_menu <= 20) && (rang6_menu >=0 && rang6_menu <= 80))
	{
	menu1 = false;
	}
	}
	 if (menu2)
	{
	
	if((rang5_menu >= 0 && rang5_menu <= 20) && (rang6_menu >=0 && rang6_menu <= 80))
	{
	menu2 = false;
	}
	int rang1_menu2 = abs(276 -x);
	int rang2_menu2 = abs(409 -y);
	if((rang1_menu2 >= 0 && rang1_menu2 <= 20) && (rang2_menu2 >=0 && rang2_menu2 <= 20))
	{
	menu2a = true;
	}
	int rang1_menu2b = abs(275-x);
	int rang2_menu2b = abs(360-y);
	if((rang1_menu2b >= 0 && rang1_menu2b <= 20) && (rang2_menu2b >=0 && rang2_menu2b <= 20))
	{
	menu2b= true;
	}
	int rang1_menu2c = abs(275-x);
	int rang2_menu2c = abs(308-y);
	if((rang1_menu2c >= 0 && rang1_menu2c <= 20) && (rang2_menu2c >=0 && rang2_menu2c <= 20))
	{
	menu2c= true;
	}
	
	
	if(menu2a)
	{
	
	if((rang5_menu >= 0 && rang5_menu <= 20) && (rang6_menu >=0 && rang6_menu <= 80))
	{
	menu2a = false;
	}
	int rang3_menu2 = abs(414 -x);
	int rang4_menu2 = abs(412 -y);
	
	if((rang3_menu2 >= 0 && rang3_menu2 <= 20) && (rang4_menu2 >=0 && rang4_menu2 <= 20))
	{
	plyr1 = 1;
	
	}
	int rang5_menu2 = abs(474 -x);
	int rang6_menu2 = abs(412 -y);
	if((rang5_menu2 >= 0 && rang5_menu2 <= 20) && (rang6_menu2 >=0 && rang6_menu2 <= 20))
	{
	plyr1 = 2;
	
	}
	int rang7_menu2 = abs(414 -x);
	int rang8_menu2 = abs(362 -y);
	
	if((rang7_menu2 >= 0 && rang7_menu2 <= 20) && (rang8_menu2 >=0 && rang8_menu2 <= 20))
	{
	plyr2 = 1;
	menu = false;
	}
	int rang9_menu2 = abs(474 -x);
	int rang10_menu2 = abs(362 -y);
	
	if((rang9_menu2 >= 0 && rang9_menu2 <= 20) && (rang10_menu2 >=0 && rang10_menu2 <= 20))
	{
	plyr2 = 2;
	menu = false;
	}

	}
	
	
	if(menu2b)
	{
	int rang_out1 =abs(70-x) ;
	int rang_out2 =abs(567-y) ;
	if((rang_out1 >= 0 && rang_out1 <= 20) && (rang_out2 >=0 && rang_out2 <= 80))
	{
	menu2b = false;
	}
	int rang3_menu2b = abs(414 -x);
	int rang4_menu2b = abs(412 -y);
	
	if((rang3_menu2b >= 0 && rang3_menu2b <= 20) && (rang4_menu2b >=0 && rang4_menu2b <= 20))
	{
	plyr1 = 1;
	
	}
	int rang5_menu2b = abs(474 -x);
	int rang6_menu2b = abs(412 -y);
	if((rang5_menu2b >= 0 && rang5_menu2b <= 20) && (rang6_menu2b >=0 && rang6_menu2b <= 20))
	{
	plyr1 = 2;
	
	}
	int rang5_menu2b3 = abs(532 -x);
	int rang6_menu2b3 = abs(412 -y);
	if((rang5_menu2b3 >= 0 && rang5_menu2b3 <= 20) && (rang6_menu2b3 >=0 && rang6_menu2b3 <= 20))
	{
	plyr1 = 3;
	
	}
	
	
	
	int rang7_menu2b = abs(414 -x);
	int rang8_menu2b = abs(362 -y);
	
	if((rang7_menu2b >= 0 && rang7_menu2b <= 20) && (rang8_menu2b >=0 && rang8_menu2b <= 20))
	{
	plyr2 = 1;
	
	}
	int rang9_menu2b = abs(474 -x);
	int rang10_menu2b = abs(362 -y);
	
	if((rang9_menu2b >= 0 && rang9_menu2b <= 20) && (rang10_menu2b >=0 && rang10_menu2b <= 20))
	{
	plyr2 = 2;
	
	}
	int rang9_menu2b3 = abs(532 -x);
	int rang10_menu2b3 = abs(362 -y);
	
	if((rang9_menu2b3 >= 0 && rang9_menu2b3 <= 20) && (rang10_menu2b3 >=0 && rang10_menu2b3 <= 20))
	{
	plyr2 = 3;
	
	}
	int ranga_menu2b = abs(414 -x);
	int rangb_menu2b = abs(314 -y);
	
	if((ranga_menu2b >= 0 && ranga_menu2b <= 20) && (rangb_menu2b >=0 && rangb_menu2b <= 20))
	{
	plyr3 = 1;
	menu=false;
	}
	int rangc_menu2b = abs(474 -x);
	int rangd_menu2b = abs(314 -y);
	
	if((rangc_menu2b >= 0 && rangc_menu2b <= 20) && (rangd_menu2b >=0 && rangd_menu2b <= 20))
	{
	plyr3 = 2;
	menu=false;
	}
	int range_menu2b3 = abs(532 -x);
	int rangf_menu2b3 = abs(314 -y);
	
	if((range_menu2b3 >= 0 && range_menu2b3 <= 20) && (rangf_menu2b3 >=0 && rangf_menu2b3 <= 20))
	{
	plyr3 = 3;
	menu = false;
	}
	
	}
	
	if(menu2c)
	{
	cout << "PLYR1 :"<< plyr1<<"PLYR2:" << plyr2<<"PLYR3:" <<plyr3<<"PLYR4:" << plyr4 <<endl;
	int rang_out1c =abs(70-x) ;
	int rang_out2c =abs(567-y) ;
	if((rang_out1c >= 0 && rang_out1c <= 20) && (rang_out2c >=0 && rang_out2c <= 80))
	{
	menu2c = false;
	}
	int rang3_menu2c = abs(414 -x);
	int rang4_menu2c = abs(412 -y);
	
	if((rang3_menu2c >= 0 && rang3_menu2c <= 20) && (rang4_menu2c >=0 && rang4_menu2c <= 20))
	{
	plyr1 = 1;
	
	}
	int rang5_menu2c = abs(474 -x);
	int rang6_menu2c = abs(412 -y);
	if((rang5_menu2c >= 0 && rang5_menu2c <= 20) && (rang6_menu2c >=0 && rang6_menu2c <= 20))
	{
	plyr1 = 2;
	
	}
	int rang5_menu2c3 = abs(532 -x);
	int rang6_menu2c3 = abs(412 -y);
	if((rang5_menu2c3 >= 0 && rang5_menu2c3 <= 20) && (rang6_menu2c3 >=0 && rang6_menu2c3 <= 20))
	{
	plyr1 = 3;
	
	}
	int rang5_menu2c4 = abs(594 -x);
	int rang6_menu2c4 = abs(412 -y);
	if((rang5_menu2c4 >= 0 && rang5_menu2c4 <= 20) && (rang6_menu2c4 >=0 && rang6_menu2c4 <= 20))
	{
	plyr1 = 4;
	
	}
	
	
	
	
	
	int rang7_menu2c = abs(414 -x);
	int rang8_menu2c = abs(362 -y);
	
	if((rang7_menu2c >= 0 && rang7_menu2c <= 20) && (rang8_menu2c >=0 && rang8_menu2c <= 20))
	{
	plyr2 = 1;
	
	}
	int rang9_menu2c = abs(474 -x);
	int rang10_menu2c = abs(362 -y);
	
	if((rang9_menu2c >= 0 && rang9_menu2c <= 20) && (rang10_menu2c >=0 && rang10_menu2c <= 20))
	{
	plyr2 = 2;
	
	}
	int rang9_menu2c3 = abs(532 -x);
	int rang10_menu2c3 = abs(362 -y);
	
	if((rang9_menu2c3 >= 0 && rang9_menu2c3 <= 20) && (rang10_menu2c3 >=0 && rang10_menu2c3 <= 20))
	{
	plyr2 = 3;
	
	}
	
	int rang5_menu2c5 = abs(594 -x);
	int rang6_menu2c5 = abs(362 -y);
	if((rang5_menu2c5 >= 0 && rang5_menu2c5 <= 20) && (rang6_menu2c5 >=0 && rang6_menu2c5 <= 20))
	{
	plyr2 = 4;
	
	}
	
	
	
	
	int ranga_menu2c = abs(414 -x);
	int rangb_menu2c = abs(314 -y);
	
	if((ranga_menu2c >= 0 && ranga_menu2c <= 20) && (rangb_menu2c >=0 && rangb_menu2c <= 20))
	{
	plyr3 = 1;
	
	}
	int rangc_menu2c = abs(474 -x);
	int rangd_menu2c = abs(314 -y);
	
	if((rangc_menu2c >= 0 && rangc_menu2c <= 20) && (rangd_menu2c >=0 && rangd_menu2c <= 20))
	{
	plyr3 = 2;
	}
	int range_menu2c3 = abs(532 -x);
	int rangf_menu2c3 = abs(314 -y);
	
	if((range_menu2c3 >= 0 && range_menu2c3 <= 20) && (rangf_menu2c3 >=0 && rangf_menu2c3 <= 20))
	{
	plyr3 = 3;
	
	}
	
	int rang5_menu2c6 = abs(594 -x);
	int rang6_menu2c6 = abs(314 -y);
	if((rang5_menu2c6 >= 0 && rang5_menu2c6 <= 20) && (rang6_menu2c6 >=0 && rang6_menu2c6 <= 20))
	{
	plyr3 = 4;
	
	}
	
	int ranga_menu2d = abs(414 -x);
	int rangb_menu2d = abs(263 -y);
	
	if((ranga_menu2d >= 0 && ranga_menu2d <= 20) && (rangb_menu2d >=0 && rangb_menu2d <= 20))
	{
	plyr4 = 1;
	menu=false;
	}
	int rangc_menu2d = abs(474 -x);
	int rangd_menu2d = abs(263 -y);
	
	if((rangc_menu2d >= 0 && rangc_menu2d <= 20) && (rangd_menu2d >=0 && rangd_menu2d <= 20))
	{
	plyr4 = 2;
	menu=false;
	}
	int range_menu2d3 = abs(532 -x);
	int rangf_menu2d3 = abs(263 -y);
	
	if((range_menu2d3 >= 0 && range_menu2d3 <= 20) && (rangf_menu2d3 >=0 && rangf_menu2d3 <= 20))
	{
	plyr4 = 3;
	menu=false;
	}
	
	int rang5_menu2d6 = abs(594 -x);
	int rang6_menu2d6 = abs(263 -y);
	if((rang5_menu2d6 >= 0 && rang5_menu2d6 <= 20) && (rang6_menu2d6 >=0 && rang6_menu2d6 <= 20))
	{
	plyr4 = 4;
	menu=false;
	}
	
	
	
	
	
	
	}	
	
	}
	int rang7_menu;
	int rang8_menu;
	rang7_menu = abs(380 -x);
	rang8_menu = abs(113-y);
	if((rang7_menu >= 0 && rang7_menu <= 20) && (rang8_menu >=0 && rang8_menu <= 80) && (menu2a==false) && (menu2b ==false) &&(menu2c == false))
	{
	exit(0);
	}
	
	
	if(menu2a)
	{
	int rang_rand1 = abs(692-x);
	int rang_rand2 = abs(345-y);
	if((rang_rand1 >= 0 && rang_rand1 <= 20) && (rang_rand2 >=0 && rang_rand2 <= 60))
	{
	plyr1 = rand_colour1();
	plyr2 = rand_colour1();
	while(plyr2==plyr1)
	{
	plyr2=rand_colour1();
	}
	
	menu=false;
	}
	
	}
	
	if(menu2b)
	{
	int rang_rand3 = abs(692-x);
	int rang_rand4 = abs(345-y);
	if((rang_rand3 >= 0 && rang_rand3 <= 20) && (rang_rand4 >=0 && rang_rand4 <= 60))
	{
	plyr1 = rand_colour2();
	plyr2 = rand_colour2();
	while(plyr2==plyr1)
	{
	plyr2=rand_colour2();
	}
	plyr3 = rand_colour2();
	while( (plyr3 == plyr1) || (plyr3 == plyr2) ) 
	{
	plyr3 = rand_colour2();
	}
	
	menu=false;
	}
	
	}
	
	
	if(menu2c)
	{
	int rang_rand5 = abs(692-x);
	int rang_rand6 = abs(345-y);
	if((rang_rand5 >= 0 && rang_rand5 <= 20) && (rang_rand6 >=0 && rang_rand6 <= 60))
	{
	plyr1 = rand_colour3();
	cout << "PLYR 1 : " <<plyr1 <<endl;
	plyr2 = rand_colour3();
	while(plyr2==plyr1)
	{
	plyr2=rand_colour3();
	}
	
	cout << "PLYR 2 : " <<plyr2 << endl;
	plyr3 = rand_colour3();
	while( (plyr3 == plyr1) || (plyr3 == plyr2) ) 
	{
	plyr3 = rand_colour3();
	}
	cout << "PLYR 3 : " <<plyr3 << endl;
	plyr4 = rand_colour3();
	while( (plyr4==plyr1) || (plyr4 == plyr2) || (plyr4 ==plyr3) )
	{
	plyr4 = rand_colour3();
	}
	
	cout << "PLYR 4 : " <<plyr4 << endl;
	
	menu=false;
	}
	
	}
	
	
	
	
	
	
	
	}
	if(menu || roll_menu) {return;}
	
				if(redtrn && roll2 ==6){
				out_piece(redplyr,red_out,x,y,366,99);
				}
				else if (bluetrn && roll2 ==6) {
				out_piece (bluplyr,blu_out,x,y,201,330);
				}
				else if(greentrn && roll2 ==6) {
				out_piece(greplyr , gre_out , x ,y,432,497);
				}
				else if(yeltrn && roll2 ==6) {
				out_piece(yelplyr ,yel_out,x,y,597,266);
				}	

	
	
	
			if(redtrn){
			choice_movement(redplyr,x,y);
			}
			else if(bluetrn){
			choice_movement(bluplyr,x,y);
			}
			else if(greentrn){
			choice_movement(greplyr,x,y);
			}
			else if(yeltrn){
			choice_movement(yelplyr,x,y);
			}
			
			
			
				
			cout << piece_no << "  "  << endl;
			cout << "x : " << x << "y : " << y << endl;
	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	
	
	cout << "PLAYER 1 : " <<endl; 
	cin >> name1;
	cout << " "<<endl;
	cout << "PLAYER 2 : " <<endl; 
	cin >> name2;
	cout << " "<<endl;
	cout << "PLAYER 3 : " <<endl; 
	cin >> name3;
	cout << " "<<endl;
	cout << "PLAYER 4 : " <<endl; 
	cin >> name4;
	cout << " "<<endl;
	
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 800, height = 600; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
