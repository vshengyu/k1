#include"Vector.h"
void CVector::Init()
{
	x=0;
	y=0;
	speed=0;  //速度
	x2 = 0;
	y2 = 0;
	times = 0;   //时间刷新
	cur = 0;     //当前


}
void CVector::Run()
{
	GetCursorPos(&p);
}
void CVector::End()
{

}