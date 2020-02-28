#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "Game.h"
#include "UI.h"
#include "Windows.h"
#include "Objects.h"


//ZAMIAST INT MAIN UØYWAM TEGO, ABY URUCHOMI£O SI  JEDYNIE OKNO SFML A NIE CMD
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Game of life"); //creates window object

	sf::Event event;

	//UTWORZENIE ZMIENNEJ KT”RA ODPOWIADA ZA CZAS POMI DZY ZMIAN• TURY
	int SLEEP_TIME_MS = 100;

	//UTWORZENIE OBIEKT”W KLASY GAME - PO JEDNYM DLA KAØDEGO MODU£U
	Game g1, g2, g3a, g3b, g3c, g3d, g3e, g3f, g4;

	while (window.isOpen())
	{
		while (1)
		{
			window.clear();
			UI::print_main_menu(window);
			// ==================SEKCJA 1 - PLANSZA Z LOSOWYMI STANAMI KOM”REK I MOZLIWOSCIA WSTAWIANIA WBUDOWANYCH OBIEKTOW===================
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
			{
				window.clear();

				//SPRAWDZAM, CZY NIE PRAWD• JEST ØE NAST•PI£O WYJåCIE Z ZAMIAREM ZAPISU STANU MAPY. JEåLI NAST•PI£O - GET_QWR ZWR”CI WARTOå∆ 1. W PRZECIWNYM WYPADKU 0.
				//UMOØLIWIA TO ZAPISANIE STANU PLANSZY JAK I ODPOWIEDNIE USTAWIENIE NUMERU TURY
				if (!g1.get_qwr())
				{
					g1.fill_random();
					g1.set_number_of_phases(0);
				}
				else g1.set_number_of_phases(g1.get_qwr_tmp());
				sf::sleep(sf::milliseconds(100));
				//P TLA G£”WNA MODU£U 1
				while (1)
				{
					UI::print_background(window);
					UI::print_quit(window);
					UI::print_add_objects(window, g1);

					//SPRAWDZAM CZY ZAPAUZOWANO. JEåLI TAK, TO NUMER TURY POZOSTAJE NIEZMIENIONY
					if (g1.get_paused()) g1.set_number_of_phases(g1.get_number_of_phases() - 1);
					UI::print_number_of_phases(window, g1);
					g1.print(window, g1);
					sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
					//SPRAWDZAM CZY KLIKNI TO Q. JEåLI TAK, USTAWIAM STAN WYJåCIA Z ZAPISEM NA 0, JAK I STAN ZAPAUZOWANIA NA 0. WYCHODZ  Z P TLI G£”WNEJ MODU£U 1
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
					{
						g1.set_paused(0);
						g1.set_qwr(0);
						break;
					}
					//SPRAWDZAM CZY KLIKNI TO W. JEåLI TAK, USTAWIAM STAN WYJåCIA Z ZAPISEM NA 1, DZI KI CZEMU PRZY PONOWNYM WEJåCIU DO MODU£U NIE ZRESETUJE ON SWOJEGO STANU
					//USTAWIAM R”WNIEØ DO ZMIENNEJ POMOCNICZEJ OBECNY LICZNIK TURY, BY PRZY P”èNIEJSZYM WEJåCIU W MODU£ PRZYPISA∆ GO SPOWROTEM. NAST PNIE WYCHODZ  Z P TLI G£”WNEJ MODU£U 1.
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
					{
						g1.set_qwr(1);
						g1.set_qwr_tmp(g1.get_number_of_phases());
						break;
					}
					//SPRAWDZAM CZY KLIKNI TO P. JEåLI TAK, TO USTAWIAM STAN PAUZY NA PRZECIWNY.
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
					{
						g1.set_paused(!g1.get_paused());
						sf::sleep(sf::milliseconds(420));
					}
					//BLOK ZWIAZANY ZE WSTAWIANIEM OBIEKTOW NA PLANSZE
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
					{
						g1.change_adding_mode(1);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 1)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::space_ship(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
					{
						g1.change_adding_mode(2);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 2)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::square(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
					{
						g1.change_adding_mode(3);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 3)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::crocodile(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
					{
						g1.change_adding_mode(4);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 4)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::diehard(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5))
					{
						g1.change_adding_mode(5);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 5)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::dot(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad6))
					{
						g1.change_adding_mode(6);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 6)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::trigger(window, g1);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad7))
					{
						g1.change_adding_mode(7);
						sf::sleep(sf::milliseconds(50));
					}
					if (g1.get_adding_mode() == 7)
					{
						if (window.pollEvent(event))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) Objects::circle(window, g1);
						}
					}

					//JEåLI NIE SPAUZOWANO, TO WYKONUJ  G£”WNE OPERACJE MODU£U. OBLICZAM NAST PN• FAZ  I WYKONUJ  J•.
					if (!g1.get_paused())
					{
						g1.calc_next_phase();
						g1.do_next_phase();
						window.clear();

					}
				}
				break;
			}
			// ==================SEKCJA 2 - RYSOWANIE MYSZK•===================
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
			{
				window.clear();
				bool start;
				if (!g2.get_qwr())
				{
					start = 1;
					g2.set_blank();
				}
				else
				{
					start = 0;
					g2.set_number_of_phases(g2.get_qwr_tmp());
				}
				while (1)
				{
					if (!g2.get_qwr())
					{
						if (start)
						{
							g2.set_blank();
							g2.set_number_of_phases(0);
							window.clear();
						}

						while (start) {
							window.clear();
							UI::print_drawing(window);
							g2.print(window, g2);

							if (window.pollEvent(event))
							{
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))  g2.set_alive_by_mouse(window, true);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Right))  g2.set_alive_by_mouse(window, false);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V))
							{
								UI::print_file_saved(window);
								g2.save_to_file();

							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) start = !start;
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) break;
						}
					}

					if (!start)
					{
						UI::print_background(window);
						if (g2.get_paused()) g2.set_number_of_phases(g2.get_number_of_phases() - 1);
						UI::print_number_of_phases(window, g2);
						UI::print_quit(window);

						g2.print(window, g2);
						sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
						{
							g2.set_paused(0);
							g2.set_qwr(0);
							break;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
						{
							g2.set_qwr(1);
							g2.set_qwr_tmp(g2.get_number_of_phases());
							break;
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
						{
							g2.set_paused(!g2.get_paused());
							sf::sleep(sf::milliseconds(420));
						}
						if (!g2.get_paused())
						{
							g2.calc_next_phase();
							g2.do_next_phase();
							window.clear();
						}
					}
				}
				break;
			}
			// ==================BUILT IN OBJECTS===================
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
			{
				window.clear();
				UI::print_list(window);
				sf::sleep(sf::milliseconds(420));

				while (1)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
					{
						if (!g3a.get_qwr())
						{
							Objects::space_ship(g3a);
							g3a.set_number_of_phases(0);
						}
						else g3a.set_number_of_phases(g3a.get_qwr_tmp());
						window.clear();
						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3a.get_paused()) g3a.set_number_of_phases(g3a.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3a);
							g3a.print(window, g3a);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3a.set_paused(0);
								g3a.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3a.set_qwr(1);
								g3a.set_qwr_tmp(g3a.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3a.set_paused(!g3a.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3a.get_paused())
							{
								g3a.calc_next_phase();
								g3a.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
					{
						if (!g3b.get_qwr())
						{
							Objects::pulsar(g3b);
							g3b.set_number_of_phases(0);
						}
						else g3b.set_number_of_phases(g3b.get_qwr_tmp());
						window.clear();

						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3b.get_paused()) g3b.set_number_of_phases(g3b.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3b);
							g3b.print(window, g3b);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3b.set_paused(0);
								g3b.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3b.set_qwr(1);
								g3b.set_qwr_tmp(g3b.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3b.set_paused(!g3b.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3b.get_paused())
							{
								g3b.calc_next_phase();
								g3b.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
					{
						if (!g3c.get_qwr())
						{
							Objects::crocodile(g3c);
							g3c.set_number_of_phases(0);
						}
						else g3c.set_number_of_phases(g3c.get_qwr_tmp());
						window.clear();
						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3c.get_paused()) g3c.set_number_of_phases(g3c.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3c);
							g3c.print(window, g3c);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3c.set_paused(0);
								g3c.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3c.set_qwr(1);
								g3c.set_qwr_tmp(g3c.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3c.set_paused(!g3c.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3c.get_paused())
							{
								g3c.calc_next_phase();
								g3c.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
					{
						if (!g3d.get_qwr())
						{
							Objects::diehard(g3d);
							g3d.set_number_of_phases(0);
						}
						else g3d.set_number_of_phases(g3d.get_qwr_tmp());
						window.clear();
						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3d.get_paused()) g3d.set_number_of_phases(g3d.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3d);
							g3d.print(window, g3d);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3d.set_paused(0);
								g3d.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3d.set_qwr(1);
								g3d.set_qwr_tmp(g3d.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3d.set_paused(!g3d.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3d.get_paused())
							{
								g3d.calc_next_phase();
								g3d.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5))
					{
						if (!g3e.get_qwr())
						{
							Objects::cross(g3e);
							g3e.set_number_of_phases(0);
						}
						else g3e.set_number_of_phases(g3e.get_qwr_tmp());
						window.clear();
						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3e.get_paused()) g3e.set_number_of_phases(g3e.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3e);
							g3e.print(window, g3e);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3e.set_paused(0);
								g3e.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3e.set_qwr(1);
								g3e.set_qwr_tmp(g3e.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3e.set_paused(!g3e.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3e.get_paused())
							{
								g3e.calc_next_phase();
								g3e.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad6))
					{
						if (!g3f.get_qwr())
						{
							g3f.read_from_file();
							g3f.set_number_of_phases(0);
						}
						else g3f.set_number_of_phases(g3f.get_qwr_tmp());
						window.clear();
						while (1)
						{
							UI::print_background(window);
							UI::print_quit(window);
							if (g3f.get_paused()) g3f.set_number_of_phases(g3f.get_number_of_phases() - 1);
							UI::print_number_of_phases(window, g3f);
							g3f.print(window, g3f);
							sf::sleep(sf::milliseconds(SLEEP_TIME_MS));
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
							{
								g3f.set_paused(0);
								g3f.set_qwr(0);
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
							{
								g3f.set_qwr(1);
								g3f.set_qwr_tmp(g3f.get_number_of_phases());
								break;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
							{
								g3f.set_paused(!g3f.get_paused());
								sf::sleep(sf::milliseconds(420));
							}
							if (!g3f.get_paused())
							{
								g3f.calc_next_phase();
								g3f.do_next_phase();
								window.clear();
							}
						}
						break;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad7)) break;
				}
				break;
			}
			// ==================SETTINGS===================
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
			{
				sf::sleep(sf::milliseconds(420));
				while (1)
				{
					window.clear();
					UI::print_settings(window, g4);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
					{
						window.clear();
						UI::print_speed_settings(window, SLEEP_TIME_MS);
						sf::sleep(sf::milliseconds(420));
						while (1)
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
							{
								SLEEP_TIME_MS = 100;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
							{
								SLEEP_TIME_MS = 250;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
							{
								SLEEP_TIME_MS = 500;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
							{
								SLEEP_TIME_MS = 1000;
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5))
							{
								sf::sleep(sf::milliseconds(420));
								break;
							}
							window.clear();
							UI::print_speed_settings(window, SLEEP_TIME_MS);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
					{
						window.clear();
						UI::print_rules_settings(window, g4);
						sf::sleep(sf::milliseconds(420));
						while (1)
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1))
							{
								if (g4.get_dead_min() < 8) g4.set_dead_min(g4.get_dead_min() + 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2))
							{
								if (g4.get_dead_min() > 0) g4.set_dead_min(g4.get_dead_min() - 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
							{
								if (g4.get_alive_min() < g4.get_alive_max()) g4.set_alive_min(g4.get_alive_min() + 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
							{
								if (g4.get_alive_min() > 0) g4.set_alive_min(g4.get_alive_min() - 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5))
							{
								if (g4.get_alive_max() < 8) g4.set_alive_max(g4.get_alive_max() + 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad6))
							{
								if (g4.get_alive_max() > g4.get_alive_min()) g4.set_alive_max(g4.get_alive_max() - 1);
								sf::sleep(sf::milliseconds(420));
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad7))
							{
								g4.set_alive_max(3);
								g4.set_alive_min(2);
								g4.set_dead_min(3);
							}
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad8))
							{
								sf::sleep(sf::milliseconds(420));
								break;
							}
							window.clear();
							UI::print_rules_settings(window, g4);
						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3))
					{
						g1.change_closed_map();
						sf::sleep(sf::milliseconds(420));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4))
					{
						sf::sleep(sf::milliseconds(420));
						break;
					}
				}
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5)) return 0;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
		}
	}
}

