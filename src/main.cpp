#include <Geode/Geode.hpp>
#include <Geode/modify/CCMenuItemSpriteExtra.hpp>

using namespace geode::prelude;

class $modify(CCMenuItemSpriteExtra) {
	void activate() {
		CCMenuItemSpriteExtra::activate();
		auto sfxFile = Mod::get()->getSettingValue<ghc::filesystem::path>("sfx");
		log::info("file: {}, exists: {}", sfxFile, ghc::filesystem::exists(sfxFile));
		if (sfxFile == "") return;
		if (!Mod::get()->getSettingValue<bool>("in-editor") && (GameManager::sharedState()->getEditorLayer() != nullptr)) return;
		FMODAudioEngine::sharedEngine()->playEffect(sfxFile.string());
	}
};	
