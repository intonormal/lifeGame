#include "gtest/gtest.h"
#include "lifeGame.h"
#include "memory.h"
#include "macro.h"

namespace {
    const int size = 3;
    const int num = 9;
    LifeGame object(size, size);
}

struct LifeGameRuleTest : testing::Test {
    void SetUp() {
        initalStatus = setArea(size, size);    
    } 

    void TearDown() {
        clearArea(initalStatus, size); 
    }

    void init(int status[]) {
        for(int i = 0; i < num; i++) {
              initalStatus[i/size][i%size] = status[i];
            }
    }

protected:
    int** initalStatus;
};
//////////////////////////////////////////////////////////////////////////
TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_0_active_neighbour_And_It_is_dead) {
    int input[num] = {DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_0_active_neighbour_And_It_is_alive) {
    int input[num] = {DEAD, DEAD, DEAD, DEAD, ALIVE, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_1_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_1_active_neighbourAnd_it_is_alive) {
    int input[num] = {ALIVE, DEAD, DEAD, DEAD, ALIVE, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_2_active_neighbour_AND_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_active_when_it_has_2_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, DEAD, DEAD, ALIVE, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(ALIVE == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_active_when_it_has_3_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);
    
    EXPECT_TRUE(ALIVE == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_active_when_it_has_3_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, DEAD, ALIVE, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(ALIVE == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_4_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_4_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_5_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, ALIVE, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_5_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_6_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, ALIVE, ALIVE, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_6_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_7_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, ALIVE, ALIVE, ALIVE, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_7_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, DEAD};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_8_active_neighbour_And_it_is_dead) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, ALIVE, ALIVE, ALIVE, ALIVE};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}

TEST_F(LifeGameRuleTest, cell_should_be_dead_when_it_has_8_active_neighbour_And_it_is_alive) {
    int input[num] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE};
    init(input);

    object.initFormInput(initalStatus);

    EXPECT_TRUE(DEAD == object.status(1, 1));
}
