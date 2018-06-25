#include "Item.h"



Item::Item()
{
	bonusVida, bonusDano, bonusDefesa = 0;
	equipped = false;
}


Item::~Item()
{
}

void Item::criar(float bonusvida, float bonusdano, float bonusdefesa, int id, char nome[30], char desc[30], char tipo[30])
{
	bonusVida = bonusvida;
	bonusDano = bonusdano;
	bonusDefesa = bonusdefesa;
	this->id = id;

	for (int i = 0; i < 30; i++) {
		if (nome[i] == '#') {
			nome[i] = '\0';
			break;
		}
			
	}

	strncpy(this->nome, nome, 30);



	for (int i = 0; i < 30; i++) {
		if (desc[i] == '#') {
			desc[i] = '\0';
			break;
		}
	}

	strncpy(this->desc, desc, 30);


	for (int i = 0; i < 30; i++) {
		if (tipo[i] == '#') {
			tipo[i] = '\0';
			break;
		}
			
	}

	strncpy(this->tipo, tipo,30);

	
}

float Item::getBonusVida()
{
	return bonusVida;
}

float Item::getBonusDano()
{
	return bonusDano;
}

float Item::getBonusDefesa()
{
	return bonusDefesa;
}

int Item::getId()
{
	return id;
}

char Item::getNome(int a)
{
	return nome[a];
}

char Item::getDesc(int a)
{
	return desc[a];
}

char Item::getTipo(int a)
{
	return tipo[a];
}

bool Item::isEquipped()
{
	return equipped;
}

void Item::setBonusVida(float bonus)
{
	bonusVida = bonus;
}

void Item::setBonusDano(float bonus)
{
	bonusDano = bonus;
}

void Item::setBonusDefesa(float bonus)
{
	bonusDefesa = bonus;
}

void Item::setId(int id)
{
	this->id = id;
}


void Item::setNome(char nome[30])
{
	strncpy(this->nome, nome,30);
}

void Item::setDesc(char desc[30])
{
	strncpy(this->desc, desc,30);
}

void Item::setTipo(char tipo[30])
{
	strncpy(this->tipo, tipo,30);
}

void Item::equip()
{
	equipped = true;
}

bool operator<(const Item & a, const Item & b)
{
	return (strcmp(a.nome, b.nome) < 0);
}

bool operator<=(const Item & a, const Item & b)
{
	return (strcmp(a.nome, b.nome) < 0) || (strcmp(a.nome, b.nome) == 0);
}

std::ostream & operator<<(std::ostream & os, const Item & item)
{
	os << item.nome;
	return os;
}
