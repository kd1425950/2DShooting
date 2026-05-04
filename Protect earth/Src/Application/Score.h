#pragma once

class Score
{
	public:
	Score() {}
	~Score() {}
	void SetScoreValue(int score) { m_score = score; }
	int GetScoreValue() { return m_score; }

	void Update();
	void Draw();
	void Init();
	void Release();

private:

	int m_score;

	KdTexture scoreTex;

	KdTexture scoreStringTex;

	Math::Matrix scoreMat1;
	Math::Matrix scoreMat2;
	Math::Matrix scoreMat3;
	Math::Matrix scoreMat4;
	Math::Matrix scoreMat5;

	Math::Matrix scoreStringMat;

	int scoreXCut1;
	int scoreXCut2;
	int scoreXCut3;
	int scoreXCut4;
	int scoreXCut5;

	int scoreYCut1;
	int scoreYCut2;
	int scoreYCut3;
	int scoreYCut4;
	int scoreYCut5;
};