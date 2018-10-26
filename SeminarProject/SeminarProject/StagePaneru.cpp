#include "StagePaneru.hpp"


StagePaneru::StagePaneru(const int draw, const int collStageHandle, const VECTOR area) : BasicObject(collStageHandle)
{
	this->area = area;


	shadowHeight = 10.0f;
	shadowSize = 5.0f;

	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	MV1SetScale(this->modelHandle, VGet(50.0f, 50.0f, 50.0f));


	MV1SetPosition(this->modelHandle, area);
}

StagePaneru::~StagePaneru()
{
	MODEL_RELEASE(modelHandle);
}

void StagePaneru::Draw()
{
	BasicObject::ShadowFoot();


	BasicObject::Draw();
}
