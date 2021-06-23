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
			list.PopBack();
			list.PopBack();
	

			//checks if the lastnode isnt null
			Assert::IsNotNull(list.LastNode());

			//checks if the last node = 30
			Assert::IsTrue(list.LastNode()->value == 10);

			//checks if the count went down to 3
			Assert::IsTrue(list.Count() == 1);
			
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

			//should remove all items in the list
			list.Clear();

			//checks if the position are null
			Assert::IsNull(list.LastNode());
			Assert::IsNull(list.FirstNode());

			//the lists count should be 0
			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Can_Insert) {
			LinkedList<int> list = { 10, 20, 30, 40 };

			//finds the position at 10

			auto iter = std::find(list.begin(), list.end(), 10);			
			//insets 5 at the position of 10
			list.Insert(iter,5);

			//checks if there is a value in the first and last position in list
			Assert::IsNotNull(list.LastNode());
			Assert::IsNotNull(list.FirstNode());

			//after adding an item in the first position it should now be 5
			Assert::IsTrue(list.FirstNode()->value == 5);

			//the count should have gone up by 1
			Assert::IsTrue(list.Count() == 5);
		}

		TEST_METHOD(Can_Remove) {
			LinkedList<int> list = { 10, 20, 30, 40 };

			//finds the position at 10
			auto iter = std::find(list.begin(), list.end(), 10);
			//removes the position at 10
			list.Remove(iter);

			//checks if there is a value in the first and last position in list
			Assert::IsNotNull(list.LastNode());
			Assert::IsNotNull(list.FirstNode());

			//after removing the first number the first should now be 20
			Assert::IsTrue(list.FirstNode()->value == 20);
			//the list size should now be 1 less then 4
			Assert::IsTrue(list.Count() == 3);
		}

		//TODO:
		TEST_METHOD(Can_Sort) {
			LinkedList<int> list = { 20, 40, 10, 50 , 30};

		
			//sorts
			list.Sort();

			//checks if there is a value in the first and last position in list
			Assert::IsNotNull(list.LastNode());
			Assert::IsNotNull(list.FirstNode());

			//after sorting the first should now be 10
			Assert::IsTrue(list.FirstNode()->value == 50);
			//last should be 40
			Assert::IsTrue(list.LastNode()->value == 10);
			//the list size should still be 4
			Assert::IsTrue(list.Count() == 5);
		}

	};
}