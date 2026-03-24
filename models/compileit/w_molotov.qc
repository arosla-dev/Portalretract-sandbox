// Created by Crowbar 0.74

$modelname "weapons/W_molotov.mdl"

$bodygroup "studio"
{
	studio "Molotov_valvebiped_reference.smd"
}


$contents "solid"

$illumposition 0.001 -0.563 0

$cdmaterials "models\weapons\w_molotov\\"

$attachment "0" "fire" 0 0 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox -1.109 -1.459 -7.298 2.236 1.46 7.299

$definebone "ValveBiped.Bip01_R_Hand" "" 1.395145 3.180122 -1.893364 1.755873 -136.324114 -179.852131 0 0 0 0 0 0
$definebone "Cylinder01" "ValveBiped.Bip01_R_Hand" 3.151128 -1.347904 -1.987387 -1.372371 -136.332761 178.894716 0 0 0 0 0 0
$definebone "fire" "Cylinder01" 0 0.88291 4.372376 0 89.999921 89.999982 0 0 0 0 0 0

$animation "a_idle" "w_molotov_anims\idle.smd" {
	fps 30
	loop
}

$animation "a_attack1" "w_molotov_anims\attack1.smd" {
	fps 30
}

$sequence "idle" {
	"a_idle"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "attack1" {
	"a_attack1"
	fadein 0.2
	fadeout 0.2
}


$collisionmodel "w_molotov_physics.smd"
{
	$mass 1
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "

}
