#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <vector>
#include <mmsystem.h>
#include <string>
#include <fstream>
#pragma comment(lib, "winmm.lib")
#define SOUND_FILE_NAME ".\\song1.wav"
using namespace std;

int scorecount = 0;
int outcount = 0;

void func2() {
	// 배경음악 재생 함수

	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC);
}


struct DATA {
	int x, y;
};
vector<DATA> v;

int linechoice[1000] = {0,12,0,12,0,12,12,0,0,33,0,0,19,0,33,0,40,0,12,0,26,0,0,33,0,0,33,0,0,33,0,0,19,0,40,12,0,33,0,19,0,40,0,0,12,19,26,33,40,0,0,0,0,0,0,26,0,0,33,40,0,0,26,12,0,40,33,26,0,0,0,33,0,26,0,19,0,0,0,0,0,19,33,26,40,33,40,0,40,33,0,0,0,0,0,0,33,19,0,0,0,40,12,33,19,0,33,26,0,0,33,0
,19,33,26,12,33,26,0,0,0,0,40,0,12,0,0,12,0,19,0,19,0,33,0,40,0,0,33,0,40,0,26,0,19,0,0,0,012,0,19,0,26,0,33,0,40,0,0,26,0,0,0,0,0,0,0,0,0,0,12,0,19,0,26,0,33,0,40,0,33,0,0,33,0,0,0,0,19,0,0,0,33,0,0,0,0,12,19,26,33,40,0,0,0,0,0,0,0,0,0,0,0,0,12,19,0,0,33,0,0,40,26,19,
0,0,0,0,0,0,0,0,26,0,0,33,0,0,0,0,12,0,19,0,40,0,33,0,40,33,0,0,0,0,0,0,0,0,26,0,19,0,12,0,19,0,26,0,0,0,12,0,0,33,0,0,19,0,33,0,40,0,12,0,26,0,0,33,0,0,33,0,0,33,0,0,19,0,40,12,0,33,0,19,0,40,12,19,26,33,40,0,0,0,0,0,0,26,0,0,33,40,0,0,26,12,0,40,33,26,0,0,0,33,0,26,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,19,33,26,40,33,
40,0,40,33,0,0,0,0,0,0,33,19,0,0,0,40,12,33,19,0,33,26,0,0,33,0,19,33,26,12,33,26,0,0,0,0,40,0,12,0,0,12,0,19,0,20,0,33,0,40,0,0,33,0,40,0,26,0,19,0,0,0,012,0,19,0,26,0,33,0,40,0,0,20,0,0,0,0,0,0,0,0,0,0,12,0,19,0,26,0,33,0,40,0,33,0,0,33,0,0,0,0,19,0,0,0,33,0,12,19,26,33,40,0,0,0,0,0,0,0,0,0,0,0,0,12,19,0,0,33,0,0,40,26,19,
0,0,0,0,0,0,0,0,26,0,0,33,0,0,0,0,12,0,19,0,40,0,33,0,40,33,0,0,12,0,26,0,33,40,0,0,0,12,0,0,19,0,0,26,0,0,12,0,19,0,0,0,33,0,40,12,0,0,26,0,0,33,0,0,26,33,0,0,40};


int idx = 0;
void gotoxy(int x, int y);
void secondmenu();
void game();

void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void textcolor(int color_number) //콘솔창 출력색상을 나타내는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void tile()
{
	cout << "\n\n\n\n\n" << endl;
	cout << "        ■■■■■■■■■■■■■■■■■■■" << endl;  // y값 7
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■        " << endl;
	cout << "        ■      |      |      |      |      ■   score :      " << endl;
	cout << "        ■      |      |      |      |      ■        " << endl;
	cout << "        ■      |      |      |      |      ■      " << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■----------------------------------■" << endl;  // y값 30
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;
	cout << "        ■      |      |      |      |      ■" << endl;  
	cout << "        ■■■■■■■■■■■■■■■■■■■" << endl;  // y값 36
}

