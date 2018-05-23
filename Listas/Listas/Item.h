#pragma once
#include <string>
#include <iostream>

class Item
{
public:
	Item();
	~Item();

	float getBonusVida();
	float getBonusDano();
	float getBonusDefesa();
	char* getNome();
	char* getDesc();
	char* getTipo();
	bool isEquipped();

	void setBonusVida(float &bonus);
	void setBonusDano(float &bonus);
	void setBonusDefesa(float &bonus);
	void setNome(char *nome);
	void setDesc(char *desc);
	void setTipo(char *tipo);
	void equip();

	void setSprite(char *sprite);

	// sobrecarregar
	friend bool operator<(const Item &a, const Item &b);
	friend bool operator<=(const Item&a, const Item&b);
	friend std::ostream& operator<<(std::ostream& os, const Item& item);


protected:
	float bonusVida, bonusDano, bonusDefesa;
	char * nome, * desc, *tipo, *sprite;
	bool equipped;
};

