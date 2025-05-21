#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(MyProfilePage, ProfilePage) {
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

        if (Mod::get()->getSettingValue<bool>("enabled")) {
            ProfilePage::updateUserScoreFinished();
        }

        return true;
    }
};