#include "Game.h"

int Game::dead_min = 3;
int Game::alive_min = 2;
int Game::alive_max = 3;
int Game::closed_map = -1;

void Game::set_qwr_tmp(int new_number)
{
	qwr_tmp = new_number;
}

void Game::set_qwr(bool n)
{
	qwr = n;
}

void Game::set_paused(bool n)
{
	paused = n;
}

int Game::get_qwr_tmp() const
{
	return qwr_tmp;
}

bool Game::get_qwr() const
{
	return qwr;
}

bool Game::get_paused() const
{
	return paused;
}

int Game::get_adding_mode() const
{
	return adding_mode;
}

int Game::get_closed_map() const
{
	return closed_map;
}

void Game::set_dead_min(int new_dead_min)
{
	dead_min = new_dead_min;
}

int Game::get_dead_min() const
{
	return dead_min;
}

void Game::set_alive_min(int new_number)
{
	alive_min = new_number;
}

void Game::set_alive_max(int new_number)
{
	alive_max = new_number;
}

int Game::get_alive_min() const
{
	return alive_min;
}

int Game::get_alive_max() const
{
	return alive_max;
}

int Game::get_number_of_phases() const
{
	return number_of_phases;
}

void Game::set_number_of_phases(int new_number)
{
	number_of_phases = new_number;
}

void Game::change_adding_mode(int change)
{
	adding_mode = change;
}

void Game::change_closed_map()
{
	closed_map *= -1;
}


void Game::increment_number_of_phases()
{
	number_of_phases += 1;
}


void Game::set_blank()
{
	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			map[i][j] = 0;
		}
	}
}

void Game::fill_random()
{
	srand(time(NULL));
	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			map[i][j] = rand() % 2;
		}
	}
}

void Game::calc_next_phase()
{
	int x = 21;
	int y = 21;
	if (closed_map == 1)
	{
		//CLOSED MAP
		//FIRST AND LAST ROW
		for (int i = 1; i < x; i++)
		{
			next_phase[i][0] = map[i - 1][0] + map[i + 1][0] + map[i - 1][1] + map[i][1] + map[i + 1][1];
			next_phase[i][y] = map[i - 1][y] + map[i + 1][y] + map[i - 1][y - 1] + map[i][y - 1] + map[i + 1][y - 1];
		}
		//INSIDE
		for (int i = 1; i < x; i++)
		{
			for (int j = 1; j < y; j++)
			{
				next_phase[i][j] =
					map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] +
					map[i][j - 1] + map[i][j + 1] +
					map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
			}
		}
		//FIRST AND LAST COLUMN
		for (int i = 1; i < y; i++)
		{
			next_phase[0][i] = map[0][i - 1] + map[0][i + 1] + map[1][i - 1] + map[1][i] + map[1][i + 1];
			next_phase[x][i] = map[x][i - 1] + map[x][i + 1] + map[x - 1][i - 1] + map[x - 1][i] + map[x - 1][i + 1];
		}
		//[0][0]
		next_phase[0][0] = map[0][1] + map[1][1] + map[1][0];
		//[X][Y]
		next_phase[x][y] = map[x - 1][y] + map[x - 1][y - 1] + map[x][y - 1];
		//[0][Y]
		next_phase[0][y] = map[0][y - 1] + map[1][y - 1] + map[1][y];
		//[X][0]
		next_phase[x][0] = map[x - 1][0] + map[x - 1][1] + map[x][1];
	}
	else if (closed_map == -1)
	{
		//OPENED MAP
		//FIRST AND LAST ROW
		for (int i = 1; i < x; i++)
		{
			next_phase[i][0] = map[i - 1][0] + map[i + 1][0] + map[i - 1][1] + map[i][1] + map[i + 1][1] + map[i - 1][y] + map[i][y] + map[i + 1][y];
			next_phase[i][y] = map[i - 1][y] + map[i + 1][y] + map[i - 1][0] + map[i][0] + map[i + 1][0] + map[i - 1][y - 1] + map[i][y - 1] + map[i + 1][y - 1];
		}
		//INSIDE
		for (int i = 1; i < x; i++)
		{
			for (int j = 1; j < y; j++)
			{
				next_phase[i][j] =
					map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] +
					map[i][j - 1] + map[i][j + 1] +
					map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
			}
		}
		//FIRST AND LAST COLUMN
		for (int i = 1; i < y; i++)
		{
			next_phase[0][i] = map[0][i - 1] + map[0][i + 1] + map[1][i - 1] + map[1][i] + map[1][i + 1] + map[x][i - 1] + map[x][i] + map[x][i + 1];
			next_phase[x][i] = map[x][i - 1] + map[x][i + 1] + map[0][i] + map[0][i - 1] + map[0][i + 1] + map[x - 1][i - 1] + map[x - 1][i] + map[x - 1][i + 1];
		}
		//[0][0]
		next_phase[0][0] = map[0][1] + map[1][1] + map[1][0] + map[0][y] + map[1][y] + map[x][0] + map[x][1] + map[x][y];
		//[X][Y]
		next_phase[x][y] = map[x - 1][y] + map[x - 1][y - 1] + map[x][y - 1] + map[0][0] + map[x][0] + map[x - 1][0] + map[0][y] + map[0][y - 1];
		//[0][Y]
		next_phase[0][y] = map[0][y - 1] + map[1][y - 1] + map[1][y] + map[x][y] + map[x][y - 1] + map[x][0] + map[0][0] + map[1][0];
		//[X][0]
		next_phase[x][0] = map[x - 1][0] + map[x - 1][1] + map[x][1] + map[0][y] + map[x][y] + map[x - 1][y] + map[0][0] + map[0][1];
	}
}

