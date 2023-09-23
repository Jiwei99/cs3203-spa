#pragma once

#include "Variable.h"

Variable::Variable(std::string name)
	: Entity(std::make_shared<std::string>(name), EntityType::Variable) {}

bool Variable::isWildCard() {
    return false;
}
