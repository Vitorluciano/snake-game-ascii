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
			// TODO: I've swapped the keys as a workaround
			switch (key_pressed) {
				case 'D':
					this->y = (this->y >= 0) ? (this->y - 1) % screen_height : screen_height - 1; 
					break;
				case 'C':
					this->y = (this->y >= 0) ? (this->y + 1) % screen_height : screen_height - 1;
					break;
				case 'B':
					this->x = (this->x >= 0) ? (this->x + 1) % screen_width : screen_width - 1;
					break;
				case 'A':
					this->x = (this->x >= 0) ? (this->x - 1) % screen_width : screen_width - 1;
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

