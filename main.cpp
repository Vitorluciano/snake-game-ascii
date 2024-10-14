#include "inputmanager.hpp"
#include "background.hpp"

int main() {
	const int WIDTH = 137;
	const int HEIGHT = 39;

	system("clear");

	// Initialization
	InputManager* inputManager = new InputManager();
	Background* background = new Background(' ', WIDTH, HEIGHT);
	Snake* snake = new Snake('o', 0, 0);
	Food* food = new Food('@', HEIGHT / 2, WIDTH / 2);
	
	while (true) {
		snake->update(inputManager->keyPressed(), HEIGHT, WIDTH);
		background->update();
		background->draw(snake, food);

		// Check if snake ate the food
		if (snake->getX() == food->getX() && snake->getY() == food->getY()) {
			food->update_position(HEIGHT, WIDTH);
		}
	}

	return 0;
}
