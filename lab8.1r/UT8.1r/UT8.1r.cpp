#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1r/lab8.1r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLabTest
{
    TEST_CLASS(UTLabTest)
    {
    public:
        // Тестування функції CountOccurrences
        TEST_METHOD(TestCountOccurrences)
        {
            const char* testStr = "a+b=c-";  // Тестовий рядок
            int result = CountOccurrences(testStr);  // Викликаємо функцію
            Assert::AreEqual(result, 3);  // Перевірка: 3 символи "+", "-", "="
        }

        // Тестування функції ReplaceSymbols
        TEST_METHOD(TestReplaceSymbols)
        {
            // Тестовий рядок
            char testStr[] = "a+b=c-";

            // Викликаємо функцію для заміни символів
            ReplaceSymbols(testStr);

            // Перевірка результату заміни
            Assert::AreEqual(testStr, "a**c**");  // Очікуваний результат після заміни
        }

        // Тест для порожнього рядка (підрахунок символів)
        TEST_METHOD(TestCountOccurrencesEmptyString)
        {
            const char* testStr = "";  // Порожній рядок
            int result = CountOccurrences(testStr);  // Викликаємо функцію
            Assert::AreEqual(result, 0);  // Повинно бути 0 символів
        }

        // Тест для рядка без символів "+", "-", "=" (заміна не відбудеться)
        TEST_METHOD(TestReplaceSymbolsNoChanges)
        {
            // Рядок без символів "+", "-", "="
            char testStr[] = "abcdef";

            // Викликаємо функцію для заміни символів
            ReplaceSymbols(testStr);

            // Перевірка, чи рядок залишився незмінним
            Assert::AreEqual(testStr, "abcdef");  // Очікуваний результат
        }

        // Тест для рядка з лише одним символом, який потрібно замінити
        TEST_METHOD(TestReplaceSymbolsSingleCharacter)
        {
            // Тестовий рядок, що містить лише один символ "+"
            char testStr[] = "+";

            // Викликаємо функцію для заміни символів
            ReplaceSymbols(testStr);

            // Перевірка, чи символ "+" замінено на "**"
            Assert::AreEqual(testStr, "**");
        }
    };
}