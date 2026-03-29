// Created by Crowbar 0.74

$modelname "weapons\w_portalgun.mdl"

$bodygroup "w_portalgun"
{
	studio "w_portalgun_reference_prospekt.smd"
}


$surfaceprop "metal"

$contents "solid"

$illumposition -1.418 12.072 -0.502

$cdmaterials "models\weapons\"
$cdmaterials ""

$attachment "muzzle" "ValveBiped.Anim_Attachment_RH" 0 11.5 21.5 rotate -60 90 0
$attachment "Arm1_attach1" "ValveBiped.Anim_Attachment_RH" 0 5 11 rotate 0 0 0
$attachment "Arm1_attach2" "ValveBiped.Anim_Attachment_RH" 0 5.5 11.5 rotate 0 0 0
$attachment "Arm1_attach3" "ValveBiped.Anim_Attachment_RH" 0 6 12 rotate 0 0 0
$attachment "Arm2_attach1" "ValveBiped.Anim_Attachment_RH" 0 6.5 12.5 rotate 0 0 0
$attachment "Arm2_attach2" "ValveBiped.Anim_Attachment_RH" 0 7 13 rotate 0 0 0
$attachment "Arm2_attach3" "ValveBiped.Anim_Attachment_RH" 0 7.5 13.5 rotate 0 0 0
$attachment "Arm3_attach1" "ValveBiped.Anim_Attachment_RH" 0 8 14 rotate 0 0 0
$attachment "Arm3_attach2" "ValveBiped.Anim_Attachment_RH" 0 8.5 14.5 rotate 0 0 0
$attachment "Arm3_attach3" "ValveBiped.Anim_Attachment_RH" 0 9 15 rotate 0 0 0
$attachment "Body_light" "ValveBiped.Anim_Attachment_RH" 1 5 5 rotate 0 0 0
$attachment "Beam_point1" "ValveBiped.Anim_Attachment_RH" 6.8 17.5 21.5 rotate 0 0 0
$attachment "Beam_point2" "ValveBiped.Anim_Attachment_RH" -4.2 17.5 21.5 rotate 0 0 0
$attachment "Beam_point3" "ValveBiped.Anim_Attachment_RH" -4.2 7.5 26.5 rotate 0 0 0
$attachment "Beam_point4" "ValveBiped.Anim_Attachment_RH" 6.8 7.5 26.5 rotate 0 0 0
$attachment "Beam_point5" "ValveBiped.Anim_Attachment_RH" 0 11.5 21.5 rotate -60 90 0
$attachment "Inside_effects" "ValveBiped.Anim_Attachment_RH" 0 7 13 rotate 0 0 0

$cbox 0 0 0 0 0 0

$bbox -4.831 -2.532 0 7.933 18.2 28.554

$definebone "ValveBiped.Anim_Attachment_RH" "" 0 0 0 0 0 0 0 0 0 0 0 0


$sequence "idle" {
	"w_portalgun_anims\idle.smd"
	fadein 0.2
	fadeout 0.2
	fps 30
}

$collisionmodel "w_portalgun_physics.smd"
{
	$mass 1
	$inertia 1
	$damping 0
	$rotdamping 0
	$rootbone " "
	$concave
	$maxconvexpieces 7

}