void shownote(int x, int y)   // 노트 그리기
{
	
	if (x == 0)
		return;
	gotoxy(x, y - 1);
	cout << " " << endl;
	textcolor(14);
	gotoxy(x, y);
	cout << "♪" << endl;

}

int getKeyValue()  //  키 입력 받기
{
	if (GetAsyncKeyState(0x51) & 0x8000) {     // Q
		return 12;
	}
	else if (GetAsyncKeyState(0x57) & 0x8000) {   // W
		return 19;
	}
	else if (GetAsyncKeyState(0x45) & 0x8000) {   // E
		return 26;
	}
	else if (GetAsyncKeyState(0x52) & 0x8000) {   // R
		return 33;
	}
	else if (GetAsyncKeyState(0x54) & 0x8000) {  // T
		return 40;
	}
	else {
		return 0; 
	}
}

int getXpos()   // 입력 받아야하는 키
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].y == 30)             // 끝에 도달하면 노트의 x값 리턴
		{
			return v[i].x;
		}
	}
	return -1;
}
void game()
{
	textcolor(15);
	tile();
	thread t2(&func2);
	while (1)           //linechoice배열의 크기 +40 까지만 루프 돔
	{
		if (idx == 90)          // 마지막에 노트 남는거 방지 
			break;
		if (idx < 60)
		{
			DATA tmp;
			tmp.x = linechoice[idx];
			tmp.y = 8;
			v.push_back(tmp);
		}

		for (int i = 0; i < v.size(); i++)  // 노트 그리기
		{
			shownote(v[i].x, v[i].y);
		}

		gotoxy(10,30);
		cout << "----------------------------------";    //선 그리기 (짤리는 것 해결)

		for (int i = 0; i < v.size(); i++)         // 노트의 위치를 하나씩 내려줌 
		{
			v[i].y += 1;
		}
		for (int i = 0; i < v.size(); i++)   // 노트 지우기 (끝에 도달하면)
		{
			if (v[i].y == 35)                
			{
				gotoxy(v[i].x, v[i].y-1);
				cout << " " << endl;
				v.erase(v.begin() + i);     // 벡터 지우기
			}
		}

		Sleep(190);   // 주기에 대해 시간 결정

		int tmp2 = getXpos(); // 입력 받아야 하는 키 (점수 획득)
		int tmp1 = getKeyValue();   // 입력 받은 키

		/*
		gotoxy(70, 16);
		cout << "입력 받아야 하는 키 / 입력 받은 키" << endl;
		gotoxy(75, 17);
		cout << tmp2;
		gotoxy(75, 20);
		cout << "   ";
		gotoxy(75, 20);
		cout << tmp1 << endl;    키 입력 잘되는지 확인하려고
		*/

		if (tmp2 == -1 || tmp2==0)
		{
			gotoxy(60, 10);
			cout << "     " << endl;
		}
		else if (tmp2 == tmp1)
		{
			gotoxy(50, 8);
			cout << "GREAT" << endl;
			scorecount += 10;
		}
		else
		{
			textcolor(12); //빨강
			gotoxy(50, 8);
			cout << " FAIL" << endl;
			outcount += 1;
		}
		textcolor(14);//노랑
		gotoxy(56,16);
		cout << scorecount;      // score 표시
		idx += 1;     // 다음 벡터 호출하기 위해 사용
		cin.clear();

		if (outcount == 10)
		{
			system("cls");
			textcolor(7);
			ifstream in("out2.txt");
			string s;

			if (in.is_open())
			{
				in >> s;
				in.seekg(0, ios::end);
				int size = in.tellg();
				s.resize(size);
				in.seekg(0, ios::beg);
				in.read(&s[0], size);
				cout << s << endl;
			}
			textcolor(12);
			gotoxy(53, 30);
			cout << "out!" << endl;
			Sleep(3000);
			break;
		}
	}

	cin.clear();
	t2.detach();
}

