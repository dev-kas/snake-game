#include <raylib.h>

#define CELL_SIZE 30
#define ROWS 21
#define COLS 12

int main() {
  InitWindow(ROWS * CELL_SIZE, COLS * CELL_SIZE, "Snake");
  SetTargetFPS(60);
  int frames = 0;

  Vector2 snake = {0, 0};
  Vector2 speed = {0, 0};
  Vector2 speedintent = {1, 0};
  Vector2 fruit = {GetRandomValue(0, ROWS - 1), GetRandomValue(0, COLS - 1)};
  Vector2 tails[ROWS * COLS];
  int length = 0;

  while (!WindowShouldClose()) {
    // input
    if (IsKeyPressed(KEY_LEFT) && speed.x != 1) {
      speedintent.x = -1;
      speedintent.y = 0;
    }

    if (IsKeyPressed(KEY_RIGHT) && speed.x != -1) {
      speedintent.x = 1;
      speedintent.y = 0;
    }

    if (IsKeyPressed(KEY_DOWN) && speed.y != -1) {
      speedintent.x = 0;
      speedintent.y = 1;
    }

    if (IsKeyPressed(KEY_UP) && speed.y != 1) {
      speedintent.x = 0;
      speedintent.y = -1;
    }

    // physics
    frames++;
    if (frames % 6 == 0) {
      if (snake.x == fruit.x && snake.y == fruit.y ||
          IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        fruit.x = GetRandomValue(0, ROWS - 1);
        fruit.y = GetRandomValue(0, COLS - 1);
        tails[length] = snake;
        length++;
        if (length >= (ROWS * COLS))
          length = 0;
      }

      for (int i = length; i >= 0; i--) {
        if (i == 0) {
          tails[0] = snake;
        } else {
          tails[i] = tails[i - 1];
        }
      }

      speed.x = speedintent.x;
      speed.y = speedintent.y;

      snake.x += speed.x;
      snake.y += speed.y;
      if (snake.x >= ROWS)
        snake.x = 0;
      if (snake.x < 0)
        snake.x = ROWS - 1;
      if (snake.y >= COLS)
        snake.y = 0;
      if (snake.y < 0)
        snake.y = COLS - 1;

      for (int i = 0; i < length; i++) {
        if (tails[i].x == snake.x && tails[i].y == snake.y) {
          length = 0;
          break;
        }
      }
    }

    // rendering
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i < length; i++) {
      DrawRectangle(tails[i].x * CELL_SIZE, tails[i].y * CELL_SIZE, CELL_SIZE,
                    CELL_SIZE, DARKGREEN);
    }
    DrawRectangle(snake.x * CELL_SIZE, snake.y * CELL_SIZE, CELL_SIZE,
                  CELL_SIZE, GREEN);
    DrawRectangle(fruit.x * CELL_SIZE, fruit.y * CELL_SIZE, CELL_SIZE,
                  CELL_SIZE, RED);
    DrawText(TextFormat("SCORE: %d", length), 0, 0, 16, WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
};
