#pragma once

class Player;
class MOUSE;
class SHOT;
class METEO;
class Particle;

class Scene
{
private:

	static const int meteoNum = 10;
	static const int particleNum = 5;

	// テクスチャ ・・・ 画像データ
	KdTexture playerTex;
	KdTexture shotTex;
	KdTexture meteoTex/*[meteoNum]*/;
	KdTexture backTex;
	KdTexture particleTex/*[particleNum]*/;

	Math::Matrix backMat;

	//インスタンス
	Player* player = nullptr;
	MOUSE* mouse = nullptr;
	SHOT* shot = nullptr;
	std::vector <METEO*> meteo;
	std::vector <Particle*> particle;
public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI
	void ImGuiUpdate();

	SHOT* GetShot() { return shot; }
	std::vector <METEO*> GetMeteo() { return meteo; }
	std::vector <Particle*>GetParticle() { return particle; }
private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
