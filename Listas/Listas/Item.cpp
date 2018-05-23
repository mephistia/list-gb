#include "Item.h"



Item::Item()
{
	bonusVida, bonusDano, bonusDefesa = 0;
	equipped = false;
}


Item::~Item()
{
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

char* Item::getNome()
{
	return nome;
}

char* Item::getDesc()
{
	return desc;
}

char* Item::getTipo()
{
	return tipo;
}

bool Item::isEquipped()
{
	return equipped;
}

void Item::setBonusVida(float & bonus)
{
	bonusVida = bonus;
}

void Item::setBonusDano(float & bonus)
{
	bonusDano = bonus;
}

void Item::setBonusDefesa(float & bonus)
{
	bonusDefesa = bonus;
}

void Item::setNome(char *nome)
{
	this->nome = new char[strlen(nome)];
	strcpy(this->nome, nome);
}

void Item::setDesc(char * desc)
{
	this->desc = new char[strlen(desc)];
	strcpy(this->desc, desc);
}

void Item::setTipo(char *tipo)
{
	this->tipo = new char[strlen(tipo)];
	strcpy(this->tipo, tipo);
}

void Item::equip()
{
	equipped = true;
}

void Item::setSprite(char *sprite)
{
	this->sprite = new char[strlen(sprite)];
	strcpy(this->sprite, sprite);
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
