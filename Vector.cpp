#include"Vector.h"
void CVector::Init()
{
	x=0;
	y=0;
	speed=0;  //�ٶ�
	x2 = 0;
	y2 = 0;
	times = 0;   //ʱ��ˢ��
	cur = 0;     //��ǰ


}
void CVector::Run()
{
	GetCursorPos(&p);
}
void CVector::End()
{

}