#include "pch.h"
#include "CppUnitTest.h"

#include "../AIE_01_Templates/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AIEUnitTests
{
	TEST_CLASS(AIELinkedListTest)
	{
	public:

		TEST_METHOD(Can_Create_Empty_List)
		{
			// Setup
			// -------------------------------
			LinkedList<int> list;

			// -------------------------------
			// Below we assert, check our expectations match

				// First and Last node in an empty list should be null
			Assert::IsNull(list.FirstNode());
			Assert::IsNull(list.LastNode());

			// the IsEmpty function should return true
			Assert::IsTrue(list.IsEmpty());

			// for an empty list begin and end should be the same
			Assert::IsTrue(list.begin() == list.end());

			// an empty list should have a count of 0
			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Can_Create_List_With_Initialiser_List)
		{
			// Setup
			// -------------------------------
			LinkedList<int> list = { 10, 20, 30, 40 };

			// -------------------------------
			// Below we assert, check our expectations match

			// First and Last nodes should not be null
			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			// First and Last nodes should have a value of 10 and 40
			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			// The IsEmpty function should return false
			Assert::IsFalse(list.IsEmpty());

			// should be able to iterate through each item
			// lets check the values are as we expect
			int arr[5] = { 10, 20, 30, 40 };
			int index = 0;

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				// de-reference iter to get its value
				// compare it against the value in our array
				Assert::AreEqual(*iter, arr[index]);
				index++;
			}
		}

		TEST_METHOD(Can_PushBack)
		{
			//setup the list
			LinkedList<int> list = { 10, 20, 30, 40 };

			//adds the value 50 to the end of the list
			list.PushBack(50);

			//checks if the lastnode isnt null
			Assert::IsNotNull(list.LastNode());

			//checks if the last node = 50
			Assert::IsTrue(list.LastNode()->value == 50);

			//checks if the count went up to 5
			Assert::IsTrue(list.Count() == 5);
		}

		TEST_METHOD(Can_PopBack)
		{
			//setup the list	
			LinkedList<int> list = { 10, 20, 30, 40 };

			//removes the last value in list
			list.PopBack();

			//checks if the lastnode isnt null
			Assert::IsNotNull(list.LastNode());

			//checks if the last node = 30
			Assert::IsTrue(list.LastNode()->value == 30);

			//checks if the count went down to 3
			Assert::IsTrue(list.Count() == 3);
			
		}

		TEST_METHOD(Can_PushFront)
		{
			//setup the list
			LinkedList<int> list = { 20, 30, 40 };

			//adds the value 50 to the end of the list
			list.PushFront(10);

			//checks if the firstnode isnt null
			Assert::IsNotNull(list.FirstNode());

			//checks if the first node = 10
			Assert::IsTrue(list.FirstNode()->value == 10);

			//checks if the count went up to 4
			Assert::IsTrue(list.Count() == 4);
		}

		TEST_METHOD(Can_PopFront) 
		{
			//setup the list
			LinkedList<int> list = { 10, 20, 30, 40 };

			//removes the last value in list
			list.PopFront();

			//checks if the lastnode isnt null
			Assert::IsNotNull(list.FirstNode());

			//checks if the last node = 20
			Assert::IsTrue(list.FirstNode()->value == 20);

			//checks if the count went down to 3
			Assert::IsTrue(list.Count() == 3);
		}

		TEST_METHOD(Can_Clear) {
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.Clear();

			Assert::IsNull(list.LastNode());
			Assert::IsNull(list.FirstNode());

			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Can_Insert) {
			LinkedList<int> list = { 10, 20, 30, 40 };

			//fix
			list.Insert();//0,5 ? 

			Assert::IsNotNull(list.LastNode());
			Assert::IsNotNull(list.FirstNode());

			Assert::IsTrue(list.FirstNode()->value == 25);

			Assert::IsTrue(list.Count() == 5);
		}

		TEST_METHOD(Can_Remove) {
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.Remove(0);

			Assert::IsNotNull(list.LastNode());
			Assert::IsNotNull(list.FirstNode());

			Assert::IsTrue(list.FirstNode()->value == 20);

			Assert::IsTrue(list.Count() == 3);
		}

		//TODO:
		//TEST_METHOD(Can_Sort) {
		//	Assert::Fail;
		//}
	};
}