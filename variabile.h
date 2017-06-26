#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define PI 3.14159265

using namespace std;

//Variabile
sf::RectangleShape player(sf::Vector2f(15.f, 25.f));
bool timp_meniu = true;
int lungimeWindow = 1280;
int inaltimeWindow = 720;
int i = 0;
sf::Vector2f playerPos;
sf::Color background(69, 88, 90), playerc(25, 12, 112), butonc(210, 105, 30), meniuc(255, 255, 255, 255);
bool dropdown = false;
int meniualfa = 255;
bool timp_meniu_escape = false;
int asdf = 0,aasdf = 0;
int volum = 25, variabilamuz = 1;
bool muzicq = false;
bool bagEuPula = true;
bool mergem = true;
int zxc1 = 1, zxc2 = 1;
//muzicTimer
sf::Clock muzicClock;
sf::Time muzicTime;
float secunde=0;

//Seteaza culoarea si pozitia initiala a playerului
void initializare_player()
{
	playerPos.x = lungimeWindow / 2;
	playerPos.y = inaltimeWindow / 2;
	player.setFillColor(playerc);
	player.setPosition(playerPos);
}

//Setari
sf::ContextSettings settings;
//Setari de antialiasing (default = 8)
void antialiasing(int x)
{
	if (x <= 0 && x >= 16)
	{
		x = 8;
	}
	settings.antialiasingLevel = x;
}

//muzica
sf::Music music;
void initializare_muzica() {
	music.openFromFile("muzica/Rock.ogg");
	music.setLoop(true);
	music.setVolume(volum);         // reduce the volume
}


//Window
sf::RenderWindow window(sf::VideoMode(lungimeWindow, inaltimeWindow), "Masinuta!", sf::Style::None, settings);
//Creare window, setare de frame, setare de vsync
void crearewindow()
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
}

sf::Vector2i mousePos;

//meniu
sf::RectangleShape meniu(sf::Vector2f(lungimeWindow, inaltimeWindow));
//Setare culoare meniu
void culoare_meniu() {
	meniu.setFillColor(meniuc);
}


//rotatie + origine
float rotation;
sf::Vector2f playerOrigin;
//Setare origine player
void setare_origine() {
	playerOrigin = player.getOrigin();
	player.setOrigin(player.getSize() / 2.f);
}

//font 
sf::Font font;
void definire_fonturi(){
font.loadFromFile("font.ttf");
}

////////////////////////////////////////////////////////////////////////////butoane
//buton1
sf::RectangleShape buton(sf::Vector2f(50, 20));
void creare_buton1() {
	buton.setPosition(lungimeWindow - 50, inaltimeWindow - 20);
	buton.setFillColor(butonc);
}

//buton2
sf::RectangleShape buton2(sf::Vector2f(50, 20));
void creare_buton2() {
	buton2.setPosition(lungimeWindow - 50, inaltimeWindow - 40);
	buton2.setFillColor(sf::Color::White);
}

//buton3
sf::RectangleShape buton3(sf::Vector2f(50, 20));
void creare_buton3() {
	buton3.setPosition(lungimeWindow - 50, inaltimeWindow - 60);
	buton3.setFillColor(sf::Color::Black);
}
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////text

//text1
sf::Text text1("Oprire/Pornire muzica", font);
void creare_text1() {
	text1.setCharacterSize(15);
	text1.setColor(sf::Color::Black);
	text1.setPosition(lungimeWindow - 210, inaltimeWindow - 40);
}

//text2
sf::Text text2("Positie centru ", font);
void creare_text2() {
	text2.setCharacterSize(15);
	text2.setColor(sf::Color::White);
	text2.setPosition(lungimeWindow - 160, inaltimeWindow - 60);
}

//text3
sf::Text textmeniu("Play!", font);
void creare_text3() {
	textmeniu.setCharacterSize(100);
	textmeniu.setColor(sf::Color::White);
	textmeniu.setPosition(lungimeWindow / 2 - 100, inaltimeWindow / 2 - 100);
}
//textescape
sf::Text textesc("Quit", font);
void creare_textesc() {
	textesc.setCharacterSize(80);
	textesc.setColor(sf::Color::Blue);
	textesc.setPosition(lungimeWindow / 2 - 100, inaltimeWindow / 2 );
}
//textescape
sf::Text textesc1("Resume", font);
void creare_textesc2() {
	textesc1.setCharacterSize(80);
	textesc1.setColor(sf::Color::Blue);
	textesc1.setPosition(lungimeWindow / 2 - 160, inaltimeWindow / 2 - 180);
}
/////////////////////////////////////////////////////////////////////////////

