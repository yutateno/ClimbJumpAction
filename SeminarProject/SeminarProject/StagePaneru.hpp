#pragma once
#include "BasicObject.hpp"


class StagePaneru : public BasicObject
{
private:

public:
	StagePaneru(const int draw, const int collStageHandle, const VECTOR area);
	~StagePaneru();


	void Draw();
};

