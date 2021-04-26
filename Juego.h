#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;
using namespace std;

class Juego
{
public:
	Juego(Vector2i resol, string titulo);
	void gameloop();
	void procesar_eventos();
	void cargar_recursos();
	void dibujar();
	void set_frame(Sprite& spr_objeto, Vector2i numero_frame);
private:
	RenderWindow* ventana1;
	Event* evento;
	Sprite* spr_personaje1;
	Texture* txt_personaje1;
	Vector2i division_sprites;
	Vector2i frame_actual;
};