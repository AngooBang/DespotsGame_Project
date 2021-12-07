#pragma once
#include "Singleton.h"

class Character;
class CharacterManager : public Singleton<CharacterManager>
{
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void AddChar(Tile& tile);

private:
	vector<Character*> m_vecChar;
};

