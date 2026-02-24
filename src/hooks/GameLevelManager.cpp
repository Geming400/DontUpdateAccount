#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GameLevelManager.hpp>
class $modify(MyGameLevelManager, GameLevelManager) {
    static void onModify(auto& self) {
        (void) self.setHookPriority("GameLevelManager::updateUserScore", Priority::Replace);
    }

    void updateUserScore() {
        this->onUpdateUserScoreCompleted(fmt::to_string(GameManager::get()->m_playerUserID.value()), "user_score");
    }
};