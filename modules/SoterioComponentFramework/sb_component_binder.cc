#include "sb_component_binder.h"
#include "core/object/class_db.h"

void SBComponentBinder::_bind_methods() {
    // Expose to editor or scripting if needed
}

void SBComponentBinder::_ready() {
    BindComponents();
}

void SBComponentBinder::BindComponents() {
    Components.clear();

    for (int i = 0; i < get_child_count(); ++i) {
        Node* Child = get_child(i);
        SBComponent* Comp = Object::cast_to<SBComponent>(Child);
        if (Comp) {
            StringName CompName = Comp->GetComponentName();
            Components[CompName] = Comp;
            Comp->OnRegistered(this);
        }
    }
}

void SBComponentBinder::_process(double Delta) {
    for (KeyValue<StringName, SBComponent*> E : Components) {
        if (E.value && E.value->GetTickType() == 0) { // Frame tick
            E.value->OnTick(Delta);
        }
    }
}
