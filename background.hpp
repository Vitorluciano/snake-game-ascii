#include <vector>
#include <iostream>
#include "snake.hpp"

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

		void draw(Snake* s) {
			system("clear");
			for (int i = 0; i < this->height; i++) {
				for (int j = 0; j < this->width; j++) {
					if (s->getX() == i && s->getY() == j) {
						cout << s->getSymbol();
					} else {
						cout << grid[i][j];
					}
				}
				cout << endl;
			}
		}
};
