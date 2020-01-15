// Domenico D'Erasmo
// 18 May 2019
// Miscellaneous Auxiliary Functions

#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

// Arguments: 
//	file is the file object being used
//	num is the line number
std::fstream& GoToLine(std::fstream& file, unsigned int num) 
{
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) 
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

#endif // !MISCELLANEOUS_H
