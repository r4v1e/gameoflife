#include <SFML/Graphics.hpp>
#include <string>

#include "Game.h"
#include "UI.h"

void UI::print_background(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("./repo/bgr.jpg");
	sf::Sprite background(texture);
	background.setTextureRect(sf::IntRect(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y));
	window.draw(background);
}

void UI::print_main_menu(sf::RenderWindow& window)
{
	sf::Text mainmenu, credits;
	sf::Font font;
	font.loadFromFile("./repo/arial.ttf");

	mainmenu.setFont(font);
	mainmenu.setCharacterSize(39);
	mainmenu.setFillColor(sf::Color::White);
	mainmenu.setOutlineColor(sf::Color(0, 0, 0));
	mainmenu.setOutlineThickness(2);
	mainmenu.setPosition((MYSIZE_X * PIXELS) / 2.3 - MENU_SIZE, (MYSIZE_Y * PIXELS) / 2.3);
	mainmenu.setString("MENU\n1. Fill random and insert objects\n2. Create objects by yourself\n3. Create an object from a list\n"
		"4. Settings\n5. Quit\n");
	window.clear();
	print_background(window);
	window.draw(mainmenu);
	window.display();
}

void UI::print_number_of_phases(sf::RenderWindow& window, Game& g1)
{
	sf::Text sNumberofphases;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");
	sNumberofphases.setFont(font);
	sNumberofphases.setCharacterSize(30);
	sNumberofphases.setFillColor(sf::Color(255, 255, 255));
	sNumberofphases.setPosition(MENU_SIZE, MENU_SIZE / 4);

	std::string sLiczba = std::to_string(g1.get_number_of_phases());
	if (g1.get_number_of_phases() == 0)
	{
		sNumberofphases.setString("Starting board:");
	}
	else
	{
		if (g1.get_paused()) sNumberofphases.setString("Paused");
		else
		{
			sNumberofphases.setString("Phase number: ");
			window.draw(sNumberofphases);
			sNumberofphases.setPosition(3.2 * MENU_SIZE, MENU_SIZE / 4);
			sNumberofphases.setString(sLiczba);
			window.draw(sNumberofphases);
		}

	}
	window.draw(sNumberofphases);
	g1.increment_number_of_phases();
}
void UI::print_list(sf::RenderWindow& window)
{
	sf::Text list;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");

	list.setFont(font);
	list.setCharacterSize(39);
	list.setFillColor(sf::Color::White);
	list.setOutlineColor(sf::Color(0, 0, 0));
	list.setOutlineThickness(2);
	list.setPosition((MYSIZE_X * PIXELS) / 2.3 - MENU_SIZE, (MYSIZE_Y * PIXELS) / 2.3);
	list.setString("1. Lightweight space ship\n2. Pulsar\n3. Crocodile\n4. Diehard\n5. Cross\n6. Created object\n7. Back to main menu\n");
	print_background(window);
	window.draw(list);
	window.display();
}

void UI::print_drawing(sf::RenderWindow& window) //ampersand czyli referencja
{
	sf::Text drawing;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");

	drawing.setFont(font);
	drawing.setCharacterSize(25);
	drawing.setFillColor(sf::Color(255, 255, 255, 70));
	drawing.setPosition(WINDOW_SIZE_X * 0.3, WINDOW_SIZE_Y - 0.9 * MENU_SIZE);
	drawing.setString("LMB - set alive, RMB - set dead\n" "r - reset, " "s - start\nv - save to file");
	print_background(window);
	window.draw(drawing);
}

void UI::print_quit(sf::RenderWindow& window)
{
	sf::Text quit;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");
	quit.setFont(font);
	quit.setCharacterSize(25);
	quit.setFillColor(sf::Color(255, 255, 255, 70));
	quit.setPosition(0.3 * MENU_SIZE, WINDOW_SIZE_Y - 0.5 * MENU_SIZE);
	quit.setString("q - quit 		 w - quit and save			p - pause/unpause");
	window.draw(quit);
}

void UI::print_settings(sf::RenderWindow& window, Game& g4)
{
	sf::Text list;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");

	list.setFont(font);
	list.setCharacterSize(39);
	list.setFillColor(sf::Color::White);
	list.setOutlineColor(sf::Color(0, 0, 0));
	list.setOutlineThickness(2);
	list.setPosition((MYSIZE_X * PIXELS) / 2.3 - MENU_SIZE, (MYSIZE_Y * PIXELS) / 2.3);
	if (g4.get_closed_map() == 1) list.setString("1. Change speed \n2. Change rules\n3. Closed map\n4. Back to main menu");
	else list.setString("1. Change speed \n2. Change rules\n3. Opened map\n4. Back to main menu");
	print_background(window);
	window.draw(list);
	window.display();
}

