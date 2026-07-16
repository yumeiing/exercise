#include <raylib.h>

#define WIDTH 480
#define HEIGHT 320
#define FPS 60

int main(int argc,char* argv[])
{
  InitWindow(WIDTH,HEIGHT,"raylib-window");
  SetTargetFPS(FPS);

  while(!WindowShouldClose())
  {
    //handle event
    //update
    BeginDrawing();

    //render

    EndDrawing();
  }

  CloseWindow();
  return 0;
}