#include "./ej2.h"
#include "../mini_test.h"

using namespace std;

/*
**  Exercise 2
**  Unit tests
*/

void test_example_1() {
	Trie emails;
	list<string> nicknames;

	string mail = "mimaileseste";
	emails.insert(mail);
	mail = "mimailesesteotro";
	emails.insert(mail);
	mail = "estemailesmio";
	emails.insert(mail);
	mail = "holaesteesmimail";
	emails.insert(mail);
	mail = "miramimail";
	emails.insert(mail);
	mail = "miramiotromail";
	emails.insert(mail);

	nicknames.push_back("mim");
	nicknames.push_back("mimailesesteot");
	nicknames.push_back("estem");
	nicknames.push_back("holaestees");
	nicknames.push_back("mi");
	nicknames.push_back("miram");

	ASSERT_EQ(4, maxAparitions(emails, nicknames));
}

void test_example_2() {
	Trie emails;
	list<string> nicknames;

	string mail = "aaaa";
	emails.insert(mail);
	mail = "bbbb";
	emails.insert(mail);
	mail = "cccc";
	emails.insert(mail);
	mail = "dddd";
	emails.insert(mail);

	nicknames.push_back("a");
	nicknames.push_back("b");
	nicknames.push_back("c");
	nicknames.push_back("dddd");

	ASSERT_EQ(1, maxAparitions(emails, nicknames));
}

void test_example_3() {
	Trie emails;
	list<string> nicknames;

	string mail = "estos";
	emails.insert(mail);
	mail = "estosmails";
	emails.insert(mail);
	mail = "estosmailsno";
	emails.insert(mail);
	mail = "estosmailsnoson";
	emails.insert(mail);
	mail = "estosmailsnosonlibres";
	emails.insert(mail);
	mail = "estosmailsnosonlibresde";
	emails.insert(mail);
	mail = "estosmailsnosonlibresdeprefijos";
	emails.insert(mail);

	nicknames.push_back("esto");
	nicknames.push_back("estos");
	nicknames.push_back("estosm");
	nicknames.push_back("estosma");
	nicknames.push_back("estosmai");
	nicknames.push_back("estosmail");
	nicknames.push_back("estosmails");

	ASSERT_EQ(7, maxAparitions(emails, nicknames));
}

void test_sufix_chains() {
	Trie emails;
	list<string> nicknames;

	string mail = "aloha";
	emails.insert(mail);
	mail = "dicenaloha";
	emails.insert(mail);
	mail = "hawaianosdicenaloha";
	emails.insert(mail);
	mail = "loshawaianosdicenaloha";
	emails.insert(mail);

	nicknames.push_back("alo");
	nicknames.push_back("dicenalo");
	nicknames.push_back("hawai");
	nicknames.push_back("loshawai");

	ASSERT_EQ(1, maxAparitions(emails, nicknames));

}

void run_unit_tests() {
	RUN_TEST(test_example_1);
	RUN_TEST(test_example_2);
	RUN_TEST(test_example_3);
	RUN_TEST(test_sufix_chains);
}
