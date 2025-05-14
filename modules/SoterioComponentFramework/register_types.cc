#include "register_types.h"
#include "core/object/class_db.h"

#include "modules/register_module_types.h"

#include "sb_component.h"
#include "sb_game_manager.h"
#include "sb_heat_component.h"
#include "sb_metal_resource.h"
#include "sb_component_binder.h"

void initialize_SoterioComponentFramework_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
        return;

    ClassDB::register_class<SBComponentBinder>();
    // ClassDB::register_class<SBComponent>(); // no need to register yet
    ClassDB::register_class<SBGameManager>();
    ClassDB::register_class<SBHeatComponent>();
    ClassDB::register_class<SBMetalResource>();
}

void uninitialize_SoterioComponentFramework_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    // Nothing to clean up for now
}