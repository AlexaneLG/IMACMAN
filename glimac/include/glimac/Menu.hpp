#pragma once

class Menu
{
  //attributes
  SDL_Surface * background;
  
  //construct & destruct
  Menu();
  virtual ~Menu();
  
  //getters & setters
  int get_bg();

  void set_bg(SDL_Surface * new_bg);
 
  //other methodes
  void display();
  void create_game();
  void load_game();
  void update();
  
  void rage_quit();
  void click_here();
};
