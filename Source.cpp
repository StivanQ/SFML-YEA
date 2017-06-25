#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "variabile.h"

#define PI 3.14159265

using namespace std;


int main()
{
//initializare
	initializare_player();
    antialiasing(8); 
	crearewindow();

//setare origine
	setare_origine();

//butoane
	creare_buton1();
	creare_buton2();
	creare_buton3();
	
//font
	definire_fonturi();

//text
	creare_text1();
	creare_text2();
	creare_text3();
    
//meniu
	culoare_meniu();

	//gameloop
	while (window.isOpen())
	{
			rotation = 360 - player.getRotation() + 90;
			mousePos = sf::Mouse::getPosition(window);
			playerPos = player.getPosition();

			//afisare la fiecare 10 tickuri debug
			debugger();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			miscare(); //miscare WASD

			window.clear(background);
			window.draw(player);

			if(timp_meniu == false && timp_meniu_escape == false) //debugger
			window.draw(buton);

			buton_dreapta(); //buton dreapta jos

			afisare_meniu(); //meniu

//escape
			creare_textesc();
			creare_textesc2();
			meniu_escape();
			window.display();
		}
	return 0;
}
// waeoweoaweoaweoawoeaweawoeaw