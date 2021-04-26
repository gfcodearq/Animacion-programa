#include "Juego.h"
using namespace std;

Juego::Juego(Vector2i resol, string tit)
{
	ventana1 = new RenderWindow(VideoMode(800, 600), tit);
	evento = new Event;
	division_sprites.x = 2;
	division_sprites.y = 4;
	frame_actual.x = 0;
	frame_actual.y = 0; 
	cargar_recursos();
	gameloop();
}

void Juego::gameloop()
{
	while (1)
	{
		procesar_eventos();
		dibujar();
	}
}

void Juego::procesar_eventos()
{
	while (ventana1->pollEvent(*evento))
	{
		switch (evento->type)
		{
		case Event::Closed:
			exit(1);
			break;

		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				if(frame_actual.x < division_sprites.x-1)
				frame_actual.x++;
				set_frame(*spr_personaje1, frame_actual);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				if(frame_actual.y < division_sprites.y-1)
				frame_actual.y++;
				set_frame(*spr_personaje1, frame_actual);
			}
		}
	}
}

void Juego::cargar_recursos()
{
	txt_personaje1 = new Texture();
	txt_personaje1->loadFromFile("spritesheet.png");
	spr_personaje1 = new Sprite(*txt_personaje1);
	spr_personaje1->setPosition(0, 512);
	spr_personaje1->setScale(0.35, 0.35);

	set_frame(*spr_personaje1, { 0,2 });
}

void Juego::dibujar()
{
	ventana1->clear();

	if (frame_actual.x < division_sprites.x - 1)
		frame_actual.x++;
	else
		frame_actual.x = 0;
	set_frame(*spr_personaje1, frame_actual);
	ventana1->draw(*spr_personaje1);
	ventana1->display();
}

void Juego::set_frame(Sprite& spr_objeto, Vector2i numero_frame)
{
	
	IntRect posicion(numero_frame.x * (spr_objeto.getTexture()->getSize().x / division_sprites.x), numero_frame.y * (spr_objeto.getTexture()->getSize().y / division_sprites.y), spr_objeto.getTexture()->getSize().x / division_sprites.x, spr_objeto.getTexture()->getSize().y / division_sprites.y);
	spr_objeto.setTextureRect(posicion);
}