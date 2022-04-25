#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 3.6/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a = 3;
			B1 b(a);
			Assert::AreEqual(a, b.get_b1());
		}
	};
}
