#pragma once

class Keymanager
{
public:
	static Keymanager& GetInstance()
	{
		static Keymanager instance;
		return instance;
	}

	bool PushEnter()
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (!enterKeyFlg)
			{
				enterKeyFlg = true;
				return true;
			}
		}
		else
		{
			enterKeyFlg = false;
		}
		return false;
	}

	bool PushC()
	{
		if (GetAsyncKeyState('C') & 0x8000)
		{
			if (!cKeyFlg)
			{
				cKeyFlg = true;
				return true;
			}
		}
		else
		{
			cKeyFlg = false;
		}
		return false;
	}

	bool PushShift()
	{
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			if (!shiftKeyFlg)
			{
				shiftKeyFlg = true;
				return true;
			}
		}
		else
		{
			shiftKeyFlg = false;
		}
		return false;
	}

	bool PushTab()
	{
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			if (!tabKeyFlg)
			{
				tabKeyFlg = true;
				return true;
			}
		}
		else
		{
			tabKeyFlg = false;
		}
		return false;

	}

	bool PushRight()
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (!rightFlg)
			{
				rightFlg = true;
				return true;
			}
		}
		else
		{
			rightFlg = false;
		}
		return false;

	}

	bool PushLeft()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (!leftFlg)
			{
				leftFlg = true;
				return true;
			}
		}
		else
		{
			leftFlg = false;
		}
		return false;

	}

	bool PushDown()
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (!downFlg)
			{
				downFlg = true;
				return true;
			}
		}
		else
		{
			downFlg = false;
		}
		return false;
	}

	bool PushUp()
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (!upFlg)
			{
				upFlg = true;
				return true;
			}
		}
		else
		{
			upFlg = false;
		}
		return false;
	}

	bool PushSpace()
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (!spaceFlg)
			{
				spaceFlg = true;
				return true;
			}
		}
		else
		{
			spaceFlg = false;
		}
		return false;
	}

	bool PushLbutton()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (!lbuttonFlg)
			{
				lbuttonFlg = true;
				return true;
			}
		}
		else
		{
			lbuttonFlg = false;
		}
		return false;
	}

private:
	Keymanager() {}

	bool enterKeyFlg = false;
	bool shiftKeyFlg = false;
	bool cKeyFlg = false;
	bool tabKeyFlg = false;
	bool rightFlg = false;
	bool leftFlg = false;
	bool upFlg = false;
	bool downFlg = false;
	bool spaceFlg = false;
	bool lbuttonFlg = false;
};

#define KEYM Keymanager::GetInstance()
