#ifndef SHADOWSCREAM_HEXAGONAL
#define SHADOWSCREAM_HEXAGONAL

#define HEX_STRING_POS_LEFT 0
#define HEX_STRING_POS_RIGHT 1
#define HEX_STRING_POS_CENTER 2
#define HEX_STYLE_RIGHT_TO_LEFT 0
#define HEX_STYLE_LEFT_TO_RIGHT 1

struct HexagonalStringEntry
{
	char szString[MAX_PATH];
	int iPosition;
	int iIndexOfCapsule;
	int r;
	int g;
	int b;
};

struct HexagonBarEntry
{
	float fValue;
	int iIndex;
};

class cHexagonal
{
	public:
		cHexagonal();
		void AddString(int position,int index,int r,int g,int b,char*fmt,...);
		int CalculateHeightCapsule();
		int CalculateWidthByStrings();
		int CalculateWidthByXLeftSide(int numberofitems);
		void SetTitles(char*title);
		void SetStyle(int style);
		void SetPercentageBlock(int position,float value);
		void ReleaseResources();
		void DrawWindow(int x,int y,int w,int h,bool background,int selected,int numberofitems);
		float fSpaceBetweenBlocksAndTitles;
	private:
		char szTitle[MAX_PATH];
		char szEndTitle[MAX_PATH];
		int iStyle;
		vector<HexagonalStringEntry> VStringEntrys;
		vector<HexagonBarEntry> VHexagonBarEntry;
		void DrawFillTriangle(int xa,int ya,int xb,int yb,int xc,int yc,int r,int g,int b,int a);
		void DrawFillTriangleWithGradientUpToDown(int xa,int ya,int xb,int yb,int xc,int yc,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab);
		void DrawFillRectangleWithGradientRightToLeft(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab);
		void DrawFillRectangleWithGradientUpToDown(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab);
		void DrawLine(int xa,int ya,int xb,int yb,int r,int g,int b,int a);
		void DrawTitleHexagon(int x,int y,int w,int hfont,int h,int selected,int numberofitems);
		void DrawHexagonWithGradientUpToDown(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab);
		POINT DrawItemHexagon(int x,int y,int w,int h,bool background,int index,int numberofitems,int r,int g,int b,int a);
		void DrawEndHexagon(int x,int y,int w,int h,int hfont,int selected,int numberofitems);
};

extern cHexagonal gHexagonalInterface;


#endif //SHADOWSCREAM_HEXAGONAL