void helpmenu()
{ 
	int n;
	system("cls");
	cout << "HELP" << endl;

	gotoxy(10, 5);
	cout << "☆ 키 : Q W E R T " << endl;
	gotoxy(10, 8);
	cout << "☆ 점선부분에서 키를 누르세요 " << endl;
	gotoxy(10, 11);
	cout << "☆ 키를 길게 누르세요" << endl;
	gotoxy(10, 14);
	cout << "☆ Rank" << endl;
	gotoxy(9, 17);
	cout << "    ○○";
	gotoxy(9, 18);
	cout << "  ○     ○";
	gotoxy(9, 19);
	cout << " ○   " << "A" << "   ○";
	gotoxy(9, 20);
	cout << "  ○     ○";
	gotoxy(9, 21);
	cout << "    ○○";
	gotoxy(22, 17);
	cout << "    ○○";
	gotoxy(22, 18);
	cout << "  ○     ○";
	gotoxy(22, 19);
	cout << " ○   " << "B" << "   ○";
	gotoxy(22, 20);
	cout << "  ○     ○";
	gotoxy(22, 21);
	cout << "    ○○";
	gotoxy(35, 17);
	cout << "    ○○";
	gotoxy(35, 18);
	cout << "  ○     ○";
	gotoxy(35, 19);
	cout << " ○   " << "C" << "   ○";
	gotoxy(35, 20);
	cout << "  ○     ○";
	gotoxy(35, 21);
	cout << "    ○○";
	gotoxy(48, 17);
	cout << "    ○○";
	gotoxy(48, 18);
	cout << "  ○     ○";
	gotoxy(48, 19);
	cout << " ○   " << "F" << "   ○";
	gotoxy(48, 20);
	cout << "  ○     ○";
	gotoxy(48, 21);
	cout << "    ○○";

	Sleep(5000);
	textcolor(7); //흰색
	/*gotoxy(30, 35);
	cout << "메뉴로 돌아가려면 '0'을 누르시오 " ;

	cin >> n;
	switch (n)
	{
	case 0:
			return secondmenu();
	}	*/
}

void firstmenu()
{
	system("mode con:cols=90 lines=30");
	textcolor(14);//노랑
	cout << "\n\n\n" << endl;
	cout << "______    _              _    _                  _____                              " << endl;
	cout << "| ___ ＼ | |            | |  | |                | ___ ＼ " << endl;
	cout << "| |_/  / | |__    _   _ | |_ | |__   _ __ ___   | |  ＼/   ___ _  _ __ ___    ___   ___" << endl;
	cout << "|     /  |  _ ＼ | | | || __||  _ ＼|  _   _ ＼ | |  __   /  _  ||  _   _ ＼ / _ ＼/__ |" << endl;
	cout << "|  |＼ ＼| | | | | |_| || |_ | | | || | | | | | | ＼_＼＼ | (_| || | | | | | | __ /＼__＼ " << endl;
	cout << "＼_|  ＼_| |_| | ＼__  |＼__||_| |_||_| |_| |_|  ＼__ __/ ＼____||_| |_| |_| ＼___| |___/" << endl;
	cout << "                   _/  |" << endl;
	cout << "                  |___/ " << endl;
	textcolor(3); // 청록색
	Sleep(1000);
	system("cls");
	
}

