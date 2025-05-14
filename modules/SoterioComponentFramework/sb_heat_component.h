#ifndef SB_HEAT_COMPONENT_H
#define SB_HEAT_COMPONENT_H

#include "sb_component.h"
#include "core/io/resource.h"

class SBMetalResource;

class SBHeatComponent : public SBComponent {
    GDCLASS(SBHeatComponent, SBComponent);

protected:
    static void _bind_methods();

    float CurrentTemp = 20.0f; // room temperature
    Ref<SBMetalResource> MetalResource;

public:
    SBHeatComponent() = default;

    StringName GetComponentName() const override { return "heat"; }
    int GetTickType() const override { return 1; } // TIMED

    void OnTick(double Delta) override;

    void AddHeat(float Amount);
    float GetTemperature() const;
    float GetSoftness() const;

    void SetMetalResource(const Ref<SBMetalResource>& Resource);
    Ref<SBMetalResource> GetMetalResource() const;
};

#endif // SB_HEAT_COMPONENT_H
