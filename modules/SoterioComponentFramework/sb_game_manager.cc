#include "sb_game_manager.h"
#include "sb_component_binder.h"

SBGameManager* SBGameManager::Singleton = nullptr;

void SBGameManager::_bind_methods() {
    // Later you can expose API for scripting here
}

void SBGameManager::_ready() {
    Singleton = this;
}

void SBGameManager::RegisterBinder(SBComponentBinder* Binder) {
    if (!TrackedBinders.has(Binder)) {
        TrackedBinders.push_back(Binder);
    }
}

void SBGameManager::UnregisterBinder(SBComponentBinder* Binder) {
    TrackedBinders.erase(Binder);
}

void SBGameManager::TickAll(double Delta) {
    for (SBComponentBinder* Binder : TrackedBinders) {
        // Optionally call future custom tick types
    }
}
