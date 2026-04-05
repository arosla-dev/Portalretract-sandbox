// Created by Crowbar 0.74

$modelname "props/laser_emitter_beta.mdl"

$bodygroup "Body"
{
	studio "laser_emitter_reference.smd"
}


$surfaceprop "metalpanel"

$contents "solid"

$illumposition 0 -5.936 0

$mostlyopaque

$cdmaterials "models\props\"

$attachment "laser_attachment" "lens" 0 -20 -50 rotate 0 -90 0

$cbox 0 0 0 0 0 0

$bbox -20 -32.25 -32.25 31.872 32.25 32.25

$definebone "Scene_Root" "" 0 0 0 0 0 89.999982 0 0 0 0 0 0
$definebone "root" "Scene_Root" 0 -14 -20 0 0 0 0 0 0 0 0 0
$definebone "body" "root" 0 0 39 0 0 0 0 0 0 0 0 0
$definebone "lens" "body" 0 0 11 0 0 0 0 0 0 0 0 0


$sequence "idle" {
	"laser_emitter_anims\idle.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$collisionmodel "laser_emitter_physics.smd"
{
	$mass 120
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "

}
