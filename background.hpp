#include <vector>
#include <iostream>
#include "snake.hpp"
#include "food.hpp"

using namespace std;


class Background {
	private:
		char symbol;
		int width;
		int height;
		vector<vector<char>> grid; // Vector of vectors of type char
		
	public:
		Background(char symbol, int width, int height) {
			this->symbol = symbol;
			this->width = width;
			this->height = height;
			this->grid.resize(height, vector<char>(width));
		}

		void update() {
			for (int i = 0; i < this->height; i++) {
				for(int j = 0; j < this->width; j++) {
					grid[i][j] = this->symbol;
				}
			}
		}

		void draw(Snake* s, Food* f) {
			system("clear");
			for (int i = 0; i < this->height; i++) {
				for (int j = 0; j < this->width; j++) {
					if (s->getX() == i && s->getY() == j) {
						cout << "\x1B[34m" << s->getSymbol() << "\033[0m";
					} else if (f->getX() == i && f->getY() == j) {
						cout << f->getSymbol();
					} else {
						cout << grid[i][j];
					}
				}
				cout << endl;
			}
		}
};
