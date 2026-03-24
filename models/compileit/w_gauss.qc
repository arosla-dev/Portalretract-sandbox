// Created by Crowbar 0.74

$modelname "Weapons/w_gauss.mdl"

$bodygroup "Body"
{
	studio "w_gauss_reference.smd"
}


$surfaceprop "metal"

$contents "solid"

$illumposition 3.326 -12.349 -0.163

$cdmaterials "models\Weapons\w_gauss\"

$attachment "muzzle" "MuzzleBone" 0 0 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox -3.101 -3.958 -3.628 34.003 3.955 5.19

$definebone "ValveBiped.Bip01_R_Hand" "" -2.014719 2.83541 -2.618802 7.617131 -80.462641 161.033458 0 0 0 0 0 0
$definebone "ValveBiped.bone" "ValveBiped.Bip01_R_Hand" 1.044117 -1.644804 -1.292907 19.955719 -79.9377 -94.256884 0 0 0 0 0 0
$definebone "MuzzleBone" "ValveBiped.bone" -0.120288 2.192312 26.681412 -89.10494 -90.002557 90.002646 0 0 0 0 0 0
$definebone "Spinner" "ValveBiped.Bip01_R_Hand" 10.152725 0.876341 -3.394151 19.955719 -79.937638 -94.256884 0 0 0 0 0 0

$animation "a_idle1" "w_gauss_anims\a_idle1.smd" {
	fps 30
	loop
}

$animation "a_fire" "w_gauss_anims\a_fire.smd" {
	fps 30
}

$sequence "idle1" {
	"a_idle1"
	activity "ACT_VM_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

$sequence "fire" {
	"a_fire"
	activity "ACT_RANGE_ATTACK_AR2" 1
	fadein 0.2
	fadeout 0.2
}


$collisionmodel "w_gauss_physics.smd"
{
	$mass 10
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "

}

$KeyValues
{
	prop_data 
	{
		"base" "Metal.Small"
	}
}
