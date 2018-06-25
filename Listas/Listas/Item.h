#pragma once
#include <string>
#include <iostream>

class Item
{
public:
	Item();
	~Item();

	void criar(float bonusvida, float bonusdano, float bonusdefesa, int id, char nome[30], char desc[30], char tipo[30]);

	float getBonusVida();
	float getBonusDano();
	float getBonusDefesa();
	int getId();
	char getNome(int a);
	char getDesc(int a);
	char getTipo(int a);
	bool isEquipped();

	void setBonusVida(float bonus);
	void setBonusDano(float bonus);
	void setBonusDefesa(float bonus);
	void setId(int id);
	void setNome(char nome[30]);
	void setDesc(char desc[30]);
	void setTipo(char tipo[30]);
	void equip();

	// sobrecarregar
	friend bool operator<(const Item &a, const Item &b);
	friend bool operator<=(const Item&a, const Item&b);
	friend std::ostream& operator<<(std::ostream& os, const Item& item);


protected:
	float bonusVida, bonusDano, bonusDefesa;
	int id;
	char nome[30], desc[30], tipo[30];
	bool equipped;
};

