#include <iostream>
#include <unistd.h>
#include <termios.h>


class InputManager {
	private:
		void setRawMode(bool enable) {
			static struct termios oldt, newt;

			if (enable) {
				// Save old terminal settings
				tcgetattr(STDIN_FILENO, &oldt);
				newt = oldt;

				// Set terminal to raw mode
				newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
				tcsetattr(STDIN_FILENO, TCSANOW, &newt);
			} else {
				// Restore old terminal settings
				tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			}
		}
	
	public:
		char keyPressed() {
			char c;

			this->setRawMode(true);
			
			c = getchar(); // Read one character;

			if (c == 27) {
				if (getchar() == '[') {
					return getchar();
				}
			}

			return 'E';
		}
};
