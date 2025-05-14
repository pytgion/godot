#include "sb_metal_resource.h"
#include "core/object/class_db.h"

void SBMetalResource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_max_temp", "value"), &SBMetalResource::SetMaxTemp);
    ClassDB::bind_method(D_METHOD("get_max_temp"), &SBMetalResource::GetMaxTemp);
    ClassDB::bind_method(D_METHOD("set_cooling_rate", "rate"), &SBMetalResource::SetCoolingRate);
    ClassDB::bind_method(D_METHOD("get_cooling_rate"), &SBMetalResource::GetCoolingRate);
    ClassDB::bind_method(D_METHOD("set_softness_curve", "curve"), &SBMetalResource::SetSoftnessCurve);
    ClassDB::bind_method(D_METHOD("get_softness_curve"), &SBMetalResource::GetSoftnessCurve);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_temp"), "set_max_temp", "get_max_temp");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "cooling_rate"), "set_cooling_rate", "get_cooling_rate");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "softness_curve", PROPERTY_HINT_RESOURCE_TYPE, "Curve"), "set_softness_curve", "get_softness_curve");
}

void SBMetalResource::SetMaxTemp(float Temp) {
    MaxTemp = Temp;
}

float SBMetalResource::GetMaxTemp() const {
    return MaxTemp;
}

void SBMetalResource::SetCoolingRate(float Rate) {
    CoolingRate = Rate;
}

float SBMetalResource::GetCoolingRate() const {
    return CoolingRate;
}

void SBMetalResource::SetSoftnessCurve(const Ref<Curve>& Curve) {
    SoftnessCurve = Curve;
}

Ref<Curve> SBMetalResource::GetSoftnessCurve() const {
    return SoftnessCurve;
}
