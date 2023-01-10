#pragma once
#include "ItemBase.h"
class Recovery : public ItemBase
{
private:
	int volume;
public:
	Recovery(T_location location);
	
public:
	virtual void Update() override;
	virtual void Draw() override;
	int GetVolume();
};

