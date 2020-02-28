#include "Objects.h"

void Objects::set_blank(Game& g)
{
	for (int i = 0; i < MYSIZE_X; i++)
	{
		for (int j = 0; j < MYSIZE_Y; j++)
		{
			g.map[i][j] = 0;
		}
	}
}

void Objects::space_ship(Game& g)
{
	set_blank(g);

	int tmp = MYSIZE_Y / 2;
	g.map[MYSIZE_X - 1][tmp] = 1;
	g.map[MYSIZE_X - 4][tmp] = 1;
	g.map[MYSIZE_X - 5][tmp + 1] = 1;
	g.map[MYSIZE_X - 5][tmp + 2] = 1;
	g.map[MYSIZE_X - 1][tmp + 2] = 1;
	g.map[MYSIZE_X - 2][tmp + 3] = 1;
	g.map[MYSIZE_X - 3][tmp + 3] = 1;
	g.map[MYSIZE_X - 4][tmp + 3] = 1;
	g.map[MYSIZE_X - 5][tmp + 3] = 1;

}

void Objects::space_ship(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS - 2;
	int x = (mousePos.x - 100) / PIXELS + 5;

	if (mousePos.x >= 100 && mousePos.y >= 100 && y < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x - 1][y] = 1;
		g.map[x - 4][y] = 1;
		g.map[x - 5][y + 1] = 1;
		g.map[x - 5][y + 2] = 1;
		g.map[x - 1][y + 2] = 1;
		g.map[x - 2][y + 3] = 1;
		g.map[x - 3][y + 3] = 1;
		g.map[x - 4][y + 3] = 1;
		g.map[x - 5][y + 3] = 1;
	}
}

void Objects::pulsar(Game& g)
{
	set_blank(g);

	int tmpx = MYSIZE_X / 2;
	int tmp_y = MYSIZE_Y / 2;

	g.map[tmpx - 1][tmpx - 2] = 1; g.map[tmpx + 1][tmpx + 2] = 1;
	g.map[tmpx - 1][tmpx - 3] = 1; g.map[tmpx + 1][tmpx + 3] = 1;
	g.map[tmpx - 1][tmpx - 4] = 1; g.map[tmpx + 1][tmpx + 4] = 1;
	g.map[tmpx + 1][tmpx - 2] = 1; g.map[tmpx - 1][tmpx + 2] = 1;
	g.map[tmpx + 1][tmpx - 3] = 1; g.map[tmpx - 1][tmpx + 3] = 1;
	g.map[tmpx + 1][tmpx - 4] = 1; g.map[tmpx - 1][tmpx + 4] = 1;

	g.map[tmpx - 6][tmpx - 2] = 1; g.map[tmpx - 6][tmpx + 2] = 1;
	g.map[tmpx - 6][tmpx - 3] = 1; g.map[tmpx - 6][tmpx + 3] = 1;
	g.map[tmpx - 6][tmpx - 4] = 1; g.map[tmpx - 6][tmpx + 4] = 1;
	g.map[tmpx + 6][tmpx - 2] = 1; g.map[tmpx + 6][tmpx + 2] = 1;
	g.map[tmpx + 6][tmpx - 3] = 1; g.map[tmpx + 6][tmpx + 3] = 1;
	g.map[tmpx + 6][tmpx - 4] = 1; g.map[tmpx + 6][tmpx + 4] = 1;

	g.map[tmpx - 2][tmpx - 1] = 1; g.map[tmpx - 2][tmpx + 1] = 1;
	g.map[tmpx - 3][tmpx - 1] = 1; g.map[tmpx - 3][tmpx + 1] = 1;
	g.map[tmpx - 4][tmpx - 1] = 1; g.map[tmpx - 4][tmpx + 1] = 1;
	g.map[tmpx + 2][tmpx - 1] = 1; g.map[tmpx + 2][tmpx + 1] = 1;
	g.map[tmpx + 3][tmpx - 1] = 1; g.map[tmpx + 3][tmpx + 1] = 1;
	g.map[tmpx + 4][tmpx - 1] = 1; g.map[tmpx + 4][tmpx + 1] = 1;

	g.map[tmpx - 2][tmpx - 6] = 1; g.map[tmpx - 2][tmpx + 6] = 1;
	g.map[tmpx - 3][tmpx - 6] = 1; g.map[tmpx - 3][tmpx + 6] = 1;
	g.map[tmpx - 4][tmpx - 6] = 1; g.map[tmpx - 4][tmpx + 6] = 1;
	g.map[tmpx + 2][tmpx - 6] = 1; g.map[tmpx + 2][tmpx + 6] = 1;
	g.map[tmpx + 3][tmpx - 6] = 1; g.map[tmpx + 3][tmpx + 6] = 1;
	g.map[tmpx + 4][tmpx - 6] = 1; g.map[tmpx + 4][tmpx + 6] = 1;
}

