#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/usdGeom/xform.h>

int main() {
    // Create a new USD stage
    pxr::UsdStageRefPtr stage = pxr::UsdStage::CreateNew("HelloWorld.usda");

    // Define an Xform prim
    pxr::UsdGeomXform xformPrim = pxr::UsdGeomXform::Define(stage, pxr::SdfPath("/hello"));

    // Define a Sphere prim under the Xform prim
    pxr::UsdGeomSphere spherePrim = pxr::UsdGeomSphere::Define(stage, pxr::SdfPath("/hello/world"));

    // Save the root layer
    stage->GetRootLayer()->Save();

    return 0;
}
