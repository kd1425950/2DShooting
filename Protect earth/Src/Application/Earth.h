#pragma once

class Earth
{	
public:
	Earth() {}
	~Earth() {}
	void Init();
	bool Update();
	void Draw();
	void Release();

	int GetHp() { return earthHp; }
	void SetHp(int hp) { earthHp = hp; }

private:
	KdTexture earthTex;
	KdTexture hpText;
	KdTexture hpTex;

	Math::Matrix earthMat;
	Math::Matrix hpMat;
	Math::Matrix hpTextMat;

	int earthHp;
};