//Functie de afisare a butonului din dreapta
	void buton_dreapta() {
	if (mousePos.x >= lungimeWindow - 50 && mousePos.y >= inaltimeWindow - 20 && timp_meniu == false && timp_meniu_escape == false)
	{
		dropdown = true;
	}
	if (mousePos.x >= lungimeWindow - 50 && mousePos.y >= inaltimeWindow - 60 && dropdown && timp_meniu == false && timp_meniu_escape == false)
	{
		dropdown = true;
		window.draw(text1); window.draw(text2);
		window.draw(buton2);
		if (mousePos.x >= lungimeWindow - 50 && mousePos.y >= inaltimeWindow - 40 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePos.y <= inaltimeWindow - 20)
		{
			if (muzicq == true && bagEuPula == true)
			{
				music.pause();
				muzicq = false;
				muzicTime = muzicClock.restart();
				secunde = muzicTime.asSeconds();
				bagEuPula = false;
			}
			else if (muzicq == false && bagEuPula == true)
			{
				music.play();
				muzicq = true;
				muzicTime = muzicClock.restart();
				secunde = muzicTime.asSeconds();
			}
			bagEuPula = false;

		}
		else
			bagEuPula = true;
		window.draw(buton3);
		if (mousePos.x >= lungimeWindow - 50 && mousePos.y >= inaltimeWindow - 60 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePos.y <= inaltimeWindow - 40)
		{
			player.setPosition(lungimeWindow / 2, inaltimeWindow / 2);
		}
	}
	else
		dropdown = false;

}

//Functie de afisare a meniului principal
void afisare_meniu() {
	if (timp_meniu == true)
	{
		sf::Color meniu2(255, 255, 255, meniualfa);
		if (meniualfa >= 125)
		{
			meniualfa -= 1;
		}
		meniu.setFillColor(meniu2);
		window.draw(meniu);
		window.draw(textmeniu);

		if (mousePos.x >= lungimeWindow / 2 - 100 && mousePos.y >= inaltimeWindow / 2 - 70 && mousePos.x <= lungimeWindow / 2 + 90 && mousePos.y <= inaltimeWindow / 2 + 30)
		{
			textmeniu.setColor(sf::Color::Red); 
		}
		else
		{
			textmeniu.setColor(sf::Color::Blue);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (mousePos.x >= lungimeWindow / 2 - 100 && mousePos.y >= inaltimeWindow / 2 - 70 && mousePos.x <= lungimeWindow / 2 + 90 && mousePos.y <= inaltimeWindow / 2 + 30)
			{
				timp_meniu = false; variabilamuz = 1;
				if (variabilamuz == 1)
				{
					music.play();
					variabilamuz = 0;
					muzicq = true;
					muzicTime = muzicClock.restart();
					secunde = muzicTime.asSeconds();
				}
			}
		}

	}
}

//functia de miscare
void miscare() {
	if (timp_meniu == false && timp_meniu_escape == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(3.f*cos(rotation*PI / 180), -3.f*sin(rotation*PI / 180));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.rotate(-1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.rotate(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(-3.f*cos(rotation*PI / 180), 3.f*sin(rotation*PI / 180));
		}
	}
}

// afisare variabile pentru debug
void debugger()
{
	if (i == 1)
	{
		//cout << "rotatie = " << rotation - 90 << endl;
		//cout << "x  = " << playerPos.x << endl;
		//cout << "y = " << playerPos.y << endl;
		cout << "sec " << secunde << endl;
		if (muzicq == true)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		i = 0;
	}
	i++;
}

//meniu escape
sf::RectangleShape meniuescape(sf::Vector2f(lungimeWindow, inaltimeWindow));
sf::Color meniuescapec(255,255,255,125);
void meniu_escape()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && timp_meniu == false && aasdf >= 20)
	{
		timp_meniu_escape = true; aasdf = 0;
	}
	if (timp_meniu_escape)
	{
		asdf++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && timp_meniu == false && timp_meniu_escape == true && asdf >= 20)
	{
		timp_meniu_escape = false; asdf = 0;
	}
	if (timp_meniu_escape == false)
	{
		aasdf++;
	}

	if (timp_meniu_escape == true)
	{
		meniuescape.setFillColor(meniuescapec);
		window.draw(meniuescape);
		if (mousePos.x >= lungimeWindow / 2 - 100 && mousePos.y >= inaltimeWindow / 2 + 10 && mousePos.x <= lungimeWindow / 2 + 90 && mousePos.y <= inaltimeWindow / 2 + 90)
		{
			textesc.setFillColor(sf::Color::White);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window.close();
			}
		}window.draw(textesc);
		if (mousePos.x >= lungimeWindow / 2 - 165 && mousePos.y >= inaltimeWindow / 2 - 170 && mousePos.x <= lungimeWindow / 2 + 110 && mousePos.y <= inaltimeWindow / 2 - 90)
		{
			textesc1.setFillColor(sf::Color::White);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				timp_meniu_escape = false; 
			}
		}window.draw(textesc1);
	}
}
