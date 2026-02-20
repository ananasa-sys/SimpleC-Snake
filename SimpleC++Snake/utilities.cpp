#include "utilities.h"

//******************Structs/Classes******************

//******************Structs/Classes******************


//******************Functions******************

/**
* @brief Вычисляем цвет клетки для создания клеток
* @param xPos Позиция клеток
* @param yPos  Позиция клеток по вертикали
* @return uint32 Шестнадцатеричный код цвета 
*/

uint32 calculateTileColor(const int xPos, const int yPos) {
	if ((xPos % 2) == (yPos % 2)) return LIGHTGREEN;
	else			  return SLIGHTLYDARKGREEN;
}

/**
* @brief Считываем ограничение FPS 
* @return int Возвращаем значение кадров в секунду
*/

int getFPS() {
	std::ifstream readFile;
	std::string settings = "settings.txt";

	short frames;

	readFile.open(settings);
	if (!readFile.is_open()) {
		frames = 60;
	}
	else {
		readFile >> frames;
	}

	readFile.close();

	return frames;
}

/**
 * @brief Определяем, должно ли произойти обновление
 * @return Возвращаем true если пора обновлять состояние игры
 */


bool getTickState() {
	bool val;
	(runNumber % static_cast<int>(1.0f / velocityScaleX) == 0) ? val = true : val = false;
	return val;
}
//******************Functions******************

//******************Global Variables******************

/** 
* @brief Глобальное состояние рендерера (память видеобуфера и размеры) 
*/

RenderState renderer = { NULL };
/** 
* @brief Флаг работы главного цикла программы 
*/
bool running = true;
/** 
* @brief Общий масштаб графики 
*/
float scale = 0.2f;
/**
* @brief Масштаб скорости перемещения по оси X
*/
float velocityScaleX = 0.2f;
/**
*
* @brief Масштаб скорости по оси Y (синхронизирован с X) 
*/
float velocityScaleY = velocityScaleX;
/**
* @brief Двумерный массив (сетка), представляющий игровое поле 
*/
std::array<std::array<uint32, tilemapSizeY>, tilemapSizeX> tilemap = { NULL };
/** 
* @brief Счетчик общего количества итераций игрового цикла 
*/
uint32 runNumber = 0;
//******************Global Variables******************