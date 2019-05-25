#pragma once
#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define KEYBOARD_UP 72
#define KEYBOARD_DOWN 80
#define KEYBOARD_LEFT 75
#define KEYBOARD_RIGHT 77
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27

using namespace std;

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

class MainMenu
{
public:
	MainMenu();
	int showMenu();
private:

};

#endif // !_MAIN_MENU_H_

