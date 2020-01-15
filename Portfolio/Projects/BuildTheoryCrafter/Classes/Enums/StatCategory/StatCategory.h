// Domenico D'Erasmo
// 18 April 2019
// Interface File for StatCategory Enumeration and Functions

#ifndef STATCATEGORY_H
#define STATCATEGORY_H

#include <iostream>

enum StatCategory {health, attack, defense, crit_chance, crit_damage, normal_attack, science_attack, magic_attack, normal_defense, science_defense, magic_defense, health_regen, move_speed, constitution, power, endurance, agility, faith, choose, date };

StatCategory StringToStat(std::string input_string);
std::string StatToString(StatCategory input_stat_category);

#endif
