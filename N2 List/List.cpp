#include <iostream>
#include <locale>
#include <conio.h>

class MyList
{
private:
	class Node
	{
	public:
		int data;
		Node* NextNode;
	};

	Node* Root = new Node();
	int NumberOfNodes;

	Node* SeekPreviousNode(int position)
	{
		if (position == 1)
			return nullptr;
		Node* PreviousNode = Root;//����, �������������� ������������
		for (int i = 0; i < (position - 2); i++)//������ ��� ���, ������� ��������� �� 1, � 2
		{
			PreviousNode = PreviousNode->NextNode;//����� ����, ��������������� ������������
		}
		return PreviousNode;
	}

	Node* SeekFollowingNode(int position)
	{
		if (position == (NumberOfNodes + 1))
			return nullptr;
		Node* FollowingNode = Root;
		for (int i = 0; i < (position - 1); i++)//������ ��� ���, ������� ��������� 1
		{
			FollowingNode = FollowingNode->NextNode;//����� ����, ������� ����� ������������
		}
		return FollowingNode;
	}

	Node* SeekCurrentNode(int position)
	{
		Node* CurrentNode = Root;
		for (int i = 0; i < (position-1); i++)//������ ��� ���, ������� ��������� 1
		{
			CurrentNode = CurrentNode->NextNode;//����� ����, ������� ����� ������������
		}
		return CurrentNode;
	}

public:
	MyList(int NewData)
	{
		Root->data = NewData;
		Root->NextNode = nullptr;
		NumberOfNodes = 1;
	}

	int AddNode(unsigned int position,int NewData)//���������� ����
	{
		Node* NewNode = new Node();
		NewNode->data = NewData;
		Node* PreviousNode = SeekPreviousNode(position);;//����, �������������� ������������
		Node* FollowingNode = SeekFollowingNode(position);//����, ������ ����� ������������
		if (PreviousNode != nullptr)
			PreviousNode->NextNode = NewNode;
		else
			Root = NewNode;
		if (FollowingNode != nullptr)
		NewNode->NextNode = FollowingNode;
		else
			NewNode->NextNode = nullptr;
		NumberOfNodes++;
		return 1;
	}

	void DeleteNode(unsigned int position)//�������� ����
	{
		Node* PreviousNode = SeekPreviousNode(position);;
		Node* FollowingNode = SeekFollowingNode(position+1);
		Node* CurrentNode = SeekCurrentNode(position);
		if (PreviousNode != nullptr)
			PreviousNode->NextNode = FollowingNode;
		else
			Root = FollowingNode;
		delete CurrentNode;
		CurrentNode = nullptr;
		NumberOfNodes--;
	}

	void DeleteRoot()
	{
		Node* FollowingNode = Root->NextNode;
		delete Root;
		Root = FollowingNode;
		NumberOfNodes--;
	}

	void Print()
	{
		if (NumberOfNodes == 0)
			std::cout << "������ ����!" << std::endl;
		else
		{
			Node* TempNode = Root;
			std::cout << TempNode->data << " ";
			for (int i = 0; i < NumberOfNodes - 1; i++)
			{
				TempNode = TempNode->NextNode;
				std::cout << TempNode->data << " ";
			}
			std::cout << std::endl;
		}
	}

	void Swap(unsigned int position1, unsigned int position2)
	{
		if (position1 > position2)//�������������
		{
			unsigned int temp = position1;
			position1 = position2;
			position2 = temp;
		}
		Node* PreviousNode1 = SeekPreviousNode(position1);;
		Node* FollowingNode1 = SeekFollowingNode(position1 + 1);
		Node* CurrentNode1 = SeekCurrentNode(position1);
		Node* PreviousNode2 = SeekPreviousNode(position2);;
		Node* FollowingNode2 = SeekFollowingNode(position2 + 1);
		Node* CurrentNode2 = SeekCurrentNode(position2);
		if (FollowingNode1 == CurrentNode2)
		{
			CurrentNode2->NextNode = CurrentNode1;
			CurrentNode1->NextNode = FollowingNode2;
		}
		else
		{
			CurrentNode1->NextNode = FollowingNode2;
			CurrentNode2->NextNode = FollowingNode1;
		}
		if (PreviousNode1 == nullptr)
		{
			Root = CurrentNode2;
		}
		else
		{
			PreviousNode1->NextNode = CurrentNode2;
		}
	    PreviousNode2->NextNode = CurrentNode1;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "�������� �������� ����, ���������� 11" << std::endl;
	MyList L1(11);
	L1.Print();
	std::cout << "�������� ���������� ���� � 1 �������" << std::endl;
	L1.AddNode(1,22);
	L1.Print();
	std::cout << "�������� ���������� ���� � 3 �������" << std::endl;
	L1.AddNode(3, 33);
	L1.Print();
	std::cout << "�������� �������� ���� � 1 �������" << std::endl;
	L1.DeleteNode(1);
	L1.Print();
	std::cout << "�������� �������� ���� �� 2 �������" << std::endl;
	L1.DeleteNode(2);
	L1.Print();
	std::cout << "�������� �������� ���� � 1 �������" << std::endl;
	L1.DeleteNode(1);
	L1.Print();
	std::cout << "������� ����� ����" << std::endl;
	L1.AddNode(1, 22);
	L1.AddNode(1, 12);
	L1.AddNode(1, 32);
	L1.Print();
	std::cout << "�������� �������� ����� 1" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "�������� �������� ����� 2" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "�������� �������� ����� 3" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "������� ����� ����" << std::endl;
	L1.AddNode(1, 12);
	L1.AddNode(1, 32);
	L1.AddNode(1, 22);
	L1.Print();
	std::cout << "�������� ������������ 1 � 3 �����" << std::endl;
	L1.Swap(1, 3);
	L1.Print();
	std::cout << "�������� ������������ 2 � 3 �����" << std::endl;
	L1.Swap(2, 3);
	L1.Print();
	std::cout << "�������� ������������ 3 � 2 �����" << std::endl;
	L1.Swap(3, 2);
	L1.Print();
	std::cout << "������� ����� ����" << std::endl;
	L1.AddNode(4, 55);
	L1.Print();
	std::cout << "�������� ������������ 1 � 4 �����" << std::endl;
	L1.Swap(1, 4);
	L1.Print();
	char s = _getch();
	return 1;
}