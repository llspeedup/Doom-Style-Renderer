#include <raylib.h>;
#include <iostream>;

using namespace std;

struct wall
{
	float x1, x2, y1, y2;
	Color Colour;
};

void drawwall2d(wall wall) {
	DrawLine(wall.x1, wall.y1, wall.x2, wall.y2, wall.Colour);
}

int main() {

	InitWindow(1024, 512, "DOOM STYLE RENDERER");

	float px, py, pa, speed;
	float pdx, pdy;

	px = 128; py = 128;
	pa = 0;
	speed = 2;

	pdx = cos(pa) * 10;
	pdy = sin(pa) * 10;



	wall wall1;

	wall1.x1 = 64;
	wall1.y1 = 64;
	wall1.x2 = 192;
	wall1.y2 = 64;
	wall1.Colour = GREEN;



	while (!WindowShouldClose()) {
		BeginDrawing();

		DrawRectangleLines(0, 0, 256, 256, RED);

		DrawRectangle(px - 2, py - 2, 3, 3, YELLOW);
		DrawLine(px, py, px + pdx, py + pdy, WHITE);

		drawwall2d(wall1);

		ClearBackground(BLACK);

		EndDrawing();

		if (IsKeyDown(KEY_A)) {
			pa += -2 * GetFrameTime();
			pdx = cos(pa) * 10;
			pdy = sin(pa) * 10;
		}
		if (IsKeyDown(KEY_D)) {
			pa += 2 * GetFrameTime();
			pdx = cos(pa) * 10;
			pdy = sin(pa) * 10;
		}
		if (IsKeyDown(KEY_W)) {
			px += pdx * GetFrameTime() * speed;
			py += pdy * GetFrameTime() * speed;
		}
	}

	return 0;
}