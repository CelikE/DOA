#include <gtest\gtest.h>

#include "..\SkipList\SkipList.h"



class SkipListUnitTest : public ::testing::Test {
protected:
	IDictionary<int>* uut;

	void SetUp() {
		uut = new SkipList<int>(5);
	}

	void TearDown() {
		delete uut;
	}
};


TEST_F(SkipListUnitTest, IsEmpty_NoElementsInserted_ListIsEmpty) {
	ASSERT_TRUE(uut->isEmpty());
}

TEST_F(SkipListUnitTest, IsEmpty_OneElementInserted_ListIsNotEmpty) {
	uut->insert(1);
	ASSERT_FALSE(uut->isEmpty());
}


TEST_F(SkipListUnitTest, IsEmpty_4And5And6Inserted4And5Removed_ListNotEmpty) {
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(5);
	uut->remove(6);

	ASSERT_FALSE(uut->isEmpty());
}

TEST_F(SkipListUnitTest, IsEmpty_4And5And6InsertedThenRemoved_ListIsEmpty) {
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(5);
	uut->remove(6);
	uut->remove(4);

	ASSERT_TRUE(uut->isEmpty());
}



TEST_F(SkipListUnitTest, Insert_5NotInserted_5IsNotFound) {
	ASSERT_FALSE(uut->search(5));
}

TEST_F(SkipListUnitTest, Insert_5Inserted_5IsFound) {
	uut->insert(5);
	ASSERT_TRUE(uut->search(5));
}


TEST_F(SkipListUnitTest, Insert_4And5And6Inserted_AllElementsAreFound) {
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);

	ASSERT_TRUE(uut->search(4) && uut->search(5) && uut->search(6));
}

TEST_F(SkipListUnitTest, Insert_DuplicateInsertedOneInstanceRemoved_ElementStillFound) {
	uut->insert(4);
	uut->insert(4);
	uut->remove(4);

	ASSERT_TRUE(uut->search(4));
}

TEST_F(SkipListUnitTest, Insert_DuplicateInsertedBothInstanceRemoved_ElementNotFound) {
	uut->insert(4);
	uut->insert(4);
	uut->remove(4);
	uut->remove(4);

	ASSERT_FALSE(uut->search(4));
}
TEST_F(SkipListUnitTest, Remove_4And5And6Inserted4Removed_4NotFound) {
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(4);

	ASSERT_FALSE(uut->search(4));
}


TEST_F(SkipListUnitTest, Remove_4And5And6Inserted4Removed_5And6StillFound) {
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(4);

	ASSERT_TRUE(uut->search(5) && uut->search(6));
}

TEST_F(SkipListUnitTest, Remove_4And5And6Inserted5Removed_5NotFound) {	
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(5);

	ASSERT_FALSE(uut->search(5));
}

TEST_F(SkipListUnitTest, Remove_4And5And6Inserted5Removed_4And6StillFound) {	
	uut->insert(4);
	uut->insert(5);
	uut->insert(6);
	uut->remove(5);

	ASSERT_TRUE(uut->search(4) && uut->search(6));
}
