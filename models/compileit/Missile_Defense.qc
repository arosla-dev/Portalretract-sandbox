// Created by Crowbar 0.74

$modelname "Missile_Defense.mdl"

$bodygroup "studio"
{
	studio "Missile_Defense_base.smd"
}
$bodygroup "hull"
{
	blank
	studio "Missile_Defense_gibs2.smd"
}
$bodygroup "gun1"
{
	blank
	studio "Missile_Defense_gibs3.smd"
}
$bodygroup "gun2"
{
	blank
	studio "Missile_Defense_gibs4.smd"
}
$bodygroup "cap"
{
	blank
	studio "Missile_Defense_gibs5.smd"
}


$contents "solid"

$illumposition 0 -0.008 28.235

$cdmaterials "models\missile_defense\"

$attachment "0" "R_Gun_AtchPnt" 0 0 0 rotate 0 0 0
$attachment "1" "L_Gun_AtchPnt" 0 0 0 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox -42.828 -42.837 0.016 42.845 42.836 56.453

$controller 0 "Main_Base" ZR -120 120
$controller 1 "Guns_Base" XR -45 45

$definebone "Root" "" 0 -0.000002 37.173691 0 0 0 0 0 0 0 0 0
$definebone "Main_Base" "Root" 0 -0.023742 -9.707077 0 0 0 0 0 0 0 0 0
$definebone "Guns_Base" "Main_Base" 7.122766 1.685086 0.000002 0 0 0 0 0 0 0 0 0
$definebone "R_Gun" "Guns_Base" -21.245588 -0.005135 -0.000002 0 0 0 0 0 0 0 0 0
$definebone "R_Gun_AtchPnt" "R_Gun" 0.301132 -27.43288 1.425652 0 -179.999978 0 0 0 0 0 0 0
$definebone "L_Gun" "Guns_Base" 7.098359 -0.00514 -0.000002 0 0 0 0 0 0 0 0 0
$definebone "L_Gun_AtchPnt" "L_Gun" -0.06864 -27.421444 1.425652 0 -179.999978 0 0 0 0 0 0 0

$animation "a_idle" "Missile_Defense_anims\idle.smd" {
	fps 30
	loop
}

$sequence "idle" {
	"a_idle"
	activity "ACT_IDLE" 1
	fadein 0.2
	fadeout 0.2
}

