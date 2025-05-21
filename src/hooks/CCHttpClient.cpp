#include <Geode/Geode.hpp>
#include <Geode/loader/Dispatch.hpp>

using namespace geode::prelude;

void CCHttpClient_send(CCHttpClient* self, CCHttpRequest* req) {
    std::string_view url = req->getUrl();
    
    if (!url.ends_with("updateGJUserScore22.php") || !Mod::get()->getSettingValue<bool>("enabled")) {
        self->send(req);
    }
}

$execute {
    (void) Mod::get()->hook(
        reinterpret_cast<void*>(
			geode::addresser::getNonVirtual(&cocos2d::extension::CCHttpClient::send)
        ),
        &CCHttpClient_send,
        "cocos2d::extension::CCHttpClient::send"
    );
}