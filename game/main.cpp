#include "raylib.h"

constexpr auto SCREEN_WIDTH  = 1200;
constexpr auto SCREEN_HEIGHT = 720;

#include "resourcemanager.h"
#include "object.h"
#include "testobj.h"
int main()
{
	//eventual outcome
	//Game game = new Game();
	//game.Play();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");

	ResourceManager* rs = ResourceManager::Instance();

	//todo
	//make scene, maybe even core
	//update scene
	float rot = 0;

	TestOBJ* i = new TestOBJ("assets/test.png");
	TestOBJ* j = new TestOBJ("assets/nonexisting.png");

    while (!WindowShouldClose()) //while (core.Run(game)) { ; }
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

		i->position = Vector2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
		i->rotation += 0.01f;
		i->Draw();

		j->position = Vector2(SCREEN_WIDTH / 4 * 3, SCREEN_HEIGHT / 2);
		j->Draw();

		//--------------Text drawing-----------------------------------//
        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(rs->GetFont(), text, 30, 1);
		Vector2 pos = Vector2(SCREEN_WIDTH / 2 - text_size.x / 2, text_size.y + 10);
		DrawTextEx(rs->GetFont(), text, pos, 30, 1, BLACK);
		//--------------end of text drawing----------------------------//

        EndDrawing();
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
