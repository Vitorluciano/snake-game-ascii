class Snake {
	private:
		char symbol;
		int x;
		int y;

	public:
		Snake(char symbol, int x, int y) {
			this->symbol = symbol;
			this->x = x;
			this->y = y;
		}

		void update(char key_pressed, int screen_width, int screen_height) {
			switch (key_pressed) {
				case 'A':
					this->y = (this->y - 1) % screen_height; 
					break;
				case 'B':
					this->y = (this->y + 1) % screen_height;
					break;
				case 'C':
					this->x = (this->x + 1) % screen_width;
					break;
				case 'D':
					this->x = (this->x - 1) % screen_width;
					break;
			}
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