void secondmenu()
{
	int n;
	system("cls");
	system("mode con:cols=70 lines=40");
	textcolor(7);
	ifstream in("smileone.txt");
	string s;

	if (in.is_open())
	{
		in >> s;
		in.seekg(0, ios::end);
		int size = in.tellg();
		s.resize(size);
		in.seekg(0, ios::beg);
		in.read(&s[0], size);
		cout << s << endl;
	}
	textcolor(3);
	gotoxy(50, 5);
	cout << "1. Game Start" << endl;
	gotoxy(50, 8);
	cout << "2. Exit" << endl;
	/*gotoxy(50, 8);
	cout << "3. Exit" << endl;*/
	gotoxy(60, 50);
	
	while (1) {
		gotoxy(20, 17);
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			helpmenu();
			system("cls");
			return;
			break;
		case 2:
			system("cls");
			exit(0);  //종료
			break;

		//	system("cls");
		//	helpmenu();
		//	break;
		//case 3:
		//	system("cls");
		//	exit(0);  //종류
		//	break;
		default:
			cout << "잘못 입력 하셨습니다." << endl;
			break;
		}
	}
}
void showscore()
{
	system("mode con:cols=100 lines=40");
	

	//그림 텍스트 삽입
	textcolor(7);//흰색
		ifstream in("smallcircle1.txt");
		string s;

		if (in.is_open())
		{
			in >> s;
			in.seekg(0, ios::end);
			int size = in.tellg();
			s.resize(size);
			in.seekg(0, ios::beg);
			in.read(&s[0], size);
			cout << s << endl;
		}
		textcolor(14);//노랑
		if (scorecount > 200)
		{
			gotoxy(72, 5);
			cout << "    ■" << endl;
			gotoxy(72, 6);
			cout << "  ■  ■" << endl;
			gotoxy(72, 7);
			cout << " ■■■■" << endl;
			gotoxy(72, 8);
			cout << " ■    ■" << endl;

		}

		//else if (scorecount > 400)
		//{
		//B

		//	gotoxy(23, 23);
		//}

		//else if (scorecount > 300)
		//{
		//   C

		//	
		//}
		else
		{
			gotoxy(72, 4);
			cout << " ■■■■" << endl;
			gotoxy(72, 5);
			cout << " ■" << endl;
			gotoxy(72, 6);
			cout << " ■■■■" << endl;
			gotoxy(72, 7);
			cout << " ■" << endl;
			gotoxy(72, 8);
			cout << " ■    " << endl;
		}
		
		gotoxy(75, 13);
		cout << "Your score is : " << scorecount << endl;
		Sleep(5000);
	


}


int main()
{

	//system("mode con:cols=70 lines=40");   //콘솔창 사이즈 설정
		while (1) {
			
			firstmenu();
			secondmenu();
			//gotoxy(10, 10);
			system("cls");
			game();
			showscore();
			cin.clear();

			system("cls");
			system("mode con:cols=50 lines=30");
			gotoxy(20, 10);
			cout << "1. Restart" << endl;
			gotoxy(20, 12);
			cout << "2. Exit";
			textcolor(0);
			gotoxy(50, 40);
			break;
			//cin.clear();
			//cin.ignore(INT_MAX,'\n');
			//char a[1];
			//cin.getline(a,1);
			//int n;
			//cin >> n;

			//if (n == 2)
			//{
			//	system("cls");
			//	break;
			//}
			//system("cls");
		}
	
	
}



//그림
//cout << "   ⊂_＼"<<endl;
//cout << "      ＼＼ Λ＿Λ" << endl;
//cout << "        ＼ ('ㅅ')  두둠칫" << endl;
//cout << "          >　⌒＼" << endl;
//cout << "         /    へ＼" << endl;
//cout << "        /    /  ＼＼" << endl;
//cout << "       /　  /　   ＼_つ" << endl;
//cout << "       /  / 두둠칫" << endl;
//cout << "      /  / |"<<endl;
//cout << "     (  (＼ ＼" << endl;
//cout << "     |  |  ＼ ＼_" << endl;
//cout << "     | /    ＼   )" << endl;
//cout << "    _| |       ) /" << endl;
//cout << "   /___ ) 　　 Lﾉ" << endl;



// help 들어갔다 게임하면 게임끝나고 cin한 키들 출력되고 점수 출력 안됨


 
