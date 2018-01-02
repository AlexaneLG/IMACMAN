#include "Menu.hpp"

Menu::Menu()
{
  this->background = SDL_CreateRGBSurface(0,
					  200,
					  200,
					  0,
					  0,0,0,0);
}

Menu::~Menu()
{
}
  
//getters & setters
int Menu::get_width()
{
  return this->width;
}

void Menu::set_width(int new_width)
{
  this->width = new_width;
}
  
//other methodes
void Menu::display()
{
  
}

void Menu::create_game();
void Menu::load_game();
void Menu::update();
  
void Menu::rage_quit();

void Menu::click_here()
{
  std::cout << "nothing happend :D" << std::endl;
}
