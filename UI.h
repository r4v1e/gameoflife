#pragma once
class UI
{
public:
	UI() = delete;
	static void print_main_menu(sf::RenderWindow& window);
	static void print_list(sf::RenderWindow& window);
	static void print_drawing(sf::RenderWindow& window);
	static void print_quit(sf::RenderWindow& window);
	static void print_background(sf::RenderWindow& window);
	static void print_number_of_phases(sf::RenderWindow& window, Game& g1);
	static void print_settings(sf::RenderWindow& window, Game& g1);
	static void print_speed_settings(sf::RenderWindow& window, int SLEEP_TIME_MS);
	static void print_rules_settings(sf::RenderWindow& window, Game& g1);
	static void print_file_saved(sf::RenderWindow& window);
	static void print_add_objects(sf::RenderWindow& window, Game& g1);
};

