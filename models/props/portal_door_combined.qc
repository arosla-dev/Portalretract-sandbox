// Created by Crowbar 0.74

$modelname "props\portal_door_combined.mdl"

$bodygroup "Body"
{
	studio "p1_door.smd"
}


$surfaceprop "metal"

$contents "solid"

$illumposition 0 -8.461 54.118

$cdmaterials "models\props\"
$cdmaterials ""

$texturegroup "skinfamilies"
{
	{ "p1_door"     }
	{ "p1_door_off" }
}

$cbox 0 0 0 0 0 0

$bbox 0 -63.86 -0.003 16.921 63.861 108.24

$definebone "door_root" "" 0 0 0 0 0 0 0 0 0 0 0 0
$definebone "door_left" "door_root" -10 0 0 0 0 0 0 0 0 0 0 0
$definebone "door_right" "door_root" 10 0 0 0 0 0 0 0 0 0 0 0


$sequence "idleclosed" {
	"portal_door_combined_anims\idleclosed.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$sequence "idleopen" {
	"portal_door_combined_anims\idleopen.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$sequence "open" {
	"portal_door_combined_anims\open.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$sequence "close" {
	"portal_door_combined_anims\close.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$collisionjoints "portal_door_combined_physics.smd"
{
	$mass 50
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "
	$concaveperjoint


	$jointconstrain "door_left" x limit 0 0 0
	$jointconstrain "door_left" y limit 0 0 0
	$jointconstrain "door_left" z limit 0 0 0

	$jointconstrain "door_right" x limit 0 0 0
	$jointconstrain "door_right" y limit 0 0 0
	$jointconstrain "door_right" z limit 0 0 0
}

$keyvalues
{
	bone_followers 
	{
		"bone" "door_root"
		"bone" "door_left"
		"bone" "door_right"
	}
}
