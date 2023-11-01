#include <iostream>
#include <locale>
#include <conio.h>

class MyDoubleList
{
private:
	class Node
	{
	public:
		int data;
		Node* Previous;
		Node* Following;
	};

	Node* Root = new Node();
	int NumberOfNodes;


	Node* SeekPreviousNode(int position)
	{
		if (position == 1)
			return nullptr;
		Node* PreviousNode = Root;//Узел, предшествующий добавляемогу
		for (int i = 0; i < (position - 2); i++)//Корень уже был, поэтому отнимется не 1, а 2
		{
			PreviousNode = PreviousNode->Following;//Поиск узла, предшествующего добавляемогу
		}
		return PreviousNode;
	}

	Node* SeekFollowingNode(int position)
	{
		if (position == (NumberOfNodes + 1))
			return nullptr;
		Node* FollowingNode = Root;
		for (int i = 0; i < (position - 1); i++)//Корень уже был, поэтому отнимется 1
		{
			FollowingNode = FollowingNode->Following;//Поиск узла, идущего после добавляемого
		}
		return FollowingNode;
	}

	Node* SeekCurrentNode(int position)
	{

		Node* CurrentNode = Root;
		for (int i = 0; i < (position - 1); i++)//Корень уже был, поэтому отнимется 1
		{
			CurrentNode = CurrentNode->Following;//Поиск узла, идущего после добавляемого
		}
		return CurrentNode;
	}

public:
	MyDoubleList(int NewData)
	{
		Root->data = NewData;
		Root->Previous = nullptr;
		Root->Following = nullptr;
		NumberOfNodes = 1;
	}

	int AddNode(unsigned int position, int NewData)//Добавление узла
	{
		Node* NewNode = new Node();
		NewNode->data = NewData;
		Node* PreviousNode = SeekPreviousNode(position);//Узел, предшествующий добавляемогу
		Node* FollowingNode = SeekFollowingNode(position);//Узел, идущий после добавляемого
		if (PreviousNode != nullptr)
		{
			PreviousNode->Following = NewNode;
			NewNode->Previous = PreviousNode;
		}
		else
			Root = NewNode;
		if (FollowingNode != nullptr)
		{
			NewNode->Following = FollowingNode;
			FollowingNode->Previous = NewNode;
		}
		else
			NewNode->Following = nullptr;
		NumberOfNodes++;
		return 1;
	}

	void DeleteNode(unsigned int position)//Удаление узла
	{
		Node* PreviousNode = SeekPreviousNode(position);;
		Node* FollowingNode = SeekFollowingNode(position + 1);
		Node* CurrentNode = SeekCurrentNode(position);
		if (PreviousNode != nullptr)
		{
			PreviousNode->Following = FollowingNode;
		}
		else
			Root = FollowingNode;
		if (FollowingNode != nullptr)
		{
			FollowingNode->Previous = PreviousNode;
		}
		delete CurrentNode;
		CurrentNode = nullptr;
		NumberOfNodes--;
	}

	void DeleteRoot()
	{
		Node* FollowingNode = Root->Following;
		delete Root;
		Root = FollowingNode;

		if (Root != nullptr)
		Root->Previous = nullptr;

		NumberOfNodes--;
	}

	void Print()
	{
		if (NumberOfNodes == 0)
			std::cout << "Список пуст!" << std::endl;
		else
		{
			Node* TempNode = Root;
			std::cout << TempNode->data << " ";
			for (int i = 0; i < NumberOfNodes - 1; i++)
			{
				TempNode = TempNode->Following;
				std::cout << TempNode->data << " ";
			}
			std::cout << std::endl;
		}
	}

	void BackPrint()
	{
		if (NumberOfNodes == 0)
			std::cout << "Список пуст!" << std::endl;
		else
		{
			Node* TempNode = Root;
			for (int i = 0; i < NumberOfNodes - 1; i++)
			{
				TempNode = TempNode->Following;
			}
			std::cout << TempNode->data << " ";
			for (int i = (NumberOfNodes-1); i > 0; i--)
			{
				TempNode = TempNode->Previous;
			    std::cout << TempNode->data << " ";
			}
			std::cout << std::endl;
		}
	}

	void Swap(unsigned int position1, unsigned int position2)
	{
		if (position1 > position2)//Упорядочиваем
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
			CurrentNode2->Following = CurrentNode1;
			CurrentNode1->Previous = CurrentNode2;
		}
		else
		{
			CurrentNode2->Following = FollowingNode1;
			CurrentNode1->Previous = PreviousNode2;
		}
		if (PreviousNode1 == nullptr)
		{
			Root = CurrentNode2;
		}
		else
		{
			PreviousNode1->Following = CurrentNode2;
		}
		if (FollowingNode2 != nullptr)
			FollowingNode2->Previous = CurrentNode1;
		CurrentNode1->Following = FollowingNode2;
		CurrentNode2->Previous = PreviousNode1;
		PreviousNode2->Following = CurrentNode1;
		FollowingNode1->Previous = CurrentNode2;

	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Создадим корневой узел, содержащий 11" << std::endl;
	MyDoubleList L1(11);
	L1.Print();
	std::cout << "Проверка добавления узла в 1 позицию" << std::endl;
	L1.AddNode(1, 22);
	L1.Print();
	std::cout << "Проверка добавления узла в 3 позицию" << std::endl;
	L1.AddNode(3, 33);
	L1.Print();
	std::cout << "Проверка удаления узла в 1 позиции" << std::endl;
	L1.DeleteNode(1);
	L1.Print();
	std::cout << "Проверка удаления узла во 2 позиции" << std::endl;
	L1.DeleteNode(2);
	L1.Print();
	std::cout << "Проверка удаления узла в 1 позиции" << std::endl;
	L1.DeleteNode(1);
	L1.Print();
	std::cout << "Добавим новые узлы" << std::endl;
	L1.AddNode(1, 22);
	L1.AddNode(1, 12);
	L1.AddNode(1, 32);
	L1.Print();
	std::cout << "Проверка удаления корня 1" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "Проверка удаления корня 2" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "Проверка удаления корня 3" << std::endl;
	L1.DeleteRoot();
	L1.Print();
	std::cout << "Добавим новые узлы" << std::endl;
	L1.AddNode(1, 12);
	L1.AddNode(1, 32);
	L1.AddNode(1, 22);
	L1.Print();
	std::cout << "Проверка взаимообмена 1 и 3 узлов" << std::endl;
	L1.Swap(1, 3);
	L1.Print();
	std::cout << "Проверка взаимообмена 2 и 3 узлов" << std::endl;
	L1.Swap(2, 3);
	L1.Print();
	std::cout << "Проверка взаимообмена 3 и 2 узлов" << std::endl;
	L1.Swap(3, 2);
	L1.Print();
	std::cout << "Добавим новый узел" << std::endl;
	L1.AddNode(4, 55);
	L1.Print();
	std::cout << "Проверка взаимообмена 1 и 4 узлов" << std::endl;
	L1.Swap(1, 4);
	L1.Print();
	std::cout << "Проверка обратного вывода" << std::endl;
	L1.BackPrint();
	char s = _getch();
	return 1;
}