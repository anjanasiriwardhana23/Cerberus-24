#include "zvariables.h"
#include <QueueArray.h>
#include "tofconfig.h"
#include "wallpid.h"
#include "zlgo.h"
#include "turns.h"
#include "speed.h"
#include "moves.h"

void calculatePath(boolean runningNext){
  floodFill2();
  
  byte xprevious=x;
  byte yprevious=y;
  x=0;
  y=0;
  byte oldOrient= orient;
  orient=0;
  
  cellCount=0;
  
    while(flood2[y][x]!=1){
        toMove2();
        //pathQueue.push(dir);

        
        if (runningNext== true){
        pathQueue.push(dir);
        }
        
        //Serial2.println(dir);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        
        xprev=x;
        yprev=y;
        updateCoordinates();
        
        
  }

        
        x= xprevious;
        y= yprevious;
        orient=oldOrient;   
        buzz();
}


void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath, boolean smooth){

  byte currentx= x;
  byte currenty= y;
  
  if (shortPath== false){
    
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();
  checkWallsCell();
  updateWalls(x, y, orient, leftWallState, rightWallState, frontWallState);
  while(flood[y][x]!=0){
    
    checkWallsCell();
    updateWalls(x, y, orient, leftWallState, rightWallState, frontWallState);
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                leftAboutTurn();
                delay(500);
                cellStart();
                currentx=0;
                currenty=0;
              }
              else{
                leftTurn();
              }
            }
            else{
            leftTurn();}
        }

        else if (dir=='R'){
          orient = orientation(orient,'R');
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                rightAboutTurn();
                delay(500);
                cellStart();
                currentx=0;
                currenty=0;
              }
              else{
                rightTurn();
              }
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              cellStart();
              currentx=0;
                currenty=0;
              }
              else{
              cellBack();
              }
        }
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
            cellStart();
            currentx=0;
                currenty=0;
          }
          else{
          cellForward();
          }
        }
        xprev=x;
        yprev=y;
        updateCoordinates();
  }
  }

  else{

        frontWallState= false;
        rightWallState= false;
        leftWallState= false;

    if (smooth == true){
        calculatePath(true);
    
        while (!pathQueue.isEmpty ()){

        dir= pathQueue.pop();

        if (dir=='L'){
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              leftAboutTurn();
              delay(500);
              cellStart();
              currentx=0;
              currenty=0;
            }
            else{
            leftSmoothTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              rightAboutTurn();
              delay(500);
              cellStart();
              currentx=0;
              currenty=0;
            }
            else{
            rightSmoothTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              cellStart();
              currentx=0;
              currenty=0;
            }
            else{
            cellBack();}
          }
        
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
              cellStart();
              currentx=0;
              currenty=0;
            }
            else{
            cellForward();}
          }

          xprev=x;
          yprev=y;
          updateCoordinates();
        
      }

      
    }

    else{
      
    calculatePath(true);
    
    while (!pathQueue.isEmpty ()){

    dir= pathQueue.pop();
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            if((x==0 && y==0)){
              leftAboutTurn();
              delay(500);
              cellStart();
            }
            else{
            leftTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)){
              rightAboutTurn();
              delay(500);
              cellStart();
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)){
              turnBack();
              delay(500);
              cellStart();
            }
            else{
            cellBack();}
          }
        
        else{
          if((x==0 && y==0)){
              cellStart();
            }
            else{
            cellForward();}
          }

          xprev=x;
          yprev=y;
          updateCoordinates();
          
        }   
    }
  }
  }


void fixOrientation(){
  while(orient!=0){
    leftAboutTurn();
    orient = orientation(orient,'L');
    delay(500);
  }
}

void loadCells(){
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
    //  cells[j][i]= EEPROM.read(i*14+j);
       cells[j][i]= cells1[j][i];
    }
  }
}

void writeCells(){
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
    //  EEPROM.write(i*14+j ,cells[j][i]);
        cells1[j][i] = cells[j][i];
    }
  }
}


void searchStates(){
 // byte searchState= EEPROM.read(200);
  byte searchState = searchstate1;
  if (searchState==3){ searchState=0; }
  loadCells();

  if (searchState>0){
    if (searchState==1){
      mazeStart();
      if (selectMode==1){
        traverse(0,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,true,false,false);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
       //   EEPROM.write(200,searchState+1);
        }
      }
      else if(selectMode==2){
        floodFill2();
        traverse(0,0,true,true,false);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        buzz();
        delay(500);
        traverse(0,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
        //  EEPROM.write(200,searchState+1);
      }
      
      }
      else if(selectMode==3){
        floodFill2();
        traverse(0,0,true,true,true);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        buzz();
        delay(500);
        //traverse(0,13,false,false,false);
        //cellBrake();
        buzz();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
        //  EEPROM.write(200,searchState+1);
      }
      
      }
    }
    else if(searchState==2){
     mazeStart();
      if (selectMode==1){
        traverse(13,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,true,false,false);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
        //  EEPROM.write(200,searchState+1);
        }
      }
      else if(selectMode==2){
        floodFill2();
        traverse(0,0,true,true,false);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        buzz();
        delay(500);
        traverse(13,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
        //  EEPROM.write(200,searchState+1);
      }
      
      }
      else if(selectMode==3){
        floodFill2();
        traverse(0,0,true,true,true);
        leftWallState=0; rightWallState=0; frontWallState=0;
        cellBrake();
        center();
        buzz();
        delay(500);
        traverse(13,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        mazeStart();

        if (selectMode==2){
          writeCells();
          searchstate1 = searchState+1;
        //  EEPROM.write(200,searchState+1);
      }
      
      }

    }
    
  
  }
  else{
      mazeStart();
      traverse(0,0,true,false,false);
      leftWallState= false; rightWallState= false; frontWallState= false;
      center();
      cellBrake();
      buzz();
      delay(3000);
      traverse(13,0,false,false,false);
      cellBrake();
      buzz();
      traverse(0,0,false,false,false);
      cellBrake();
      fixOrientation();
      delay(3000);
      mazeStart();
      if (selectMode==2){
        writeCells();
        searchstate1 = searchState+1;
       // EEPROM.write(200,searchState+1);
      }
  }


}


void eepromClear(){
  for (int i=0 ;i< 250; i++){
  //  EEPROM.write(i,0);
  }
}