void Game::do_next_phase()
{
	//IF DEAD CELL HAS 3 NEIGHBOURS, IT COMES ALIVE
	//IF ALIVE CELL HAS 2 OR 3 NEIGHBOURS, IT STAYS ALIVE, OTHERWISE IT DIES

	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			if (map[i][j] == 0) //IF DEAD CELL..
			{
				if (next_phase[i][j] == dead_min) map[i][j] = 1; //..HAS 3 NEIGHBOURS IT COMES ALIVE
			}
			else //ELSE IF ALIVE CELL ..
			{
				if (next_phase[i][j] >= alive_min && next_phase[i][j] <= alive_max) //..HAS 2 OR 3 NEIGHBOURS IT STAYS ALIVE.
				{
					map[i][j] = 1;
				}
				else //..ELSE IT DIES.
				{
					map[i][j] = 0;
				}
			}
		}
	}
}

void Game::print(sf::RenderWindow& window, Game& g)
{
	sf::RectangleShape cell(sf::Vector2f(PIXELS, PIXELS));

	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			if (g.map[i][j] == 1) cell.setFillColor(sf::Color::White);
			else cell.setFillColor(sf::Color::Black);
			cell.setOutlineColor(sf::Color(168, 168, 168));
			cell.setOutlineThickness(1);
			cell.setPosition(sf::Vector2f((i * PIXELS) + 100, (j * PIXELS) + 100));
			window.draw(cell);
		}
	}
	window.display();
	if (number_of_phases == 1) sf::sleep(sf::milliseconds(1500));
}

void Game::set_alive_by_mouse(sf::RenderWindow& window, bool leftClick)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS;
	int x = (mousePos.x - 100) / PIXELS;
	//std::cout << "x: " << x << " y: " << y << std::endl;
	if (mousePos.x >= 100 && mousePos.y >= 100 && y < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		if (leftClick == 1)	map[x][y] = 1;
		else map[x][y] = 0;
	}
}

void Game::save_to_file()
{
	std::ofstream myfile;
	myfile.open("repo/drawings.txt");
	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			myfile << map[j][i];
		}
		myfile << std::endl;
	}
	myfile.close();
}

void Game::read_from_file()
{
	std::string line;
	std::ifstream myfile;
	myfile.open("repo/drawings.txt");

	int j = 0;
	while (getline(myfile, line))
	{
		for (int i = 0; i < MYSIZE_X; i++)
		{
			map[i][j] = (line[i] == '0') ? 0 : 1;
		}
		j++;
	}
	myfile.close();
}
