#ifndef SB_GAME_MANAGER_H
#define SB_GAME_MANAGER_H

#include "scene/main/node.h"
#include "core/templates/vector.h"

class SBComponentBinder;

class SBGameManager : public Node {
    GDCLASS(SBGameManager, Node);

protected:
    static void _bind_methods();
    static SBGameManager* Singleton;

    Vector<SBComponentBinder*> TrackedBinders;

public:
    static SBGameManager* GetSingleton() { return Singleton; }

    void _ready();
    void RegisterBinder(SBComponentBinder* Binder);
    void UnregisterBinder(SBComponentBinder* Binder);

    void TickAll(double Delta); // For custom tick types in the future
};

#endif // SB_GAME_MANAGER_H