void Objects::square(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS;
	int x = (mousePos.x - 100) / PIXELS;

	if (mousePos.x >= 100 && mousePos.y >= 100 && x < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x][y] = 1;
		g.map[x + 1][y] = 1;
		g.map[x][y + 1] = 1;
		g.map[x + 1][y + 1] = 1;
	}
}
void Objects::dot(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS;
	int x = (mousePos.x - 100) / PIXELS;

	if (mousePos.x >= 100 && mousePos.y >= 100 && x < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x][y - 1] = 1;
		g.map[x - 1][y] = 1;
		g.map[x + 1][y] = 1;
		g.map[x][y + 1] = 1;
	}
}
void Objects::trigger(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS;
	int x = (mousePos.x - 100) / PIXELS;

	if (mousePos.x >= 100 && mousePos.y >= 100 && x < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x][y - 1] = 1;
		g.map[x][y] = 1;
		g.map[x][y + 1] = 1;
	}
}
void Objects::circle(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS;
	int x = (mousePos.x - 100) / PIXELS;

	if (mousePos.x >= 100 && mousePos.y >= 100 && x < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x][y - 1] = 1;
		g.map[x][y + 1] = 1;
		g.map[x + 1][y + 1] = 1;
		g.map[x + 1][y] = 1;
		g.map[x + 1][y - 1] = 1;
		g.map[x - 1][y] = 1;
		g.map[x - 1][y - 1] = 1;
		g.map[x - 1][y + 1] = 1;
	}
}
void Objects::crocodile(Game& g)
{
	set_blank(g);

	int tmpx = MYSIZE_X / 2;
	int tmpy = MYSIZE_Y / 2;

	g.map[tmpx - 2][tmpy] = 1;	   g.map[tmpx - 5][tmpy] = 1;
	g.map[tmpx - 2][tmpy + 1] = 1; g.map[tmpx - 5][tmpy + 1] = 1;
	g.map[tmpx - 2][tmpy - 1] = 1; g.map[tmpx - 5][tmpy - 1] = 1;
	g.map[tmpx + 3][tmpy] = 1;     g.map[tmpx + 6][tmpy] = 1;
	g.map[tmpx + 3][tmpy + 1] = 1; g.map[tmpx + 6][tmpy + 1] = 1;
	g.map[tmpx + 3][tmpy - 1] = 1; g.map[tmpx + 6][tmpy - 1] = 1;

	g.map[tmpx - 3][tmpy + 2] = 1; g.map[tmpx - 3][tmpy - 2] = 1;
	g.map[tmpx - 4][tmpy + 2] = 1; g.map[tmpx - 4][tmpy - 2] = 1;
	g.map[tmpx + 4][tmpy + 2] = 1; g.map[tmpx + 4][tmpy - 2] = 1;
	g.map[tmpx + 5][tmpy + 2] = 1; g.map[tmpx + 5][tmpy - 2] = 1;
}

void Objects::crocodile(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS - 2;
	int x = (mousePos.x - 100) / PIXELS + 5;

	if (mousePos.x >= 100 && mousePos.y >= 100 && y < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x - 2][y] = 1;	 g.map[x - 5][y] = 1;
		g.map[x - 2][y + 1] = 1; g.map[x - 5][y + 1] = 1;
		g.map[x - 2][y - 1] = 1; g.map[x - 5][y - 1] = 1;
		g.map[x + 3][y] = 1;     g.map[x + 6][y] = 1;
		g.map[x + 3][y + 1] = 1; g.map[x + 6][y + 1] = 1;
		g.map[x + 3][y - 1] = 1; g.map[x + 6][y - 1] = 1;

		g.map[x - 3][y + 2] = 1; g.map[x - 3][y - 2] = 1;
		g.map[x - 4][y + 2] = 1; g.map[x - 4][y - 2] = 1;
		g.map[x + 4][y + 2] = 1; g.map[x + 4][y - 2] = 1;
		g.map[x + 5][y + 2] = 1; g.map[x + 5][y - 2] = 1;
	}
}

void Objects::diehard(Game& g)
{
	set_blank(g);

	int tmpx = MYSIZE_X / 2;
	int tmpy = MYSIZE_Y / 2;

	g.map[tmpx - 2][tmpy] = 1; g.map[tmpx - 3][tmpy] = 1;
	g.map[tmpx - 2][tmpy + 1] = 1; g.map[tmpx + 2][tmpy + 1] = 1;
	g.map[tmpx + 3][tmpy + 1] = 1; g.map[tmpx + 4][tmpy + 1] = 1;
	g.map[tmpx + 3][tmpy - 1] = 1;
}

void Objects::diehard(sf::RenderWindow& window, Game& g)
{
	sf::Vector2i mousePos;
	mousePos = sf::Mouse::getPosition(window);

	int y = (mousePos.y - 100) / PIXELS - 2;
	int x = (mousePos.x - 100) / PIXELS + 5;

	if (mousePos.x >= 100 && mousePos.y >= 100 && y < MYSIZE_X && y >= 0 && y < MYSIZE_Y)
	{
		g.map[x - 2][y] = 1; g.map[x - 3][y] = 1;
		g.map[x - 2][y + 1] = 1; g.map[x + 2][y + 1] = 1;
		g.map[x + 3][y + 1] = 1; g.map[x + 4][y + 1] = 1;
		g.map[x + 3][y - 1] = 1;
	}
}

void Objects::cross(Game& g)
{
	set_blank(g);

	int tmpx = MYSIZE_X / 2;
	int tmpy = MYSIZE_Y / 2;

	for (int i = 0; i < MYSIZE_X; i++)
	{
		g.map[i][tmpy] = 1;
		g.map[tmpx][i] = 1;
	}
}

