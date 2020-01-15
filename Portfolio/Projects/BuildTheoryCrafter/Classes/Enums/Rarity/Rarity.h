// Domenico D'Erasmo
// 14 May 2019
// Interface File for Rarity Enumeration and Functions


#ifndef RARITY_H
#define RARITY_H

enum Rarity {white, green, blue, purple, gold};

Rarity StringToRarity(std::string input_string);
std::string RarityToString(Rarity input_rarity);

#endif // !RARITY_H