void UI::print_speed_settings(sf::RenderWindow& window, int SlEEP_TIME_MS)
{
	sf::Text list, high;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");

	list.setFont(font);
	list.setCharacterSize(39);
	list.setFillColor(sf::Color::White);
	list.setOutlineColor(sf::Color(0, 0, 0));
	list.setOutlineThickness(2);
	list.setPosition((MYSIZE_X * PIXELS) / 2.3 - MENU_SIZE, (MYSIZE_Y * PIXELS) / 2.3);

	high.setFont(font);
	high.setCharacterSize(39);
	high.setFillColor(sf::Color::Yellow);
	high.setPosition((MYSIZE_X * PIXELS) / 2.3 - MENU_SIZE, (MYSIZE_Y * PIXELS) / 2.3);

	list.setString("1. 0.1s\n2. 0.25s\n3. 0.5s\n4. 1s\n5. Back to settings");
	if (SlEEP_TIME_MS == 100) high.setString("1. 0.1s");
	else if (SlEEP_TIME_MS == 250) high.setString("\n2. 0.25s");
	else if (SlEEP_TIME_MS == 500) high.setString("\n\n3. 0.5s");
	else if (SlEEP_TIME_MS == 1000) high.setString("\n\n\n4. 1s");

	print_background(window);
	window.draw(list);
	window.draw(high);
	window.display();
}

void UI::print_rules_settings(sf::RenderWindow& window, Game& g1)
{
	sf::Text list, list2, tmp1, tmp2, tmp3, exit;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");

	list.setFont(font);
	list.setCharacterSize(39);
	list.setFillColor(sf::Color::White);
	list.setOutlineColor(sf::Color(0, 0, 0));
	list.setOutlineThickness(2);
	list.setPosition((MYSIZE_X * PIXELS) / 10, (MYSIZE_Y * PIXELS) / 10);

	list2.setFont(font);
	list2.setCharacterSize(39);
	list2.setFillColor(sf::Color::White);
	list2.setOutlineColor(sf::Color(0, 0, 0));
	list2.setOutlineThickness(2);
	list2.setPosition((MYSIZE_X * PIXELS) / 10, (MYSIZE_Y * PIXELS) / 2);

	exit.setFont(font);
	exit.setCharacterSize(39);
	exit.setFillColor(sf::Color::White);
	exit.setOutlineColor(sf::Color(0, 0, 0));
	exit.setOutlineThickness(2);
	exit.setPosition((MYSIZE_X * PIXELS) / 10, (MYSIZE_Y * PIXELS) / 1.2);

	int dead_min = g1.get_dead_min();
	int alive_min = g1.get_alive_min();
	int alive_max = g1.get_alive_max();

	list.setString("Dead cell has to have " + std::to_string(dead_min) + "  (1. +	2. -)\nneighbours to become alive");
	list2.setString("Living cell has to have between\n " + std::to_string(alive_min) + "  (3. +   4. -) and " + std::to_string(alive_max)
		+ "  (5. +   6. -)\nneighbours to stay alive");
	exit.setString("7. Reset rules\n8. Back to settings");

	print_background(window);
	window.draw(list);
	window.draw(list2);
	window.draw(exit);
	window.display();
}

void UI::print_file_saved(sf::RenderWindow& window)
{
	sf::Text saved;
	sf::Font font;

	font.loadFromFile("./repo/arial.ttf");
	saved.setFont(font);
	saved.setCharacterSize(25);
	saved.setFillColor(sf::Color(255, 255, 255, 70));
	saved.setPosition(WINDOW_SIZE_X - 1.3 * MENU_SIZE, WINDOW_SIZE_Y - 0.5 * MENU_SIZE);
	saved.setString("file saved");
	window.draw(saved);
	window.display();
	sf::sleep(sf::milliseconds(420));
}

void UI::print_add_objects(sf::RenderWindow& window, Game& g1)
{
	sf::Text list, high;
	sf::Font font;
	font.loadFromFile("./repo/arial.ttf");

	list.setFont(font);
	list.setCharacterSize(19);
	list.setFillColor(sf::Color(255, 255, 255, 70));
	list.setPosition(WINDOW_SIZE_X - 2.3 * MENU_SIZE, 0.5 * MENU_SIZE);

	high.setFont(font);
	high.setCharacterSize(19);
	high.setFillColor(sf::Color::Yellow);
	high.setPosition(WINDOW_SIZE_X - 2.3 * MENU_SIZE, 0.5 * MENU_SIZE);

	list.setString("list of objects\n1. Lightweight space ship\n2. Square\n3. Crocodile\n4. Diehard\n5. Dot\n6. Trigger\n7. Circle");
	if (g1.get_adding_mode() == 1) high.setString("\n1. Lightweight space ship");
	else if (g1.get_adding_mode() == 2) high.setString("\n\n2. Square");
	else if (g1.get_adding_mode() == 3) high.setString("\n\n\n3. Crocodile");
	else if (g1.get_adding_mode() == 4) high.setString("\n\n\n\n4. Diehard");
	else if (g1.get_adding_mode() == 5) high.setString("\n\n\n\n\n5. Dot");
	else if (g1.get_adding_mode() == 6) high.setString("\n\n\n\n\n\n6. Trigger");
	else if (g1.get_adding_mode() == 7) high.setString("\n\n\n\n\n\n\n7. Circle");
	window.draw(list);
	window.draw(high);

}
