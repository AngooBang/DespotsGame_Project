#pragma once
#include "GameEntity.h"

class BMPImage;
class GameObject : public GameEntity
{
protected:
	POINT m_pos;
	RECT m_shape;
	int m_bodySize;

public:
	void Move();

	inline void SetPos(POINT pos) { m_pos = pos; }
	inline POINT GetPos() { return m_pos; }
	inline int GetBodySize() { return m_bodySize; }

	GameObject();
	~GameObject();
};

