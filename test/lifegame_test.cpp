#include "gtest/gtest.h"
#include "lifeGame.h"
#include "userInterface.h"

TEST(LifeGameTest, show_life_game_using_by_random) {
    LifeGame object(40, 40);
    object.initByRandom();
    object.show();
}

TEST(LifeGameTest, show_interface_using_by_random) {
    lifeGameWithRandomInitData();
}

//TEST(LifeGameTest, show_interface_using_by_import_data_from_file) {
//    lifeGameWithImportInitDataFromFile();
//}