#pragma once
#include "Bean.h"

class SuperBean : public Bean
{
public:
	SuperBean(float x , float y);
	float Time() const { return time; }
private:
	float time;
};