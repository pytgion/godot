#ifndef SB_METAL_RESOURCE_H
#define SB_METAL_RESOURCE_H

#include "core/io/resource.h"
#include "scene/resources/curve.h"

// abstract class for metals

class SBMetalResource : public Resource {
    GDCLASS(SBMetalResource, Resource);

protected:
    static void _bind_methods();

    float MaxTemp = 1000.0f;
    float CoolingRate = 25.0f;
    Ref<Curve> SoftnessCurve; // normalized 0.0–1.0 over temp

public:
    void SetMaxTemp(float Temp);
    float GetMaxTemp() const;

    void SetCoolingRate(float Rate);
    float GetCoolingRate() const;

    void SetSoftnessCurve(const Ref<Curve>& Curve);
    Ref<Curve> GetSoftnessCurve() const;
};

#endif // SB_METAL_RESOURCE_H
