#include "inputmanager.hpp"
#include "background.hpp"

int main() {
	const int WIDTH = 50; // 137
	const int HEIGHT = 10; // 39

	system("clear");

	// Initialization
	InputManager* inputManager = new InputManager();
	Background* background = new Background('x', WIDTH, HEIGHT);
	Snake* snake = new Snake('o', 0, 0);
	
	while (true) {
		//inputManager->keyPressed();
		snake->update(inputManager->keyPressed(), WIDTH, HEIGHT);
		background->update();
		background->draw(snake);
	}

	return 0;
}
