#include <MorseTree.h>

#include <gtest/gtest.h>

using namespace morse;

TEST(MorseTreeTest, InsertA) {
    MorseTree tree;
    tree.insert('A', ".-", 2);

    MorseTree::FSM fsm(&tree);
    EXPECT_TRUE(fsm.process('.'));
    EXPECT_EQ(fsm.getValue(), '\0');
    EXPECT_TRUE(fsm.process('-'));
    EXPECT_EQ(fsm.getValue(), 'A');
}

TEST(MorseTreeTest, FSMInvalidState) {
    MorseTree tree;
    tree.insert('A', ".-", 2);

    MorseTree::FSM fsm(&tree);
    EXPECT_FALSE(fsm.process('-'));
    EXPECT_EQ(fsm.getValue(), '\0');
}

TEST(MorseTreeTest, ITU) {
    std::unique_ptr<MorseTree> tree(MorseTree::itu());

    MorseTree::FSM fsm(tree.get());
    EXPECT_EQ(fsm.getValue(), '\0');
    EXPECT_TRUE(fsm.process(".--.", 4));
    EXPECT_EQ(fsm.getValue(), 'P');

    fsm.reset();
    EXPECT_TRUE(fsm.process("--...", 5));
    EXPECT_EQ(fsm.getValue(), '7');
}

#if defined(ARDUINO)
#include <Arduino.h>

void setup()
{
    // should be the same value as for the `test_speed` option in "platformio.ini"
    // default value is test_speed=115200
    Serial.begin(115200);

    ::testing::InitGoogleTest();
}

void loop()
{
	// Run tests
	if (RUN_ALL_TESTS())
	;

	// sleep 1 sec
	delay(1000);
}

#else
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
	if (RUN_ALL_TESTS())
	;
	// Always return zero-code and allow PlatformIO to parse results
	return 0;
}
#endif
