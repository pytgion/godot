#ifndef SB_COMPONENT_H
#define SB_COMPONENT_H

#include "scene/main/node.h"

class SBComponentBinder;

class SBComponent : public Node {
    GDCLASS(SBComponent, Node);

protected:
    static void _bind_methods();

public:
    virtual StringName GetComponentName() const = 0;

    virtual void OnRegistered(SBComponentBinder* Binder) {}
    virtual void OnTick(double Delta) {}
    virtual int GetTickType() const { return 0; }

    SBComponent() = default;
};

#endif // SB_COMPONENT_H
