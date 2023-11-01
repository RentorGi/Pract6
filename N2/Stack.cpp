#include <iostream>
#include <locale>
#include <conio.h>


	class MyStack
	{
	private:
		unsigned int NumberOfElements, MaxSize;
		int* Elements;

	public:
		MyStack(unsigned int Size)//�����������
		{
			NumberOfElements = 0;
			MaxSize = Size;
			Elements = new int[Size];
		}

		~MyStack()//����������
		{
			delete[] Elements;
		}

		void Push(int NewElement)//���������� �������� � ����
		{
			if (NumberOfElements == MaxSize)
				std::cout << "���� ����������!" << std::endl;
			else
			{
				Elements[NumberOfElements] = NewElement;
				NumberOfElements++;
			}
		}

		int Pop()//�������� �������� �����
		{
			if (IsEmpty())
			{
				std::cout << "���� ����!" << std::endl;
				return 0;
			}
			else
			{
				int LastElement = Elements[NumberOfElements - 1];
				NumberOfElements--;
				int* NewArr = new int[NumberOfElements];
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					NewArr[i] = Elements[i];
				}
				delete[] Elements;
				Elements = NewArr;
				return LastElement;
			}
		}

		bool IsEmpty()//�������� �� �������
		{
			if (NumberOfElements == 0)
				return true;
			else
				return false;
		}

		int Peek()//��������� �������� �������� ����� ��� ��������
		{

			if (IsEmpty())
			{
				std::cout << "���� ����!" << std::endl;
				return 0;
			}
			else
			{
				return Elements[NumberOfElements - 1];
			}
		}

		unsigned int GetSize()//��������� �������
		{
			return NumberOfElements;
		}

		void PeekAll()//����� ���� ��������� �� ��������
		{
			if (IsEmpty())
				std::cout << "���� ����!" << std::endl;
			else
			{
				for (unsigned int i = NumberOfElements; i > 0; i--)
				{
					std::cout << Elements[i - 1] << " ";
				}
				std::cout << std::endl;
			}
		}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		unsigned int StackSize;
		std::cout << "������� ������ �����!" << std::endl;
		std::cin >> StackSize;
		MyStack stack1(StackSize);
		std::cout << "��������� �������� � ����" << std::endl;
		int buff;
		for (unsigned int i = 0; i < StackSize; i++)
		{
			std::cin >> buff;
			stack1.Push(buff);
		}
		std::cout << "���� ����:" << std::endl;
		stack1.PeekAll();
		std::cout << "������ ����� = " << stack1.GetSize() << std::endl;
		std::cout << "���������� ��������� ������� ��� ��������" << std::endl;
		std::cout << "��������� ������� = " << stack1.Peek() << std::endl;
		std::cout << "������ ����� �� ��������� � = " << stack1.GetSize() << std::endl;
		std::cout << "������ ��������� ������� = " << stack1.Pop() << std::endl;
		std::cout << "���� ����:" << std::endl;
		stack1.PeekAll();
		std::cout << "������ ����� ��������� � ����� = " << stack1.GetSize() << std::endl;
		std::cout << "������ ��� ��������" << std::endl;
		StackSize = stack1.GetSize();
		for (unsigned int i = 0; i < StackSize; i++)
		{
			stack1.Pop();
		}
		std::cout << "�������� ���� �� ������� ���������" << std::endl;
		if (stack1.IsEmpty())
			std::cout << "���� ����!" << std::endl;
		char s = _getch();
		return 1;
	}

