#include "sb_heat_component.h"
#include "core/object/class_db.h"
#include "sb_metal_resource.h"

void SBHeatComponent::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add_heat", "amount"), &SBHeatComponent::AddHeat);
    ClassDB::bind_method(D_METHOD("get_temperature"), &SBHeatComponent::GetTemperature);
    ClassDB::bind_method(D_METHOD("get_softness"), &SBHeatComponent::GetSoftness);
    ClassDB::bind_method(D_METHOD("set_metal_resource", "resource"), &SBHeatComponent::SetMetalResource);
    ClassDB::bind_method(D_METHOD("get_metal_resource"), &SBHeatComponent::GetMetalResource);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "metal_resource", PROPERTY_HINT_RESOURCE_TYPE, "SBMetalResource"), "set_metal_resource", "get_metal_resource");
}

void SBHeatComponent::AddHeat(float Amount) {
    CurrentTemp += Amount;
}

float SBHeatComponent::GetTemperature() const {
    return CurrentTemp;
}

float SBHeatComponent::GetSoftness() const {
    if (MetalResource.is_valid()) {
        float TempRatio = CLAMP(CurrentTemp / MetalResource->GetMaxTemp(), 0.0f, 1.0f);
        return MetalResource->GetSoftnessCurve()->sample_baked(TempRatio);
    }
    return 0.0f;
}

void SBHeatComponent::OnTick(double Delta) {
    if (!MetalResource.is_valid())
        return;

    CurrentTemp -= MetalResource->GetCoolingRate() * static_cast<float>(Delta);
    if (CurrentTemp < 20.0f)
        CurrentTemp = 20.0f;
}

void SBHeatComponent::SetMetalResource(const Ref<SBMetalResource>& Resource) {
    MetalResource = Resource;
}

Ref<SBMetalResource> SBHeatComponent::GetMetalResource() const {
    return MetalResource;
}
