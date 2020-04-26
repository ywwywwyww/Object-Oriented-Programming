/**
 * @file pizza.cpp
 * @author Wuwei YUAN
 * @date 4/26/20
 */

#include "pizza.h"
#include "../generator/generator.h"

Pizza::Pizza() : id_{Generator::GetInstance().GenerateId()} {}