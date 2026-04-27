#pragma once

class Earth
{	
public:
	Earth() {}
	~Earth() {}
	void Init();
	void Update();
	void Draw();
	void Release();

	int GetHp() { return earthHp; }
	void SetHp(int hp) { earthHp = hp; }

private:
	KdTexture earthTex;
	Math::Matrix earthMat;

	KdTexture hpTex;
	Math::Matrix hpMat;

	int earthHp;
};