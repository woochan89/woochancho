#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Exam_1
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//
//	if (binary_search(v.begin(), v.end(), 20))
//		cout << "20 ���Ұ� �����մϴ�." << endl;
//	else
//		cout << "20 ���Ұ� �������� �ʽ��ϴ�." << endl;
//}

//Exam_2
//bool Pred(int left, int right)
//{
//	return 3 < right - left;
//}
//
//void main()
//{
//	vector<int> v;
//
//	v.push_back(40);
//	v.push_back(46);
//	v.push_back(12);
//	v.push_back(80);
//	v.push_back(10);
//	v.push_back(47);
//	v.push_back(30);
//	v.push_back(55);
//	v.push_back(90);
//	v.push_back(53);
//
//	cout << "[v ����]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	/*sort(v.begin(), v.end());
//	cout << "[v: ����]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;*/
//
//	sort(v.begin(), v.end(), Pred);
//	cout << "[v: ���� pred]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	if (binary_search(v.begin(), v.end(), 32, Pred))
//		cout << "32 ���Ұ� �����մϴ�." << endl;
//	else
//		cout << "32 ���Ұ� �������� �ʽ��ϴ�." << endl;
//
//	if (binary_search(v.begin(), v.end(), 35, Pred))
//		cout << "35 ���Ұ� �����մϴ�." << endl;
//	else
//		cout << "35 ���Ұ� �������� �ʽ��ϴ�." << endl;
//}

//Exam_3
//void main()
//{
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(20);
//
//	cout << "[v ����]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	//�⺻ ���� ���� less ���
//	sort(v.begin(), v.end());
//	cout << "[v: less ����]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	//�� ������ less ����(�Ϲ� ���� binary_search() ����)
//	cout << "�� less ã��: " << binary_search(v.begin(), v.end(), 20, less<int>()) << endl;
//
//	//���� ���� greater ����
//	sort(v.begin(), v.end(), greater<int>());
//	cout << "[v: greater ����]: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//	//������ ���� ���� greater ����
//	cout << "�� greater ã��: " << binary_search(v.begin(), v.end(), 20, greater<int>()) << endl;
//}

//Exam_4
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(20);
//	v2.push_back(40);
//
//	vector<int> v3;
//	v3.push_back(10);
//	v3.push_back(20);
//	v3.push_back(60);
//
//	if (includes(v1.begin(), v1.end(), v2.begin(), v2.end()))
//		cout << "v2�� v1�� �κ� ����" << endl;
//	else
//		cout << "v2�� v1�� �κ� ���� �ƴ�" << endl;
//
//	if (includes(v1.begin(), v1.end(), v3.begin(), v3.end()))
//		cout << "v3�� v1�� �κ� ����" << endl;
//	else
//		cout << "v3�� v1�� �κ� ���� �ƴ�" << endl;
//
//	//���� ������ greater<int> ����
//	sort(v1.begin(), v1.end(), greater<int>());
//	sort(v2.begin(), v2.end(), greater<int>());
//	//�� ������ greater<int> ����
//	if (includes(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()))
//		cout << "greater���� ������: v2�� v1�� �κ� ����" << endl;
//}

//Exam_5
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	vector<int>::iterator iter_lower, iter_upper;
//
//	iter_lower = lower_bound(v.begin(), v.end(), 30);
//	iter_upper = upper_bound(v.begin(), v.end(), 30);
//
//	cout << "30 ������ ������ [iter_lower, iter_upper): ";
//	for (vector<int>::iterator iter = iter_lower; iter != iter_upper; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_6
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	//vector<int>::iterator iter_lower, iter_upper;
//	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
//
//	iter_pair = equal_range(v.begin(), v.end(), 30);
//
//	cout << "30 ������ ������ [iter_pair.first, iter_pair.second): ";
//	for (vector<int>::iterator iter = iter_pair.first; iter != iter_pair.second; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//}

//Exam_7
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(20);
//	v2.push_back(30);
//	v2.push_back(60);
//
//	vector<int> v3(10); //size: 10�� vector ����
//
//	cout << "v1: ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//	cout << "v2: ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//	cout << "v3: ";
//	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	vector<int>::iterator iter_end;
//	//v1�� �������� v2�� �������� �պ��Ͽ� [v3.begin(), iter_end)�� �������� �����Ѵ�.
//	iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//
//	cout << "v1: ";
//	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
//		cout << v1[i] << " ";
//	cout << endl;
//	cout << "v2: ";
//	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
//		cout << v2[i] << " ";
//	cout << endl;
//	cout << "v3: ";
//	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_8
//void main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(60);
//
//	cout << "v�� �� �������� ���ĵ� �ϳ��� ������" << endl;
//	cout << "[v.begin(), v.begin()+5) + [v.begin()+5, v.end())" << endl;
//	cout << "v: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//
//
//	// �� �������� ���ĵ� �ϳ��� �������� �� �������� �����Ѵ�.
//	inplace_merge(v.begin(), v.begin() + 5, v.end());
//
//	cout << "v: ";
//	for (vector<int>::size_type i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}

//Exam_9
//void main()
//{
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	vector<int> v2;
//	v2.push_back(20);
//	v2.push_back(30);
//	v2.push_back(60);
//
//	vector<int> v3(10); //size: 10�� vector ����
//	vector<int>::iterator iter_end;
//
//	iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	cout << "[v3.begin(), iter_end): ";
//	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
//		cout << *iter << " ";
//	cout << endl;
//
//	cout << "v3: ";
//	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
//		cout << v3[i] << " ";
//	cout << endl;
//}

//Exam_10
void main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(60);

	vector<int> v3(10); //size: 10�� vector ����
	vector<int>::iterator iter_end;

	iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	cout << "������[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;

	iter_end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	cout << "������[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;

	iter_end = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	cout << "��Ī������[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}
