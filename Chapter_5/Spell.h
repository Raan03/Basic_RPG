#ifndef MAGIC_H
#define MAGIC_H

#include "Range.h"
#include <string>

struct Spell
{
	std::string mName;
	Range mDamageRange;
	int mMagicRequired;
};

#endif // MAGIC_H