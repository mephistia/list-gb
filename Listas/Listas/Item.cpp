#include "Item.h"



Item::Item()
{
	bonusVida, bonusDano, bonusDefesa = 0;
	nome, desc, tipo, sprite = "";
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

std::string Item::getNome()
{
	return nome;
}

std::string Item::getDesc()
{
	return desc;
}

std::string Item::getTipo()
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

void Item::setNome(std::string & nome)
{
	this->nome = nome;
}

void Item::setDesc(std::string & desc)
{
	this->desc = desc;
}

void Item::setTipo(std::string & tipo)
{
	this->tipo = tipo;
}

void Item::equip()
{
	equipped = true;
}

void Item::setSprite(std::string sprite)
{
	this->sprite = sprite;
}
