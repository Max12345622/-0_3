#include "pch.h"
#include "CppUnitTest.h"
#include "..\oplia2\Postuplenie_tovarov.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(validCreateTovars)
        {
            Postuplenie_tovarow P;
            std::stringstream f("in.txt");

            try {
                P.createTovars(f);
            }
            catch (const std::runtime_error& message) {
                return;
            }
            Assert::Fail();
        }

        TEST_METHOD(validFunciaDate) {
            Date D;
            std::stringstream f("in.txt");

            try {
                D.funcia_date(f);
            }
            catch (const std::runtime_error& message) {
                return;
            }
            Assert::Fail();
        }

        TEST_METHOD(validPrintDate) {
            Date D;

            D.setDay(11);
            D.setMonth(2);
            D.setYear(2022);

            std::stringstream x;
            D.printDate(x);
            std::string d = "11.2.2022";
            Assert::AreEqual(x.str(), d);
        }

        TEST_METHOD(validCorrectDate) {
            Date D;
            D.correctDate(13, 12, 11);
        }

        TEST_METHOD(validIsLeapYear) {
            Date D;
            D.leapYear(2024);
        }

        TEST_METHOD(validReadDate) {
            Date D;
            std::string d = "12.12.22";
            D.readDate(d);
        }

        TEST_METHOD(validCorrectKolichestvo) {
            Postuplenie_tovarow P;

            P.correctKolichestwo(10);
        }

        TEST_METHOD(validPrintTovar) {
            Postuplenie_tovarow P;

            P.setKolichestwo(10);
            P.setTovar("Milk");
            std::string s = " Milk 10\n";
            std::stringstream x;
            P.printTovar(x);
            Assert::AreEqual(x.str(), s);
        }

        TEST_METHOD(validPrint) {
            Postuplenie_tovarow P;
            Date D;
            std::vector<Postuplenie_tovarow> tovars;
            std::ostringstream ost{""};
            P.setKolichestwo(10);
            P.setTovar("Milk");

            D.setDay(10);
            D.setMonth(12);
            D.setYear(2022);
            P.setDate(D);

            tovars.push_back(P);
            P.print(tovars, ost);
            std::string str = ost.str();

            Assert::IsTrue(str == "10.12.2022 Milk 10\n");
        }

        ///////

        TEST_METHOD(invalidPrintDate) {
            Date D;
            D.setDay(10);
            D.setMonth(2);
            D.setYear(2023);

            std::string str = "12.12.12";
            std::stringstream x;
            D.printDate(x);
            Assert::AreNotEqual(x.str(), str);
        }

        TEST_METHOD(invalidCorrecctDate) {
            Date D;
            try {
                D.correctDate(1, 100, 2020);
            }
            catch (const std::runtime_error& Message) {
                return;
            }
            Assert::Fail();
        }

        TEST_METHOD(invalidCorrectKolichestvo) {
            Postuplenie_tovarow P;
            try {
                P.correctKolichestwo(-1);
            }
            catch (const std::runtime_error& Message) {
                return;
            }
            Assert::Fail();
        }

        TEST_METHOD(invalidPrintTovars) {
            Postuplenie_tovarow P;
            P.setKolichestwo(10);
            P.setTovar("Milk");

            std::stringstream x;
            std::string str = " Milllk 10 \n";
            P.printTovar(x);
            Assert::AreNotEqual(x.str(), str);
        }

        TEST_METHOD(invalidDateRead) {
            Date D;
            std::string str = "12.12.13";
            D.readDate(str);
        }

        TEST_METHOD(invalidLeapYear) {
            try {
                Date D;
                D.leapYear(-2017);
            }
            catch (const std::runtime_error& message) {
                return;
            }
            Assert::Fail();
        }
    };
}