#ifndef GAME_H
#define GAME_H

#include "utilities.h"
#include "renderer.h"
#include "platform_commands.h"
#include "object_manager.h"
//@brief Класс игры, где заложена вся логика

class Game {

private:
	//   @brief Конструктор класса, для работы с объектами игры
	   //@params ObjectManager указатель на менкеджер объектов
	   //@params FoodObject  указатель на объект еды
	   //@params PlayerObject указатель на объект игрока
	   //@params ScoreObject указатель на объект счета
	   //@params window окно для работы с игрой
	   //@params hdc указатель на контекст устройства
	   //@params finalScore финальный счет игры

	ObjectManager* objectManager;
	FoodObject* food;
	PlayerObject* player;
	ScoreObject* score;

	HWND* window;
	HDC* hdc;
	int finalScore;

public:


	Game(HWND* window, HDC* hdc, ObjectManager* objectManager, FoodObject* food, PlayerObject* player, ScoreObject* score);
	~Game();
	//@brief получить текущий счет игры
	//@return финальный счет
	inline int getScore() { return finalScore; }

	
	void init(); // иницилизация игры


	void gameOver(); // завершение игры

	void input(); // ввод пользователя
	void update(); // логика игры и прочие обновления
	void draw(); // рисует на экране
};


#endif