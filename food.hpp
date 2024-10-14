#include <cstdlib>


class Food {
	private:
		char symbol;
		int x;
		int y;

	public:
		Food(char symbol, int x, int y) {
			this->symbol = symbol;
			this->x = x;
			this->y = y;
		}	

		void update_position(int max_x, int max_y) {
			this->x = std::rand() % max_x;
			this->y = std::rand() % max_y;
		}

		int getX() {
			return this->x;
		}

		int getY() {
			return this->y;
		}

		char getSymbol() {
			return this->symbol;
		}
};
