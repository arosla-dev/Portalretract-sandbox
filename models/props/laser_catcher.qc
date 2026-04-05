// Created by Crowbar 0.74

$modelname "props/laser_catcher_beta.mdl"

$bodygroup "Body"
{
	studio "laser_catcher_reference.smd"
}


$surfaceprop "metalpanel"

$contents "solid"

$illumposition 0 -5 0

$opaque

$cdmaterials "models\props\"

$attachment "laser_point" "root" 0 -1 42 rotate 0 0 0
$attachment "lens_center" "root" 0 -1 43 rotate 0 0 0
$attachment "laser_target" "root" 0 -1 5 rotate 0 0 0
$attachment "particle_emitter" "root" 0 -1 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox -20 -32.25 -32.25 30 32.25 32.25

$definebone "Scene_Root" "" 0 0 0 0 0 89.999982 0 0 0 0 0 0
$definebone "root" "Scene_Root" 0 -13 -20 0 0 0 0 0 0 0 0 0
$definebone "body" "root" 0 -1 39 0 0 0 0 0 0 0 0 0
$definebone "lock01" "body" 0 -0.000002 -2 0 0 0 0 0 0 0 0 0
$definebone "lock02" "body" 0 -0.000002 -2 0 0 0 0 0 0 0 0 0
$definebone "lens" "root" 0 -1.000002 50 0 0 0 0 0 0 0 0 0


$sequence "idle" {
	"laser_catcher_anims\idle.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$collisionmodel "laser_catcher_physics.smd"
{
	$mass 120
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "

}
