#pragma once
#include "Bean.h"
#include <hgeanim.h>

class SuperBean : public Bean
{
public:
	SuperBean(float x , float y);
	virtual ~SuperBean();
	float Time() const { return time; }
private:
	float time;
};