#include <cstdio>
#include <iostream>

#include "question.h"

#include "Picture.h"

using namespace std;

//chapter_15
void questionZero()
{
}

//15-1
void questionOne()
{
	const Picture p({"sentence a", "new sentence b", "new new sentence c"});
	const Picture q = frame(p);
	const Picture r = hcat(p, q);
	const Picture s = vcat(q, r);
	cout << frame(hcat(s, vcat(r, q))) << endl;
}

//15-2
void questionTwo()
{
	const Picture p({"sentence a", "new sentence b", "new new sentence c"});
	const Picture q = frame_new(p);
	const Picture r = hcat(p, q);
	const Picture s = vcat(q, r);
	cout << frame_new(hcat(s, vcat(r, q))) << endl;
}

//15-3
void questionThree()
{
	const Picture p({"sentence a", "new sentence b", "new new sentence c"});
	const Picture q = frame(p);
	const Picture r = hcat(p, q);
	const Picture s = vcat(q, r);
	cout << frame(hcat(s, vcat(r, q))) << endl;
}

//15-4
void questionFour()
{
}

//15-5
void questionFive()
{
	cin >> frame_ch;
	const Picture p({"sentence a", "new sentence b", "new new sentence c"});
	const Picture q = frame(p);
	const Picture r = hcat(p, q);
	const Picture s = vcat(q, r);
	cout << frame(hcat(s, vcat(r, q))) << endl;
}

//15-6
void questionSix()
{
}

//15-7
void questionSeven()
{
}

//15-8
void questionEight()
{
}

//15-9
void questionNine()
{
}

//15-10
void questionTen()
{
}

//15-11
void questionEleven()
{
}
