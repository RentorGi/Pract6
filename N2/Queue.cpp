#include <iostream>
#include <locale>
#include <conio.h>

	class MyQueue
	{
	private:
		unsigned int NumberOfElements, MaxSize;
		int* Elements;

	public:
		MyQueue(unsigned int Size)//�����������
		{
			NumberOfElements = 0;
			MaxSize = Size;
			Elements = new int[Size];
		}

		~MyQueue()//����������
		{
			delete[] Elements;
		}

		void Push(int NewElement)//���������� �������� � �������
		{
			if (NumberOfElements == MaxSize)
				std::cout << "������� �����������!" << std::endl;
			else
			{
				Elements[NumberOfElements] = NewElement;
				NumberOfElements++;
			}
		}

		int Pop()//�������� �������� �� �������
		{
			if (IsEmpty())
			{
				std::cout << "������� �����!" << std::endl;
				return 0;
			}
			else
			{
				int FirstElement = Elements[0];
				NumberOfElements--;
				int* NewArr = new int[NumberOfElements];
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					NewArr[i] = Elements[i+1];
				}
				delete[] Elements;
				Elements = NewArr;
				return FirstElement;
			}
		}

		bool IsEmpty()//�������� �� �������
		{
			if (NumberOfElements == 0)
				return true;
			else
				return false;
		}

		int Peek()//��������� ������� �������� ������� ��� ��������
		{

			if (IsEmpty())
			{
				std::cout << "������� �����!" << std::endl;
				return 0;
			}
			else
			{
				return Elements[0];
			}
		}

		unsigned int GetSize()//��������� �������
		{
			return NumberOfElements;
		}

		void PeekAll()//����� ���� ��������� �� ��������
		{
			if (IsEmpty())
				std::cout << "������� �����!" << std::endl;
			else
			{
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					std::cout << Elements[i] << " ";
				}
				std::cout << std::endl;
			}
		}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		unsigned int QueueSize;
		std::cout << "������� ������ �������!" << std::endl;
		std::cin >> QueueSize;
		MyQueue queue1(QueueSize);
		std::cout << "��������� �������� � �������" << std::endl;
		int buff;
		for (unsigned int i = 0; i < QueueSize; i++)
		{
			std::cin >> buff;
			queue1.Push(buff);
		}
		std::cout << "��� �������:" << std::endl;
		queue1.PeekAll();
		std::cout << "������ ������� = " << queue1.GetSize() << std::endl;
		std::cout << "���������� ��������� ������� ��� ��������" << std::endl;
		std::cout << "��������� ������� = " << queue1.Peek() << std::endl;
		std::cout << "������ ������� �� ��������� � = " << queue1.GetSize() << std::endl;
		std::cout << "������ ������ ������� = " << queue1.Pop() << std::endl;
		std::cout << "��� �������:" << std::endl;
		queue1.PeekAll();
		std::cout << "������ ������� ��������� � = " << queue1.GetSize() << std::endl;
		std::cout << "������ ��� ��������" << std::endl;
		QueueSize = queue1.GetSize();
		for (unsigned int i = 0; i < QueueSize; i++)
		{
			queue1.Pop();
		}
		std::cout << "�������� ���� �� ������� ���������" << std::endl;
		if (queue1.IsEmpty())
			std::cout << "������� �����!" << std::endl;
		char s = _getch();
		return 1;
	}
