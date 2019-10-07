#include <iostream>
using namespace std;

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)    // �̵��� ������ ���� 1�����
	{
		cout << "����1�� " << from << "���� " << to << "�� �̵�" << endl;
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);    // 3�ܰ� �� 1�ܰ�
		cout << "����" << num <<"��(��) " << from << "���� " << to << "�� �̵�" << endl;  // 3�ܰ� �� 2�ܰ�
		HanoiTowerMove(num - 1, by, from, to);    // 3�ܰ� �� 3�ܰ�
	}
}


int main(void)
{
	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}