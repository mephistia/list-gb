#pragma once
#include <string>
class Item
{
public:
	Item();
	~Item();

	float getBonusVida();
	float getBonusDano();
	float getBonusDefesa();
	std::string getNome();
	std::string getDesc();
	std::string getTipo();
	bool isEquipped();

	void setBonusVida(float &bonus);
	void setBonusDano(float &bonus);
	void setBonusDefesa(float &bonus);
	void setNome(std::string &nome);
	void setDesc(std::string &desc);
	void setTipo(std::string &tipo);
	void equip();

	void setSprite(std::string sprite);

protected:
	float bonusVida, bonusDano, bonusDefesa;
	std::string nome, desc, tipo, sprite;
	bool equipped;
};

