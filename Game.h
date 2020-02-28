#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <string>

const int MYSIZE_X = 22;	//X NUMBER OF CELLS			}
const int MYSIZE_Y = 22;	//Y NUMBER OF CELLS			}THESE TWO SHOULD BE THE SAME 
const int MENU_SIZE = 100;	//DISTANCE BETWEEN BORDER OF SCREEN AND BORDER OF BOARD [PX]
const float PIXELS = 32.f;	//CERTAIN AMOUNT OF PIXELS, THAT ONE CELL WILL HAVE

const int WINDOW_SIZE_X = MYSIZE_X * PIXELS + 2 * MENU_SIZE + 150;	//X SIZE OF ENTIRE WINDOW
const int WINDOW_SIZE_Y = MYSIZE_Y * PIXELS + 2 * MENU_SIZE;	//Y SIZE OF ENTIRE WINDOW

class Game
{
	friend class Objects;

private:
	bool map[MYSIZE_X][MYSIZE_Y],
		qwr = 0,
		paused = 0;

	int next_phase[MYSIZE_X][MYSIZE_Y],
		number_of_phases = 0,
		qwr_tmp,
		adding_mode = -1;

	static int
		dead_min,
		alive_min,
		alive_max,
		closed_map;

public:
	//SETTERS
	void set_qwr_tmp(int new_number);
	void set_qwr(bool n);
	void set_paused(bool n);
	void set_dead_min(int new_dead_min);
	void set_alive_min(int new_number);
	void set_alive_max(int new_number);
	void set_number_of_phases(int new_number);
	void change_adding_mode(int change);
	void change_closed_map();

	//GETTERS
	int get_qwr_tmp()const;
	int get_dead_min()const;
	int get_alive_min()const;
	int get_alive_max()const;
	int get_number_of_phases()const;
	bool get_qwr() const;
	bool get_paused()const;
	int get_adding_mode()const;
	int get_closed_map()const;

	void increment_number_of_phases();

	void set_blank();
	void fill_random();

	//GAME PRINTING FUNCTION
	void print(sf::RenderWindow& window, Game& g);

	//NEXT PHASE 
	void calc_next_phase();
	void do_next_phase();

	//MOUSE INTERACTIONS
	void set_alive_by_mouse(sf::RenderWindow& window, bool leftClick);

	//SAVING AND READING FROM A FILE
	void save_to_file();
	void read_from_file();
};

