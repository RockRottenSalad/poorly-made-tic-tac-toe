#include<stdio.h>
#include<stdlib.h>
#include<raylib.h>

static int xtaken;
static int ytaken;
static int turn = 2;
static int won = 0;

static int board[][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};

void CheckForWin(){
  Font Arial = LoadFontEx("./font/arial.ttf", 30, 0, 200);
  //printf("\n%d, %d, %d\n%d, %d, %d\n%d, %d, %d\n", board[0][0],board[0][1],board[0][2],
//  board[1][0],board[1][1],board[1][2],board[2][0],board[2][1],board[2][2]);
BeginDrawing();
    if(board[0][0] != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2]){
      DrawLineEx((Vector2){0,150}, (Vector2){900,150}, 10.0, BLACK);
      //printf("\nwin on row 0\n");
      won = 1;
      if(board[0][0] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[1][0] != 0 && board[1][0] == board[1][1] && board[1][1] == board[1][2]){
      DrawLineEx((Vector2){0,450}, (Vector2){900,450}, 10.0, BLACK);
      //printf("\nwin on row 1\n");
      won = 1;
      if(board[1][0] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[2][0] != 0 && board[2][0] == board[2][1] && board[2][1] == board[2][2]){
      DrawLineEx((Vector2){0,750}, (Vector2){900,750}, 10.0, BLACK);
      //printf("\nwin on row 2\n");
      won = 1;
      if(board[2][0] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[0][0] != 0 && board[0][0] == board[1][0] && board[1][0] == board[2][0]){
      DrawLineEx((Vector2){140,0}, (Vector2){140,900}, 10.0, BLACK);
      //printf("\nwin on line 0\n");
      won = 1;
      if(board[0][0] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[0][1] != 0 && board[0][1] == board[1][1] && board[1][1] == board[2][1]){
      DrawLineEx((Vector2){450,0}, (Vector2){450,900}, 10.0, BLACK);
      //printf("\nwin on line 1\n");
      won = 1;
      if(board[0][1] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[0][2] != 0 && board[0][2] == board[1][2] && board[1][2] == board[2][2]){
      DrawLineEx((Vector2){750,0}, (Vector2){750,900}, 10.0, BLACK);
      //printf("\nwin on line 2\n");
      won = 1;
      if(board[0][2] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
      DrawLineEx((Vector2){0,0}, (Vector2){900,900}, 10.0, BLACK);
      //printf("\nwin on cross 1\n");
      won = 1;
      if(board[0][0] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }

    if(board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
      DrawLineEx((Vector2){900,0}, (Vector2){0,900}, 10.0, BLACK);
      //printf("\nwin on cross 2\n");
      won = 1;
      if(board[0][2] == 1){
        DrawTextEx(Arial, "O won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }else{
        DrawTextEx(Arial, "X won!", (Vector2){400,5}, 30.0, 2.0, BLACK);
      }
    }
    EndDrawing();

}


void DrawXO(int x, int y, int xo, Texture2D tictactoe, float frameWidth, float frameHeight){
  if(y <= 300){
    y = 20;
    ytaken = 0;
  }else if(y > 300 && y <= 600){
    y = 320;
    ytaken = 1;
  }else if(y > 600){
    y = 620;
    ytaken = 2;
  }
  int boardchecker = board[ytaken][xtaken];
  if(boardchecker == 0){
    board[ytaken][xtaken] = turn;
    DrawTextureRec(tictactoe,(Rectangle){(frameWidth * xo), 0, frameWidth,
      frameHeight}, (Vector2){x, y}, RAYWHITE);

      if(turn == 2){
        turn = 1;
      }else{
        turn = 2;
      }
      CheckForWin();
  }
}

int main(){
  //won = 0;

  int x = 300;
  int y = 300;

  InitWindow(900, 900, "Tic Tac Toe");
  Texture2D tictactoe = LoadTexture("./tictactoe.png");
  float frameWidth = (tictactoe.width) / 2;
  float frameHeight = (tictactoe.height);

  SetTargetFPS(60);
  
      BeginDrawing();
      
        ClearBackground(RAYWHITE);
        DrawLine(0, 300, 900, 300, BLACK);
        DrawLine(0, 600, 900, 600, BLACK);
        DrawLine(300,0,300,900, BLACK);
        DrawLine(600,0,600,900, BLACK);
        EndDrawing();



  while(!WindowShouldClose()){

      BeginDrawing();

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && won == 0){
      x = GetMouseX();
      y = GetMouseY();
      printf("clicked");
      if(x <= 300){
        x = 11;
        xtaken = 0;
        DrawXO(x,y,turn,tictactoe,frameWidth,frameHeight);
      }else if(x > 300 && x <= 600){
        x = 311;
        xtaken = 1;
        DrawXO(x,y,turn,tictactoe,frameWidth,frameHeight);
      }else if(x > 600){
        x = 611;
        xtaken = 2;
        DrawXO(x,y,turn,tictactoe,frameWidth,frameHeight);
      }
    }

EndDrawing();
    
  }

  CloseWindow();
  return 0;
}