#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1r/lab8.1r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLabTest
{
    TEST_CLASS(UTLabTest)
    {
    public:
        // ���������� ������� CountOccurrences
        TEST_METHOD(TestCountOccurrences)
        {
            const char* testStr = "a+b=c-";  // �������� �����
            int result = CountOccurrences(testStr);  // ��������� �������
            Assert::AreEqual(result, 3);  // ��������: 3 ������� "+", "-", "="
        }

        // ���������� ������� ReplaceSymbols
        TEST_METHOD(TestReplaceSymbols)
        {
            // �������� �����
            char testStr[] = "a+b=c-";

            // ��������� ������� ��� ����� �������
            ReplaceSymbols(testStr);

            // �������� ���������� �����
            Assert::AreEqual(testStr, "a**c**");  // ���������� ��������� ���� �����
        }

        // ���� ��� ���������� ����� (��������� �������)
        TEST_METHOD(TestCountOccurrencesEmptyString)
        {
            const char* testStr = "";  // ������� �����
            int result = CountOccurrences(testStr);  // ��������� �������
            Assert::AreEqual(result, 0);  // ������� ���� 0 �������
        }

        // ���� ��� ����� ��� ������� "+", "-", "=" (����� �� ����������)
        TEST_METHOD(TestReplaceSymbolsNoChanges)
        {
            // ����� ��� ������� "+", "-", "="
            char testStr[] = "abcdef";

            // ��������� ������� ��� ����� �������
            ReplaceSymbols(testStr);

            // ��������, �� ����� ��������� ��������
            Assert::AreEqual(testStr, "abcdef");  // ���������� ���������
        }

        // ���� ��� ����� � ���� ����� ��������, ���� ������� �������
        TEST_METHOD(TestReplaceSymbolsSingleCharacter)
        {
            // �������� �����, �� ������ ���� ���� ������ "+"
            char testStr[] = "+";

            // ��������� ������� ��� ����� �������
            ReplaceSymbols(testStr);

            // ��������, �� ������ "+" ������� �� "**"
            Assert::AreEqual(testStr, "**");
        }
    };
}