#include "init.hpp"
int main() {
	init obj(0.5f, 300.f, 17.f, 16);
	ContextSettings settings;
	settings.antialiasingLevel = 0;
	RenderWindow window(VideoMode(1000, 1000), "circle animation", sf::Style::Default, settings);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
			if (Keyboard::isKeyPressed(Keyboard::Escape)
				|| event.type == event.Closed)
				window.close();
		window.clear();
		obj.Draw(window);
		window.display();
	}
}
