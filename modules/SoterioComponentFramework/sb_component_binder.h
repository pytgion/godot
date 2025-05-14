#ifndef SB_COMPONENT_BINDER_H
#define SB_COMPONENT_BINDER_H

#include "scene/main/node.h"
#include "core/templates/hash_map.h"

#include "sb_component.h"

// Bind components to centeral controller.

class SBComponentBinder : public Node {
    GDCLASS(SBComponentBinder, Node);

protected:
    static void _bind_methods();

    HashMap<StringName, SBComponent*> Components;

public:
    void BindComponents();

    template<typename T>
    T* GetComponent(const StringName& Name) const {
        if (Components.has(Name)) {
            return Object::cast_to<T>(Components[Name]);
        }
        return nullptr;
    }

    void _ready();
    void _process(double Delta);
};

#endif // SB_COMPONENT_BINDER_H
