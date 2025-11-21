#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\YAA\source\repos\laba2oipz\laba2oipz\laba2oipz.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тести для функції calculate_y
        TEST_METHOD(Test_CalculateY_NegativeX)
        {
            // Тест для x < 0
            double x = -2.0;
            int n = 5;
            double result = calculate_y(x, n);
            Assert::IsTrue(result != 0, L"Результат не повинен бути нульовим для x < 0");
        }

        TEST_METHOD(Test_CalculateY_PositiveX)
        {
            // Тест для x >= 0
            double x = 2.0;
            int n = 5;
            double result = calculate_y(x, n);
            Assert::IsTrue(result >= 0, L"Результат повинен бути >= 0 для x >= 0");
        }

        TEST_METHOD(Test_CalculateY_ZeroX)
        {
            // Тест для x = 0
            double x = 0.0;
            int n = 5;
            double result = calculate_y(x, n);
            Assert::IsTrue(result >= 0, L"Результат повинен бути >= 0");
        }

        TEST_METHOD(Test_CalculateY_SmallN)
        {
            // Тест для малого n
            double x = 1.5;
            int n = 5;
            double result = calculate_y(x, n);
            Assert::IsTrue(result != 0, L"Результат не повинен бути нульовим");
        }

        // Тести для перевірки параметра n
        TEST_METHOD(Test_CheckValidParams_N_LessThan4)
        {
            int n = 3;
            try {
                checkValidParams(n);
                Assert::Fail(L"Очікувалось виключення для n < 4");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_CheckValidParams_N_Equal4)
        {
            int n = 4;
            try {
                checkValidParams(n);
                Assert::Fail(L"Очікувалось виключення для n = 4");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_CheckValidParams_N_Valid)
        {
            int n = 10;
            try {
                checkValidParams(n);
                Assert::IsTrue(true, L"Не повинно бути виключення для n > 4");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для коректного n");
            }
        }

        TEST_METHOD(Test_CheckValidParams_N_Negative)
        {
            int n = -5;
            try {
                checkValidParams(n);
                Assert::Fail(L"Очікувалось виключення для n < 0");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        // Тести для перевірки параметрів a і b
        TEST_METHOD(Test_CheckValidParams_A_GreaterThan_B)
        {
            double a = 5.0;
            double b = 2.0;
            try {
                checkValidParams(a, b);
                Assert::Fail(L"Очікувалось виключення для a > b");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_CheckValidParams_A_Equal_B)
        {
            double a = 5.0;
            double b = 5.0;
            try {
                checkValidParams(a, b);
                Assert::IsTrue(true, L"Не повинно бути виключення для a = b");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для a = b");
            }
        }

        TEST_METHOD(Test_CheckValidParams_A_LessThan_B)
        {
            double a = 2.0;
            double b = 5.0;
            try {
                checkValidParams(a, b);
                Assert::IsTrue(true, L"Не повинно бути виключення для a < b");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для коректних a та b");
            }
        }

        // Тести для перевірки кроку h
        TEST_METHOD(Test_CheckValidParams_H_Negative)
        {
            double h = -1.0;
            try {
                checkValidParams(h);
                Assert::Fail(L"Очікувалось виключення для h < 0");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_CheckValidParams_H_Zero)
        {
            double h = 0.0;
            try {
                checkValidParams(h);
                Assert::Fail(L"Очікувалось виключення для h = 0");
            }
            catch (const logic_error&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_CheckValidParams_H_Positive)
        {
            double h = 1.0;
            try {
                checkValidParams(h);
                Assert::IsTrue(true, L"Не повинно бути виключення для h > 0");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для коректного h");
            }
        }

        // Тести для typeIntoFile
        TEST_METHOD(Test_TypeIntoFile_Invalid_Negative)
        {
            int writeIntoFile = -1;
            try {
                typeIntoFile(writeIntoFile);
                Assert::Fail(L"Очікувалось виключення для значення -1");
            }
            catch (const invalid_argument&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_TypeIntoFile_Invalid_Two)
        {
            int writeIntoFile = 2;
            try {
                typeIntoFile(writeIntoFile);
                Assert::Fail(L"Очікувалось виключення для значення 2");
            }
            catch (const invalid_argument&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(Test_TypeIntoFile_Valid_Zero)
        {
            int writeIntoFile = 0;
            try {
                typeIntoFile(writeIntoFile);
                Assert::IsTrue(true, L"Не повинно бути виключення для значення 0");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для значення 0");
            }
        }

        TEST_METHOD(Test_TypeIntoFile_Valid_One)
        {
            int writeIntoFile = 1;
            try {
                typeIntoFile(writeIntoFile);
                Assert::IsTrue(true, L"Не повинно бути виключення для значення 1");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для значення 1");
            }
        }

        // Тест для перевірки файлу
        TEST_METHOD(Test_CheckFile_Valid)
        {
            ofstream fout("test_output.txt");
            try {
                checkFile(fout);
                Assert::IsTrue(true, L"Файл успішно відкрито");
            }
            catch (...) {
                Assert::Fail(L"Не очікувалось виключення для відкритого файлу");
            }
            fout.close();
        }

        TEST_METHOD(Test_CheckFile_Invalid)
        {
            ofstream fout;
            try {
                checkFile(fout);
                Assert::Fail(L"Очікувалось виключення для закритого файлу");
            }
            catch (const invalid_argument&) {
                Assert::IsTrue(true);
            }
        }
    };
}